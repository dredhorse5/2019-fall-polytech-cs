rc = 0

def setup():
    size(600, 600)
    smooth()
    background(0)
    font = loadFont("Gadugi-Bold-48.vlw")
    textFont(font, 48)
    
    
def draw():
    global rc
    translate(width/2, height/2)
    
    pushMatrix()
    rotate(rc)
    fill(255)
    text("Black", mouseX - width/4, mouseY - height/4)
    popMatrix()
    
    pushMatrix()
    rotate(-rc * 1.5)
    fill(0)
    text("White", width/4 - mouseX, height/4 - mouseY)
    popMatrix()
    
    rc += 0.05
