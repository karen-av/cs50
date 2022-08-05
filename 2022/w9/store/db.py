#Создание базы данных

import sqlite3 


connection = sqlite3.connect('store.db')
cursor = connection.cursor()
cursor.execute('''CREATE TABLE IF NOT EXISTS books
              (id INTEGER, title TEXT NOT NULL, PRIMARY KEY (id))''')
connection.commit()
connection.close()