number = int(input("Enter the number you want to check:"))
count = 0
#print(type(count))

for i in range(1,number+1):
    #print(i)
    if number%i == 0:
        count+=1
if count == 2:
    print("entered number is",number,"and it is prime\n")
else:
    print("entered number is",number,"and it is not prime\n")



