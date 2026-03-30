#include "ExceptionsClassHeader.h"

// --- general exception ---
DeviceException::DeviceException(const string& errorMessage)
{
    error = errorMessage;
}

const char* DeviceException::what() const noexcept
{
    return error.c_str(); // converts string to cstring return type
}

// --- exception thrown when device is off ---
PowerException::PowerException(const string& deviceName) 
               : DeviceException(deviceName + " is OFF."){}


// --- exception thrown when user enters an invalid input ---
InvalidInputException::InvalidInputException(const string& errorMessage) 
                      : DeviceException("Invalid Input: " + errorMessage){}