#include "Point.hpp"
#include <cmath>
#include <iostream>
using namespace ariel;
using namespace std;

Point::Point (double xPos, double yPos) : xPos(xPos), yPos(yPos) {

}

double Point::getX () {
    return this->xPos;
}

double Point::getY () {
    return this->yPos;
}

void Point::setX (double xPos) {
    this->xPos = xPos;
}

void Point::setY (double yPos) {
    this->yPos = yPos;
}

double Point::distance (Point pos) {
    double xSub = (this->getX() - pos.getX());
    double ySub = (this->getY() - pos.getY());
    double xPow = pow(xSub, 2);
    double yPow = pow(ySub, 2);
    return sqrt(xPow + yPow);
}

Point Point::moveTowards (Point source, Point target, double dis) {
    double xNew = target.getX() - source.getX() + dis;
    double yNew = target.getY() - source.getY() + dis;
    return Point(xNew, yNew);
}

void Point::print () {
    cout << "(" << this->getX() << ", " << this->getY() << ")" << endl;
}

bool Point::operator== (Point other) {
    if (this->getX() == other.getX() && this->getY() == other.getY()) {
        return true;
    }
    return false;
}