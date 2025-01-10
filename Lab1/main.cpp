#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/**
 * The Flight struct stores all the information needed for flights, each
 * column value in the csv file is stored into the attributes of Flight
 * and each row in the csv file is a unique flight.
 */
struct Flight {
    string departure;
    string arrival;
    string flight_number;
    float price;
};

struct FlightDataBase {
    Flight* flights;
    int size;

    Flight cheapest_flight() {
        Flight cheapest = flights[0];
        for (int i = 0; i < size; i++) {
            if (flights[i].price < cheapest.price) {
                cheapest = flights[i];
            }
        }
        cout << "The cheapest flight is flight #" << cheapest.flight_number <<
            " from " << cheapest.departure << " to " << cheapest.arrival << " at " <<
                cheapest.price << "$\n" << endl;
        return cheapest;
    }

    int total_flights(string city) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (flights[i].departure == city) {count++;}
            if (flights[i].arrival == city) {count++;}
        }
        cout << "There is " << count << " flight arriving at or leaving from " << city << endl;
        return count;
    }

    float average_price(string city) {
        int count = 0;
        float sum = 0;
        for (int i = 0; i < size; i++) {
            if (flights[i].departure == city) {
                sum += flights[i].price;
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

    void display(int n) {
        cout << size << " flights loaded\n" << endl;
        cout << "The first " << n << " flights are:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Flight #" << flights[i].flight_number << " from " <<
                flights[i].departure << " to " << flights[i].arrival << " costs " <<
                    flights[i].price << "$" << endl;
        }
        cout << endl;
        cout << "The last " << n << " flights are:" << endl;
        for (int i = size - n; i < size; i++) {
            cout << "Flight #" << flights[i].flight_number << " from " <<
                flights[i].departure << " to " << flights[i].arrival << " costs " <<
                    flights[i].price << "$" << endl;
        }
        cout << endl;
    }

    void sort() {
        helperSort(0, size);
    }

private:
    void helperSort(int current_index, int length) {
        if (length == 1) {
            return;
        }
        int smallest_index = find_smallest_index(current_index);
        swap(current_index, smallest_index);
        if (flights[current_index].flight_number > flights[smallest_index].flight_number) {
            swap(current_index, smallest_index);
        }
        helperSort(current_index + 1, length - 1);
    }

    void swap(int a, int b) {
        Flight tmp = flights[a];
        flights[a] = flights[b];
        flights[b] = tmp;
    }

    int find_smallest_index(int start_index) {
        int smallest_index = start_index;
        for (int i = start_index; i < size; i++) {
            if (flights[i].flight_number < flights[smallest_index].flight_number) {
                smallest_index = i;
            }
        }
        return smallest_index;
    }

};

FlightDataBase read_csv(string filename) {
    const int MAX_FLIGHTS = 100000;
    FlightDataBase flightDB;
    flightDB.flights = new Flight[MAX_FLIGHTS]; // Ideally we would have a dynamic array that resizes itself
    int flight_index = 0;
    ifstream myFile;
    string line;
    myFile.open(filename, ios::in);

    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            string colValues[4]; // Declare an array to hold the 4 column values
            stringstream ss(line);
            for (int i = 0; i < 4; i++) {
                getline(ss, colValues[i], ','); // Store each comma separated value into the array
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
    FlightDataBase flightDB = read_csv("FlightsAll_Winter2025.dat");
    flightDB.display(5);

    // Question 2
    flightDB.cheapest_flight();

    // Question 3
    flightDB.total_flights("Jacksonville");
    flightDB.total_flights("Liverpool");
    flightDB.total_flights("Amsterdam");
    flightDB.total_flights("Kingston");
    cout << endl;

    // Question 4
    flightDB.average_price("Liverpool");
    flightDB.average_price("Jacksonville");
    flightDB.average_price( "Kingston");
    cout << endl;

    // Question 5
    flightDB.sort();
    flightDB.display(10);
}