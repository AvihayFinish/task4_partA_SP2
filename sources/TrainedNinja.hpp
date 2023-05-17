#pragma once
#include "Character.hpp"
#include <iostream>

namespace ariel {

    class TrainedNinja : public Character {
        private:
            int speed;
        public:
            TrainedNinja (string name, Point pos);
            void move (Character* enemy);
            void slash (Character* enemy);
            string print () override;
    };
}