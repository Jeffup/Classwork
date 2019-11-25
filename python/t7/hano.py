def t7(num,a,b,c):
    '''
    把a-->c
    :param num: 第一个柱子圆盘数目
    :param a: 第一个柱子
    :param b: 第二个柱子
    :param c: 第三个柱子
    :return:
    '''
    if num==1:
        print(a,'-->',c)
    else:
        # 思想：上面一大块的放到第二个柱子，最后一块放到第三个柱子，然后把第二个柱子的盘子移到第三个柱子即可。（分治策略）
        t7(num-1,a,c,b)#a-->b
        print(a,'-->',c)
        t7(num-1,b,a,c)#b-->c