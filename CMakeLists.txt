cmake_minimum_required(VERSION 3.16)
project(PhotoFilter LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS Core)
find_package(Qt5 COMPONENTS Gui)
find_package(Qt5 COMPONENTS Widgets)

find_package(OpenCV REQUIRED)

add_executable(PhotoFilter
    CamWidget.cpp CamWidget.h
    MainWindow.cpp MainWindow.h
    main.cpp
)
set_target_properties(PhotoFilter PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(PhotoFilter PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
    opencv_core
    opencv_objdetect
    opencv_video
    opencv_videoio
    opencv_highgui
)