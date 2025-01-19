cmake_minimum_required(VERSION 3.19)
project(Task_1)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES main.cpp
        mainwindow.cpp
        mainwindow.h
        ./ui/mainwindow.ui
        )
add_executable(Task_1 ${PROJECT_SOURCES})
target_link_libraries(Task_1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

