# IMU-GPS EKF

Prerequisite  
--------
- Eigen3:  
```apt-get install libeigen3-dev```  
- YAML-cpp:  
```apt-get install libyaml-cpp-dev```

<br/>

Build and Run
--------
- Docker Container (If needed)  
    To build a docker image (Ubuntu 20.04 + ROS2 galactic),   
    ```
    $ docker-compose build  
    ```
    To run the container
    ```
    $ docker-compose up   
    ```
    ```  
    $ xhost +local:docker
    $ ./bash.sh             
    ```
- Build package:  
    ```
    $ cd [ros2_ws]
    $ colcon build --symlink-install  
    ```
- To run EKF node 
    ```
    $ source /opt/ros/galactic/setup.bash  
    $ source [ros2_ws]/install/setup.bash
    $ ros2 run imu_gps_navigation ekf
    ```
    (EKF settings => src/imu_gps_navigation/config.yaml)  

Example
-------
- rosbag example
    ```
    // Terminal 1 (run ekf)
    $ ros2 run imu_gps_navigation ekf
    
    // Terminal 2 (record topic)
    $ ros2 topic echo /nav_topic navigation_interfaces/msg/NavState --csv --qos-history keep_all --qos-reliability reliable > navtest_output.csv
    
    // Terminal 3 (play ros2 bag file)
    $ ros2 bag play [bag_file_name]  
    ```

- C++ example 
    ```
    $ cd src/imu_gps_navigation/example  
    $ ./test_ekf  
    $ python3 output_graph.py   
    ```
