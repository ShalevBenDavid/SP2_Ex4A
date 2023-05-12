// Created by Shalev Ben David.

#ifndef SP2_EX4A_NINJA_H
#define SP2_EX4A_NINJA_H
#include "Character.hpp"

const int NINJA_DAMAGE = 13;

namespace ariel {
    class Ninja : public Character {
    private:
        int _speed;

    public:
        // Constructors.
        Ninja (const std :: string& name, Point& location, int hit_points, int speed) :
            Character(name, location, hit_points), _speed(speed) {}

        // Methods.
        void slash (Character *) const;
        void move (Character *);

        // Print method.
        virtual std :: string print () const override;

        // Get methods.
        int getSpeed () const;
    }
}

#endif //SP2_EX4A_NINJA_H