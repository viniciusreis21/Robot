#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <iostream>

struct Estado
{
  float x,y,theta;
};

class Robot
{
  private:
    int numeroMotores; 
    int numeroSensores;
    float bateria;
    Estado orientacao;
    
  public:
    Robot();
    Robot(int,int,float); //Sobrecarga do construtor robot
    ~Robot();
    void Locomocao();
    int getNumeroMotores();
    int getNumeroSensores();
    float getNivelBateria();//Função mudada para o tipo float
    Estado getOrientacao();
    void setOrientacao(Estado);
    void setNivelBateria(float);
    void setNumeroMotores(int);
    void setNumeroSensores(int);
  
};
#endif