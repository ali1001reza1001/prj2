/**
 * @file Cam.h
 * @author Charles Owen
 *
 * A cam and pin that detects when to open the box
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_CAM_H
#define CANADIANEXPERIENCE_MACHINELIB_CAM_H

#include "Component.h"
#include "IRotationSink.h"
#include "Polygon.h"
#include "IKeyDrop.h"


/**
 * A cam and pin that detects when to open the box
 */
class Cam : public Component, public IRotationSink
{
private:
    /// The pulley rotation
    double mRotation = 0;

    /// The angle to the hole relative to top dead center rotation=0
    double mHoleAngle = 0.25;

    /// The key
    cse335::Polygon mKey;

    /// The last drop status
    bool mLastDrop = false;

    /// Connected components that we will tell the key dropped for
    std::vector<std::shared_ptr<IKeyDrop>> mKeyDrops;

public:
    Cam(std::wstring imagesDir);
    void SetRotation(double rotation) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Set the hole angle
     * @param angle Angle to set
     */
    void SetHoleAngle(double angle) {mHoleAngle = angle;}

    /**
     * Add a key drop target
     * @param drop Target
     */
    void AddKeyDrop(std::shared_ptr<IKeyDrop> drop) {mKeyDrops.push_back(drop);}
};

#endif //CANADIANEXPERIENCE_MACHINELIB_CAM_H
