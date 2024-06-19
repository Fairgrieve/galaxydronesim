#include "PlanetarySystem.h"

Planet::Planet(std::string name, double mass, double xPos, double yPos, double xVel, double yVel)
    : name(name), mass(mass), xPos(xPos), yPos(yPos), xVel(xVel), yVel(yVel) {}


// Get Methods
std::string Planet::getName() const {
    return name;
}

double Planet::getMass() const {
    return mass;
}

double Planet::getXPos() const {
    return xPos;
}

double Planet::getYPos() const {
    return yPos;
}

double Planet::getXVel() const {
    return xVel;
}

double Planet::getYVel() const {
    return yVel;
}

// Set methods

void Planet::setMass(double mass) {
    this->mass = mass;
}

void Planet::setPosition(double xPos, double yPos) {
    this->xPos = xPos;
    this->yPos = yPos;
}

void Planet::setVelocity(double xVel, double yVel) {
    this->xVel = xVel;
    this->yVel = yVel;
}


void Planet::updatePosition(double timeStep) {
    xPos += xVel * timeStep;
    yPos += yVel * timeStep;
}