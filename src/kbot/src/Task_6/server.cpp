#include "ros/ros.h"
#include "kbot/MulTwoInts.h"

bool mul(kbot::MulTwoInts::Request  &req,
         kbot::MulTwoInts::Response &res)
{
  res.mul = req.a * req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.mul);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "mul_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("mul_two_ints", mul);
  ROS_INFO("Ready to multiply two ints.");
  ros::spin();

  return 0;
}
