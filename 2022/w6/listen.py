

while True:
    words = input("Sey samthing...").lower()
    if "hello" in words:
        print("Hello!")
    elif "haw are you" in words:
        print("i'm good, are you?")
    elif "goodbye" in words:
        print("Goodbye!")
    elif "fuck" in words:
        print("Fuck you!")
        break
    else:
        print("Huh?")