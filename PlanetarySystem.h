
#ifndef PLANETARY_SYSTEM_H
#define PLANETARY_SYSTEM_H

#include <vector>
#include <string>


class Planet {

private:

    // Variable definitions
    std::string name;
    double mass;
    double xPos;
    double yPos;
    double xVel;
    double yVel;


public:

    // Constructor
    Planet(std::string name, double mass, double xPos, double yPos, double xVel, double yVel);

    // Get methods
    std::string getName() const;
    double getMass() const;
    double getXPos() const;
    double getYPos() const;
    double getXVel() const;
    double getYVel() const;

    // Set methods
    void setMass(double mass);
    void setPosition(double xPos,double yPos);
    void setVelocity(double xVel, double yVel);

    // Update position based on vel and timeStep
    void updatePosition(double timeStep);


};

#endif