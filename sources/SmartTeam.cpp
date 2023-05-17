#include "SmartTeam.hpp"
using namespace std;
using namespace ariel;

Character& SmartTeam::passOverTheTeam() {
    return this->getLeader();
}