#!/usr/bin/python3
import random
num = random.randint(-20,20)
if(num < 0):
	print(num, "Negative Number")
elif(num > 0):
	print(num, "positive Number")
else:
	print(num, "zero")
