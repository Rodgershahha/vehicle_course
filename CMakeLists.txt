cmake_minimum_required(VERSION 3.10.2)
project(myProject)

set(CMAKE_CXX_STANDARD 17)

# 添加可执行文件
add_executable(main
    main.cpp
    AGXKit.cpp
    AGXKit.h
    Battery.cpp
    Battery.h
    Camera.cpp
    Camera.h
    Chassis.cpp
    Chassis.h
    Display.cpp
    Display.h
    Gyroscope.cpp
    Gyroscope.h
    Lidar.cpp
    Lidar.h
    SmartCar.cpp
    SmartCar.h
    Student.cpp
    Student.h
    Tire.cpp
    Tire.h
    tool.cpp
    tool.h
    ObstacleStatus.h
)


