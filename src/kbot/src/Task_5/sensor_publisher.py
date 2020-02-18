#!/usr/bin/env python
# license removed for brevity
import rospy
from kbot.msg import Sensor
import random

#create a new publisher. we specify the topic name, then type of message then the queue size
pub = rospy.Publisher('sensor_topic', Sensor, queue_size=10)

#we need to initialize the node
rospy.init_node('sensor_publisher_node', anonymous=True)

#set the loop rate
rate = rospy.Rate(1) # 1hz
#keep publishing until a Ctrl-C is pressed
i = 0
while not rospy.is_shutdown():
    sensor = Sensor()
    sensor.id = 1
    sensor.name="sensor_01"
    sensor.temperature = 24.33 + (random.random()*2)
    sensor.humidity = 33.41+ (random.random()*2)
    rospy.loginfo("I publish:")
    rospy.loginfo(sensor)
    pub.publish(sensor)
    rate.sleep()
    i=i+1

