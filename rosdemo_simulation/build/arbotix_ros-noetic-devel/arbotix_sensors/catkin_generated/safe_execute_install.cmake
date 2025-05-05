execute_process(COMMAND "/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/build/arbotix_ros-noetic-devel/arbotix_sensors/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/xiaofanglinux/ROS1_Example/rosdemo_simulation/build/arbotix_ros-noetic-devel/arbotix_sensors/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
