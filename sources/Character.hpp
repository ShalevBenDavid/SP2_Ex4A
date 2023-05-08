// Created by Shalev Ben David.

#ifndef SP2_EX4A_CHARACTER_H
#define SP2_EX4A_CHARACTER_H
#include <string>
#include <iostream>
#include "Point.hpp"

namespace ariel {
    class Character {
        // Private attributes.
        std :: string _name;
        Point _location;
        int _hit_points;
        bool _alive;

    public:
        // Constructors.
        Character(std :: string name, Point location) : _name(name), _location(location), _alive(true) {}

        // Methods.
        bool isAlive () const;
        double distance (Character* other) const;
        void hit (int amount);

        // Print method.
        virtual void print () const = 0;

        // Get methods.
        std :: string getName ();
        Point getLocation ();
        int getHitPoints ();
    }
}


#endif //SP2_EX4A_CHARACTER_H
