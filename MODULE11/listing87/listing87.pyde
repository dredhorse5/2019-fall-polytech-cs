vertexCount = 0


def setup():
    global borders, drow
    size(600,600)
    smooth()
    background(255)
    noFill()
    strokeWeight(1)
    drow = loadShape("m1.svg")
    borders = range(6)
    borders[0] = drow.getChild("path16")
    borders[1] = drow.getChild("path18")
    borders[2] = drow.getChild("path20")
    borders[3] = drow.getChild("path22")
    borders[4] = drow.getChild("path24")
    borders[5] = drow.getChild("path26")
    
    
def draw():
    for j in range(0, 6):
        vertexCount = borders[j].getVertexCount()
        for i in range(0, vertexCount - 1):
            vx = borders[j].getVertexX(i) + 50
            vy = borders[j].getVertexY(i) + 50
            stroke(0, 50)
            if dist(mouseX, mouseY, vx, vy) < 10:
                line(mouseX, mouseY, vx, vy)
