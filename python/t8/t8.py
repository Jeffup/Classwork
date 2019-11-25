class score:
    def __init__(self,textname='class_score.txt'):
        self.data={}
        num=0
        with open(textname,'r') as f:
            for s in f.readlines():
                self.data[num]=s.split()
                num+=1
        print('文档数据为：')
        print(self.data)
    #（1）分别求这个班数学和语文的平均分（保留 1 位小数） 并输出。
    def getavg(self):
        sum1=0#数学
        sum2=0#语文
        for s in self.data.values():
            sum1+=int(s[1])
            sum2+=int(s[2])
        print('1.计算平均分：')
        print('数学平均分：',format((sum1/len(self.data)),'.1f'))
        print('语文平均分：',round(sum2/len(self.data),1))
    #（2）找出两门课都不及格（<60） 的学生， 输出他们的学号和各科成绩。
    def find1(self):
        print('2.两门课不及格的学生：')
        for s in self.data.values():
            if int(s[1])<60 and int(s[2])<60:
                print(s)
    #（3） 找出两门课的平均分在 90 分以上的学生， 输出他们的学号和各科成绩。
    def find2(self):
        print('3.两门课在90以上的的学生：')
        for s in self.data.values():
            if int(s[1])>90 and int(s[2])>90:
                print(s)
def main():
    sc=score()
    sc.getavg()
    sc.find1()
    sc.find2()
if __name__=="__main__":
    main()