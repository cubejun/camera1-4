#include "camera1-4/sub.hpp"
void Sub::mysub_callback(const sensor_msgs::msg::CompressedImage::SharedPtr msg) const
{
    cv::Mat frame = cv::imdecode(cv::Mat(msg->data), cv::IMREAD_COLOR);
    cv::imshow("wsl",frame);
    cv::waitKey(1);
    RCLCPP_INFO(this->get_logger(), "Received Image : %s,%d,%d", msg->format.c_str(),frame.rows,frame.cols);
}
Sub::Sub() : Node("camsub_wsl")
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)).best_effort();
    sub_ = this->create_subscription<sensor_msgs::msg::CompressedImage>("image/compressed", qos_profile, std::bind(&Sub::mysub_callback, this, _1));
}
  
