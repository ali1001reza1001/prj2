/**
 * @file PictureFactory.cpp
 *
 * @author Charles Owen
 * @author Anik Momtaz
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"


/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();

    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background2.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    //
    // Create and add machines
    //
    auto machineActor = std::make_shared<Actor>(L"Machine Actor 1");
    machineActor->SetPosition(wxPoint(400, 530));
    auto machine = std::make_shared<MachineDrawable>(L"Machine 1", resourcesDir);
    mMachine1 = machine;
    machineActor->AddDrawable(machine);
    machineActor->SetRoot(machine);
    machine->SetStart(240);

    picture->AddActor(machineActor);
    picture->SetMachine1(machine);

    // Create and add machines
    machineActor = std::make_shared<Actor>(L"Machine Actor 2");
    machineActor->SetPosition(wxPoint(1000, 480));
    machine = std::make_shared<MachineDrawable>(L"Machine 2",resourcesDir);
    machine->ChooseMachine(2);
    mMachine2 = machine;
    machineActor->AddDrawable(machine);
    machineActor->SetRoot(machine);
    machine->SetStart(5);

    picture->AddActor(machineActor);
    picture->SetMachine2(machine);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(150, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(650, 620));
    picture->AddActor(sparty);

    return picture;
}

