#ifndef EKF_ROS_WRAPPER_H
#define EKF_ROS_WRAPPER_H

#include <chrono>
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "sensor_interfaces/msg/imu.hpp"
#include "sensor_interfaces/msg/gnss.hpp"
#include "navigation_interfaces/msg/nav_state.hpp"

#include "ekf.h"

class EKFWrapper: public rclcpp::Node
{
    public:
        EKFWrapper(EKF* pEKF);
    
    private:
        rclcpp::Subscription<sensor_interfaces::msg::Imu>::SharedPtr imu_subscriber;
        rclcpp::Subscription<sensor_interfaces::msg::Gnss>::SharedPtr gps_subscriber;
        rclcpp::Publisher<navigation_interfaces::msg::NavState>::SharedPtr state_publisher;
        
        EKF* mpEKF;
        NavSol* mpSol;
        
        void ImuCallback(const sensor_interfaces::msg::Imu & msg);
        void GpsCallback(const sensor_interfaces::msg::Gnss & msg);
        void PublishNavSol();
};

#endif