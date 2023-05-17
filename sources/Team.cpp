#include "Team.hpp"
using namespace ariel;
using namespace std;

Team::Team (Character* leader) {
    this->theTaem.push_back(leader);
    this->leader = leader;
}

void Team::add (Character* fri) {
    if(this->theTaem.size() == 10) {
        cout << "the team is full" << endl;
        return;
    }
    this->theTaem.push_back(fri);
}

void Team::attack (Team* enemy) {

}

int Team::stillAlive () {
    return 0;
}

Character& Team::getLeader () {
    return *this->leader;
}

void Team::setLeader (Character* leader) {
    this->leader = leader;
}

Character& Team::passOverTheTeam() {
    return *this->leader;
}

void Team::print () {

} 
