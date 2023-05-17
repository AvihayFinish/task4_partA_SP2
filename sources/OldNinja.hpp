#pragma once
#include <iostream>
#include "Character.hpp"

namespace ariel {

    class OldNinja : public Character {
        private:
            int speed;
        public:
            OldNinja (string name, Point pos);
            void move (Character* enemy);
            void slash (Character* enemy);
            string print () override;
    };
}