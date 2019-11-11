
#include <iostream>
#include "robot.h"
#include "robotSPL.h"


int main(){
    Estado inicial;
    inicial.x = 3.7;
    inicial.y = 2.4;
    inicial.theta = 0;
    RobotSPL r1(24,4,50,"Stand",inicial,ATACANTE,PLAYING); //nao deve rodar pq os defines tao na classe, nao na main;
    int i=0;
    while(i<10){
        r1.movimentacao();
        i++;
    }
    

    return 0;
}