#!/usr/bin/env python

from kbot.srv import MulTwoInts
from kbot.srv import MulTwoIntsRequest
from kbot.srv import MulTwoIntsResponse

import rospy

def handle_mul_two_ints(req):
    print "Returning [%s * %s = %s]"%(req.a, req.b, (req.a * req.b))
    return MulTwoIntsResponse(req.a * req.b)

def mul_two_ints_server():
    rospy.init_node('mul_two_ints_server')
    s = rospy.Service('mul_two_ints', MulTwoInts, handle_mul_two_ints)
    print "Ready to multiply 2 numbers"
    rospy.spin()
    
if __name__ == "__main__":
    mul_two_ints_server()
