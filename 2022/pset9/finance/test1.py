


def checkUsername(name):
    if len(name) < 3 or len(name) > 30:
        return True

    for n in name:
        if not n.isalpha():
            return True
   
    return False
        

name = "NjoGT\m"
if checkUsername(name):
        print("Invalid Username")
else:
    print("Good Username")