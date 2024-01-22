#include <Gamebuino-Meta.h>
//score
int score1 = 0;
int score2 = 0;
//joeurs
int raquette1 = 5;
int raquette2 = 73;
//ball
int positionX = 32;
int speedX = 1;
int positionY = 32;
int speedY = 1;

//hauteur de l'élément
int a = 25;
int b = 25;
int c = 25;
void setup() {
  gb.begin();
  }


  void loop() {  
    while(! gb.update());
    gb.display.clear();
    //joeur 1
    if (gb.buttons.pressed(BUTTON_UP)){
      a = a - 1;
    }
    if (gb.buttons.pressed(BUTTON_DOWN)){
      a = a + 1;
    }
    //joeur 2
        if (gb.buttons.pressed(BUTTON_A)){
      b = b - 1;
    }
    if (gb.buttons.pressed(BUTTON_B)){
      b = b + 1;
    }
    //balle
    positionX = positionX + speedX ;
    positionY = positionY + speedY;
    
    if (positionX > 79) {
      speedX= -1;
    }
    if (positionX < 0 ){
      speedX = 1;
    }    
    if (positionY < 0) {
      speedY= +1;
    }
    if (positionY > 63){
      speedY = -1;
    }
    //collision
    if (gb.collide.rectRect(raquette1,a,2,16,positionX,positionY,2,2)){
      speedX = 1;
    }
    if (gb.collide.rectRect(raquette2,b,2,16,positionX,positionY,2,2)){
      speedX = -1;
    }
    //point des joueurs
    if (positionX < 0) {
      score1++;
      positionX = 40;
      positionY = 30;
    }
     if (positionX > 79) {
      score2++ ;
      positionX = 40;
      positionY = 30;
    }
    //affichage
    gb.display.setCursorX(5);
    gb.display.print(score1);
    gb.display.setCursorX(70);
    gb.display.print(score2);
    gb.display.fillRect(raquette1, a, 2 , 16);
    gb.display.fillRect(raquette2, b, 2 , 16);
    gb.display.fillRect(positionX,positionY,2,2);
    }
