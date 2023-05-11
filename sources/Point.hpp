// Created by Shalev Ben David.

#ifndef SP2_EX4A_POINT_H
#define SP2_EX4A_POINT_H
#include <string>

namespace ariel {
    class Point {
    protected:
        double _x;
        double _y;

    public:
        // Constructors.
        Point (double x, double y) : _x(x), _y(y) {}

        // Methods.
        double distance (Point other) const;
        Point moveTowards (Point source, Point dest, double dist) const;

        // Print method.
        void print () const;

        // toString method.
        std :: string toString () const;
    }
}

#endif //SP2_EX4A_POINT_H
