#include "StarSystem.h"

Star::Star(std::string name, double mass, double xPos, double yPos, double xVel, double yVel,
    double temp, double radius, double luminosity, double age, char spectralType)
    : name(name), mass(mass), xPos(xPos), yPos(yPos), xVel(xVel), yVel(yVel), temp(temp),
    radius(radius), luminosity(luminosity), age(age), spectralType(spectralType) {}

// Get Methods
std::string Star::getName() const {
    return name;
}

double Star::getMass() const {
    return mass;
}

double Star::getXPos() const {
    return xPos;
}

double Star::getYPos() const {
    return yPos;
}

double Star::getXVel() const {
    return xVel;
}

double Star::getYVel() const {
    return yVel;
}

double Star::getTemp() const {
    return temp;
}

double Star::getRadius() const {
    return radius;
}

double Star::getLuminosity() const {
    return luminosity;
}

double Star::getAge() const {
    return age;
}

char Star::getSpectralType()  const {
    return spectralType;
}

// Set methods

void Star::setMass(double mass) {
    this->mass = mass;
}

void Star::setPosition(double xPos, double yPos) {
    this->xPos = xPos;
    this->yPos = yPos;
}

void Star::setVelocity(double xVel, double yVel) {
    this->xVel = xVel;
    this->yVel = yVel;
}

void Star::setTemp(double temp) {
    this->temp = temp;
}

void Star::setRadius(double radius) {
    this->radius = radius;
}

void Star::setLuminosity(double luminosity) {
    this->luminosity = luminosity;
}

void Star::setAge(double age) {
    this->age = age;
}

void Star::setSpectralType(char spectralType) {
    this->spectralType = spectralType;
}

void Star::updatePosition(double timeStep) {
    xPos += xVel * timeStep;
    yPos += yVel * timeStep;
}