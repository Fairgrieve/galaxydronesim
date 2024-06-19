#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include "PlanetarySystem.h"
#include "StarSystem.h"
#include <stdio.h>

// This function sets up the CUDA environment and allocates memory.
cudaError_t initializeCuda();

// Main function
int main()
{
    cudaError_t cudaStatus = initializeCuda();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "initializeCuda failed!");
        return 1;
    }

    // Create some planets
    Planet earth("Earth", 5.972e24, 1.496e8, 0.0, 0.0, 29.78);
    Planet mars("Mars", 0.64171e24, 2.279e8, 0.0, 0.0, 24.077);

    // Create some stars
    Star sun("Sun", 1.989e30, 0.0, 0.0, 0.0, 0.0, 5778, 1.0, 1.0, 4.603e9, 'G');
    Star sirius("Sirius", 2.063e30, 8.6e16, 0.0, 0.0, 0.0, 9940, 1.711, 25.4, 2.5e8, 'A');

    // Output the names of the planets and stars
    printf("Planet 1: %s\n", earth.getName().c_str());
    printf("Planet 2: %s\n", mars.getName().c_str());
    printf("Star 1: %s\n", sun.getName().c_str());
    printf("Star 2: %s\n", sirius.getName().c_str());

    // Test updating position for planets
    double timeStep = 1.0; // 1 second
    earth.updatePosition(timeStep);
    mars.updatePosition(timeStep);
    printf("After 1 second:\n");
    printf("Earth position: (%.2f, %.2f)\n", earth.getXPos(), earth.getYPos());
    printf("Mars position: (%.2f, %.2f)\n", mars.getXPos(), mars.getYPos());

    // Test updating position for stars
    sun.updatePosition(timeStep);
    sirius.updatePosition(timeStep);
    printf("After 1 second:\n");
    printf("Sun position: (%.2f, %.2f)\n", sun.getXPos(), sun.getYPos());
    printf("Sirius position: (%.2f, %.2f)\n", sirius.getXPos(), sirius.getYPos());

    // Test setting new position and velocity for planets
    earth.setPosition(1.5e8, 0.0);
    earth.setVelocity(0.0, 29.78);
    mars.setPosition(2.3e8, 0.0);
    mars.setVelocity(0.0, 24.077);
    printf("After setting new position and velocity for planets:\n");
    printf("Earth new position: (%.2f, %.2f)\n", earth.getXPos(), earth.getYPos());
    printf("Earth new velocity: (%.2f, %.2f)\n", earth.getXVel(), earth.getYVel());
    printf("Mars new position: (%.2f, %.2f)\n", mars.getXPos(), mars.getYPos());
    printf("Mars new velocity: (%.2f, %.2f)\n", mars.getXVel(), mars.getYVel());

    // Test setting new position and velocity for stars
    sun.setPosition(0.0, 0.0);
    sun.setVelocity(0.0, 0.0);
    sirius.setPosition(8.6e16, 0.0);
    sirius.setVelocity(0.0, 0.0);
    printf("After setting new position and velocity for stars:\n");
    printf("Sun new position: (%.2f, %.2f)\n", sun.getXPos(), sun.getYPos());
    printf("Sun new velocity: (%.2f, %.2f)\n", sun.getXVel(), sun.getYVel());
    printf("Sirius new position: (%.2f, %.2f)\n", sirius.getXPos(), sirius.getYPos());
    printf("Sirius new velocity: (%.2f, %.2f)\n", sirius.getXVel(), sirius.getYVel());

    // Reset the device and free memory before exiting
    cudaStatus = cudaDeviceReset();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceReset failed!");
        return 1;
    }

    return 0;
}

// Helper function for initializing CUDA and allocating memory.
cudaError_t initializeCuda()
{
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed! Do you have a CUDA-capable GPU installed?");
        return cudaStatus;
    }

    // Allocate GPU buffers (this is just a placeholder, you'll need actual buffers for your project)
    // Example:
    // int *dev_buffer;
    // cudaStatus = cudaMalloc((void**)&dev_buffer, bufferSize * sizeof(int));
    // if (cudaStatus != cudaSuccess) {
    //     fprintf(stderr, "cudaMalloc failed!");
    //     return cudaStatus;
    // }

    return cudaStatus;
}

