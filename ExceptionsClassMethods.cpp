#include "ExceptionsClassHeader.h"

DeviceException::DeviceException(const string& errorMessage)
{
    error = errorMessage;
}

const char* DeviceException::what() const noexcept
{
    return error.c_str();
}