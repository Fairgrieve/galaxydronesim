#pragma once
#ifndef STAR_SYSTEM_H
#define STAR_SYSTEM_H

#include <vector>
#include <string>


class Star {

private:

    std::string name;
    double mass;
    double xPos;
    double yPos;
    double xVel;
    double yVel;
    double temp;
    double radius;
    double luminosity;
    double age;
    char spectralType;

public:

    Star(std::string name, double mass, double xPos, double yPos, double xVel, double yVel, double temp, double radius,
        double luminosity, double age, char spectralType);

    std::string getName() const;
    void setName(std::string name);

    double getMass() const;
    void setMass(double mass);
    
    double getXPos() const;
    double getYPos() const;
    double getXVel() const;
    double getYVel() const;

    double getTemp() const;
    void setTemp(double temp);

    double getRadius() const;
    void setRadius(double radius);

    double getLuminosity() const;
    void setLuminosity(double luminosity);

    double getAge() const;
    void setAge(double age);

    char getSpectralType() const;
    void setSpectralType(char spectralType);

    void setPosition(double xPos, double yPos);
    void setVelocity(double xVel, double yVel);

    void updatePosition(double timeStep);

};

#endif

