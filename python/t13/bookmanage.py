import mysql.connector
#安装此库 python -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple mysql-connector

class Book:
    def __init__(self):
        #连接数据库
        self.mydb = mysql.connector.connect(
            host="127.0.0.1",
            port="3306",
            user="root",
            passwd="root",
        )
        self.mycursor = self.mydb.cursor()
        self.col=['ISBN','bookname','version','author','publish','price']
        #使用数据库中的test库
        self.mycursor.execute("use test")
#展示数据头
    def showhead(self):
        print('|    ISBN    |, |   bookname  |, |   version  |,|  publish  |,|  author  |,|  price |')
#展示数据库中的所有信息
    def showbook(self):
        self.mycursor.execute('select * from book')
        self.showhead()
        for x in self.mycursor:
            print(x)
#添加功能
    def add(self):
        sql='insert into book values('
        sql+=self.makesql(1)
        if sql=='insert into book values(':#若啥也没添加进来，则。。。
            print('加了个寂寞~')
            return False
        else:
            sql+=')'
        self.mycursor.execute(sql)
        self.showbook()
        return True
#删除功能
    def delete(self):
        sql='delete from book where'
        sql += self.makesql()
        if sql=='delete from book where':
            print('什么！？你想删库跑路！？')
            return False
        else:
            self.mycursor.execute(sql)
            for x in self.mycursor:
                print(x)
            self.showbook()
            return True
#查询功能
    def search(self):
        sql = 'select * from book where'
        sql+=self.makesql()
        if sql=='select * from book where':
            sql=sql[0:-5]
        self.mycursor.execute(sql)
        self.showhead()
        for x in self.mycursor:
            print(x)
#构造sql查询数据块，mode==0时为删除和查询数据块，不等于0时为添加数块
    def makesql(self,mode=0):
        print('请输入以下信息')
        count=0
        sql=''
        ISBN = input('ISBN:')
        if mode==0:
            if ISBN != '':
                sql += " ISBN='" + ISBN + "' and"
                count+=1
        else:
            if ISBN!='':
                sql+="'"+ISBN+"',"
                count += 1
            else:
                sql+="'None',"

        bookname = input('bookname:')
        if mode == 0:
            if bookname != '':
                sql += " bookname='" + bookname + "' and"
                count += 1
        else:
            if bookname!='':
                sql+="'"+bookname+"',"
                count += 1
            else:
                sql+="'None',"

        version = input('version:')
        if mode == 0:
            if version != '':
                sql += " version='" + version + "' and"
                count += 1
        else:
            if version!='':
                sql+="'"+ version+"',"
                count += 1
            else:
                sql+="'None',"

        author = input('author:')
        if mode == 0:
            if author != '':
                sql += " author='" + author + "' and"
                count += 1
        else:
            if author!='':
                sql+="'"+ author+"',"
                count += 1
            else:
                sql+="'None',"

        publish = input('publish:')
        if mode == 0:
            if publish != '':
                sql += " publish='" + publish + "' and"
                count += 1
        else:
            if publish!='':
                sql+="'"+ publish+"',"
                count += 1
            else:
                sql+="'None',"

        price = input('price:')
        if mode == 0:
            if price != '':
                sql += " price='" + price + "' and"
                count += 1
        else:
            if price!='':
                sql+="'"+price+"',"
                count += 1
            else:
                sql+="'None',"

        if sql!='' and mode==0:
            sql = sql[0:-3]
        else:
            sql =sql[0:-1]
        if count==0:
            sql=''
        return sql
#功能菜单
    def menu(self):
        print('*' * 29)
        print('*欢迎查书！输入代号执行功能! *')
        print('*1.-------------------- 查询*')
        print('*2.-------------------- 插入*')
        print('*3.-------------------- 删除*')
        print('*4.-----------------展示所有*')
        print('*5.---------------------退出*')
        print('*' * 29)
        while(1):
            choose=input('请输入代号：')
            if choose=='1':
                self.search()
            elif choose=='2':
                self.add()
            elif choose=='3':
                self.delete()
            elif choose=='4':
                self.showbook()
            elif choose=='5':
                return
            else:
                print('无此选项！')


if __name__=='__main__':
    book=Book()
    book.menu()