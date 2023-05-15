// Created by Shalev Ben David.

#ifndef SP2_EX4A_CHARACTER_H
#define SP2_EX4A_CHARACTER_H
#include <string>
#include <iostream>
#include "Point.hpp"

namespace ariel {
    class Character {
    protected:
        std :: string _name;
        Point _location;
        int _hit_points;
        bool _alive;
        bool _in_team;

    public:
        // Constructors.
        Character (const std :: string& name, Point& location, int hit_points) :
            _name(name), _location(location), _hit_points(hit_points), _alive(true), _in_team(false) {}

        // Destructor.
        virtual ~Character() = default;

        // Methods.
        bool isAlive () const;
        double distance (Character*) const;
        void hit (int);

        // Print method.
        virtual std :: string print () const = 0;

        // Get methods.
        std :: string getName () const;
        Point getLocation () const;
        int getHitPoints () const;
        bool& getInTeam ();
    };
}

#endif //SP2_EX4A_CHARACTER_H
