/**
 * @file IKeyDrop.h
 * @author Charles Owen
 *
 * Interface for indicating the key has dropped
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_IKEYDROP_H
#define CANADIANEXPERIENCE_MACHINELIB_IKEYDROP_H

/**
 * Interface for indicating the key has dropped
 */
class IKeyDrop
{
public:
    /**
     * Key has been dropped!
     */
    virtual void KeyDrop() = 0;
};

#endif //CANADIANEXPERIENCE_MACHINELIB_IKEYDROP_H
