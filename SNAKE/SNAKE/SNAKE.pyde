field_size = 40
snakeTailX = [40,80,120]
snakeTailY = [0,0,0 ]
Xhead, Yhead, Xfood, Yfood = 120,0,-40,- 40
snakeDirection = 'R'
foodkey = True
snakeLeight = 2
deadKey = False
score = 0


def setup():
    size(720,720)
    noStroke()
    frameRate(4)

def draw():
    global Xhead, Yhead, snakeDirection1, Xfood, Yfood, snakeLeight,snakeTailX,snakeTailY, deadKey
    println(snakeTailX)

    if deadKey == False:
        background(0)
        snakeDirection1()
        snakeGO()
        food()
        foodEat()
        snakeTail()
        for i in range(snakeLeight):
            if snakeTailX[i] == Xhead and snakeTailY[i] == Yhead:
                snakeDead()
        if Xhead + field_size/2 > width or Xhead < 0 or Yhead + field_size/2 > height or Yhead < 0:
            snakeDead()
        fill(255)
        textSize(25)
        text(score, width - 50,50)
        fill(255, 0, 0)
        rect(Xhead, Yhead, field_size, field_size)
    
def keyPressed():
    global snakeDirection, foodkey, snakeLeight, deadKey, score, Xhead, Yhead,snakeTailX,snakeTailY
    if deadKey and keyCode == DOWN:
        print("ssss")
        snakeDirection = 'R'
        foodkey = True
        snakeLeight = 2
        deadKey = False
        score = 0
        Xhead, Yhead = 120, 0
        snakeTailX = [40,80,120]
        snakeTailY = [0,0,0 ]
    
def snakeTail():
    global foodkey
    if foodkey == False:
        for i in range(snakeLeight):
            snakeTailX[i] = snakeTailX[i+1]
            snakeTailY[i] = snakeTailY[i+1]
        snakeTailX[snakeLeight] = Xhead
        snakeTailY[snakeLeight] = Yhead
    fill(0, 255, 0)
    for i in range(snakeLeight):
        rect(snakeTailX[i], snakeTailY[i],field_size,field_size)

def foodEat():
    global Xhead, Yhead, Xfood, Yfood, foodkey, snakeLeight, score
    if Xhead == Xfood and Yfood == Yhead:
        foodkey = True
        score += 1
        snakeTailX.append(Xhead)
        snakeTailY.append(Yhead)
        snakeLeight += 1
        
def food():
    global foodkey, Xfood, Yfood
    fill(random(0,255),random(0,255),random(0,255))
    rect(Xfood, Yfood, field_size, field_size)
    if foodkey:
        Xfood = int(random(0, width/field_size))*field_size
        Yfood = int(random(0, height/field_size))*field_size
        foodkey = False
        for i in range(snakeLeight):
            if snakeTailX[i] == Xfood and snakeTailY[i] == Yfood:
                foodkey = True
                food()
        
def snakeGO():
    global snakeDirection, Xhead, Yhead
    if snakeDirection == 'R':
        Xhead += field_size
    if snakeDirection == 'D':
        Yhead += field_size
    if snakeDirection == 'L':
        Xhead -= field_size
    if snakeDirection == 'U':
        Yhead -= field_size
    
def snakeDirection1():
    global snakeDirection
    if keyCode == RIGHT and snakeDirection != 'L':
        snakeDirection = 'R'
    if keyCode == LEFT  and snakeDirection != 'R':
        snakeDirection = 'L' 
    if keyCode == UP    and snakeDirection != 'D':
        snakeDirection = 'U'
    if keyCode == DOWN  and snakeDirection != 'U':
        snakeDirection = 'D'
        
def snakeDead():
    global deadKey, score
    deadKey = True
    textSize(50)
    text("snake is dead!", 250, 200)
    textSize(40)
    text("pess down to start new game", 100, 250)
    text(score, 350, 300)
