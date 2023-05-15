// Created by Shalev Ben David.

#ifndef SP2_EX4A_POINT_H
#define SP2_EX4A_POINT_H
#include <string>

namespace ariel {
    class Point {
    private:
        double _px;
        double _py;

    public:
        // Constructors.
        Point (double x = 0, double y = 0) : _px(x), _py(y) {}

        // Methods.
        double distance (Point other) const;
        static Point moveTowards (Point source, Point dest, double dist);

        // Print method.
        void print () const;

        // toString method.
        std :: string toString () const;

        // Get && Set methods.
        double& getX () { return _px; }
        double& getY () { return _py; }
    };
}

#endif //SP2_EX4A_POINT_H