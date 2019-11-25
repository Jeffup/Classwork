import tkinter
import decimal
import math


class KeyValue:

    def __init__(self, key_):
        self.key_ = key_
        self.flag = 0

    def del_(self):
        print("删除")
        if save:
            save.pop()
        else:
            pass
        var_text.set(''.join(save))

    def clear(self):
        print("清除")
        save.clear()
        var_text.set('')
    def plus_sub(self):
        print('plus_sub')
        if save[0]:
            if save[0] == '-':
                save[0] = '+'
            elif save[0] == '+':
                save[0] = '-'
            else:
                save.insert(0, '-')
        var_text.set(''.join(save))

    def calculate(self):
        global save, var_text, result, symbol
        if var_text.get() == '':
            pass
        else:
            get1 = decimal.Decimal(var_text.get())
            if self.key_ in ('1/x', 'sqrt'):
                if self.key_ == '1/x':
                    result = 1 / get1
                elif self.key_ == 'sqrt':
                    result = math.sqrt(get1)
            elif self.key_ in ('+', '-', '*', '/', '=', '%'):
                if symbol is not None:
                    get1 = decimal.Decimal(result)
                    get2 = decimal.Decimal(var_text.get())
                    if symbol == '+':
                        result = get1 + get2
                    elif symbol == '-':
                        result = get1 - get2
                    elif symbol == '*':
                        result = get1 * get2
                    elif symbol == '/':
                        result = get1 / get2
                    elif symbol == '%':
                        result = get1 % get2
                else:
                    result = get1
                if self.key_ == '=':
                    print('计算结果 = ', result)
                    symbol = None
                else:
                    symbol = self.key_
                    print('计算符号 ：',symbol)

            var_text.set(str(result))
            save.clear()

    def press(self):
        print('输入：', self.key_)
        if self.key_ == '.':
            if save.count('.') >= 1:
                pass
            else:
                if save == []:
                    save.append('0')
                else:
                    save.append(self.key_)
                    var_text.set(''.join(save))
        else:
            save.append(self.key_)
            var_text.set(''.join(save))

def window(root):
    global var_text
    entry1 = tkinter.Label(root, width=40, height=2, bg='white', anchor='se', textvariable=var_text)
    entry1.grid(row=0, columnspan=5)

    button_del = tkinter.Button(root, text='←', width=5, command=KeyValue('del_').del_)
    button_del.grid(row=2, column=0)
    button_CE = tkinter.Button(root, text='CE', width=5, command=KeyValue('ce').clear)
    button_CE.grid(row=2, column=1)
    button_C = tkinter.Button(root, text=' C ', width=5, command=KeyValue('c').clear)
    button_C.grid(row=2, column=2)
    button_P_S = tkinter.Button(root, text='±', width=5, command=KeyValue('c').plus_sub)
    button_P_S.grid(row=2, column=3)
    button_sqrt = tkinter.Button(root, text='√', width=5, command=KeyValue('sqrt').calculate)
    button_sqrt.grid(row=2, column=4)

    button_7 = tkinter.Button(root, text=' 7 ', width=5, command=KeyValue('7').press)
    button_7.grid(row=3, column=0)
    button_8 = tkinter.Button(root, text=' 8 ', width=5, command=KeyValue('8').press)
    button_8.grid(row=3, column=1)
    button_9 = tkinter.Button(root, text=' 9 ', width=5, command=KeyValue('9').press)
    button_9.grid(row=3, column=2)
    button_c = tkinter.Button(root, text=' / ', width=5, command=KeyValue('/').calculate)
    button_c.grid(row=3, column=3)
    button_f = tkinter.Button(root, text=' % ', width=5, command=KeyValue('%').calculate)
    button_f.grid(row=3, column=4)

    button_4 = tkinter.Button(root, text=' 4 ', width=5, command=KeyValue('4').press)
    button_4.grid(row=4, column=0)
    button_5 = tkinter.Button(root, text=' 5 ', width=5, command=KeyValue('5').press)
    button_5.grid(row=4, column=1)
    button_6 = tkinter.Button(root, text=' 6 ', width=5, command=KeyValue('6').press)
    button_6.grid(row=4, column=2)
    button_multi = tkinter.Button(root, text=' * ', width=5, command=KeyValue('*').calculate)
    button_fraction = tkinter.Button(root, text='1/x', width=5, command=KeyValue('1/x').calculate)
    button_multi.grid(row=4, column=3)
    button_fraction.grid(row=4, column=4)

    button_1 = tkinter.Button(root, text=' 1 ', width=5, command=KeyValue('1').press)
    button_2 = tkinter.Button(root, text=' 2 ', width=5, command=KeyValue('2').press)
    button_3 = tkinter.Button(root, text=' 3 ', width=5, command=KeyValue('3').press)
    button__ = tkinter.Button(root, text=' - ', width=5, command=KeyValue('-').calculate)
    button_equal = tkinter.Button(root, text=' \n = \n ', width=5, command=KeyValue('=').calculate)
    button_1.grid(row=5, column=0)
    button_2.grid(row=5, column=1)
    button_3.grid(row=5, column=2)
    button__.grid(row=5, column=3)
    button_equal.grid(row=5, column=4, rowspan=2)

    button_0 = tkinter.Button(root, text='     0    ', width=13, command=KeyValue('0').press)
    button_sub = tkinter.Button(root, text=' . ', width=5, command=KeyValue('.').press)
    button_plus = tkinter.Button(root, text=' + ', width=5, command=KeyValue('+').calculate)
    button_0.grid(row=6, column=0, columnspan=2)
    button_sub.grid(row=6, column=2)
    button_plus.grid(row=6, column=3)




if __name__ == '__main__':
    root = tkinter.Tk()
    root.title('计算器')
    root.resizable(0, 0)
    result = symbol = None
    var_text = tkinter.StringVar()
    save = []

    window(root)
    root.mainloop()