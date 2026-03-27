# dict = {} # initializes a dictionary, not a set, it is mutable
# print(type(dict))
dict={"go":6, 2:"ok", 3:True, 4:9.2, "_tuple":(8,2), "_set":{3,5}}
### to get values from dictionary
# print(dict["go"]) #1 returns keyerror if key doesn't exist
# print(dict.get("go")) #2 returns none if key doesn't exist
# print(dict)
# print("-------------")
### adding new key or update key
# # if key is present already then value is updated or new key is added
# dict.update({6:"happy birthday"}) 
# dict[3]=5
# print(dict)
### deleting elements -- pop, clear, del, popitem
# print(dict)
# a = dict.pop(3) # removes a key and returns it value
# print(a)
# print(dict)
# print("-------------")
# dict.popitem() #removes random element
# print(dict)
# print("-------------")
# del dict[2] #can delete values using key or delete entire dict
# d = {1:4, 2:5, 3:8}
# del d # deletes entire dict
# #print("d = ", d) # throws error
# print("-------------")
# dict.clear() #removes all key,value pair
# print(dict)
### dictionary membership test
# # membership is tested for keys only, not for values
# # prints true of false
# print(dict)
# print("2 in dict :", 2 in dict)
# print("5 in dict :", 5 in dict)
# print("5 not in dict :", 5 not in dict)
### iteration in dictionary
# print(dict)
# for item in dict: # iterates through keys
#     temp = dict[item] # gets the value
#     print(item,":",temp)
# # for keys only
# print("-------------")
# for a in dict:
#     print(a)
# print("another way :")
# for a in dict.keys():
#     print(a)
# a = dict.keys()
# print(type(a)) # type is <class dict_keys>
# print("-------------")
# for a,b in dict.items():
#     print("key :",a)
#     print("value :",b) # b returns value
# ## Q1 : frequency count using dict
# data = "PYTHON DICTIONARY IS AMAZING"
# freq = {}
# for c in data:
#     freq[c]=freq.get(c,0)+1
# print(freq)
# ## Q2 : find max and min, key and values
# j = {'a':10, 'b':8, 'c':9, 'd': 10}
# maxm = max(j,key=j.get)
# minm = min(j,key=j.get)
# print("maxm value in dict :", maxm)
# print("maxm value is :", max(j.values()))
# print("min malue in dict :",minm)
# print("minm value is :", min(j.values()))
# j = {1:10, 2:8, 3:9, 4:10}
### dictionary functions
j = {'a':10, 'd':8, 'c':9, 'b': 10}
print(len(j)) # returns no of keys in dictionary
a = sorted(j) # returns sorted list
print(a)
print(type(a))