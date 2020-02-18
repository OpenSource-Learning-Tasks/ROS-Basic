#include "ros/ros.h" 
#include "turtlesim/Pose.h"

//pose_callback
void pose_callback(const turtlesim::Pose& msgIn){

ROS_INFO_STREAM(std::setprecision(2) << std::fixed
<< "position=(" << msgIn.x << "," << msgIn.y << ")"
<< "direction=" << msgIn.theta); 
  
}

int main(int argc, char **argv)
{
    // Initiate a new ROS node named "subTsim"
 ros::init(argc, argv, "subTsim");
 //create a node handle: it is reference assigned to a new node
 ros::NodeHandle node;
    ros::Subscriber subscriber_pose=node.subscribe("turtle1/pose", 1000, pose_callback);
    // Enter a loop, pumping callbacks
    ros::spin();

    return 0;
}

