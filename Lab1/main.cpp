#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Flight {
    string departure;
    string arrival;
    string flight_number;
    float price;
};

int main() {
    string line;
    ifstream myFile;
    myFile.open("Flights10_Winter2025.dat", ios::in);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            cout << line << endl;
        }
        myFile.close();
    }
}