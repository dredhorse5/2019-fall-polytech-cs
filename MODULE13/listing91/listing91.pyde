class LightParticle:
    counter,x,y,cx,cy,size,step,dist,angle = 0,0,0,0,0,0,0,0,0
    
    LightParticle(self, cx, cy, size, step, dist, angle):
        self.cx = cx
        self.cy = cy
        self.size=size
        self.dist = dist
        self.step = step
        self.angle = angle
        
    def render():
        counter += step
        if counter > TWO_PI:
            counter = 0
            
        if counter
        