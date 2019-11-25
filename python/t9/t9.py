import math
	class GeometricObject:
	    def __init__(self,color='none'):
	        self.color=color
	    def perimeter(self):
	        pass
	    def area(self):
	        pass
	
	class Circle(GeometricObject):
	    def __init__(self,radius,color):
	        GeometricObject.__init__(self,color)
	        self.radius=radius
	    def perimeter(self):
	        return 2*math.pi*self.radius
	    def area(self):
	        return math.pi*(self.radius**2)
	
	class Rectangle(GeometricObject):
	    def __init__(self,length,width,color):
	        GeometricObject.__init__(self,color)
	        self.length=length
	        self.width=width
	    def perimeter(self):
	        return (self.length+self.width)*2
	    def area(self):
	        return self.length*self.width
	
	class testGeometric:
	    def __init__(self,radius,length,width,colorC,colorR):
	        self.re = Rectangle(length,width,colorR)
	        self.cl = Circle(radius,colorC)
	    def printit(self):
	        print('Rectangle:[color:%s ;perimeter:%d ;area:%d]'%(self.re.color,self.re.perimeter(),self.re.area()))
	        print('Circle:[color:%s ;perimeter:%d ;area:%d]'%(self.cl.color,self.cl.perimeter(),self.cl.area()))
	
	def main():
	    tg = testGeometric(5,10,5,'red','blue')
	    tg.printit()
	if __name__=="__main__":
    main()