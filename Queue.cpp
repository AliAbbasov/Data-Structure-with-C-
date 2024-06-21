#include <iostream>
#include <string>


using namespace std;

/*

    Source: https://www.geeksforgeeks.org/queue-data-structure/

    A queue is a common data structure that follows the "first-in, first-out" (FIFO) principle. 
    It can be visualized as a line of people waiting for a service, 
    where the person who arrives first gets served first.

    In a queue, elements are added at one end called the "rear" or "enqueue" operation, 
    and elements are removed from the other end called the "front" or "dequeue" operation. 
    This ensures that the element that has been in the queue the longest gets dequeued first.

    Some key operations associated with a queue are:

    1. Enqueue: Adds an element to the rear of the queue.
    2. Dequeue: Removes the front element from the queue and returns it.
    3. Peek/Front: Returns the front element of the queue without removing it.
    4. IsEmpty: Checks if the queue is empty.
    5. Size: Returns the number of elements currently in the queue.

    Queues can be implemented using various data structures such as arrays, 
    linked lists, or even built-in collections in programming languages. 
    The choice of implementation depends on the specific requirements and constraints of the application.

    [Application of Queues]
    Queues have many practical use cases in computer science and everyday programming. 
    Here are some common scenarios where queues are used:

    1. Task Scheduling: Queues are often used to manage and schedule tasks or jobs in various systems. 
    For example, in an operating system, a queue can be used to schedule processes for execution based on their arrival time or priority.

    2. Message Queues: In messaging systems or distributed systems, 
    queues are used to handle asynchronous communication between components. 
    Messages are placed in a queue and processed by the receiving components at their own pace.

    3. Print Spooling: In print management systems, 
    queues are used to store print jobs in the order they were submitted. 
    The jobs are then printed one by one, following the FIFO principle.

    4. Web Server Request Handling: Web servers typically use queues to handle incoming requests. 
    Each request is added to a queue, and the server processes them in the order they arrived. 
    This ensures fair handling and prevents overload on the server.

    5. Breadth-First Search (BFS): BFS is a graph traversal algorithm that explores all the vertices of a graph in breadth-first order. 
    A queue is used to keep track of the vertices to be visited, 
    allowing the algorithm to visit adjacent vertices before exploring deeper into the graph.

    6. Buffering in I/O Operations: Queues can be used to buffer input and output operations in various scenarios.
    For example, when reading data from a file or a network socket, the data can be stored in a queue before being processed.

    7. Call Center Systems: In call center applications, queues are used to manage incoming calls. 
    Calls are placed in a queue and are assigned to available agents in the order they were received, ensuring a fair distribution of calls.
*/


/*
    Exercise: Implement a Queue using a Linked List

    Implement the queue data structure using your previous linked list solution.
    The linked list should have nodes that store an integer value and a reference to the next node. 
    The queue should support the following operations:

    1. Enqueue: Add an element to the rear of the queue.
    2. Dequeue: Remove and return the front element of the queue.
    3. Peek/Front: Returns the front element of the queue without removing it.
    4. IsEmpty: Check if the queue is empty.
    5. Size: Return the number of elements currently in the queue.
*/


/*  Solution  */


struct Node {
    int data;
    Node *next;
};

class Queue {
private:
    Node *first = new Node();
    Node *last = first;

public:
    Queue() {
        first->next = nullptr;
        first->data = 0;
    }

    ~Queue() {
        Node *current = first;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete first;
    }

    bool isEmpty() const {
        return first->next == nullptr;
    }


    int size() const {
    int count = 0;
    Node *current = first->next; 
    while (current != nullptr) {
        count++; 
        current = current->next; 
    }
    return count; 
}

    Queue &enqueue(const int &data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
    
        if (isEmpty()) {
            this->first->next = newNode;
        } else {
            Node *current = this->first->next;
            while (current->next != nullptr) {
            }
            current->next = newNode;
        }
        return *this;
    }


    int dequeue() {
        if (isEmpty()) {
            cout << "Cannot dequeue." << endl;
            return -1;
        }

        Node *temp = first->next;
        first->next = temp->next;

        if (temp == last) {
            last = first;     // Bura fikir ver
        }

        delete temp;
        return -1;
    }

    int peek() const {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    } else {
        return first->next->data; 
    }
}
    

};


int main() {


    Queue queue;
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Size: " << queue.size() << endl;   // Output: Size: 3
    cout << "Front: " << queue.peek() << endl;  // Output: Front: 10
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 10
    cout << "Is Empty? " << queue.isEmpty() << endl;  // Output: Is Empty? 0 (false)
    cout << "Front: " << queue.peek() << endl;  // Output: Front: 20
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 20
    cout << "Is Empty? " << queue.isEmpty() << endl;  // Output: Is Empty? 0 (false)
    cout << "Front: " << queue.peek() << endl;  // Output: Front: 30
    cout << "Dequeued: " << queue.dequeue() << endl;  // Output: Dequeued: 30
    cout << "Is Empty? " << queue.isEmpty() << endl;  // Output: Is Empty? 1 (true)

    return 0;
}