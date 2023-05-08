// Created by Shalev Ben David.

#include "Point.hpp"
#include <iostream>
using namespace ariel;

/**
 * @param other - other point
 * @return - the distance between this and other
 */
double Point :: distance (Point other) {
    return sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2));
}

/**
 * @param source - source point
 * @param dest - destination point
 * @param dist - distance
 * @return - the closest point to dest such that the distance between it and source < dist
 */
Point Point :: moveTowards (Point source, Point dest, double dist) { }

/**
 * print point in the form (x,y)
 */
void Point :: print () {
    cout << "(" << _x << ", " << _y << ")";
}

/**
 * @return - string representing the point
 */
string Point :: toString() {
    string info;
    info = "(" +  to_string(_x) + ", " +  to_string(_y) + ")";
    return info;
}