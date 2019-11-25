from tkinter import *
from tkinter.filedialog import *
from tkinter.messagebox import *

filename=None

def newFile():
    global filename
    filename= "未命名"
    text.delete(0.0, END) #0.0表示行号和列号

def saveAs():
    f=asksaveasfile(defaultextension='.txt')
    t=text.get(0.0,END)
    try:
        f.write(t.rstrip())
    except:
        showerror(title="糟糕！",message="保存文件失败！")

def openFile():
    global filename
    f=askopenfile(mode='r')
    t=f.read()
    text.delete(0.0,END)
    text.insert(0.0,t)

root=Tk()
root.title("简单编辑器")
root.minsize(width=400,height=400)
root.maxsize(width=400,height=400)

text=Text(root,width=400,height=400)
text.pack()

menubar=Menu(root)
menubar.add_command(label="新建",command=newFile)
menubar.add_command(label="打开",command=openFile)
menubar.add_command(label="保存",command=saveAs)
menubar.add_separator()
menubar.add_command(label="退出",command=root.quit)
root.config(menu=menubar)
root.mainloop()