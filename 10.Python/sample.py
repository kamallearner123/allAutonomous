'''
If, else, elif
'''

# 0 -200000 -notax   if
# 200001 - 500000 - 30%
# > 500001 - 40%

sal = input("Enter your salary ")
sal = int(sal)
if sal <= 200000:
  print("No tax")
  print("Haapy.. :)")
elif 200001 <= sal <= 500000:
  tax = sal*0.3
  print("tax to be paid = ", tax)
else:
  tax = sal*0.4
  print("tax to be paid = ", tax)
  
print("End....of the program")

