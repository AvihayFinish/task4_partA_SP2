#include "Cowboy.hpp"
using namespace ariel;
using namespace std;

Cowboy::Cowboy (string name, Point pos) : Character(pos, 110, name), numBoolets(6) {

}

Cowboy::~Cowboy() {

}

void Cowboy::shoot (Character* enemy) {
    enemy->hit(10);
}

bool Cowboy::hasboolets () {
    if (this->numBoolets > 0 ) {
        return true;
    }
    return false;
}

void Cowboy::reload () {
    if (!(this->numBoolets)) {
        this->numBoolets = 6;
    }
}

string Cowboy::print () {
    return "";
}

