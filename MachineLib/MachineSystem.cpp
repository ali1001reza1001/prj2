/**
 * @file MachineSystem.cpp
 *
 * @author Anik Momtaz
 * @author Charles B. Owen
 */

#include "pch.h"
#include "MachineSystem.h"
#include "MachinesFactory.h"
#include "Machine.h"

/**
 * Constructor
 * @param resourcesDir Directory containing the resources
 */
MachineSystem::MachineSystem(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
    ChooseMachine(1);
}

/**
 * Set the machine number
 * @param machine New machine number
 */
void MachineSystem::ChooseMachine(int machine)
{
    MachinesFactory factory(mResourcesDir);
    mMachine = factory.Create(machine);
    //mMachine->Reset();
    mMachineNumber = machine;
}

/**
 * Get the current machine number
 * @return IMachineSystem number
 */
int MachineSystem::GetMachineNumber()
{
    return mMachineNumber;
}

/**
 * Set the machine location
 * @param location Location of the machine
 */
void MachineSystem::SetLocation(wxPoint location)
{
    mLocation = location;
}


/**
* Set the current machine animation frame
* @param frame Frame number
*/
void MachineSystem::SetMachineFrame(int frame)
{
    if (frame < mFrame)
    {
        mFrame = 0;
        Reset();
        mMachine->SetMute(true);
    }

    while (mFrame < frame) {
        mFrame++;
        mTime = mFrame / mFrameRate;
        mMachine->Advance(1.0 / mFrameRate);
        mMachine->SetTime(mTime);
    }

    mMachine->SetMute(false);
}

/**
 * Set the frame rate
 * @param rate Frame rate in frames per second
 */
void MachineSystem::SetFrameRate(double rate)
{
    mFrameRate = rate;
}


/**
 * Reset the machine to time zero
 */
void MachineSystem::Reset()
{
    mFrame = 0;
    mTime = 0;
    mMachine->Reset();
}


/**
 * Get the current machine time.
 * @return Machine time in seconds
 */
double MachineSystem::GetMachineTime()
{
    return mTime;
}

/**
 * Set the machine flag
 * @param flag Flag to set
 */
void MachineSystem::SetFlag(int flag)
{
    mMachine->SetFlag(flag);
}



/**
* Draw the machine at the currently specified location
* \param graphics Graphics object to draw on
*/
void MachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    // This will put the machine where it is supposed to be drawn
    graphics->PushState();
    graphics->Translate(mLocation.x, mLocation.y);

    mMachine->Draw(graphics);

    graphics->PopState();
}
