import random
def t5():
    #input()函数输入的是字符串，应该转成数字
    guess=int(input('please input you number:'))
    t=random.randint(0,9)

    while guess!=t:
        if guess>t:
            print('you number %d too high'%(guess))
        else:
            print('you number %d too low'%(guess))
        guess = int(input('please input you number:'))
    print('bingo! the random number is %d'%(t))