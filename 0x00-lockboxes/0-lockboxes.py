#!/usr/bin/python3

def canUnlockAll(boxes):
    key = 0
    keychain = [0]
    if len(boxes) is 0:
        return
    for key in keychain:
        for key in boxes[key]:
            if key in keychain:
                continue
            else:
                if key <= len(boxes) - 1:
                    keychain.append(key)
                else:
                    continue
    if len(boxes) is len(keychain) or len(boxes) is 0:
        return True
    else:
        return False
