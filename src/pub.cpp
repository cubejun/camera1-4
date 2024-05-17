#include "camera1-4/pub.hpp"
Pub::Pub() : Node("campub")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)).best_effort();
    pub_ = this->create_publisher<sensor_msgs::msg::CompressedImage>("image/compressed", qos_profile );
    timer_ = this->create_wall_timer(25ms, std::bind(&Pub::publish_msg, this));
    cap.open(src, cv::CAP_GSTREAMER);
    if (!cap.isOpened()) {
        RCLCPP_ERROR(this->get_logger(), "Could not open video!");
        rclcpp::shutdown();
        return;
    }
}
void Pub::publish_msg()
{
    cap >> frame;
    if (frame.empty()) { RCLCPP_ERROR(this->get_logger(), "frame empty"); return;}
    msg = cv_bridge::CvImage(hdr, "bgr8", frame).toCompressedImageMsg();
    pub_->publish(*msg);
}


