#!/usr/bin/env python
import rospy
from kbot.msg import Sensor

def sensor_callback(sensor_message):
    rospy.loginfo("new data received: (%d, %s, %.2f ,%.2f)", 
        sensor_message.id,sensor_message.name,
        sensor_message.temperature,sensor_message.humidity)
    
rospy.init_node('sensor_subscriber_node', anonymous=True)

rospy.Subscriber("sensor_topic", Sensor, sensor_callback)

# spin() simply keeps python from exiting until this node is stopped
rospy.spin()
