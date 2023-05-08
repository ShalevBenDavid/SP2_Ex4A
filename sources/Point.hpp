// Created by Shalev Ben David.

#ifndef SP2_EX4A_POINT_H
#define SP2_EX4A_POINT_H
#include <string>

namespace ariel {
    class Point {
        // Private attributes.
        double _x;
        int _y;

    public:
        // Constructors.
        Point(double x, double y) : _x(x), _y(y) {}

        // Methods.
        double distance(Point other);
        Point moveTowards(Point source, Point dest, double dist);

        // Print method.
        void print();

        // toString method.
        std :: string toString();
    }
}

#endif //SP2_EX4A_POINT_H
