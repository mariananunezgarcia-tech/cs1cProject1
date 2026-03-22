#ifndef EXCEPTIONSCLASSHEADER_H
#define EXCEPTIONSCLASSHEADER_H
#include <exception>
#include <string>
#include <iostream>
using namespace std;

class DeviceException : public exception
{
public:
    DeviceException(const string& errorMessage);
    const char* what() const noexcept override;

private:
    string error;
};

#endif