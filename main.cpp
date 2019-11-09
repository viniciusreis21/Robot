
#include <iostream>
#include "robot.h"
#include "robotSPL.h"


int main(){
    Estado2D inicial;
    inicial.x = 3.7;
    inicial.y = 2.4;
    RobotSPL r1(20,4,50,"Stand",inicial,2,3);
    int i=0;
    while(i<10){
        r1.movimentacao();
        i++;
    }
    

    return 0;
}