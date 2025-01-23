#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
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
    Flight *flights;
    int size;


    void selectionSort() {
        for (int i = 0; i < size; i++) {
            int min = i;
            for (int j = min + 1; j < size; j++) {
                if (flights[j].flight_number < flights[min].flight_number) {
                    min = j;
                }
            }
            swap(i, min);
        }
    }


    void swap(int a, int b) {
        Flight temp = flights[a];
        flights[a] = flights[b];
        flights[b] = temp;
    }

    void quickSort() {
        quickSort(0, size - 1);
    }

    void quickSort(int low, int high) {
        if (high <= low) {
            return;
        }
        int pivot = partition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }

    int partition(int low, int high) {
        int pivot = high;
        int i = low;
        for (int j = low; j < high; j++) {
            if (flights[j].flight_number < flights[pivot].flight_number) {
                swap(i, j);
                i++;
            }
        }
        swap(pivot, i);
        return i;
    }

    void mergeSort() {
        mergeSort(0, size - 1);
    }

    void mergeSort(int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }

    void merge(int low, int mid, int high) {
        int t1 = mid - low + 1;
        Flight *temp1 = new Flight[t1 + 1];
        int i = 0;
        for (int j = low; j <= mid; j++) {
            temp1[i] = flights[j];
            i++;
        }
        temp1[i] = Flight{"","", "ZZZZZZZ", 0};

        int t2 = high - mid;
        Flight* temp2 = new Flight[t2 + 1];
        i = 0;
        for (int j = mid + 1; j <= high; j++) {
            temp2[i] = flights[j];
            i++;
        }
        temp2[i] = Flight{"","", "ZZZZZZZ", 0};

        i = 0;
        int j = 0;
        for (int k = low; k <= high; k++) {
            if (temp1[i].flight_number < temp2[j].flight_number) {
                flights[k] = temp1[i];
                i++;
            }
            else {
                flights[k] = temp2[j];
                j++;
            }
        }
        delete[] temp1;
        delete[] temp2;
    }

//    Flight* arrayCopyWithInfinity() {
//        return;
//    }

    /*
     * This function prints out the total number of flights in the database, then it
     * will print out the first n lines and the last n lines of the database.
     *
     * @param n      The number of lines displayed in the head and the tail of the database
     */
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
};

/*
 * This function reads a csv file's information into a database object and returns it.
 * Each row is stored inside a Flight object and column values are stored inside the
 * object's attributes. The Flight objects are stored inside the flights attribute
 * (array) of the FlightDataBase object.
 *
 * @param filename      Name of the csv file we want to read
 * @return              FlightDataBase object containing the information read from the file
 */
FlightDataBase read_csv(string filename) {
    const int MAX_FLIGHTS = 100000;
    FlightDataBase flightDB;
    flightDB.flights = new Flight[MAX_FLIGHTS]; // Ideally we would have a dynamic array that resizes itself
    flightDB.size = 0;
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

            flightDB.flights[flightDB.size] = Flight{colValues[0], colValues[1], colValues[2], stof(colValues[3])};
            flightDB.size++;
        }
    }
    myFile.close();
    return flightDB;
}

int main() {
    // Question 1
    FlightDataBase flightDB = read_csv("Flights10_Winter2025.dat");
    cout << "---------------------- Question 1 ----------------------" << endl;
    flightDB.display(5);
    clock_t start = clock();
    flightDB.selectionSort();
    clock_t total = clock() - start;
    cout << "SELECTION sorting took " << total / CLOCKS_PER_SEC << "s" << endl;
    flightDB.display(5);
    start = clock();
    flightDB.selectionSort();
    total = clock() - start;
    cout << "SELECTION sorting RESORTING took " << total / CLOCKS_PER_SEC << "s" << endl;
    flightDB.display(5);
    delete[] flightDB.flights;

    // Question 2
    flightDB = read_csv("FlightsAll_Winter2025.dat");
    cout << "---------------------- Question 2 ----------------------" << endl;
    start = clock();
    flightDB.mergeSort();
    total = clock() - start;
    cout << "MERGE sorting took " << total / CLOCKS_PER_SEC << "s" << endl;
    flightDB.display(5);
    start = clock();
    flightDB.mergeSort();
    total = clock() - start;
    cout << "MERGE sorting RESORTING took " << total / CLOCKS_PER_SEC << "s" << endl;
    flightDB.display(5);
    delete[] flightDB.flights;

    // Question 3
    flightDB = read_csv("Flights10_Winter2025.dat");
    cout << "---------------------- Question 3 ----------------------" << endl;
    start = clock();
    flightDB.quickSort();
    total = clock() - start;
    cout << "QUICK sorting took " << total / CLOCKS_PER_SEC << "s" << endl;
    flightDB.display(5);
    start = clock();
    flightDB.quickSort();
    total = clock() - start;
    cout << "QUICK sorting RESORTING took " << total / CLOCKS_PER_SEC << "s" << endl;
    flightDB.display(5);
    delete[] flightDB.flights;

    // Question 4
    cout << "---------------------- Question 4 ----------------------" << endl;
    cout << "The second run of QuickSort is much slower because the list is already sorted. Since we were instructed to use the last element of the array as the pivot, we always choose the worst possible pivot when the array is sorted. Since the pivot isn't close to the median of the array, we're not actually dividing the problem into a much smaller one. Instead of approximately dividing the problem by 2, we are simply reducing the problem by one which means that it is no longer O(nlog(n)) but rather O(n^2)" << endl;
}