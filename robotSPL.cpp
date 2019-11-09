#include "robotSPL.h"
#include <iostream>
#include <cstdlib>.
RobotSPL::RobotSPL(){
    std::cout<<"Construtor RobotSPL invocado."<<std::endl;
}
RobotSPL::RobotSPL(int nMot,int nSens,float bat, string post,Estado2D orient, int pos, int estJ):Robot(nMot,nSens,bat){
    this->postura=post;
    this->orientacaoCampo=orient;
    this->estadoDeJogo=estJ;
    this->posicao=pos;
    std::cout<<"Construtor do RobotSPL com parametros invocado."<<std::endl;
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
RobotSPL::~RobotSPL(){
    std::cout<<"Destrutor RobotSPL invocado."<<std::endl;
}
bool RobotSPL::getsensCamera(){
    if(sensCamera[0]==1 || sensCamera[1]==1){
        return 1;
    }
    else
    {
        return 0;
    }    
}
void RobotSPL::setsensCamera(bool sens1,bool sens2){
    this->sensCamera[0]=sens1;
    this->sensCamera[1]=sens2;
}
void RobotSPL::procuraBola(){
    std::cout<<"Procurando a bola..."<<std::endl;
    int x=rand()%100;
    while(x<30){
        std::cout<<"Procurando a bola..."<<std::endl;
        x = rand()%100;
    }
    std::cout<<"Indentificou a bola"<<std::endl;
    setsensCamera(0,1); // Quando achar a bola, seta a segunda camera para 1;
}
void RobotSPL::movimentacao(){
    if(posicao == ATACANTE){
        if(getsensCamera()==1){
            std::cout<< "Atacante indo ate a bola."<<std::endl;
        }
        else{
            procuraBola();
        }
    }
    else if(posicao == ZAGUEIRO){
        if(getsensCamera()==1){
            std::cout<< "Zagueiro indo ate a bola."<<std::endl;
        }
        else{
            procuraBola();
        }
    }
    else{
        if(getsensCamera()==1){
            //Considerando tambem a distancia da bola definida
            std::cout<< "Goleiro posicao de defesa."<<std::endl;
        }
        else{
            procuraBola();
        }
    }
}
