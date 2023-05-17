#pragma once
#include "Character.hpp"
#include <iostream>

namespace ariel {

    class YoungNinja : public Character {
        private:
            int speed;
        public:
            YoungNinja (string name, Point pos);
            void move (Character* enemy);
            void slash (Character* enemy);
            string print () override;
    };
}