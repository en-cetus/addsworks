#include "Reverser.h"
#include <iostream>
#include <string>
using namespace std;



int Reverser::reverseDigit(int value) {
    return reverseHelper(value, 0);
};

string Reverser::reverseString(string characters) {
    //base case
    if (characters.length() <= 1){
        return characters;
    }else{
        //arrange
        char num1char = characters[0];
        string leastnum = characters.substr(1);
        string reversstring = reverseString(leastnum);

        return reversstring + num1char;
    }
};


int Reverser::reverseHelper(int remaining, int reversed) {
    if (remaining == 0) {
        return reversed;
    }
    //calculate
        return reverseHelper(remaining / 10, reversed * 10 + remaining % 10);
}


//int main() {
//    // Create an instance of the Reverser class
//    Reverser reverser;
//    
//    int num;
//    cout << "Enter a non-negative integer: ";
//    cin >> num;
//    
//    // Reverse the digits of the input number
//    int reversedNum = reverser.reverseDigit(num);
//    if (reversedNum == -1) {
//        cout << "Invalid input for reverseDigit" << endl;
//    } else {
//        cout << "Reversed number: " << reversedNum << endl;
//    }
//    
//    string str;
 //   cout << "Enter a string: ";
//    cin >> str;
//    
//    // Reverse the characters of the input string
//    string reversedStr = reverser.reverseString(str);
//    if (reversedStr == "ERROR") {
//        cout << "Invalid input for reverseString" << endl;
//    } else {
//        cout << "Reversed string: " << reversedStr << endl;
//    }
//    
//    return 0;
//}