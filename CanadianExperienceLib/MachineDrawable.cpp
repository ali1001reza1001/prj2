/**
 * @file MachineDrawable.cpp
 *
 * @author Charles Owen
 * @author Anik Momtaz
 */

#include "pch.h"
#include "MachineDrawable.h"
#include "Timeline.h"

#include <machine-api.h>

/**
 * Constructor
 * @param name Name of the drawable
 * @param resourcesDir The directory containing the resources
 */
MachineDrawable::MachineDrawable(const std::wstring &name, const std::wstring resourcesDir) :
    Drawable(name)
{
    MachineSystemFactory factory(resourcesDir);
    mMachineSystem = factory.CreateMachineSystem();
}

/**
 * Draw the machine
 * @param graphics Graphics device to render to
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachineSystem->SetFrameRate(mTimeline->GetFrameRate());
    int frame = mTimeline->GetCurrentFrame();
    if (frame >= mStart)
    {
        mMachineSystem->SetMachineFrame(frame - mStart);
    }
    else
    {
        mMachineSystem->SetMachineFrame(0);
    }

    double scale = 0.65f;

    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(scale, scale);
    mMachineSystem->SetLocation(wxPoint(0, 0));
    mMachineSystem->DrawMachine(graphics);
    graphics->PopState();
}

/**
 * Hit test the machine - hit testing is not supported
 * @param pos Position to test
 * @return False
 */
bool MachineDrawable::HitTest(wxPoint pos)
{

    return false;
}

/**
 * Set the timeline
 * @param timeline Timeline object
 */
void MachineDrawable::SetTimeline(Timeline *timeline)
{
    Drawable::SetTimeline(timeline);

    mTimeline = timeline;
}

/**
 * Use the machine dialog box to choose a machine number
 * @param parent Parent window for the dialog box
 * @return Dialog result
 */
int MachineDrawable::DoMachineDialog(wxWindow* parent)
{
    MachineDialog dlg(parent, mMachineSystem);
    return dlg.ShowModal();
}

/**
 * Set the machine number
 * @param machineNumber Machine number to set
 */
void MachineDrawable::ChooseMachine(int machineNumber)
{
    mMachineSystem->ChooseMachine(machineNumber);
}

/**
 * Get the machine number
 * @return Current machine number
 */
int MachineDrawable::GetMachineNumber()
{
    return mMachineSystem->GetMachineNumber();
}
