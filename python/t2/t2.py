def t2(profit):
    price = 0
    rate = {1: 0.1, 2: 0.075, 3: 0.05, 4: 0.03, 5: 0.015, 6: 0.1}
    base = {1: 10000, 2: 10000, 3: 20000, 4: 20000, 5: 400000}
    case=1
    while profit-base[case]>=0:
        profit -= base[case]
        price += base[case] * rate[case]
        if case==5:
            case += 1
            break
        case+=1
    price+=profit*rate[case]
    return price