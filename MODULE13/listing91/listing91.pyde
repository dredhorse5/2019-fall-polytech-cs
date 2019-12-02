class LightParticle:
    counter,x,y,cx,cy,size,step,dist,angle = 0,0,0,0,0,0,0,0,0
    
    LightParticle(self, cx, cy, size, step, dist, angle):
        self.cx = cx
        self.cy = cy
        self.size = size
        self.dist = dist
        self.step = step
        self.angle = angle
        
    def render():
        counter += step
        if counter > TWO_PI:
            counter = 0
            
        if counter < 0:
            counter = TWO_PI
        
        x1 = x-sin(counter)*(size/2)
        x2 = x + sin(counter)*(size/2)
        y1 = y - cos(counter)*(size/2)
        y2 = y + cos(counter)*(size/2)
        
        line(x1, y1, x2, y2)
        
        x3 = x - sin(counter + PI/2)*(size/2) 
        x4 = x + sin(counter + PI/2)*(size/2)
        y3 = y - cos(counter + PI/2)*(size/2)      
        y4 = y + cos(counter + PI/2)*(size/2)
        
        line(x3, y3, x4, y4)
        
class ParticleController():
     void createParticles(self x, self y, self number):
         for i in range
