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
int main() {
    int startIdx, endIdx;
    int len;
    cout << "please input the number of nodes in the link list:" << endl;
    cin >> len;
    int * array = new int[len];
    cout << "please input the link list:" << endl;
    for (int i = 0; i < len; i++) {
        cin >> array[i];
    }
    cout << "please input the start and end index for reversing:" << endl;
    cin >> startIdx >> endIdx;

    if (startIdx < 0 || endIdx >= len || startIdx > endIdx) {
        cout << "wrong input" << endl;
        return(0);
    }

    // create a linked list
    Node * linkHead = new Node();
    Node * curP = linkHead;
    for (int i = 0; i < len; i++) {
        Node * newNode = new Node(array[i]);
        curP->next = newNode;
        curP = newNode;
    }
    Node * preP = linkHead;
    curP = linkHead->next;
    Node * startP = linkHead;


    // go the startIdx
    for (int i = 0; i < startIdx; i++) {
        startP = startP->next;
    }
    preP = startP->next; // this is the first element need to reverse
    curP = preP->next; // now this is the 2nd

    for (int i = 0; i < endIdx - startIdx; i ++) {
        preP->next = curP->next;
        curP->next = startP->next;
        startP->next = curP;
        curP = preP->next;
    }

    // output
    curP = linkHead;
    while (curP->next) {
        curP = curP ->next;
        cout << curP->num;
    }




    return 0;
}