#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
using namespace std;

namespace ariel {

    class Team {
        private:
            std::vector<Character*> theTaem;
            Character* leader;
        public:
            Team (Character* leader);
            void add (Character* fre);
            void attack (Team* enemy);
            int stillAlive ();
            Character& getLeader();
            void setLeader(Character* leader);
            virtual Character& passOverTheTeam();
            virtual void print (); 
    };
}