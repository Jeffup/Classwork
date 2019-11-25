
def t3(limit):
    queue=[]
    result=[]
    base=1
    while base<=limit:
        queue.append(base**2)
        base+=1
        while queue[-1]-queue[0]>=168:
            if queue[-1] - queue[0] == 168:
                result.append(queue[0]-100)
            queue.pop(0)
    return result
print(t3(10000))
