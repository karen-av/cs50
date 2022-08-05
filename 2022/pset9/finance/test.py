
from ast import Try
from os import symlink


passw = "qdwdqwE/3"



def checkPassword(passw):
    symbols = [" ", '"' "!", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\",  "]", "^", "_", "`", "{", "|", "}", "~"]
    if passw or len(passw) > 6 or len(passw) < 30:
        for s in symbols:
            if s in passw:
                for p in passw:
                    if p.isdigit():
                        for p in passw:
                            if p.isupper():
                                for p in passw:
                                    if p.islower():
                                        return False

    return True

if checkPassword(passw):
    print("Password not good")
else: 
    print("Continue")