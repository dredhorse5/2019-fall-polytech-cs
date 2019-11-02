counter = 0
class FunnyEllipse():
    fsize = random(50,150)
    
    mycolor = 200
    size = random(50,100)
    noise = False
    x = 0
    y = 0
    
    def render(self):
        rectMode(CENTER)
        fill(self.mycolor, 100)
        noStroke()
        
        if self.noise == True:
            fill(random(150,255), 150)
            nx = self.x + noise(self.x)*10
            ny = self.y + noise(self.y)*10
            ellipse(nx, ny, self.size, self.size)
            
        else:
            ellipse(self.x, self.y, self.size, self.size)
            
            
    
    def isLine(self, box):
        result = False
        
        if dist(self.x, self.y, box.x, box.y)< 150:
            result = True
            box.noise = True
        else:
            box.noise = False
        self.noise = result
        
        
        
        return result
        
        
    
    def drawLine(self, box):
        stroke(255)
        strokeWeight(1)
        line(self.x,self.y, box.x, box.y)
        noStroke()
        fill(10)
        ellipseMode(CENTER)
        ellipse(self.x, self.y,10,10)
        ellipse(box.x,  box.y, 10, 10)
        


obj1 = FunnyEllipse()
obj2 = FunnyEllipse()

def setup():
    size(500,500)


def draw():
    global counter
    background(10)
    obj1.x = map(sin(counter), -1, 1, 100, width-100)
    obj2.x = map(cos(counter),-1,1,100,width-100) 
    obj1.y = map(cos(counter + 0.1),-1,1,100,width-100)  
    obj2.y = map(sin(counter - 0.1),-1,1,100,width-100)
    obj1.render()
    obj2.render()
    if obj1.isLine(obj2):
        obj1.drawLine(obj2)
    counter += 0.01    
