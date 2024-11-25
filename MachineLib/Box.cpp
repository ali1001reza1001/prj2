/**
 * @file Box.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "Box.h"

/// The background image to use
const std::wstring BoxBackgroundImage = L"/box-background.png";

/// The foreground image to use
const std::wstring BoxForegroundImage = L"/box-foreground.png";

/// The lid image to use
const std::wstring BoxLidImage = L"/box-lid.png";

/// The horizontal scale for the lid when the angle is zero
const double LidZeroAngleScale = 0.02;

/// How long it takes to up the lid in seconds
const double LidOpeningTime = 0.25;

/**
 * Constructor
 * @param imagesDir Directory containing the images
 * @param boxSize Size of the box in pixels (just the box, not the lid)
 * @param lidSize Size of the lid in pixels
 */
Box::Box(std::wstring imagesDir, int boxSize, int lidSize) : mBoxSize(boxSize)
{
    // Background image
    mBox.Rectangle(-boxSize / 2, 0, boxSize, boxSize);
    mBox.SetImage(imagesDir + BoxBackgroundImage);

    mForeground.Rectangle(-boxSize / 2, 0, boxSize, boxSize);
    mForeground.SetImage(imagesDir + BoxForegroundImage);

    mLid.Rectangle(-lidSize / 2, 0, lidSize, lidSize);
    mLid.SetImage(imagesDir + BoxLidImage);
}

/**
 * Reset the animation to time zero
 */
void Box::Reset()
{
    Component::Reset();

    mLidAngle = 0;
    mOpen = false;
}

/**
 * Advance the animation in time
 * @param delta Amount of time to advance in seconds
 */
void Box::Advance(double delta)
{
    Component::Advance(delta);

    double openAngle = M_PI / 2;

    if(mOpen && mLidAngle < openAngle)
    {
        mLidAngle += openAngle * delta / LidOpeningTime;

        if(mLidAngle > openAngle)
        {
            mLidAngle = openAngle;
        }
    }
}

/**
 * Draw the box
 * @param graphics Graphics device to draw on
 */
void Box::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Component::Draw(graphics);

    mBox.DrawPolygon(graphics, GetX(), GetY());

    // Convert lid angle to a lid scaling from 0 to 1
    double s = sin(mLidAngle);
    double lidScale = (1 - s) * LidZeroAngleScale + s * 1.0;

    graphics->PushState();
    graphics->Translate(GetX(), GetY() - mBoxSize);
    graphics->Scale(1, lidScale);

    mLid.DrawPolygon(graphics, 0, 0);

    graphics->PopState();
}

/**
 * Draw the component in the second drawing group
 * @param graphics Graphics device to draw on
 */
void Box::DrawLast(std::shared_ptr<wxGraphicsContext> graphics)
{
    Component::DrawLast(graphics);

    mForeground.DrawPolygon(graphics, GetX(), GetY());
}
