from tkinter import *
import requests
import json

raw_url = 'http://localhost:3000/raw'

root = Tk()
frame1 = Frame(root)
labelCity = Label(frame1, height=1, width=6, font=("Tahoma", 24), text='Симферополь', bg='#FFCE57', fg='#383838')
labelWeather = Label(frame1, height=1, width=6, font=("Tahoma", 12), text='', bg='#FFCE57', fg="#383838")
frame2 = Frame(root)
labelTemp = Label(frame1, height=2, width=6, font=("Tahoma", 64), text='0°C', bg='#FFFFFF')
frame3 = Frame(root)
Empty = Label(frame3, height=2, width=6, font=("Tahoma", 16), text='', bg='#FFCE57')

Empty.pack(expand=YES, fill=BOTH)
labelCity.pack(expand=YES, fill=BOTH)
labelWeather.pack(expand=YES, fill=BOTH)
labelTemp.pack(expand=YES, fill=BOTH)
frame1.pack(expand=YES, fill=BOTH)
frame2.pack(expand=YES, fill=BOTH)
frame3.pack(expand=YES, fill=BOTH)

root.resizable(False, False)

def refreshWeather(event):
	global labelCity
	global labelWeather
	global labelTemp
	r = requests.get(raw_url)
	j = json.loads(r.text)
	labelWeather.config(text = j["description"]) 
	labelTemp.config(text = str(j["temp"])+'°C')

refreshWeather(0);
root.bind('<Button-1>', refreshWeather)
root.mainloop()