rc = 0

def setup():
    size(600, 600)
    smooth()
    background(0)
    font = loadFont("Gadugi-Bold-48.vlw")
    font1 = loadFont("SegoePrint-Bold-48.vlw")
    global font, font1
    
def draw():
    global rc, font, font1
    filter(BLUR, 3)
    translate(width/2, height/2)
    
    pushMatrix()
    textFont(font, 48)
    rotate(rc)
    fill(255)
    text("Black", mouseX - width/4, mouseY - height/4)
    popMatrix()
    
    pushMatrix()
    textFont(font1, 48)
    rotate(-rc * 1.5)
    fill(0)
    text("White", width/4 - mouseX, height/4 - mouseY)
    popMatrix()
    
    rc += 0.05
