// Created by Shalev Ben David.

#include "Point.hpp"
#include <iostream>
using namespace ariel;

/**
 * @param other - other point
 * @return - the distance between this and other
 */
double Point :: distance (Point other) const {
    return sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2));
}

/**
 * @param source - source point
 * @param dest - destination point
 * @param dist - distance
 * @return - the closest point to dest such that the distance between it and source < dist
 */
Point Point :: moveTowards (Point source, Point dest, double dist) {
    if (dist < 0) {
        throw std :: invalid_argument ("Distance can't be negative!");
    }
    // If "dest" is already at distance "dist" or less, return it.
    if (distance(dest) <= dist) {
        return dest;
    }
}

/**
 * print point in the form (x,y)
 */
void Point :: print () const {
    cout << "(" << _x << ", " << _y << ")";
}

/**
 * @return - string representing the point
 */
string Point :: toString () const {
    string info;
    info = "(" +  to_string(_x) + ", " +  to_string(_y) + ")";
    return info;
}