#pragma once

namespace ariel {

    class Point
    {
    private:
        double xPos;
        double yPos;
    public:
        Point (double xPos, double yPos);
        double getX ();
        double getY ();
        void setX (double xPos);
        void setY (double yPos);
        double distance (Point pos);
        void print ();
        bool operator== (Point other);
        static Point moveTowards (Point source, Point target, double dis);
    }; 
}