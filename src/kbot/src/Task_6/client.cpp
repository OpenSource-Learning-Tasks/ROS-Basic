#include "ros/ros.h"
#include "kbot/MulTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "mul_two_ints_client");
  if (argc != 3)
  {
    ROS_INFO("usage: mul_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<kbot::MulTwoInts>("mul_two_ints");
  kbot::MulTwoInts srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Mul: %ld", (long int)srv.response.mul);
  }
  else
  {
    ROS_ERROR("Failed to call service mul_two_ints");
    return 1;
  }

  return 0;
}
