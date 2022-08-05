#import library
from PIL import Image, ImageFilter

# variable befor is like a fopen function in C
befor = Image.open("1.jpg")

#точка использутся для попадания в функцию или переменную в структере данных или библиотеке  как в си
after = befor.filter(ImageFilter.BoxBlur(20))
after.save("out.jpg")