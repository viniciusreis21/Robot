
#ifndef _ROBOTSPL_H_
#define _ROBOTSPL_H_

#define GOLEIRO 0
#define ZAGUEIRO 1
#define ATACANTE 2

#define INITIAL 0
#define READY 1
#define SET 2
#define PLAYING 3
#define PENALIZED 4
#define FINISHED 5 

#include<iostream>
#include "robot.h"
#include<string>
using std::string;

struct Estado2D{
    float x,y;
};


class RobotSPL: public Robot{
    private:
        string postura;
        Estado2D orientacaoCampo;
        int posicao;
        int estadoDeJogo;
    public:
        string getPostura();
        Estado2D getorientacaoCampo();
        int getPosicao();
        int getEstadoDeJogo();
        void setEstadoDeJogo(int);
        void setPostura(string);
        void setorientacaoCampo(Estado2D);
        void setPosicao(int);

};

#endif