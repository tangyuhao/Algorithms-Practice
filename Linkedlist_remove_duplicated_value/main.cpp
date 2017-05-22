#include <iostream>
using namespace std;
class Node {
    public:
        int num;
        Node * next;
        Node() {
            this->num = 0;
            this->next = NULL;
        }
        Node(int val): num(val), next(NULL) {};
};

void DeleteDuplicatedNode(Node * pHead) {

    Node * pCur = pHead->next;
    Node * pTemp;
    while(pCur && pCur->next) {
        // if duplicated
        if (pCur->num == pCur->next->num) {
            pTemp = pCur->next;
            pCur->next = pCur->next->next;
            delete(pTemp);
        }
        else {
            pCur = pCur->next;
        }
    }
}

void PrintLinkedlist(Node * pHead) {
    Node * pCur = pHead->next;
    while (pCur) {
        cout << pCur->num << " ";
        pCur = pCur->next;
    }
}

int main() {
    cout << "please input one linked list, this program will remove duplicated neighbor values:" << endl;
    int temp;
    Node * pHead = new Node();
    Node * pCur = pHead;
    while (cin >> temp) {
        pCur->next = new Node(temp);
        pCur = pCur->next;
    }
    cin.clear();
    cin.ignore();
    DeleteDuplicatedNode(pHead);
    PrintLinkedlist(pHead);
    return 0;
}