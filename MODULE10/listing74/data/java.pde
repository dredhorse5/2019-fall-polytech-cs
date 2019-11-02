PImage img1;
PImage img2;
PImage img3;

boolean isAnimate = true;
int currentFrame = 1;

void setup(){
  background(100);
  smooth();
  size(800,800);
  frameRate(12);
  img1 = loadImage("001.jpg");
  img2 = loadImage("002.jpg");
  img3 = loadImage("003.jpg");
}

void draw(){
  background(100);
  if(isAnimate){
    switch(currentFrame){
      case 1:
        image(img1, mouseX, mouseY);
      break;
      case 2:
        image(img2, mouseX, mouseY);
      break;
      case 3:
        image(img3, mouseX, mouseY);
      break;
    }
    
    currentFrame++;
    if(currentFrame > 3){
      currentFrame = 1;
    }
  } else{
    image(img1, mouseX, mouseY);
  }
}
void keyPressed(){
  isAnimate = !isAnimate;
}
