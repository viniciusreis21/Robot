#include "robotSPL.h"
#include <iostream>

RobotSPL::RobotSPL(){

}
int RobotSPL::getEstadoDeJogo(){
    return this->estadoDeJogo;
}
string RobotSPL::getPostura(){
    return this->postura
}
Estado2D RobotSPL::getorientacaoCampo(){
    return this->orientacaoCampo
}
int RobotSPL::getPosicao(){
    return this->posicao;
}
void RobotSPL::setPostura(string post){
    if(post.length != 0){
        this->postura = post;
    }
    else std::cout<<"string vazia" << std::endl;
}
void RobotSPL::setorientacaoCampo(Estado2D est){
    this->orientacaoCampo = est; // teste 
}
void RobotSPL::setPosicao(int pos){
    if(pos != GOLEIRO && pos != ZAGUEIRO && pos != ATACANTE){
        std::cout<<"Posicao Invalida";
    }
    else 
        this->posicao = pos;
}
void RobotSPL::setEstadoDeJogo(int est){
    if(est < INITIAL || est > FINISHED){
        std::cout<<"Estado Invalido";
    }
    else{
        this->estadoDeJogo = est;
    }
}

