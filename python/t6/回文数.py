def t6(num):
    lon = 0
    temp = num
    while temp//10:
        lon+=1
        temp=temp//10
    renum=0
    temp=num
    for i in range(lon,-1,-1):
        k=temp//(10**i)
        temp-=k*(10**(i))
        renum+=k*(10**(lon-i))
    if renum!=num:
        return False
    else:
        return True