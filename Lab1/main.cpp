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

struct FlightDataBase {
    Flight* flights;
    int size;
};

float cheapest_flight(FlightDataBase flightDB) {
    Flight cheapest = flightDB.flights[0];
    for (int i = 0; i < flightDB.size; i++) {
        if (flightDB.flights[i].price < cheapest.price) {
            cheapest = flightDB.flights[i];
        }
    }
    cout << "The cheapest flight is flight #" << cheapest.flight_number <<
        " from " << cheapest.departure << " to " << cheapest.arrival << " at " <<
            cheapest.price << "$" << endl;
    cout << endl;
    return cheapest.price;
}

int total_flights(FlightDataBase flightDB, string city) {
    int count = 0;
    for (int i = 0; i < flightDB.size; i++) {
        if (flightDB.flights[i].departure == city) {count++;}
        if (flightDB.flights[i].arrival == city) {count++;}
    }
    cout << "There is " << count << " flight arriving at or leaving from " << city << endl;
    cout << endl;
    return count;
}

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
    cout << endl;
}

FlightDataBase read_csv(string filename) {
    const int MAX_FLIGHTS = 100000;
    FlightDataBase flightDB;
    flightDB.flights = new Flight[MAX_FLIGHTS];
    int flight_index = 0;
    ifstream myFile;
    string line;
    myFile.open(filename, ios::in);

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
            flightDB.flights[flight_index] = Flight{departure, arrival, flight_number, price};
            flight_index++;
            flightDB.size++;
        }
    }
    myFile.close();
    return flightDB;
}

int main() {
    FlightDataBase flightDB = read_csv("Flights10_Winter2025.dat");
    display(flightDB.flights);
    cheapest_flight(flightDB);
    total_flights(flightDB, "Jacksonville");
    total_flights(flightDB, "Liverpool");
    total_flights(flightDB, "Amsterdam");
    total_flights(flightDB, "Kingston");
}