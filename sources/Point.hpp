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
        Point (double p_x = 0, double p_y = 0) : _px(p_x), _py(p_y) {}

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