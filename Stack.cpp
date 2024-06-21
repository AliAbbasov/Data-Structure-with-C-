#include <iostream>

/*
    Definition of Stack:

    A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. 
    It is an abstract data type with a collection of elements in which elements are added and removed from only one end, 
    known as the "top" of the stack.

    In a stack, the element that is added last is the first one to be removed. 
    This behavior is similar to a stack of objects, where you can only add or remove items from the top of the stack. 
    Due to its LIFO nature, a stack can be visualized as a vertical stack of items, where you can only access the topmost item.

    The two primary operations performed on a stack are:
    1. Push: Adds an element to the top of the stack.
    2. Pop: Removes and returns the topmost element from the stack.

    Other common operations associated with a stack include:
    - Peek or Top: Retrieves the value of the topmost element without removing it.
    - Size: Returns the number of elements currently in the stack.
    - isEmpty: Checks if the stack is empty.

    Stacks are widely used in various computer science applications, such as expression evaluation, 
    function call management, undo/redo functionality, backtracking algorithms, memory management, and more. 
    The simplicity and efficiency of stacks make them an essential data structure in many programming scenarios.
*/

/*
    Exercise:

    1. Once the "LinkedList" class is implemented and tested, use it to build the "LinkedListStack" class. 

    2. Define a class called "LinkedListStack" that represents the stack using a linked list. 
    The class should have a private member to store the top node pointer.

    3. Implement a constructor for the LinkedListStack class that initializes the top pointer to nullptr, indicating an empty stack.

    4. Implement a member function in the LinkedListStack class called "push", 
    which takes a value as a parameter and pushes (inserts) that value onto the top of the stack.

    5. Add a "getHead" member function to the "LinkedList" class, which returns the head node pointer.

    6. Implement a member function in the LinkedListStack class called "pop", 
    which removes and returns the value from the top of the stack. 
    If the stack is empty, return a special value or throw an exception to indicate an underflow condition.

    7. Implement a member function in the LinkedListStack class called "peek", 
    which returns the value from the top of the stack without removing it. 
    If the stack is empty, return a special value or throw an exception to indicate an underflow condition.

    8. Implement a member function in the LinkedListStack class called "isEmpty", 
    which checks if the stack is empty and returns a boolean value accordingly.

    9. Implement a member function in the LinkedListStack class called "size", which returns the number of elements currently in the stack.
    
    10. Implement a "destructor" for the LinkedListStack class that deletes all the nodes in the stack.

    11. Test your implementation by creating an instance of the LinkedListStack class, pushing several values onto the stack, 
    and then performing pop, peek, isEmpty, size, and destructor operations to verify the correctness of the stack behavior.

    [Stack use cases]: https://www.enjoyalgorithms.com/blog/application-of-stack-data-structure-in-programming
*/


/*  Solution  */


class Node {
public:
    int data;
    Node* next;
};

class LinkedListStack  {
private:
        Node *top = new Node();

public:
    LinkedListStack() {
        this->top->next = nullptr;
        this->top->data = 0;
    }
    
LinkedListStack& push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

bool isEmpty() const {
    return top == nullptr;
}

LinkedListStack& pop() {
    if (isEmpty()) {
        std::cout << "Nothing to pop (^_^)" << std::endl;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
    return *this;
}

void peek() const {
    if (isEmpty()) {
        std::cout << "Nothing to peek (^_^)" << std::endl;
    } else {
        std::cout << "Peek: [" << top->data << " | " << top << "]" << std::endl;
    }
}

    int size() const {
        int count = 0; 
        Node* current = top;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count ; 
    }

void displayStack() const {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
    } else {
        Node* current = top;
        std::cout << "Display Stack: ";
        while (current) {
            std::cout << "[" << current->data << " | " << current << "] ---> ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

~LinkedListStack() {
    Node* current = top;
    std::cout << "Destructor: " << std::endl;

    while (current != nullptr) {
        Node* nextNode = current->next;
        std::cout << "   delete on " << current->data << std::endl;
        delete current;
        current = nextNode;
    }

    top = nullptr;
    std::cout << "End of Stack Deallocation" << std::endl;
}

    Node *getHead() const {
        return this->top;
    }    

};

int main() {

    /*      Example usage:     */
    LinkedListStack stack;

    stack.peek();

    stack.push(1).push(2).push(3).push(4).push(5);

    std::cout << "Size: " << stack.size() << std::endl << std::endl;

    stack.displayStack();
    stack.pop();
    stack.displayStack();

    std::cout << std::endl;
    stack.peek();
    std::cout << std::endl;

    stack.pop().pop().pop().pop();


    stack.displayStack();
    
    return 0;
}