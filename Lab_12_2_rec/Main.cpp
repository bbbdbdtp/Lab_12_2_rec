#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasDuplicatePairRecursive(Node* current, int value) {
    if (current == nullptr)
        return false;

    if (current->data == value)
        return true;

    return hasDuplicatePairRecursive(current->next, value);
}

bool hasDuplicatePair(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return false;

    int value = head->data;
    return hasDuplicatePairRecursive(head->next, value) || hasDuplicatePair(head->next);
}

Node* createListRecursive(Node*& head, Node*& tail, int valuesV1[], int valuesV2[], int index, int size) {
    if (index >= size)
        return nullptr;

    Node* newNodeV1 = new Node();
    newNodeV1->data = valuesV1[index];
    newNodeV1->next = nullptr;

    Node* newNodeV2 = new Node();
    newNodeV2->data = valuesV2[index];
    newNodeV2->next = nullptr;

    if (head == nullptr) {
        head = newNodeV1;
        tail = newNodeV2;
    }
    else {
        tail->next = newNodeV1;
        tail = newNodeV2;
    }

    newNodeV1->next = newNodeV2;
    createListRecursive(head, tail, valuesV1, valuesV2, index + 1, size);
}

void createList(Node*& head, Node*& tail, int valuesV1[], int valuesV2[], int size) {
    createListRecursive(head, tail, valuesV1, valuesV2, 0, size);
}

void printListRecursive(Node* current) {
    if (current == nullptr)
        return;

    cout << current->data << " ";
    printListRecursive(current->next);
}

void printList(Node* head) {
    printListRecursive(head);
    cout << endl;
}

int main() {

    int valuesV1[] = { 1, 2, 3, 4, 5 };
    int valuesV2[] = { 11, 12, 13, 14, 15 };
    int size = sizeof(valuesV1) / sizeof(valuesV1[0]);

    Node* head = nullptr;
    Node* tail = nullptr;

    createList(head, tail, valuesV1, valuesV2, size);

    cout << "List of elements:" << endl;
    printList(head);

    if (hasDuplicatePair(head))
        cout << "The list contains a pair of elements with the same values." << endl;
    else
        cout << "The list does not contain a pair of elements with the same values." << endl;

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}