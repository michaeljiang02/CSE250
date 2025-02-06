#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
using namespace std;

int global_count = 0;

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

class FlightDataBase {
public:
    Flight *flights;
    int size;

    /*
     * This function sorts the entire database in lexicographical order based on each flight's
     * flight number. It uses selection sort, it takes no arguments and returns nothing.
     */
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

    /*
     * This is the driver function that kicks off the recursive quick sort process. It takes no arguments and returns nothing
     * it simply calls the helper function.
     */
    void quickSort() {
        quickSort(0, size - 1);
    }

    /*
     * This is the driver function that kicks off the recursive merge sort process. It takes no arguments and returns nothing
     * it simply calls the helper function.
     */
    void mergeSort() {
        mergeSort(0, size - 1);
    }

    /*
     * This function searches for a specific flight by its flight number using binary search. It is O(log(n)).
     *
     * @param flightNumber      The flight number of the flight we want to search
     * @return                  Flight object with the inputted flight number or a Flight object
     *                          with no attributes if not flight has the flight number.
     */
    Flight binarySearch(string flightNumber) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (flightNumber == flights[mid].flight_number) {
                return flights[mid];
            }
            if (flightNumber > flights[mid].flight_number) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return Flight{"","", "", 0};
    }

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

private:
    /*
    * This function swaps two flights in the database by their indices.
    *
    * @param a      Index of the first object we want to swap.
    * @param b      Index of the second object we want to swap.
    */
    void swap(int a, int b) {
        Flight temp = flights[a];
        flights[a] = flights[b];
        flights[b] = temp;
    }

    /*
    * This is the helper function of the recursive merge sort function. It recursively
    * calls itself, dividing the problem in two, until each subarray have only one element and merges them back together
    * in sorted order.
    *
    * @param low        The index of the lower bound of the subarray.
    * @param high       The index of the upper bound of the subarray.
    */
    void mergeSort(int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }

    /*
    * The merge function divides a subarray of the original array into two sorted arrays,
    * it then compares each element of both arrays one by one, and adds the smaller
    * value object to the original array until the "infinity" object is reached on both arrays.
    *
    * @param low        The index of the lower bound of the subarray.
    * @param mid        The index of the middle point of the subarray.
    * @param high       The index of the upper bound of the subarray.
    */
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

void flightDetails(Flight flight, string flight_number) {
    if (flight.flight_number == "") {
        cout << "The flight " << flight_number << " does not exist!" << endl;
    }
    else {
        cout << "The flight " << flight.flight_number << " leaves " << flight.departure << " for " << flight.arrival << " and cost " << flight.price << "$" << endl;
    }
}

void list_binary_strings(char* array, int n, int current) {
    if (current == n) {
        cout << array << endl;
        return;
    }
    array[current] = '0';
    list_binary_strings(array, n, current + 1);
    array[current] = '1';
    list_binary_strings(array, n, current + 1);
}

void list_binary_strings(int n) {
    char A[n + 1];
    A[n] = '\0';
    list_binary_strings(A, n, 0);
    delete[] A;
}

int RecurF(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    global_count++;
    return RecurF(n - 1) + RecurF(n - 2);
}

int IterF(int n) {
    int* FibArray = new int[n + 1];
    FibArray[0] = 0;
    if (n >= 1) {
        FibArray[1] = 1;
    }
    for (int i = 2; i <= n; i++) {
        FibArray[i] = FibArray[i - 1] + FibArray[i - 2];
        global_count++;
    }
    int result = FibArray[n];
    delete [] FibArray;
    return result;
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

    // Question 4
    cout << "---------------------- Question 4 ----------------------" << endl;
    cout << "The second run of QuickSort is much slower because the list is already sorted. Since we were instructed to use the last element of the array as the pivot, we always choose the worst possible pivot when the array is sorted. Since the pivot isn't close to the median of the array, we're not actually dividing the problem into a much smaller one. Instead of approximately dividing the problem by 2, we are simply reducing the problem by one which means that it is no longer O(nlog(n)) but rather O(n^2)" << endl;
    cout << endl;

    // Question 5
    cout << "---------------------- Question 5 ----------------------" << endl;
    Flight flight1 = flightDB.binarySearch("US0842");
    flightDetails(flight1, "US0842");

    Flight flight2 = flightDB.binarySearch("FL0044");
    flightDetails(flight2, "FL0044");

    Flight flight3 = flightDB.binarySearch("GH2333");
    flightDetails(flight3, "GH2333");

    delete[] flightDB.flights;

    cout << endl;

    // Question 6
    cout << "---------------------- Question 6 ----------------------" << endl;
    list_binary_strings(5);
    cout << endl;

    // Question 7
    cout << "---------------------- Question 7 ----------------------" << endl;
    int n = 12;
    cout << "The first " << n << " F numbers computed recursively are ";
    for (int i = 0; i < n; i++) {
        cout << RecurF(i) << ",";
    }
    cout << " it used " << global_count << " additions" << endl;

    global_count = 0;
    cout << "The first " << n << " F numbers computed iteratively are ";
    for (int i = 0; i < n; i++) {
        cout << IterF(i) << ",";
    }
    cout << " it used " << global_count << " additions" << endl;
    cout << endl;

    cout << "The recursive version takes much more additions because it needs to call the function recursively until n becomes 1 every time it calls the function for an n bigger than 2. The issue with this is that the essence of recursion lies in reusing the solution of a smaller n, however, with recursion, even if we already know return value of the function with a smaller input, we still compute it again. For example, fib(4) needs fib(3) which needs fib(2) which needs fib(1), but we shouldn't recompute fib(2) if we already have the answer from a previous computation. This issue can be fixed through caching. The iterative version does not have this problem because each return value is stored inside an array that can be immediately accessed." << endl;
}
