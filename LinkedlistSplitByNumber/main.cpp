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

void PrintLinkedlist(Node * pHead) {
    Node * pCur = pHead->next;
    while (pCur) {
        cout << pCur->num << " ";
        pCur = pCur->next;
    }
}

void SplitLinkedlistByNumber(Node * pHead, int splitNum) {
    Node * pLeftHead = new Node();
    Node * pRightHead = new Node();
    Node * pLeftCur = pLeftHead;
    Node * pRightCur = pRightHead;
    Node * pCur = pHead->next;
    Node * pTemp;
    while (pCur) {
        if (pCur->num <= splitNum) {
            pLeftCur->next = pCur;
            pCur = pCur->next;
            pLeftCur = pLeftCur->next;
            pLeftCur->next = NULL;
        }
        else {
            pRightCur->next = pCur;
            pCur = pCur->next;
            pRightCur = pRightCur->next;
            pRightCur->next = NULL;
        }
    }
    pLeftCur->next = pRightHead->next;
    pHead->next = pLeftHead->next;
}
int main() {
    cout << "please input one linked list:" << endl;
    int temp;
    int splitNum;
    Node * pHead = new Node();
    Node * pCur = pHead;
    while (cin >> temp) {
        pCur->next = new Node(temp);
        pCur = pCur->next;
    }
    cin.clear();
    cin.ignore();
    cout << "please input the number you would like to use for splitting:" << endl;
    cin >> splitNum;
    SplitLinkedlistByNumber(pHead, splitNum);
    PrintLinkedlist(pHead);

    cin.clear();
    cin.ignore();
    return 0;
}