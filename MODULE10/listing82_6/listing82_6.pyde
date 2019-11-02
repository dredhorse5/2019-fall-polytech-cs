def setup():
    global drow
    background(100)
    smooth()
    strokeWeight(1)
    stroke(600,600)
    drow = loadShape("data/drawing.svg")
    size(800, 400)
    
def shapeDraw(my):
    global drow
    for i in range(0, my.getVertexCount()):
        vx = my.getVertexX(i) + 200
        vy = my.getVertexY(i) + 200
        lx1 = vx + random(-150, 150)
        ly1 = vy + random(-150, 150)
        lx = mouseX + random(-150, 150)
        ly = mouseY + random(-150, 150)
        mCursor = map(mouseX, 0, width, 0, 255)
        stroke(mCursor, 10)
        noFill()
        bezier(vx, vy, lx, ly, lx1, ly1, vx, vy)
    

def draw():
    global drow
    fill(10, 10)
    drow.disableStyle()
    shape(drow, 0, 0)
    
    border = drow.getChild("path4583")
    shapeDraw(border)
    
    border1 = drow.getChild("path4585")
    shapeDraw(border1)
    
    border2 = drow.getChild("path4587")
    shapeDraw(border2)
    
    border3 = drow.getChild("path4589")
    shapeDraw(border3)
