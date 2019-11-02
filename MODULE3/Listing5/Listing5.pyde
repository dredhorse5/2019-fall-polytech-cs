Width = 500
Height = 500
Size1 = 100
EWidth = 200
EHeight = 300

size(500,500)
smooth()
background(255) 
noLoop()
fill(50, 80)
stroke(100)
strokeWeight(3)

ellipse(Width/2,            Height/2 - Size1/2, EWidth ,EHeight)
ellipse(Width/2 - Size1/2,  Height/2,           EWidth ,EHeight)
ellipse(Width/2 + Size1/2,  Height/2,           EWidth ,EHeight)
ellipse(Width/2,            Height/2 + Size1/2, EWidth ,EHeight)
