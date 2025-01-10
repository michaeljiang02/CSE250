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

Flight cheapest_flight(FlightDataBase flightDB) {
    Flight cheapest = flightDB.flights[0];
    for (int i = 0; i < flightDB.size; i++) {
        if (flightDB.flights[i].price < cheapest.price) {
            cheapest = flightDB.flights[i];
        }
    }
    cout << "The cheapest flight is flight #" << cheapest.flight_number <<
        " from " << cheapest.departure << " to " << cheapest.arrival << " at " <<
            cheapest.price << "$\n" << endl;
    return cheapest;
}

int total_flights(FlightDataBase flightDB, string city) {
    int count = 0;
    for (int i = 0; i < flightDB.size; i++) {
        if (flightDB.flights[i].departure == city) {count++;}
        if (flightDB.flights[i].arrival == city) {count++;}
    }
    cout << "There is " << count << " flight arriving at or leaving from " << city << endl;
    return count;
}

float average_price(FlightDataBase flightDB, string city) {
    int count = 0;
    float sum = 0;
    for (int i = 0; i < flightDB.size; i++) {
        if (flightDB.flights[i].departure == city) {
            sum += flightDB.flights[i].price;
            count++;
        }
    }
    if (count == 0) {
        cout << "There is no flight leaving " << city << endl;
        return 0;
    }
    float average = sum / count;
    cout << "The average price to leave " << city << " is " << average << "$" << endl;
    return average;

}

void display(FlightDataBase flightDB, int n) {
    cout << flightDB.size << "flights loaded\n" << endl;
    cout << "The first " << n << " flights are:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Flight #" << flightDB.flights[i].flight_number << " from " <<
            flightDB.flights[i].departure << " to " << flightDB.flights[i].arrival << " costs " <<
                flightDB.flights[i].price << "$" << endl;
    }
    cout << endl;
    cout << "The last " << n << " flights are:" << endl;
    for (int i = flightDB.size - n; i < flightDB.size; i++) {
        cout << "Flight #" << flightDB.flights[i].flight_number << " from " <<
            flightDB.flights[i].departure << " to " << flightDB.flights[i].arrival << " costs " <<
                flightDB.flights[i].price << "$" << endl;
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
            string colValues[4];
            stringstream ss(line);
            for (int i = 0; i < 4; i++) {
                getline(ss, colValues[i], ',');
            }

            flightDB.flights[flight_index] = Flight{colValues[0], colValues[1], colValues[2], stof(colValues[3])};
            flightDB.size++;
            flight_index++;
        }
    }
    myFile.close();
    return flightDB;
}

int main() {
    // Question 1
    FlightDataBase flightDB = read_csv("Flights10_Winter2025.dat");
    display(flightDB, 5);

    // Question 2
    cheapest_flight(flightDB);

    // Question 3
    total_flights(flightDB, "Jacksonville");
    total_flights(flightDB, "Liverpool");
    total_flights(flightDB, "Amsterdam");
    total_flights(flightDB, "Kingston");
    cout << endl;

    // Question 4
    average_price(flightDB, "Liverpool");
    average_price(flightDB, "Jacksonville");
    average_price(flightDB, "Kingston");
}