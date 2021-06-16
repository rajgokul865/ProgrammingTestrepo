class NumFunctions:
    def factorial(self,num):
        if num==0:
            print("0 factorial is 1\n")
        elif num>0:
            fact =1
            for x in range(num,0,-1):
                fact = fact*x
            print(num,"factorial is",fact)
        else:
            print("invalid number\n")        




while(1):
    number=int(input("enter the number"))
    factobj = NumFunctions()
    factobj.factorial(number)
    ch=input("Do you want to continue:(y/n)")
    #print(ch)
    if ch=="y" or ch=="Y":
        continue
    else:
        break

