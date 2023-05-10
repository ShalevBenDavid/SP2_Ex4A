// Created by Shalev Ben David.

#ifndef SP2_EX4A_TEAM_H
#define SP2_EX4A_TEAM_H
#include "Character.hpp"

const int NUM_OF_WARRIORS = 10;

namespace ariel {
    class Team {
    protected:
        Character* _warriors[NUM_OF_WARRIORS];

    public:
        // Constructors.
        Point (double x, double y) : _x(x), _y(y) {}

        // Methods.
        double distance(Point other);
        Point moveTowards(Point source, Point dest, double dist);

        // Print method.
        void print();

        // toString method.
        std :: string toString();
    }
}

#endif //SP2_EX4A_TEAM_H
