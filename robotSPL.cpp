#include "robotSPL.h"
#include <iostream>
#include <cstdlib>.
#include <time.h> 



RobotSPL::RobotSPL(){
    std::cout<<"Construtor RobotSPL invocado."<<std::endl;
}
RobotSPL::RobotSPL(int nMot,int nSens,float bat, string post,Estado orient, int pos, int estJ):Robot(nMot,nSens,bat){
    this->postura=post;
    this->orientacaoCampo=orient;
    this->estadoDeJogo=estJ;
    this->posicao=pos;
    this->sensCamera[0]=false;
    this->sensCamera[1]=false;
    std::cout<<"Construtor do RobotSPL com parametros invocado."<<std::endl;
}
int RobotSPL::getEstadoDeJogo(){
    return this->estadoDeJogo;
}
string RobotSPL::getPostura(){
    return this->postura;
}
Estado RobotSPL::getorientacaoCampo(){
    return this->orientacaoCampo;
}
int RobotSPL::getPosicao(){
    return this->posicao;
}
void RobotSPL::setPostura(string post){
        this->postura = post;

}
void RobotSPL::setorientacaoCampo(Estado est){
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
    if(sensCamera[0]==true || sensCamera[1]==true){
        return true;
    }
    else
    {
        return false;
    }    
}
void RobotSPL::setsensCamera(bool sens1,bool sens2){
    this->sensCamera[0]=sens1;
    this->sensCamera[1]=sens2;
}
void RobotSPL::procuraBola(){
    std::cout<<"Procurando a bola..."<<std::endl;
    srand (time(NULL));
    int x=rand()%100;
    std::cout<< x<<std::endl;
    while(x<80){
        std::cout<<"Procurando a bola..."<<std::endl;
        x = rand()%100;
    }
    std::cout<<"Indentificou a bola"<<std::endl;
    setsensCamera(false,true); // Quando achar a bola, seta a segunda camera para 1;
}
void RobotSPL::movimentacao(){
    if(estadoDeJogo!= PLAYING){
        std::cout<<"Nao pode jogar"<<std::cout;
        return;
    }
    
    if(posicao == ATACANTE){
        if(getsensCamera()==true){
            std::cout<< "Atacante indo ate a bola."<<std::endl;
        }
        else{
            procuraBola();
        }
    }
    else if(posicao == ZAGUEIRO){
        if(getsensCamera()==true){
            std::cout<< "Zagueiro indo ate a bola."<<std::endl;
        }
        else{
            procuraBola();
        }
    }
    else{
        if(getsensCamera()==true){
            //Considerando tambem a distancia da bola definida
            std::cout<< "Goleiro posicao de defesa."<<std::endl;
        }
        else{
            procuraBola();
        }
    }
}
void RobotSPL::estudaestadoDeJogo(){
    std::cout <<"INITIAL=0, READY=1, SET=2, PLAYING=3, PENALIZED=4, FINISHED 5"<< std::endl;
    int aux;
    std::cin>> aux;
    while(aux>5 || aux<0){
        switch (aux)
        {
            case 0:
                std::cout<< "Posição INITIAL:"<<std::endl;
                std::cout<<"Robô não pode se mover, a não ser que seja para se levantar"<<std::endl;
                break;
            case 1:
                std::cout<< "Posição READY:"<<std::endl;
                std::cout<<"Nesse estado o robô anda para sua posicao de 'kick off'"<<std::endl;
                break;
            case 2:
                std::cout<< "Posição SET:"<<std::endl;
                std::cout<<"O robô para e espera o 'kick off'"<<std::endl;
                break;
            case 3:
                std::cout<< "Posição PLAYING:"<<std::endl;
                std::cout<<"O robô está jogando"<<std::endl;
                break;
            case 4:
                std::cout<< "Posição PENALIZED:"<<std::endl;
                std::cout<<"O robô foi penalizado e não pode se mover"<<std::endl;
                break;
            case 5:
                std::cout<< "Posição FINISHED:"<<std::endl;
                std::cout<<"Esse estado é atingido quando um 'tempo' acaba"<<std::endl;
                break;
        default:
            std::cout<< "Valor invalido"<<std::endl;
            break;
        }
        std::cin >> aux;
    }
}