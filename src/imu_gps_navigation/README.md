Prerequisite  
--------
- Eigen3:  
```apt-get install libeigen3-dev```  
- YAML-cpp:  
```apt-get install libyaml-cpp-dev```

<br/>

Build and Run
--------
- Build package:  
    ```
    $ cd ros2_ws
    $ colcon build --symlink-install  
    ```
- To run EKF node 
    ```
    $ source /opt/ros/galactic/setup.bash  
    $ source install/setup.bash
    $ ros2 run imu_gps_navigation ekf
    ```
    (EKF settings => src/imu_gps_navigation/config.yaml)    

- To run example code  
    ```
    $ cd src/imu_gps_navigation/example  
    $ ./test_ekf  
    $ python3 output_graph.py  
    ```

<br/>

Test topic publish
-------
```
$ ros2 run imu_gps_navigation ekf  
```
```
$ ros2 topic pub Imu navigation_interfaces/msg/Imu "{timestamp: {sec: 10, nanosec: 0}, acceleration: {x: 2.0, y: 1.0, z: 1.0}, angular_velocity: {x: 0.0, y: 0.0, z: 0.1}}"  
```
```
$ ros2 topic pub Gps navigation_interfaces/msg/Gps "{timestamp: {sec: 1659259370, nanosec: 0}, position: {x: 2.0, y: 1.0, z: 1.0}, velocity: {x: 0.0, y: 0.0, z: 0.1}}"  
```
```
$ ros2 topic pub nav_topic navigation_interfaces/msg/NavState "{timestamp: {sec: 10, nanosec: 0}, origin: {x: 0, y: 0, z: 0}, position: {x: 10, y: 10, z: 10}, velocity: {x: 1, y: 0, z: 0}, quaternion: {w: 1, x: 0, y: 0, z: 0}, acceleration: {x: 0, y: 0, z: 0}, angular_velocity: {x: 0, y: 0, z: 0.3}}"
```

