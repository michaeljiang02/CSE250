#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Flight {
    string departure;
    string arrival;
    string flight_number;
    float price;
};


int main() {
    string line;
    Flight flights[10];
    int flight_index = 0;

    ifstream myFile;
    myFile.open("Flights10_Winter2025.dat", ios::in);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            string values[4];
            stringstream ss(line);
            for (int i = 0; i < 4; i++) {
                getline(ss, values[i], ',');
            }

            string departure = values[0];
            string arrival = values[1];
            string flight_number = values[2];
            float price = stof(values[3]);
            flights[flight_index] = Flight{departure, arrival, flight_number, price};
            flight_index++;
        }
        myFile.close();
        cout << flights[1].price << endl;
    }
}