def setup():
    global drow
    background(100)
    smooth()
    strokeWeight(1)
    size(800,400)
    drow = loadShape("data/drawing.svg")
    
def draw():
    global drow
    fill(10, 15)
    rect(0,0,width, height)
    mCursor = map(mouseX, 0, width, 100, 155)
    fill(10, 100)
    drow.disableStyle()
    shape(drow,0,0)
    
    border = drow.getChild("path4583")
    for i in range(0, border.getVertexCount()):
        vx = border.getVertexX(i) +200
        vy = border.getVertexY(i) +200
        lx = vx + random(-150, 150)
        ly = vy + random(-150, 150)
        lineColor = mCursor + random(-100, 100)
        stroke(lineColor, 100)
        line(vx, vy, lx, ly)
        fill(200, 50)
        noStroke()
        ellipse(vx, vy, 3 ,3 )
        
    border1 = drow.getChild("path4585")
    for i in range(0, border1.getVertexCount()):
        vx = border1.getVertexX(i) +200#Надо подогнать под размер букв
        vy = border1.getVertexY(i) +200#Надо подогнать под размер букв
        lx = vx + random(-150, 150)
        ly = vy + random(-150, 150)
        lineColor = mCursor + random(-100, 100)
        stroke(lineColor, 100)
        line(vx, vy, lx, ly)
        fill(200, 50)
        noStroke()
        ellipse(vx, vy, 3 ,3 )
        
    border2 = drow.getChild("path4587")
    for i in range(0, border2.getVertexCount()):
        vx = border2.getVertexX(i) +200#Надо подогнать под размер букв
        vy = border2.getVertexY(i) +200#Надо подогнать под размер букв
        lx = vx + random(-150, 150)
        ly = vy + random(-150, 150)
        lineColor = mCursor + random(-100, 100)
        stroke(lineColor, 100)
        line(vx, vy, lx, ly)
        fill(200, 50)
        noStroke()
        ellipse(vx, vy, 3 ,3 )
        
    border3 = drow.getChild("path4589")
    for i in range(0, border3.getVertexCount()):
        vx = border3.getVertexX(i) +200#Надо подогнать под размер букв
        vy = border3.getVertexY(i)  +200 #Надо подогнать под размер букв
        lx = vx + random(-150, 150)
        ly = vy + random(-150, 150)
        lineColor = mCursor + random(-100, 100)
        stroke(lineColor, 100)
        line(vx, vy, lx, ly)
        fill(200, 50)
        noStroke()
        ellipse(vx, vy, 3 ,3 )
