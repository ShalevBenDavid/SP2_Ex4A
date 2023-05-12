// Created by Shalev Ben David.

#ifndef SP2_EX4A_TEAM2_H
#define SP2_EX4A_TEAM2_H
#include "Team.hpp"

namespace ariel {
    class Team2 : public Team {

    public:
        Team2 (Character* leader) : Team(leader) {}

        // Methods.
        virtual void attack (Team *);

        // Print method.
        virtual void print() const;
    }
}

#endif //SP2_EX4A_TEAM2_H
