vertexCount = 0
sinCounter = 0
eSize = 15

def setup():
    global borders, drow
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
    global drow, sinCounter
    noStroke()
    fill(0, 10)
    rect(0,0, width, height)
    stroke(200, 150)
    strokeWeight(1)
    fill(100, 200)
    drow.disableStyle()
    noFill()
    for j in range(0, 6):
        vertexCount = borders[j].getVertexCount()
        for i in range(0, vertexCount -1, 2):
            vx = borders[j].getVertexX(i) + 50
            vy = borders[j].getVertexY(i) + 0
            vx1 = borders[j].getVertexX(i + 1)+ 50
            vy1 = borders[j].getVertexY(i + 1) + 50
            
            vcx1 = vx + random(-10, 10)
            vcx2 = vx1+ random(-10,10)
            vcy1 = vy + random(-10,10)
            vcy2 = vy1 + random(-10,10)
            
            letterSColor = map(sin(sinCounter), -1, 1, 0, 255)
            stroke(letterSColor, 50)
            
            if sinCounter <TWO_PI:
                cv = map(mouseX, 0, width, 0, 0.5)
                sinCounter += cv
            else:
                sinCounter = 0
                
            bezier(vx, vy, vcx1, vcy1, vcx2, vcy2, vx1, vy1)
