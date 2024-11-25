/**
 * @file Shaft.h
 * @author Charles Owen
 *
 * A shaft component
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SHAFT_H
#define CANADIANEXPERIENCE_MACHINELIB_SHAFT_H

#include "Component.h"
#include "Cylinder.h"
#include "IRotationSink.h"
#include "RotationSource.h"


/**
 * A shaft component
 */
class Shaft : public Component, public IRotationSink
{
private:
    /// The rod we use to draw the shaft
    cse335::Cylinder mCylinder;

    /// Any rotation of the shaft?
    double mRotation = 0;

    /// The rotation source for this component
    RotationSource mSource;

public:
    Shaft();

    /**
     * Set the rod color
     * @param color Color to draw the rod
     */
    void SetColour(wxColour color) {mCylinder.SetColour(color);}

    /**
     * Set the shaft size
     * @param diameter Rod diameter in pixels
     * @param length Rod length in pixels
     */
    void SetSize(int diameter, int length) {mCylinder.SetSize(diameter, length);}
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Optional offset added to the rotation of the lines on the cylinder
     * @param offset
     */
     void SetOffset(double offset) {mCylinder.SetOffset(offset);}

    void SetRotation(double rotation) override;

    /**
     * Get the rotation source
     * @return Rotation source
     */
    RotationSource* GetSource() {return &mSource;}
};

#endif //CANADIANEXPERIENCE_MACHINELIB_SHAFT_H
