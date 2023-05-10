#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int deleteElements(Node*& head, int x) {
    int count = 0;
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL) {
        if (current->data == x) {
            Node* temp = current;
            current = current->next;
            if (previous == NULL) {
                head = current;
            } else {
                previous->next = current;
            }
            delete temp;
            count++;
        } else {
            previous = current;
            current = current->next;
        }
    }
    return count;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtHead(Node*& head, int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = head;
    head = temp;
}

int main() {
    Node* head = NULL;
    int n, x;
    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertAtHead(head, x);
    }
    int count = deleteElements(head, x);
    printList(head);
    return 0;
}
