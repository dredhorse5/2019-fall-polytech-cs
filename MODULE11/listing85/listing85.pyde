vertexCount = 0
sinCounter = 0
eSize = 15

def setup():
    global borders
    size(300,300)
    smooth()
    background(0)
    noStroke()
    drow = loadShape("m1.svg")
    borders = range(6)
    borders[0] = drow.getChild("path16")
    borders[1] = drow.getChild("path18")
    borders[2] = drow.getChild("path20")
    borders[3] = drow.getChild("path22")
    borders[4] = drow.getChild("path24")
    borders[5] = drow.getChild("path26")
    
    
def draw():
    global borders, vertexCount, sinCounter
    background(255)
    pushMatrix()
    #translate(width/2, height/2)
    for j in range(0, 6):
        vertexCount = borders[j].getVertexCount()
        for i in range(0, vertexCount):
            vx = borders[j].getVertexX(i) + 50
            vy = borders[j].getVertexY(i) + 50
            ellipseColor = map(sin(sinCounter), -1, 1, 0, 255)
            fill(ellipseColor)
            ellipseSize = map( i, 0, vertexCount, eSize, eSize + 40)
            ellipse(vx, vy, ellipseSize/4, ellipseSize/4)
            
            if sinCounter < TWO_PI:
                cv = map(mouseX, 0, width, 0, 1)
                sinCounter += cv
            else:
                sinCounter = 0
    popMatrix()
