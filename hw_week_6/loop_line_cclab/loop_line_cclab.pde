//For Loops
float endX=0;

void setup() {
  size (500,500);
}

void draw (){
  background (0);
  
  for(int x=0; x<endX; x=x+30){
    stroke(0,255,255);
    strokeWeight(3);
    line (x,0,x,height);
  }
  
  endX = endX + 5;
  
  
   for(int x=0; x<endX; x=x+30){
    stroke(255,0,255);
    strokeWeight(3);
    line (x,0,x,height);
  }
  
  endX = endX + 5;
}
  
  
//in order to loop we need to manipulate the width
//the way to make it animated is the use the boolean to make the x smaller than the variable
//it's drawing one more ellipse every time