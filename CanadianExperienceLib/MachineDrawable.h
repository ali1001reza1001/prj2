/**
 * @file MachineDrawable.h
 *
 * @author Charles Owen
 * @author Anik Momtaz
 *
 * Adapter class the implements Harold's Infernal Machine
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H

#include "Drawable.h"

class IMachineSystem;

/**
* Adapter class the implements Harold's Infernal Machine
*/
class MachineDrawable : public Drawable
{
private:
    std::shared_ptr<IMachineSystem> mMachineSystem; ///< The adaptee class

    /// The timeline object
    Timeline *mTimeline;

    /// Machine starting frame
    int mStart = 0;

public:
    MachineDrawable(const std::wstring &name, const std::wstring resourcesDir);

    /** Default constructor disabled */
    MachineDrawable() = delete;
    /** Copy constructor disabled */
    MachineDrawable(const MachineDrawable &) = delete;
    /** Assignment operator disabled */
    void operator=(const MachineDrawable &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override;
    void SetTimeline(Timeline *timeline) override;

    int GetMachineNumber();
    void ChooseMachine(int s);

    int DoMachineDialog(wxWindow* parent);

    /**
     * Get the machine start frame
     * @return Starting frame
     */
    int GetStart() { return mStart; }

    /**
     * Set the machine starting frame
     * @param start Starting frame
     */
    void SetStart(int start) { mStart = start;}
};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLE_H
