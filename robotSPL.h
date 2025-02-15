
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

struct Point{
    float x, y;
};

class RobotSPL: public Robot{
    private:
        string postura;
        Estado orientacaoCampo;
        int posicao;
        int estadoDeJogo;
        bool sensCamera[2];
        Point bola;

    

    public:
        RobotSPL();
        RobotSPL(int,int,float,string,Estado,int,int);
        ~RobotSPL();
        bool getsensCamera();
        void setsensCamera(bool,bool);
        void movimentacao();
        void procuraBola();
        void estudaestadoDeJogo();
        string getPostura();
        Estado getorientacaoCampo();
        int getPosicao();
        int getEstadoDeJogo();
        Point getBola();
        void setEstadoDeJogo(int);
        void setPostura(string);
        void setorientacaoCampo(Estado);
        void setPosicao(int);
        void setBola(Point);

};

#endif