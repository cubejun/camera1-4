#ifndef _PUB_HPP_
#define _PUB_HPP_
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/compressed_image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/opencv.hpp"
#include <memory>
#include <chrono>
using namespace std::chrono_literals;
class Pub : public rclcpp::Node
{
    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<sensor_msgs::msg::CompressedImage>::SharedPtr pub_;
        void publish_msg();
        std::string src = "nvarguscamerasrc sensor-id=0 ! \
	        video/x-raw(memory:NVMM), width=(int)640, height=(int)360, \
            format=(string)NV12 ! nvvidconv flip-method=0 ! video/x-raw, \
            width=(int)640, height=(int)360, format=(string)BGRx ! \
	        videoconvert ! video/x-raw, format=(string)BGR ! appsink"; 
        std_msgs::msg::Header hdr;
        sensor_msgs::msg::CompressedImage::SharedPtr msg;
        cv::VideoCapture cap;
        cv::Mat frame;
    public:
        Pub();
        
};
#endif //_PUB_HPP_

