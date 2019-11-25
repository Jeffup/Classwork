def t4(str):
    dict={}
    for i in range(len(str)):
        key=str[i]
        if key in dict:
            dict[key]=dict[key]+1
        else:
            #字典中的添加：直接赋值即可
            dict[key]=1
    return dict