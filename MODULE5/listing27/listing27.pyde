def setup():
    size(500,500)
    smooth()
        
def draw():
    if frameCount == 1:
        c = 0
    global c
    noStroke()
    fill(10,50)
    rect(-1,-1, width+1,height+1)
    
    ny = sin(c) *100+200
    nx = c*10
    
    stroke(250)
    strokeWeight(20)
    line(nx, ny, nx, ny)
    
    c +=0.1
    
    if nx > width:
        c = 0
def KeyPressed():
    if key == "s":
        saveFrame("meProcessing.png")
