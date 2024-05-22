# camera1-4

Mat객체를 bgr8로 인코딩한 CVimage객체로 변환하고 압축해 토픽으로 전송할수 있는 인터페이스인 sensor_msgs::msg::CompressedImageMessage로 변환하여 publish 하는 pub 클래스와

압축된 이미지를 subscribe해서 다시 Mat 객체로 바꾸어 영상을 출력하는 sub 클래스를 

pub.hpp, pub.cpp, pmain.cpp
sub.hpp, sub.cpp, smain.cpp

로 분할해 작성했다.
