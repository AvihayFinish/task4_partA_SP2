#pragma once
#include <iostream>
#include <string.h>
#include "Point.hpp"
using namespace std;

namespace ariel {

    class Character {
        private:
            Point pos;
            int pointsLive;
            string name;
        public:
            Character (Point pos, int pointsLive, string name);
            virtual ~Character();
            bool isAlive ();
            double distance (Character* other);
            void hit (int num);
            string getName ();
            Point getLocation ();
            int getPointsLive ();
            virtual string print (); // check this if I need this pure virtual or not
            bool operator== (Character other);

    };
}