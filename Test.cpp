#include "doctest.h"
#include <stdexcept>
#include "Character.hpp"
#include "Team.hpp"
#include "Team2.hpp"
#include "SmartTeam.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
using namespace ariel;

TEST_CASE("check the point class") {
    Point p1(0,0);
    CHECK(p1.getX() == 0);
    CHECK(p1.getY() == 0);
    Point p2(1,7);
    CHECK(p2.getX() == 1);
    CHECK(p2.getY() == 7);
    Point p3(-1,-6.5);
    CHECK(p3.getX() == -1);
    CHECK(p3.getY() == -6.5);
    CHECK(p1.distance(p2) == p2.distance(p1));
    p1.setX(2);
    CHECK(p1.getX() == 2);
    p1.setY(2);
    CHECK(p1.getY() == 2);
    Point p4(0,0);
    Point p5(0,5);
    Point p6(0,4);
    CHECK(Point::moveTowards(p4, p5, 4) == p6);
    p5.setY(-5);
    p6.setY(-4);
    CHECK(Point::moveTowards(p4, p5, 4) == p6);
}

TEST_CASE("check the cowboy functions") {
    CHECK_THROWS(Cowboy("", Point(4,4)));
    Point p(0,0);
    Cowboy c1("Avihay", p);
    CHECK(c1.getLocation() == p);
    CHECK(c1.getName() == "Avihay");
    CHECK(c1.isAlive() == true);
    c1.hit(10);
    CHECK(c1.getPointsLive() == 100);
    CHECK(c1.hasboolets() == true);
    Cowboy c3("ahron", Point(5,5));
    for(int i = 0; i < 6; i++) {
        c1.shoot(&c3);
    }
    CHECK(c3.getPointsLive() == 40);
    CHECK(c1.hasboolets() == false);
    c1.reload();
    CHECK(c1.hasboolets() == true);
    Cowboy c2("Finish", Point(2,2));
    CHECK(c1.distance(&c2) == c2.distance(&c1));
    c1.hit(100);
    CHECK(c1.isAlive() == false);
}

TEST_CASE("check the oldNinja functions") {
    CHECK_THROWS(OldNinja("", Point(0,0)));
    Point p(0,0);
    OldNinja o1("Avihay", p);
    CHECK(o1.getLocation() == p);
    CHECK(o1.getName() == "Avihay");
    CHECK(o1.isAlive() == true);
    o1.hit(10);
    CHECK(o1.getPointsLive() == 140);
    OldNinja o2("Avihay", Point(0,8.5));
    o1.move(&o2);
    Point p1(0,8);
    CHECK(o1.getLocation() == p1);
    o1.slash(&o2);
    CHECK(o2.getPointsLive() == 110);
    o1.hit(140);
    CHECK(o1.isAlive() == false);
}

TEST_CASE("check the TrainedNinja functions") {
    CHECK_THROWS(TrainedNinja("", Point(0,0)));
    Point p(0,0);
    TrainedNinja o1("Avihay", p);
    CHECK(o1.getLocation() == p);
    CHECK(o1.getName() == "Avihay");
    CHECK(o1.isAlive() == true);
    o1.hit(10);
    CHECK(o1.getPointsLive() == 110);
    TrainedNinja o2("Avihay", Point(0,12.5));
    o1.move(&o2);
    Point p1(0,12);
    CHECK(o1.getLocation() == p1);
    o1.slash(&o2);
    CHECK(o2.getPointsLive() == 80);
    o1.hit(110);
    CHECK(o1.isAlive() == false);
}

TEST_CASE("check the YoungNinja functions") {
    CHECK_THROWS(YoungNinja("", Point(0,0)));
    Point p(0,0);
    YoungNinja o1("Avihay", p);
    CHECK(o1.getLocation() == p);
    CHECK(o1.getName() == "Avihay");
    CHECK(o1.isAlive() == true);
    o1.hit(10);
    CHECK(o1.getPointsLive() == 90);
    OldNinja o2("Avihay", Point(0,14.5));
    o1.move(&o2);
    Point p1(0,14);
    CHECK(o1.getLocation() == p1);
    o1.slash(&o2);
    CHECK(o2.getPointsLive() == 60);
    o1.hit(90);
    CHECK(o1.isAlive() == false);
}

TEST_CASE("check the team functions") {
    Cowboy c1("Avihay", Point(0,0));
    OldNinja o1("Finish", Point(0,1));
    TrainedNinja t1("Ahron", Point(0,2));
    YoungNinja y1("Nifish", Point(0,3));
    Team a(&c1);
    CHECK(a.getLeader() == c1);
    a.add(&o1);
    a.add(&t1);
    a.add(&y1);
    Cowboy *shinif = new Cowboy("enemy", Point(0,10));
    CHECK_THROWS(a.setLeader(shinif));
    CHECK_NOTHROW(a.setLeader(&o1));
    CHECK(a.getLeader() == o1);
    c1.hit(100);
    CHECK(a.stillAlive() == 3);
    Cowboy c2("Avihay", Point(0,-1));
    OldNinja o2("Finish", Point(0,-3));
    TrainedNinja t2("Ahron", Point(0,-5));
    YoungNinja y2("Nifish", Point(0,9));
    Team b(&c2);
    a.attack(&b);
    CHECK(y2.getPointsLive() == 90);
    CHECK(o1.getLocation() == Point(0,2));
    CHECK(t1.getLocation() == Point(0,3));
    CHECK(y1.getLocation() == Point(0,4));
    shinif->hit(100);
    CHECK(shinif->isAlive() == false);
    a.attack(&b);
    CHECK(a.getLeader() == y1);
}
