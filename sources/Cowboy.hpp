#pragma once
#include <iostream>
#include "Character.hpp"
using namespace std;

namespace ariel {

    class Cowboy : public Character {
        private:
            int numBoolets;
        public:
            Cowboy (string name, Point pos);
            ~Cowboy() override;
            void shoot (Character* enemy);
            bool hasboolets ();
            void reload ();
            string print () override;
    };
}

