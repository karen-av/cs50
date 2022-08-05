import speech_recognition



recognozer = speech_recognition.Recognizer()
with speech_recognition.Microphone() as sourse:
    print("Sey samthing")
    audi = recognizer.listen(sourse)
word = recognizer.recognize_google(audi)
print(word)

