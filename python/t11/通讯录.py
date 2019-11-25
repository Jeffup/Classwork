import sys
class AdressBook:
    def __init__(self,filename):
        self.filename=filename
        self.data = {}
        num = 0
        with open(filename, 'r') as f:
            for s in f.readlines():
                self.data[num] = s.split()
                num += 1

    def showmenu(self):
        print('|---1 查询联系人资料---| ')
        print('|---2 插入新的联系人---| ')
        print('|---3 删除已有联系人---| ')
        print('|---4 退出通讯录程序---| ')

    def function(self,choose):
        if choose==1:
            self.selectanddel()
        elif choose==2:
            self.insert()
        elif choose==3:
            self.selectanddel(1)
        elif choose==4:
            self.leave()
        else:
            print('没有此选项!')
            self.showmenu()
    #mode==0为查询,mode！=1为删除
    def selectanddel(self,mode=0):
        choose = 0
        choose = input('精确搜索为0,采用模糊搜索输入1，输出全部信息输入2：')
        if int(choose)!=2:
            if mode==0:
                name=input('查询联系人姓名：')
                depart=input('查询联系人单位：')
                tel=input('查询联系人电话：')
            else:
                name = input('删除联系人姓名：')
                depart = input('删除联系人单位：')
                tel = input('删除联系人电话：')
        if mode!=0:
            print('删除人员列表：')

        for s in self.data.keys():
            if int(choose)==0:
                if name==self.data[s][0] and depart==self.data[s][1] and tel==self.data[s][2]:
                    print(s,':',self.data[s])
            elif int(choose)==1:
                if name==self.data[s][0] or depart==self.data[s][1] or tel==self.data[s][2]:
                    print(s,':',self.data[s])
            else:
                print(s,':',self.data[s])

        if mode != 0:
            num = input('输入选择删除的人的代号：')
            self.data.pop(int(num))

    def insert(self):
        name=input('插入联系人姓名：')
        depart=input('插入联系人单位：')
        tel=input('插入联系人电话：')
        self.data[self.data.__len__()]=[name,depart,tel]

    def leave(self):
        print('bye')
        with open(self.filename, 'w') as f:
            for s in self.data.values():
                f.write(s[0]+' '+s[1]+' '+s[2]+'\n')
        sys.exit()

    def menu(self):
        self.showmenu()
        while 1:
            choose=input('请输入功能项：')
            self.function(int(choose))

if __name__=='__main__':
    ad = AdressBook('contact.txt')
    ad.menu()