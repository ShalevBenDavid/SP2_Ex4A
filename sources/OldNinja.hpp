// Created by Shalev Ben David.

#ifndef SP2_EX4A_OLDNINJA_H
#define SP2_EX4A_OLDNINJA_H
#include "Ninja.hpp"

const int OLD_NINJA_SPEED 8;
const int OLD_NINJA_HP 150;

namespace ariel {
    class OldNinja : public Ninja {

    public:
        // Constructors.
        OldNinja () : _speed(OLD_NINJA_SPEED), _hit_points(OLD_NINJA_HP) {}
    }
}

#endif //SP2_EX4A_OLDNINJA_H
