#include <iostream>
#include <sstream>
#include <string>
#include "Queue.h"
#include "LinkedList.h"
#include "Stack.h"
#include <cstdlib>
#include <ctype.h>

using namespace std;

/*
* This function simulates a queue where customers line up and get served. The simulation stops when
* 3 times the queue size has come and gone.
*
* @param QueueSize      Size of the queue we want to simulate.
*/
void Simulation(int QueueSize) {
    srand(time(0));
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
        if (rand() % 2 == 0) {
            //enqueue
            if (Q1.IsFull()) {
                cout << "Step #" << steps << ": Queue too long, person left" << endl;
                steps++;
                continue;
            }
            Q1.Enqueue(number);
            cout << "Step #" << steps << ": Arrival #" << number << " inserted" << endl;
            Q1.PrintQueue();
            steps++;
            number++;
            total++;
        }

        else {
            //dequeue
            if (Q1.IsEmpty()) {
                cout << "Step #" << steps << ": There is no one to serve" << endl;
                steps++;
                continue;
            }
            int first;
            Q1.Dequeue(first);
            cout << "Step #" << steps << ": Processing #" << first << " successfully" << endl;
            Q1.PrintQueue();
            steps++;
            total++;
        }
    }
}

/*
* This function checks whether a string object is an operator.
*
* @param str        String object we want to check.
*/
bool IsOperator(string str) {
    if (str.length() == 1) {
        char c = str[0];
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
    return false;
}

/*
* This function applies an operator to two operands.
*
* @param a        First operand
* @param b        Second operand
* @param op       Operator applied to both operands
*
* @return         The outcome of the operation
*/
double Operator(double a, double b, string op) {
    if (op == "+") {
        return a + b;
    } if (op == "-") {
        return a - b;
    } if (op == "*") {
        return a * b;
    } if (op == "/" && b != 0) {
        return a / b;
    }
    cerr << "Invalid operation" << endl;
    return 0;
}

/*
* This function takes in a postfix equation and calculates the result. It uses a stack.
*
* @param postfixeq        The postfix equation as a string object
*
* @return                 The outcome of the calculation
*/
double PostFixCalculator(const string &postfixeq) {
    int length = (postfixeq.size() + 1) / 2;
    string equation[length];
    stringstream ss(postfixeq);
    for (int i = 0; i < length; i++) {
        getline(ss, equation[i], ',');
    }
    Stack S = Stack();
    for (int i = 0; i < length; i++) {
        if (IsOperator(equation[i])) {
            double operand1 = stod(S.Pop());
            double operand2 = stod(S.Pop());
            S.Push(to_string(Operator(operand2, operand1, equation[i])));
        }
        else {
            S.Push(equation[i]);
        }
    }
    return stod(S.Pop());
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
    cout << "and the output exit code is 0 (no other error or odd messages). " << endl << endl;

    cout << "---------------- Question 3 ----------------" << endl << endl;

    Simulation(10);
    cout << endl;

    cout << "---------------- Question 5 ----------------" << endl << endl;

    cout << "Creating an empty list" << endl;
    LinkedList L1 = LinkedList();
    cout << " List length: " << L1.Length() << endl;
    cout << " List content: "; L1.PrintList(); cout << endl << endl;

    cout << "Remove from empty list" << L1.RemoveFirst() << endl;
    cout << " List length: " << L1.Length() << endl;
    cout << " List content: "; L1.PrintList(); cout << endl << endl;

    cout << "Adding 5 strings to the list" << endl;

    L1.InsertFirst("Michael");
    L1.InsertFirst("is");
    L1.InsertFirst("name");
    L1.InsertFirst("my");
    L1.InsertFirst("Hello");

    cout << " List length: " << L1.Length() << endl;
    cout << " List content: "; L1.PrintList(); cout << endl << endl;

    cout << "Get the third element of the list (index 2)" << endl;
    cout << " 3rd element: " << L1.GetValueAt(2) << endl << endl;

    cout << "Get an element out of index" << endl;
    cout << " 10th element: " << L1.GetValueAt(10) << endl << endl;

    cout << "Remove two elements" << endl;
    L1.RemoveFirst();
    string tmp = L1.RemoveFirst();
    cout << " List length: " << L1.Length() << endl;
    cout << " List content: "; L1.PrintList(); cout << endl;
    cout << "Last element removed: " << tmp << endl << endl;

    cout << "Remove all remaining elements + 1" << endl;
    L1.RemoveFirst();
    L1.RemoveFirst();
    L1.RemoveFirst();
    L1.RemoveFirst();
    cout << " List length: " << L1.Length() << endl;
    cout << " List content: "; L1.PrintList(); cout << endl << endl;

    cout << "The destructor cannot be tested, but it clearly deletes the allocated memory," << endl;
    cout << "and the output exit code is 0 (no other error or odd messages). " << endl << endl;

    cout << "---------------- Question 7 ----------------" << endl << endl;

    cout << "Creating an empty stack" << endl;
    Stack S1 = Stack();
    cout << " Is the stack empty? " << S1.IsEmpty() << endl;
    cout << " Stack content: " ; S1.PrintStack(); cout << endl << endl;

    cout << "Pop an empty stack and call top()" << endl;
    cout << " Top: " << S1.Top() << endl;
    S1.Pop();
    cout << " Stack content: " ; S1.PrintStack(); cout << endl << endl;

    cout << "Push 5 strings to the stack" << endl;
    S1.Push("cheese");
    S1.Push("and");
    S1.Push("mac");
    S1.Push("like");
    S1.Push("I");
    cout << " Stack content: " ; S1.PrintStack(); cout << endl << endl;

    cout << "Pop two strings from the stack" << endl;
    S1.Pop();
    tmp = S1.Pop();
    cout << " Stack content: " ; S1.PrintStack(); cout << endl << endl;
    cout << "Last element removed: " << tmp << endl << endl;

    cout << "Check if top is the correct string (it should be mac)" << endl;
    cout << " Top: " << S1.Top() << endl << endl;

    cout << "Pop remaining elements" << endl;
    S1.Pop();
    S1.Pop();
    S1.Pop();
    cout << " Is the stack empty? " << S1.IsEmpty() << endl;
    cout << " Stack content: " ; S1.PrintStack(); cout << endl << endl;

    cout << "The destructor cannot be tested, but it clearly deletes the allocated memory," << endl;
    cout << "and the output exit code is 0 (no other error or odd messages). " << endl << endl;

    cout << "---------------- Question 8 ----------------" << endl << endl;
    cout << "Equation examples: " << endl;
    cout << "Input: 4,5,+                 Output: " << PostFixCalculator("4,5,+") << endl;
    cout << "Input: 3,9,*                 Output: " << PostFixCalculator("3,9,*") << endl;
    cout << "Input: 2,5,3,+,-             Output: " << PostFixCalculator("2,5,3,+,-") << endl;
    cout << "Input: 1,5,+,8,4,1,-,-,*     Output: " << PostFixCalculator("1,5,+,8,4,1,-,-,*") << endl << endl;

    cout << "Try your own equation: ";
    string input;
    cin >> input;
    cout << endl << "Output: " << PostFixCalculator(input) << endl;
}

