#include <iostream>
// note this program use numbers to compare whether two nodes is same to each other
// since this is a good way to simulate the process of determining whether two linklist
// have common parts
class Node {
    public:
        int num;
        Node *next;

        Node() {
            this->num = 0;
            this->next = NULL;
        }

        Node(int val) : num(val), next(NULL) {};
};

int main() {
    int temp, i = 0, j = 0;
    int input_arr[1000];
    std::cout << "please input the first linklist, using non-number to end!" << std::endl;
    Node * pHead1 = new Node();
    Node * pHead2 = new Node();
    Node * pCur2 = pHead2;
    Node * pCur1 = pHead1;

    while (std::cin >> temp ) {
        pCur1->next = new Node(temp);
        pCur1 = pCur1->next;
        i++;
    }
    std::cin.clear();
    std::cin.ignore();

    std::cout << "please input the second linklist, using non-number to end!" << std::endl;
    while (std::cin >> temp ) {
        pCur2->next = new Node(temp);
        pCur2 = pCur2->next;
        j++;
    }
    // we suppose linklist 1 is shorter than linklist 2
    if (i > j) {
        // swap i and j
        int tmp;
        tmp = i;
        i = j;
        j = tmp;

        // swap link1 and link2
        Node * tmpNode;
        tmpNode = pHead1;
        pHead1 = pHead2;
        pHead2 = tmpNode;
    }
    pCur1 = pHead1->next;
    pCur2 = pHead2->next;
    for (int k = 0; k < j - i; k ++) {
        pCur2 = pCur2->next;
    }
    while (pCur1 != NULL && pCur1->num != pCur2->num) {
        pCur1 = pCur1->next;
        pCur2 = pCur2->next;
    }
    if (pCur1 == NULL) {
        std::cout << "no common parts" << std::endl;
    }
    else {
        std::cout << "the common part is ";
        while (pCur1) {
            std::cout << pCur1->num;
            pCur1 = pCur1->next;
        }
        std::cout << std::endl;
    }

    return 0;
}