cmake_minimum_required(VERSION 3.16)
project(PhotoFilter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)


find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Gui)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

find_package(OpenCV REQUIRED COMPONENTS opencv_core)
find_package(OpenCV REQUIRED COMPONENTS opencv_objdetect)
#find_package(OpenCV REQUIRED COMPONENTS opencv_video)
find_package(OpenCV REQUIRED COMPONENTS opencv_videoio)
#find_package(OpenCV REQUIRED COMPONENTS opencv_highgui)

add_executable(PhotoFilterApp
    CamWidget.cpp CamWidget.h
    MainWindow.cpp MainWindow.h
    main.cpp
)
set_target_properties(PhotoFilterApp PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(PhotoFilterApp PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
    opencv_core
    opencv_objdetect
    #opencv_video
    opencv_videoio
    #opencv_highgui
)