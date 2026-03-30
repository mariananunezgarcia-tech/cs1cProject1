#ifndef EXCEPTIONSCLASSHEADER_H
#define EXCEPTIONSCLASSHEADER_H
#include <exception>
#include <string>
#include <iostream>
using namespace std;

// --- general exception ---
class DeviceException : public exception
{
public:
    DeviceException(const string& errorMessage); // displays the error message as a string

    // overrides what() (inherited from stl exception) with custom string message
    // noexcept -> prevents an exception being thrown within itself
    // returns a char string (cstring)
    const char* what() const noexcept override; 

protected: // allows other inherited classes to access
    string error;
};

// --- exception thrown when device is off ---
class PowerException : public DeviceException
{
public:
    PowerException(const string& deviceName); // displays the error message with device as a string
};


// --- exception thrown when user enters an invalid input ---
class InvalidInputException : public DeviceException
{
public:
    InvalidInputException(const string& errorMessage); // displays the error mesage as a string
};

#endif