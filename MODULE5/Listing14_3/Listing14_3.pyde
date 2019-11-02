X1 = 50
X2 = 150

size(500,500)
smooth
background(255)
strokeWeight(30)

stroke(20)

line(X1,200,X2,300)

while X1 < 350:
    
    
    if X1 < 350:
        X1 +=50
    if X2 < 500:
        X2 +=50
        
    line(X1,200,X2,300)
