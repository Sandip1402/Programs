### text to speeck
import pyttsx3
engine=pyttsx3.init()
engine.say("hello, Motherfucker!")
engine.runAndWait()

# import os
# print(os.listdir()) 


# # multiline print
# print('''Twinkle, twinkle, little star,
# How I wonder what you are!
# Up above the world so high,
# Like a diamond in the sky.
# Twinkle, twinkle, little star,
# How I wonder what you are!''')

# b=int(input("enter another number :"))
# a=int(input("enter a number :"))
# print(a+b)
# b="sandip"


### String Operations
# mystr="check if  this contain  double  space"
# print(mystr.find("  "))
# print(mystr.count("  "))
# print(mystr.replace("  "," "))


### List Operations
# list=["sandip",23,"end"]
# # list.insert(1,"apple")
# print(list.pop(2))
# # list.remove(23)
# # list.append(514)
# print(list)

# b=5**2
# b=5/2
# b=5//2
# print(b)

# str='''hello cousin"'''
# print(str.startswith('cousin"'))
# print(str.endswith('cousin"'))

# # # for and while loop
# list=[4,5,8.9,10]
# print(list[5])
# print(list[0:6:3])
# i=1
# print(type(i))
# while i<6:
#     print(i)
#     i+=1
#     if(i==4):
#         break
# else:
#     print("while loop ended")
# for x in range(8):
#     print(x)
#     if(x==6):
#         break
# else:
#     print("for loop ended
# for i in range(5):
#     print(i)
#     if(i == 4):
#         break
# else:
#     print("we reached 5")
# for x in [0,384,28]:
#     pass
#     print(x)



### ternary operator
# c = 8
# b = 8
# a = 8
# print("a is greater") if a>b and a>c else print("b is greater") if b>c and b>a else print("c is greater")

### Object
# student = {"name":"sikander", "course": "CSE"}
# print(student)
# student["course"] = "IT"
# print(student)
# student["marks"] = 45
# print(student)

### Memory View
# x = memoryview(bytes(5))
# print(x)


### File Operations
# f = open("abc.txt",'r')
# for x in f:
#     print(x)

# from collections import Counter
# f = open("abc.txt",'r')
# # f.write("Hello, Sandip")
# d=f.read().split()
# f.close()
# print(d)
# print(Counter(d))