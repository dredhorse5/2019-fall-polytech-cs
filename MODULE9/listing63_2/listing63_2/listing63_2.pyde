JU = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
i = 1

def setup():
    size(500,500)
    smooth()
    noStroke()
    myInit()
    
def myInit():
    for i in range (0, len(JU)):
        JU[i] = 250 + random(-100,100)


def draw():
    background(50)
    for i in range(0, len(JU)):
        fill(20)
        ellipse(JU[i], 250, 5, 5)
        fill(250, 40)
        ellipse(JU[i], 250, 10*i,10*i)
    if mouseX > 250:
        myInit()
        
    print( max(JU))
