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

/**
* This function displays the first 5 flights of the file as well as the last
* 5 flights of the file.
*
* @param flights    The array containing all the flights of the file.
*/
void display(Flight * flights) {

    cout << "The first 5 flights are:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Flight #" << flights[i].flight_number << " from " <<
            flights[i].departure << " to " << flights[i].arrival << " costs " <<
                flights[i].price << "$" << endl;
    }
    cout << endl;
    cout << "The last 5 flights are:" << endl;
    for (int i = 5; i < 10; i++) {
        cout << "Flight #" << flights[i].flight_number << " from " <<
            flights[i].departure << " to " << flights[i].arrival << " costs " <<
                flights[i].price << "$" << endl;
    }
}

/**
* This function prints out the cheapest flight of the file.
*/
void cheapest_flight(Flight * flights) {
    float smallest = flights[0].price;

}

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
    }
    display(flights);
}