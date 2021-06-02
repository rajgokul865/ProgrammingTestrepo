while(1):
    num=int(input("enter the number"))
    if num==0:
        print("0 factorial is 1\n")
    elif num>0:
        fact =1
        for x in range(num,0,-1):
            fact = fact*x
        print(num,"factorial is",fact)
    else:
        print("invalid number\n")
    ch=input("Do you want to continue:(y/n)")
    #print(ch)
    if ch=="y" or ch=="Y":
        continue
    else:
        break




