#!/usr/bin/env python3
# Requires PyAudio and PySpeech.

from practicum import find_mcu_boards
from peri import McuWithPeriBoard
from time import sleep

import speech_recognition as sr
r = sr.Recognizer()
order = "hello"

import pyautogui, sys , time
center_x=int(pyautogui.size()[0]/2)
center_y=int(pyautogui.size()[1]/2)
pyautogui.moveTo(center_x,center_y)

devs = find_mcu_boards()

if len(devs) == 0:
	print("*** No practicum board found.")
	exit(1)

b = McuWithPeriBoard(devs[0])
print("*** Practicum board found")
print("*** Manufacturer: %s" % \
	b.handle.getString(b.device.iManufacturer, 256))
print("*** Product: %s" % \
	b.handle.getString(b.device.iProduct, 256))

def Listen():
	with sr.Microphone() as source:
		print("######### Say something! #########")
		b.setLedValue(7)
		audio = r.listen(source,phrase_time_limit=3)
		b.setLedValue(0)
	return audio

while(not order == "close" ):
		
	# Speech recognition using Google Speech Recognition
	try:
	    # for testing purposes, we're just using the default API key
	    # to use another API key, use `r.recognize_google(audio, key="GOOGLE_SPEECH_RECOGNITION_API_KEY")`
	    # instead of `r.recognize_google(audio)
		order = r.recognize_google(Listen()).lower()
		print("You said: " + order)
		
		if(order=="right" or order=="red"):
			pyautogui.click(button='right')
		elif(order=="left"):
			pyautogui.click(button='left')
		elif(order=="double"):
			pyautogui.click(button='left',clicks=2)
		elif(order=="go up"):
			pyautogui.vscroll(30)
		elif(order=="center"):
			pyautogui.moveTo(center_x,center_y)
		elif(order=="go down"):
			pyautogui.vscroll(-30)
		elif(order=="hold"):
			pyautogui.mouseDown(button='left')			
			#stop_draging="running"
			print("############ Say ""left"" to stop draging ! #############")

	except sr.UnknownValueError:
		print("Google Speech Recognition could not understand audio")
	except sr.RequestError as e:
		print("Could not request results from Google Speech Recognition service; {0}".format(e))
