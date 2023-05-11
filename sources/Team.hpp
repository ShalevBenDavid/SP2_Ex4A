// Created by Shalev Ben David.

#ifndef SP2_EX4A_TEAM_H
#define SP2_EX4A_TEAM_H
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

const int NUM_OF_WARRIORS = 10;

namespace ariel {
    class Team {
    protected:
        std :: array <Character*, NUM_OF_WARRIORS> _warriors;
        Character* _leader;

    public:
        // Constructors.
        Team (Character* leader) : _leader(leader) {}

        // Destructor.
        ~Team () {}

        // Methods.
        virtual void add (Character*);
        virtual void attack (Team*);
        int stillAlive () const;

        // Print method.
        virtual void print() const;
    }
}

#endif //SP2_EX4A_TEAM_H
