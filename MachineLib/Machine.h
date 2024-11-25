/**
 * @file Machine.h
 *
 * @author Anik Momtaz
 * @author Charles Owen
 */

#pragma once

#include <vector>
#include <memory>

class Component;
class IMutable;


/**
 * This is the root object for a working machine as allocated by 
 * the Machines factory.
 */
class Machine
{
private:
    /// The flag set by the system, can include bits
    /// that we use to turn on diagnostic features
    int mFlag = 1;

    /// The components that make up the machine
    std::vector<std::shared_ptr<Component>> mComponents;

    /// Components subject to muting
    std::vector<std::shared_ptr<IMutable>> mMutables;

public:
    /**
     * Constructor
     */
    Machine() {}

    /// Copy constructor (disabled)
    Machine(const Machine &) = delete;

    /// Assignment operator
    void operator=(const Machine &) = delete;

    void Reset();

    void AddComponent(std::shared_ptr<Component> component);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void SetTime(double time);

    void Advance(double delta);

    /**
     * Set the flag as transmitted from the control panel
     * @param flag
     */
    void SetFlag(int flag) {mFlag = flag;}

    /**
     * Add a mutable object
     * @param canMute This is an object that can be mutable.
     */
    void AddMutable(std::shared_ptr<IMutable> canMute) {mMutables.push_back(canMute);}
    void SetMute(bool mute);
};

