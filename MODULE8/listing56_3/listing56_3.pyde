radius = 50
centerX = 500/2
centerY = 500/2
leng = 350
angle = PI/4
weight = 1
counter = 0
r = 0
g = 10
b = 150
class myline():
    
    def render(self, centerX, centerY, angle):
        x1 = centerX - cos(angle)*leng/2
        y1 = centerY + sin(angle)*leng/2
        x2 = centerX + cos(angle)*leng/2
        y2 = centerY - sin(angle)*leng/2
        self.x1 = x1
        self.x2 = x2
        self.y1 = y1
        self.y2 = y2
                
        stroke(150,100)
        strokeWeight(weight)
        line(x1,y1,x2,y2)
        
    def colors(self):
        global r, g, b
        r += random(0,10)
        g += random(0,5)
        b += random(10,15)
        
        if g >255:
            g = -g
        if r > 255:
            r =-r
        if b >255:
            b = -b
            
        stroke( r, g, b, 150)
        strokeWeight(10)
        line(self.x2, self.y2, self.x2, self.y2)
        line(self.x1, self.y1, self.x1, self.y1)

mline = myline()

def setup():
    size(500,500)
    smooth()
    background(0)
    
    
def colOr():
    global r, g, b

    
    
def draw():
    global counter, radius
    counter += 0.05
    
    if counter > 2*PI:
        counter = 0
        radius += 50
        
    mline.render(width/2 + sin(counter)*radius, width/2 + cos(counter)*radius, counter*2)
    mline.colors()
