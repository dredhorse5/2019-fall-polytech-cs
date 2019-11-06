add_library('video')


def setup():
    size(640, 480)
    smooth()
    background(0)
    noStroke()
    video = Capture(this, width, height)
    video.start()
    global video
    
def draw():
    global video
    if video.available():
        video.read()
    
    pushMatrix()
    scale(-1, 1)
    image(video, -width, 0)
    popMatrix()
