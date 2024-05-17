#ifndef _SUB_HPP_
#define _SUB_HPP_
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/compressed_image.hpp"
#include "opencv2/opencv.hpp"
#include <memory>
#include <functional>
#include <iostream>
using std::placeholders::_1;
class Sub : public rclcpp::Node
{
    private:
        rclcpp::Subscription<sensor_msgs::msg::CompressedImage>::SharedPtr sub_;
        void mysub_callback(const sensor_msgs::msg::CompressedImage::SharedPtr msg) const;
        std::function<void(const sensor_msgs::msg::CompressedImage::SharedPtr msg)> fn;
    public:
        Sub();
};
#endif //_SUB_HPP_
