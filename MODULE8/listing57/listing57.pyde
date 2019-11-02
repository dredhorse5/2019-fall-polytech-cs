centerX = 0
centerY = 0
angle = 0
fsize  = 0
weight = 0
counter = 0
centerX= 500/2
centerY= 500/2
angle= 0
fsize= 150
weight = 1

class MyEllipse():
    
    #cX = centerX
    #cY = centerY
    #cA = angle
    #eS = fsize
    #Ew = weight
        
    def render(self, fsize):
        fill(200, fsize/20)
        x1 = centerX - cos(angle)*fsize/2
        y1 = centerY + sin(angle)*fsize/2
        
        stroke(250, 100)
        strokeWeight(weight)
        ellipse(x1, y1,fsize,fsize)
        
ell = MyEllipse()
        
def setup():
    size(500,500)
    smooth()
    background(10)
    
def draw():
    global counter
    counter += 0.01
    if counter > TWO_PI:
        sounter = 0
        
    ell.render(sin(counter*4)*mouseX)
    
