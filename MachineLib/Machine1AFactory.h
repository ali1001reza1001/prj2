/**
 * @file Machine1AFactory.h
 *
 * @author Anik Momtaz
 * @author Charles Owen
 *
 * Factory for creating Machine #1
 */

#ifndef CANADIANEXPERIENCE_MACHINE1AFACTORY_H
#define CANADIANEXPERIENCE_MACHINE1AFACTORY_H

#include <memory>
#include <string>

class Machine;
class Shape;

/**
 * Factory for creating Machine #1
 */
class Machine1AFactory {
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// Path to the images directory
    std::wstring mImagesDir;

public:
    Machine1AFactory(std::wstring resourcesDir);

    std::shared_ptr<Machine> Create();
};

#endif //CANADIANEXPERIENCE_MACHINE1AFACTORY_H
