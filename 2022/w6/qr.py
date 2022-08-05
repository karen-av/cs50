import os
import qrcode

img = qrcode.make("https://youtu.be/1yc1G31NaT0")
img.save("qr.png", "PNG")
os.system("open qr.png")