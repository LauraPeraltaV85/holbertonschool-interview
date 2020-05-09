#!/usr/bin/python3
"""
Method that calculates the fewest number of operations needed to result in exactly n H characters in the file
"""


def minOperations(n):
    """This method returns the number of operations to copy paste"""
    if n < 1:
        return 0
    char = 1
    copy = 0
    pasted = 1
    paste = 0
    pre = 1
    notcopy1 = 0
    notcopy3 = 0
    while char < n:
        if n % (char * 2) == 0:
            if notcopy1 == 1:
                notcopy1 = 0
            notcopy3 = 0
            copy += 1
            pre = char
            paste += 1
            char = 2 * char
            pasted += (2 * pre) - pasted
        elif n % char == 0 and char != 1:
            if n % pasted == 0:
                pre = pasted
                notcopy1 = 0
                char = pasted
            else:
                pre = char
            notcopy3 = 0
            if notcopy1 == 0:
                notcopy1 = 1
                copy += 1
            paste += 1
            pasted += pre
        else:
            notcopy1 = 0
            if notcopy3 == 0:
                notcopy3 = 1
                copy += 1
                pre = char
            char = char + pre
            paste += 1
            pasted += pre
        if pasted >= n:
            break
    return copy + paste
