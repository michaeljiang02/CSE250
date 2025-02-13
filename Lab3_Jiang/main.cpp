#include <iostream>
#include <sstream>
#include <string>
#include "Queue.h"
#include "LinkedList.h"
#include "Stack.h"
using namespace std;

void Simulation(int QueueSize) {
    Queue Q1(QueueSize);
    cout << "Creating a queue of size " << QueueSize << endl << endl;
    int total = 0;
    int steps = 0;
    int number = 1;
    while (number <= 5) {
        cout << "Step #" << steps << ": Initial arrival #" << number << endl;
        Q1.Enqueue(number);
        Q1.PrintQueue();
        steps++;
        number++;
        total++;
    }
    while (total <= 3 * QueueSize) {
        // insert
        if (Q1.IsFull()) {
            cout << "Step #" << steps << ": Queue too long, person left" << endl;
            steps++;
        }

        Q1.Enqueue(number);
        cout << "Step #" << steps << ": Arrival #" << number << " inserted" << endl;
        Q1.PrintQueue();
        steps++;
        number++;
        total++;

        // dequeue
        if (Q1.IsEmpty()) {
            cout << "Step #" << steps << ": There is no one to serve" << endl;
            steps++;
        }

        int first;
        Q1.Dequeue(first);
        cout << "Step #" << steps << ": Processing #" << first << " successfully" << endl;
        Q1.PrintQueue();
        steps++;
        total++;
    }
}

double PostFixCalculator(const string &postfixeq) {
    int length = (postfixeq.size() + 1) / 2;
    string equation[length];
    stringstream ss(postfixeq);
    for (int i = 0; i < length; i++) {
        getline(ss, equation[i], ',');
    }
    Stack S = Stack();
    for (int i = 0; i < length; i++) {
        S.Push(equation[i]);
    }
}

int main()
{
    cout << "---------------- Question 2 ----------------" << endl << endl;
    cout << "Creating an empty queue of size 5" << endl;
    Queue Q1(5);
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "Adding 1 and 2 to the queue" << endl;
    cout << " Is adding 1 successful? " << Q1.Enqueue(1) << endl;
    cout << " Is adding 2 successful? " << Q1.Enqueue(2) << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "Adding 3, 4, 5, 6 to the queue (6 should fail)" << endl;
    cout << " Is adding 3 successful? " << Q1.Enqueue(3) << endl;
    cout << " Is adding 4 successful? " << Q1.Enqueue(4) << endl;
    cout << " Is adding 5 successful? " << Q1.Enqueue(5) << endl;
    cout << " Is adding 6 successful? " << Q1.Enqueue(6) << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    int old_value;

    cout << "Removing 1 and 2 from the queue" << endl;
    cout << " Is removing successful? " << Q1.Dequeue(old_value) << endl;
    cout << " Is removing successful? " << Q1.Dequeue(old_value) << endl;
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "Wrapping around 7 and 8" << endl;
    cout << " Is adding 7 successful? " << Q1.Enqueue(7) << endl;
    cout << " Is adding 8 successful? " << Q1.Enqueue(8) << endl;
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "Removing 3 to 7 (4 elements, including wrap around)" << endl;
    cout << " Is removing successful? " << Q1.Dequeue(old_value) << endl;
    cout << " Is removing successful? " << Q1.Dequeue(old_value) << endl;
    cout << " Is removing successful? " << Q1.Dequeue(old_value) << endl;
    cout << " Is removing successful? " << Q1.Dequeue(old_value) << endl;
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "Adding 9" << endl;
    cout << " Is adding 9 successful? " << Q1.Enqueue(9) << endl;
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "Emptying the list, removing one extra element, last one should fail " << endl;
    cout << " Is removing successful? " << Q1.Dequeue(old_value) << endl;
    cout << " Is removing successful? " << Q1.Dequeue(old_value) << endl;
    cout << " Is removing successful? " << Q1.Dequeue(old_value) << endl;
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "Adding 10" << endl;
    cout << " Is adding 10 successful? " << Q1.Enqueue(10) << endl;
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "The destructor cannot be tested, but it clearly deletes the allocated memory," << endl;
    cout << "and the output exit code is 0 (no other error or odd messages). " << endl;

    LinkedList L1 = LinkedList();
    L1.InsertFirst("Michael");
    L1.InsertFirst("is");
    L1.InsertFirst("name");
    L1.InsertFirst("my");
    L1.InsertFirst("Hello");
    L1.PrintList();
    L1.RemoveFirst();
    L1.PrintList();


    Stack S1 = Stack();
    S1.Push("cheese");
    S1.Push("and");
    S1.Push("mac");
    S1.Push("like");
    S1.Push("I");
    S1.PrintStack();

    S1.Pop();
    S1.PrintStack();
//
    Simulation(10);

}
