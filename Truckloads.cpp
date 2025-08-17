#include <iostream>
using namespace std;

class Truckloads {
public:
    int numTrucks(int numCrates,  int loadSize) {
        //basecase
        if (numCrates <= loadSize){
            return 1;
        }
        else {
            int pileLeft = numCrates / 2;
            int pileRight = numCrates - pileLeft;
            return numTrucks(pileLeft, loadSize) + numTrucks(pileRight, loadSize);
        }
    }

};

// int main() {
//     int numCrates, loadSize;
//     cout << "Enter number of crates: ";
//     cin >> numCrates;
//     cout << "Enter load size: ";
//     cin >> loadSize;

//     Truckloads tl;
//     int result = tl.numTrucks(numCrates, loadSize);

//     cout << "Number of trucks needed: " << result << endl;
//     return 0;
// }