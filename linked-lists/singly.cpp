/**
 * Singly linked lists
 */

#include <iostream>
#include <string>


// What other namespaces exist?
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class SinglyLinkedList {
    Node<T>* head;
    Node<T>* tail;

    size_t _size;

    // What is this pattern called?
    // Bo Qian explained it in some video
    // Bitcoin's codebase also uses these SetNull type functions
    void SetNull() {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

public:

    SinglyLinkedList() {
        SetNull();
    }

    SinglyLinkedList(initializer_list<T> init) {
        SetNull();

        for (auto &s : init)
            push_back(s);
    }

    ////////////////////////////////////////////////////////////

    // TODO: const reference?
    size_t size() {
        return _size;
    }

    // TODO: public access to head, tail pointers?

    // Notice that 'const' is placed at the end to denote
    // that this function won't modify state?
    void print(ostream& out, const Node<T>* p) const {
        for(; p != nullptr; p = p->next) {

            out << '"' << p->data << '"'
                 << (p->next != nullptr ? " -> " : "\n");
        }
    }

    // TODO: Generalize ostream to work with stringstream
    friend ostream& operator<<(ostream& out, const SinglyLinkedList<T>& LL) {
        LL.print(out, LL.head);
        return out;
    }

    ////////////////////////////////////////////////////////////

    // TODO: Should return a pointer to the newly added node?
    void push_back(T data) {
        // new is required to ensure that node
        // isn't freed as soon as the function exits
        Node<T>* n = new Node<T>{data, nullptr};

        _size++;

        if (head == nullptr)
            head = n;
        else
            tail->next = n;

        tail = n;
    }

    void push_front(T data) {
        Node<T>* n = new Node<T>{data, nullptr};

        _size++;

        if (head == nullptr) {
            tail = n;
        } else {
            n->next = head;
        }

        head = n;
    }

};


int main() {

    // Implicitly uses the push_back methods
    SinglyLinkedList<string> LL {"Shadab", "duffer", "Zafar"};
    LL.push_front("Shadab"); LL.push_front("duffer"); LL.push_front("Zafar");
    cout << LL;

    SinglyLinkedList<int> LL_int {1,2,3,4,5};
    cout << LL_int;

    return 0;
}
