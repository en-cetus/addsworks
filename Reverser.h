#ifndef REVERSER_H
#define REVERSER_H

#include <string>
using namespace std;

class Reverser {
public:
    int reverseDigit(int value);
    string reverseString(string characters);

private:
    int reverseHelper(int remaining, int reversed);
};

#endif
