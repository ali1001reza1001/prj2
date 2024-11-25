/**
 * @file Sparty.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "Sparty.h"

/// The image to draw for Sparty
const std::wstring SpartyImage = L"/sparty.png";

/// The spring pen size to use in pixels
const double SpringWireSize = 2;

/// Minimum spacing between spring wire
const double SpringWireMinSpacing = 1;

/// Color to draw the spring
const wxColour SpringColor = wxColour(220, 220, 220);

/// Sparty popup time in seconds
const double SpartyPopupTime = 0.25;

/**
 * Constructor
 * @param image Image file to load
 * @param size Size to draw Sparty (width and height)
 * @param springLength How long the spring is when fully extended in pixels
 * @param springWidth How wide the spring is in pixels
 * @param numLinks How many links (loops) there are in the spring
 */
Sparty::Sparty(std::wstring image, int size, int springLength, int springWidth, int numLinks) :
    mSpringLength(springLength), mSpringWidth(springWidth), mNumLinks(numLinks)
{
    double compressedLength = mNumLinks * (SpringWireSize + SpringWireMinSpacing);

    mSparty.Rectangle(-size/2, compressedLength / 2, size, size);
    mSparty.SetImage(image);
}

/**
 * Reset the sparty animation
 */
void Sparty::Reset()
{
    Component::Reset();

    mSpartyTime = 0;
    mPop = false;
}

/**
 * Advance the Sparty animation in time.
 * @param delta
 */
void Sparty::Advance(double delta)
{
    Component::Advance(delta);

    if(mPop)
    {
        mSpartyTime += delta;
    }

}

/**
 * Draw Sparty
 * @param graphics Graphics context to draw on
 */
void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Component::Draw(graphics);
    
    wxPen pen(SpringColor, SpringWireSize);

    graphics->SetPen(pen);


    // Compute the current t value
    double t = mSpartyTime / SpartyPopupTime;
    if(t > 1)
    {
        t = 1;
    }

    // The smallest possible size...
    double compressedLength = mNumLinks * (SpringWireSize + SpringWireMinSpacing);

    double springLength = (1 -t) * compressedLength + t * mSpringLength;

    DrawSpring(graphics, GetX(), GetY(), springLength, mSpringWidth, mNumLinks);

    mSparty.DrawPolygon(graphics, GetX(), GetY() - springLength);
}

/**
 * Draw a spring.
 * @param graphics Graphics context to render to
 * @param x X location of the bottom center of the spring in pixels
 * @param y Y location of the bottom center of the spring in pixels
 * @param length Length to draw the spring (bottom to top) in pixels
 * @param width Spring width in pixels
 * @param numLinks Number of links (loops) in the spring
 */
void Sparty::DrawSpring(std::shared_ptr<wxGraphicsContext> graphics,
                        int x, int y, double length, double width, int numLinks)
{
    auto path = graphics->CreatePath();

    // We keep track of three locations, the bottom of which
    // is y1. First half-loop will be y1 to y3, second half-loop
    // will be y3 to y2.
    double y1 = y;
    double linkLength = length / numLinks;

    // Left and right X values
    double xR = x + width / 2;
    double xL = x - width / 2;

    path.MoveToPoint(x, y1);

    for(int i=0; i<numLinks; i++)
    {
        auto y2 = y1 - linkLength;
        auto y3 = y2 - linkLength / 2;

        path.AddCurveToPoint(xR, y1, xR, y3, x, y3);
        path.AddCurveToPoint(xL, y3, xL, y2, x, y2);

        y1 = y2;
    }

    graphics->StrokePath(path);
}