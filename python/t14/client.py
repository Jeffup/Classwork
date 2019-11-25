import socket
from tkinter import *
import threading

class wechat:
    def __init__(self,filename,myport):
        #本端数据
        self.s = socket.socket()  # 创建 socket 对象
        self.host = socket.gethostname()  # 获取本地主机名
        self.hostip = socket.gethostbyname(self.host)# 获取本机IP
        self.hostport = myport  # 设置连接端口
        self.s.connect((self.host, self.hostport))

        #连接成功
        print('system: 成功连接地址：', (self.hostip, self.hostport))

        #数据记录文件
        self.filename=filename

        #建立多线程：
        self.th_send = threading.Thread(target=self.tosend)
        self.th_recv = threading.Thread(target=self.torecv)
        self.th_recv.start()
        self.th_send.start()
        self.gLock = threading.Lock()#加锁（文件读写）
        self.fileos = 1#资源数

    def tosend(self):
        sendmeg=input()
        while sendmeg!='':
            self.s.send(sendmeg.encode())
            #此处放输出文件
            while True:
                if self.fileos == 1:
                    self.gLock.acquire()  # 加锁
                    self.fileos = 0
                    with open(self.filename, 'a+') as f:
                        f.writelines('Client send:'+ sendmeg+'\n')
                    self.gLock.release()  # 释放锁
                    self.fileos = 1
                    break
            sendmeg = input()
        print('system: 关闭连接')
        self.isconnect=0
        self.s.close()  # 关闭连接

    def torecv(self):
        while True:
            recemeg = self.s.recv(1024)
            if recemeg!=b'':
                print('接受信息：',recemeg)
                while True:
                    if self.fileos==1:
                        self.gLock.acquire()  # 加锁
                        self.fileos=0
                        with open(self.filename,'a+') as f:
                            f.writelines('Client get:'+ recemeg.decode()+'\n')
                        self.gLock.release()  # 释放锁
                        self.fileos = 1
                        break

        print('system: 结束连接')

if __name__=="__main__":
    # main()
    wc=wechat('chat2.txt',12345)