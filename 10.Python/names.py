'''
List: Data structure
'''
list1 = []  #empty list

for i in range(3):
  name =input("Enter the name")
  list1.append(name)

print(list1)
for name in list1:
  list1.append(name.upper())

print(list1)
