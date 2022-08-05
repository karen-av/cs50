
#загрузаем словавь в глобальную переменную
words = set()

# Создаем функцию загрузки словаря
def load(dictionary):
    #объявляем переменную и открываем файл для чтения
    file = open(dictionary, "r")
    #Читаем файл по строчно
    for line in file:
        #добавляем почитанную строку в переменную words и удаляем последний символ /0
        words.add(line.rstrip())
        # Закрываем файл
    file.close()
    return True

def check(word):
    #Провермяем есть ли слово в загруженном словаре  слово переводим в нижний регистр
    if word.lower() in words:
        return True
    else:
        return False

def size():
    #расчет размера файла
    return len(words)

def unload():
    return True