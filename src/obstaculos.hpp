#ifndef OBSTACULOS_HPP_
#define OBSTACULOS_HPP_
#include "map.hpp"

class Obstaculo {
   public:
    FloatRect bear;
    FloatRect jokers;
    FloatRect chica;
    FloatRect foxy;
    FloatRect freddy;
    FloatRect purple;
    FloatRect bonnie;

    vector<FloatRect> vetor;

   public:
    Obstaculo();
    FloatRect returnPersonagens(int i);
};

#endif  // OBSTACULOS_HPP_