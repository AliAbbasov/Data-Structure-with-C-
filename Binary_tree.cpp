#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <math.h> 
#include <queue> 
 
using namespace std; 
 
struct Node { 
    int data; 
    Node *left; 
    Node *right; 
}; 
 
class BinaryTree { 
private: 
    int height; 
    Node *root; 
 
    void printTree(const Node *node, int level) const { 
        if (node == nullptr) 
            return; 
        printTree(node->right, level + 1); 
        for (int i = 0; i < level; i++) 
            cout << "    "; 
        cout << node->data << endl; 
        printTree(node->left, level + 1); 
    } 
 
    void destroyTree(Node *node) { 
        if (node != nullptr) { 
            destroyTree(node->left); 
            destroyTree(node->right); 
            cout << "Delete: " << node->data << endl; 
            delete node; 
        } 
    } 
 
public: 
    BinaryTree() { 
        root = nullptr; 
        height = 0; 
    } 
 
    ~BinaryTree() { 
        destroyTree(root); 
    } 
 
    BinaryTree& insert(const int &data) { 
    Node *newNode = new Node; 
    newNode->data = data; 
    newNode->left = nullptr; 
    newNode->right = nullptr; 
 
    if (root == nullptr) { 
        root = newNode; 
        height = 1; 
        return *this; 
    } 
 
    Node *current = root; 
    Node *parent = nullptr; 
 
    while (current != nullptr) { 
        parent = current; 
        if (data < current->data) 
            current = current->left; 
        else if (data > current->data) 
            current = current->right; 
        else { 
            delete newNode;  
            return *this; 
        } 
    } 
    if (data < parent->data) 
        parent->left = newNode; 
    else 
        parent->right = newNode; 
 
    height++;  
    return *this; 
} 
 
 
 
void preorder() const { 
    preorder(root); 
}      
void preorder(const Node *node) const { 
    if (node == nullptr) 
        return; 
    cout << node->data << " "; 
    preorder(node->left); 
    preorder(node->right); 
} 
 
 
void inorder() const { 
    inorder(root); 
}     
void inorder(const Node *node) const { 
    if (node == nullptr) 
        return; 
         
    inorder(node->left); 
    cout << node->data << " "; 
    inorder(node->right); 
} 
     
 
void postorder() const { 
    postorder(root); 
} 
 
void postorder(const Node *node) const { 
    if (node == nullptr) 
        return; 
         
    postorder(node->left); 
    postorder(node->right); 
    cout << node->data << " "; 
} 
 
    void levelorder() const { 
        if (root == nullptr) 
            return; 
             
        queue<const Node *> queue; 
        queue.push(root); 
        while (!queue.empty()) { 
            const Node *node = queue.front(); 
            queue.pop(); 
            cout << node->data << " "; 
            if (node->left!= nullptr) 
                queue.push(node->left); 
            if (node->right!= nullptr) 
                queue.push(node->right); 
        } 
    } 
 
    bool search(const int &data) const { 
        if (root == nullptr) 
            return false; 
        queue<const Node *> que; 
        que.push(root); 
        while (!que.empty()) { 
            const Node *node = que.front(); 
            que.pop(); 
            if (node->data == data) 
                return true; 
            if (node->left!= nullptr) 
                que.push(node->left); 
            if (node->right!= nullptr) 
                que.push(node->right); 
        } 
        return false; 
    } 
 
void deleteNode(const int &data) { 
    Node *current = root; 
    Node *parent = nullptr; 
 
    while (current != nullptr && current->data != data) { 
        parent = current; 
        if (data < current->data) 
            current = current->left; 
        else 
            current = current->right; 
    } 
 
    if (current == nullptr) 
        return; 
 
    if (current->left == nullptr) { 
        if (parent == nullptr) 
            root = current->right; 
        else if (parent->left == current) 
            parent->left = current->right; 
        else 
            parent->right = current->right;
delete current; 
    } else if (current->right == nullptr) { 
        if (parent == nullptr) 
            root = current->left; 
        else if (parent->left == current) 
            parent->left = current->left; 
        else 
            parent->right = current->left; 
        delete current; 
    } else { 
        Node *successor = current->right; 
        parent = current; 
 
        while (successor->left != nullptr) { 
            parent = successor; 
            successor = successor->left; 
        } 
        current->data = successor->data; 
        if (parent->left == successor) 
            parent->left = successor->right; 
        else 
            parent->right = successor->right; 
 
        delete successor; 
    } 
} 
 
    void display() const { 
        if (root == nullptr) { 
            cout << "Tree is empty" << endl; 
            return; 
        } 
        cout << "Tree height: " << height << endl; 
        printTree(root, 0); 
    } 
 
     
 
 
}; 
 
int main() { 
    BinaryTree tree; 
 
    cout << endl; 
    tree.display(); 
 
    tree.insert(2).insert(1).insert(33).insert(70).insert(25).insert(40).insert(11).insert(34).insert(7).insert(12).insert(36).insert(13).insert(52); 
 
    cout << endl; 
    tree.display(); 
    cout << endl; 
 
    cout << (tree.search(13) ? "[13 found]" : "[13 not found]") << endl << endl; 
 
    tree.deleteNode(1); 
    tree.deleteNode(2); 
 
    cout << endl; 
    tree.display(); 
    cout << endl; 
 
    // Tree traversals (preorder, inorder, postorder, levelorder) 
     
    cout << "Preorder:   "; 
    tree.preorder(); 
    cout << endl; 
 
    cout << "Inorder:    "; 
    tree.inorder(); 
    cout << endl; 
 
    cout << "Postorder:  "; 
    tree.postorder(); 
    cout << endl; 
 
    cout << "Levelorder: "; 
    tree.levelorder(); 
    cout << endl; 
 
    return 0; 
}