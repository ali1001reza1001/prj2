/**
 * @file PictureFactory.h
 * @author Charles Owen
 *
 * A factory class that builds our picture.
 */

#ifndef CANADIANEXPERIENCE_PICTUREFACTORY_H
#define CANADIANEXPERIENCE_PICTUREFACTORY_H

class Picture;
class MachineDrawable;

/**
 * A factory class that builds our picture.
 */
class PictureFactory {
private:
    /// Pointer to the first machine
    std::shared_ptr<MachineDrawable> mMachine1;

    /// Pointer to the second machine
    std::shared_ptr<MachineDrawable> mMachine2;

public:
    std::shared_ptr<Picture> Create(std::wstring resourcesDir);

    /**
     * Get the first machine
     * @return Pointer to machine 1
     */
    std::shared_ptr<MachineDrawable> GetMachine1() { return mMachine1; }

    /**
     * Get a pointer to the second machine
     * @return
     */
    std::shared_ptr<MachineDrawable> GetMachine2() { return mMachine2; }
};

#endif //CANADIANEXPERIENCE_PICTUREFACTORY_H
