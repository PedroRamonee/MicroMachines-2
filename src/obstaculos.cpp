#include "obstaculos.hpp"

Obstaculo::Obstaculo() {

    bonnie.height = 157;
    bonnie.width = 130;
    bonnie.top = 45;
    bonnie.left = 473;

    bear.height = 100;
    bear.width = 70;
    bear.top = 190;
    bear.left = 1050;

    jokers.height = 230;
    jokers.width = 147;
    jokers.top = 510;
    jokers.left = 895;

    chica.height = 125;
    chica.width = 85;
    chica.top = 960;
    chica.left = 1050;

    foxy.height = 113;
    foxy.width = 90;
    foxy.top = 180;
    foxy.left = 135;

    freddy.height = 200;
    freddy.width = 360;
    freddy.top = 970;
    freddy.left = 460;

    purple.height = 136;
    purple.width = 85;
    purple.top = 960;
    purple.left = 135;

    vetor.push_back(bonnie);
    vetor.push_back(bear);
    vetor.push_back(jokers);
    vetor.push_back(chica);
    vetor.push_back(foxy);
    vetor.push_back(freddy);
    vetor.push_back(purple);

}

FloatRect Obstaculo:: returnPersonagens(int i){
    return vetor[i];
}
