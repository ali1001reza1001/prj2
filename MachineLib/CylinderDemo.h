/**
 * @file CylinderDemo.h
 * @author Charles Owen
 *
 * Demonstration of a Cylinder
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_CYLINDERDEMO_H
#define CANADIANEXPERIENCE_MACHINELIB_CYLINDERDEMO_H

#include "Component.h"
#include "Cylinder.h"

/**
 * Demonstration of a Cylinder
 */
class CylinderDemo : public Component
{
private:
    /// The current rotation
    double mRotation = 0;

    /// Speed in turns per second
    double mSpeed = 0.25;

    cse335::Cylinder mCylinder;

public:
    CylinderDemo();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Reset() override;
    void Advance(double delta) override;
};

#endif //CANADIANEXPERIENCE_MACHINELIB_CYLINDERDEMO_H
