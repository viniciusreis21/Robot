#include "robot.h"
#include <iostream>

#define BAT_MAX 100
#define BAT_MIN 0

Robot::Robot(){
    std::cout<< "Construtor robô inicializado"<<std::endl;
}
Robot::Robot(int nMot,int nSens, float bat){
    this->numeroMotores=nMot;
    this->numeroSensores=nSens;
    this->bateria=bat;
    std::cout<<"Construtor robô realizado com numMotores "<< numeroMotores<<", numSensores "<< numeroSensores<<" e nivel de bateria"<< bateria<<std::endl;
}
int Robot::getNumeroMotores(){
    return this->numeroMotores;
}
float Robot::getNivelBateria(){
    return this->bateria;
}
int Robot::getNumeroSensores(){
    return this->numeroSensores;
}
Estado Robot::getOrientacao(){
    return this->orientacao;
}
void Robot::setOrientacao(Estado est){
    this->orientacao.theta = est.theta;
    this->orientacao.x=est.x;
    this->orientacao.y=est.y; 
}
void Robot::setNumeroMotores(int mot){
    if(mot>0){
    this->numeroMotores=mot;
    }
    else
    {
        std::cout<< "Numero de motores invalidos"<<std::endl;
    }
}
void Robot::setNumeroSensores(int sens){
    if(sens>=0){
        this->numeroSensores=sens;
    }
    else{
        std::cout<<"Numero de sensores inválido."<<std::endl;
    }
}
void Robot::setNivelBateria(float nivel){
    if(nivel>BAT_MAX || nivel<BAT_MIN){
        std::cout<<"Nivel de Bateria invalido"<<std::endl;
    }
    else{
        this->bateria=nivel;
    }
}
void Robot::Locomocao(){
    std::cout<< "Robo se locomovendo com orientacao x="<< orientacao.x <<" y="<<orientacao.y<< " e angulo="<<orientacao.theta<<std::endl;
}
Robot::~Robot(){
    std::cout<< "Destrutor invocado"<<std::endl;
}
