project(MachineLib)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.14)

set(SOURCE_FILES
        pch.h
        IMachineSystem.h
        MachineSystemFactory.cpp MachineSystemFactory.h
        MachineSystem.cpp MachineSystem.h
        MachinesFactory.cpp MachinesFactory.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h
        Const.cpp
        Const.h
        MachineSystemStandin.h
        MachineSystemStandin.cpp
        MachineStandin.cpp
        MachineStandin.h
        Component.cpp
        Component.h
        Polygon.cpp
        Polygon.h
        Machine.cpp
        Machine.h
        RotationSource.cpp
        RotationSource.h
        Machine1Factory.h
        Machine1Factory.cpp
        MachineCFactory.cpp
        MachineCFactory.h
        Box.cpp
        Box.h
        Sparty.cpp
        Sparty.h
        Crank.cpp
        Crank.h
        Cylinder.cpp
        Cylinder.h
        Shaft.cpp
        Shaft.h
        IRotationSink.h
        Pulley.cpp
        Pulley.h
        Cam.cpp
        Cam.h
        IKeyDrop.h
        MusicBox.h MusicBox.cpp
        Machine2Factory.cpp
        Machine2Factory.h
        IMutable.h
        Machine1AFactory.cpp
        Machine1AFactory.h
        TrigDemo.cpp
        TrigDemo.h
        CylinderDemo.cpp
        CylinderDemo.h
)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
