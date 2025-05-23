# Install script for directory: /home/xiaofanglinux/ROS1_Example/rosdemo_simulation/src/arbotix_ros-noetic-devel/arbotix_controllers

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/build/arbotix_ros-noetic-devel/arbotix_controllers/catkin_generated/installspace/arbotix_controllers.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/arbotix_controllers/cmake" TYPE FILE FILES
    "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/build/arbotix_ros-noetic-devel/arbotix_controllers/catkin_generated/installspace/arbotix_controllersConfig.cmake"
    "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/build/arbotix_ros-noetic-devel/arbotix_controllers/catkin_generated/installspace/arbotix_controllersConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/arbotix_controllers" TYPE FILE FILES "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/src/arbotix_ros-noetic-devel/arbotix_controllers/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/arbotix_controllers" TYPE PROGRAM FILES
    "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/src/arbotix_ros-noetic-devel/arbotix_controllers/bin/gripper_controller"
    "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/src/arbotix_ros-noetic-devel/arbotix_controllers/bin/one_side_gripper_controller.py"
    "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/src/arbotix_ros-noetic-devel/arbotix_controllers/bin/parallel_gripper_controller.py"
    "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/src/arbotix_ros-noetic-devel/arbotix_controllers/bin/parallel_single_servo_controller.py"
    )
endif()

