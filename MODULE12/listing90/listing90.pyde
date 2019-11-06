add_library('video')

mySize = 0

def setup():
    size(640, 480)
    smooth()
    background(0)
    noStroke()
    video = Capture(this, width, height)
    video.start()
    global video
    
def draw():
    global mySize
    if video.available():
        video.read()
    
        if mouseX >20 and mouseY >20:
            if mouseX < width -20 and mouseY < height- 20:
                if frameCount /% 5 == 0:
                    blendMode(BLEND)
                    noTint()
                    fill(0, 10)
                    rect(0, 0, width, height)
                else:
                    blendMode(ADD)
            x = mouseX + random(-100, 100)
            y = mouseY + random( -100, 100)
