my_tuple=(3,4,5,9,8,4)
print(my_tuple[0:4])
print(my_tuple+my_tuple)
print(my_tuple.count(4))
print(my_tuple.index(8))
print(my_tuple*2)
print(sorted(my_tuple))
del my_tuple
my_tuple=("sikander","sarath","jatin","ram")
for ch in my_tuple:
    print("hello",ch)
mystr="check if  this contain  double  space"
mytuple=tuple(mystr)
print(mytuple)
print(max(my_tuple))
print(min(my_tuple))
tuple=()
# all returns true if all elements are true or tuple is empty
# any returns true if any element is true and returns false if tuple is empty
print(all(tuple)) 
print(any(tuple))
a=enumerate(my_tuple)
print(0x000001F6EABE28E0)