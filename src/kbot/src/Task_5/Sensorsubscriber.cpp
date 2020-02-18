#include "ros/ros.h"
#include "std_msgs/String.h"
#include "kbot/Sensor.h"
void PublishMsg_callback(const kbot::Sensor& msg)
{
  std::cout<<"acquired Sensor id : "<<(int)msg.id<<"-- acquired Sensor name : "<<msg.name<<"-- acquired temperature : "<<(float)msg.temperature<<"-- acquired Sensor humdidity : "<<(float)msg.humidity<<std::endl;
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "Sensorsubmsg");
  ros::NodeHandle n;
  ros::Subscriber sensor_sub = n.subscribe("Sensorpubmsg", 1000, PublishMsg_callback);
  ros::spin();
  return 0;
}
