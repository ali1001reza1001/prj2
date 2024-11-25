/**
 * @file Box.h
 * @author Charles Owen
 *
 * The Jack in the box Box itself
 */

#ifndef JACKINBOX_CPP_MACHINELIB_BOX_H
#define JACKINBOX_CPP_MACHINELIB_BOX_H

#include "Polygon.h"
#include "Component.h"
#include "IKeyDrop.h"

/**
 * The Jack in the box Box itself
 */
class Box : public Component, public IKeyDrop
{
private:
    /// The box background image
    cse335::Polygon mBox;

    /// The box foreground image
    cse335::Polygon mForeground;

    /// The lid image
    cse335::Polygon mLid;

    /// The box size
    int mBoxSize = 0;

    /// Lid angle in radians
    double mLidAngle = 0;

    /// Should we be opening?
    bool mOpen = false;

public:
    Box(std::wstring imagesDir, int boxSize, int lidSize);
    void DrawLast(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Advance(double delta) override;
    void Reset() override;

    /**
     * Key has been dropped!
     */
    void KeyDrop() override { mOpen = true; }
};

#endif //JACKINBOX_CPP_MACHINELIB_BOX_H
