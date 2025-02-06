#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
#include "Stack.h"
using namespace std;

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

    cout << "Removing 1 and 2 from the queue" << endl;
    cout << " Is removing successful? " << Q1.Dequeue() << endl;
    cout << " Is removing successful? " << Q1.Dequeue() << endl;
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
    cout << " Is removing successful? " << Q1.Dequeue() << endl;
    cout << " Is removing successful? " << Q1.Dequeue() << endl;
    cout << " Is removing successful? " << Q1.Dequeue() << endl;
    cout << " Is removing successful? " << Q1.Dequeue() << endl;
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "Adding 9" << endl;
    cout << " Is adding 9 successful? " << Q1.Enqueue(9) << endl;
    cout << " Is the queue empty? " << Q1.IsEmpty() << endl;
    cout << " Is the queue full? " << Q1.IsFull() << endl;
    cout << " Queue content: "; Q1.PrintQueue(); cout << endl << endl;

    cout << "Emptying the list, removing one extra element, last one should fail " << endl;
    cout << " Is removing successful? " << Q1.Dequeue() << endl;
    cout << " Is removing successful? " << Q1.Dequeue() << endl;
    cout << " Is removing successful? " << Q1.Dequeue() << endl;
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
}
