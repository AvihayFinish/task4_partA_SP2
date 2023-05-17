#include "Character.hpp"
using namespace ariel;

Character::Character (Point pos, int pointsLive, string name) : pos(pos), pointsLive(pointsLive), name(name) {
    if (name == "") {
        throw runtime_error("the character must have a name");
    }

}

Character::~Character() {

}

bool Character::isAlive () {
    if (this->pointsLive > 0) {
        return true;
    }
    return false;
}

double Character::distance (Character* other) {
    return this->pos.distance(other->pos); // distance of point class
}

void Character::hit (int num) {
    if (this->getPointsLive() > 0) {
        this->pointsLive -= num;
    }
    if (this->getPointsLive() < 0) {
        this->pointsLive = 0;
    }
}

string Character::getName () {
    return this->name;
}

Point Character::getLocation () {
    return this->pos;
}

int Character::getPointsLive () {
    return this->pointsLive;
}

string Character::print () {
    return "";
}

bool Character::operator== (Character other) {
    if (this->getName() == other.getName()) {
        return true;
    }
    return false;
}