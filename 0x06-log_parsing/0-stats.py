#!/usr/bin/python3
""" this calculates the file size and
number of status codes in a log list
"""

import sys

if __name__ == "__main__":
    a = 1
    statusn = [0, 0, 0, 0, 0, 0, 0, 0]
    size = 0
    statuses = ["200", "301", "400", "401", "403", "404", "405", "500"]

    def print_log(statusn, statuses):
        """Method to print file size and status"""
        print("File size: {}".format(size))
        for i in range(len(statusn)):
            if statusn[i] > 0:
                print("{}: {}".format(statuses[i], statusn[i]))

    try: 
        for line in sys.stdin:
            each_argvs = line.split(" ")
            if len(each_argvs) == 9:
                status = each_argvs[-2]
                if status in statuses:
                    i = statuses.index(status)
                    statusn[i] = statusn[i] + 1
                    size = size + int(each_argvs[-1][:-1])
                    if a % 10 == 0:
                        print_log(statusn, statuses)
            a = a + 1
    except KeyboardInterrupt:
        print_log(statusn, statuses)
        raise
    #print_log(statusn, statuses)
