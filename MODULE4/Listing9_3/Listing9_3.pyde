size (600, 600)

def Scene(myColor):
    fill(myColor)
    rotate(PI/4)
    rect(0,50,150,50)
    rect(50, 0, 50, 150)

background(20)
smooth()
noStroke()

pushMatrix() # сохраняет систему координат
translate(100,0)#перенос системы координат
rotate(PI/4)
Scene(180)
popMatrix() # Скидывает систему координат

pushMatrix() # сохраняет систему координат
translate(220,110)#перенос системы координат
rotate(PI/6)
scale(2)
Scene(220)
popMatrix() # Скидывает систему координат

pushMatrix() # сохраняет систему координат
translate(520,350) #перенос системы координат
rotate(PI/3)
scale(1.4)
Scene(80)
popMatrix() # Скидывает систему координат
