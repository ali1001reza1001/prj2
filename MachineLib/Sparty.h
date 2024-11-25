/**
 * @file Sparty.h
 * @author Charles Owen
 *
 * The pop-up Sparty
 */

#ifndef SNOWBLOWER_CPP_MACHINELIB_SPARTY_H
#define SNOWBLOWER_CPP_MACHINELIB_SPARTY_H

#include "Polygon.h"
#include "Component.h"
#include "IKeyDrop.h"

/**
 * The pop-up Sparty
 */
class Sparty : public Component, public IKeyDrop
{
private:
    /// Sparty image
    cse335::Polygon mSparty;

    /// Length of the spring when fully extended
    int mSpringLength = 0;

    /// Width of the spring
    int mSpringWidth = 0;

    /// Number of spring links
    int mNumLinks = 0;

    /// Sparty animation time
    double mSpartyTime = 0;

    /// Should we be popping?
    bool mPop = false;

    void DrawSpring(std::shared_ptr<wxGraphicsContext> graphics, int x, int y, double length, double width, int numLinks);

public:
    Sparty(std::wstring image, int size, int springLength, int springWidth, int numLinks);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Reset() override;
    void Advance(double delta) override;

    /**
     * Key has been dropped!
     */
    void KeyDrop() override { mPop = true; }

};

#endif //SNOWBLOWER_CPP_MACHINELIB_SPARTY_H
