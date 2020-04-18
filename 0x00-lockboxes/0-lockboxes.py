#!/usr/bin/python3

def canUnlockAll(boxes):
    key = 0
    keychain = [0]
    for key in keychain:
        for key in boxes[key]:
            if key in keychain:
                continue
            else:
                keychain.append(key)
    if len(boxes) == len(keychain):
        return True
    else:
        return False
