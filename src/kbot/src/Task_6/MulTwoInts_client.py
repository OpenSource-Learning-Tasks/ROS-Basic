#!/usr/bin/env python

import sys
import rospy
from kbot.srv import MulTwoInts
from kbot.srv import MulTwoIntsRequest
from kbot.srv import MulTwoIntsResponse

def mul_two_ints_client(x, y):
    rospy.wait_for_service('mul_two_ints')
    try:
        mul_two_ints = rospy.ServiceProxy('mul_two_ints', MulTwoInts)
        resp1 = mul_two_ints(x, y)
        return resp1.mul
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

def usage():
    return "%s [x y]"%sys.argv[0]

if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        print usage()
        sys.exit(1)
    print "Requesting %s*%s"%(x, y)
    s = mul_two_ints_client(x, y)
    print "%s * %s = %s"%(x, y, s)
