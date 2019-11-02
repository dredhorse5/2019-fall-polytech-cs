size(600,600)
smooth
background(255)
strokeWeight(30)
noLoop

k = 0
i = 1

while k < 4:
    while i < 8:
        i += 1
        stroke(20*i)
        line(i*50,       100 + 100*k,  150 +(i-1)*50,  200 + 100*k)
        stroke(160 - 20*i)
        line(i*50 +100,  100 + 100*k,  50 + (i-1)*50,  200 + 100*k)
    k += 1
    i = 1
