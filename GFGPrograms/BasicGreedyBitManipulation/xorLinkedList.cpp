// XOR Linked List – A Memory Efficient Doubly Linked List

#include <iostream>

using namespace std;

class xorLinkedList
{
private:
    struct Node
    {
        int data;
        Node *pnx;

        Node(int data_, Node *pnx_)
        {
            data = data_;
            pnx = pnx_;
        }
    };
    Node *head, *tail;

    Node *xorNodes(Node *x, Node *y)
    {
        return reinterpret_cast<Node *>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
    }

public:
    xorLinkedList()
    {
        head = tail = NULL;
    }
    void pushFirst(int data)
    {
        Node *newNode = new Node(data, head);
        if (head == NULL)
            head = tail = newNode;
        else
        {
            head->pnx = xorNodes(head->pnx, newNode);
            head = newNode;
        }
    }
    void pushLast(int data)
    {
        Node *newNode = new Node(data, tail);
        if (tail == NULL)
            head = tail = newNode;
        else
        {
            tail->pnx = xorNodes(tail->pnx, newNode);
            tail = newNode;
        }
    }
    void popFirst()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = temp->pnx;
        if (head == NULL)
        {
            tail = NULL;
            delete temp;
            return;
        }
        head->pnx = xorNodes(head->pnx, temp);
        delete temp;
    }
    void popLast()
    {
        if (tail == NULL)
            return;
        Node *temp = tail;
        tail = temp->pnx;
        if (tail == NULL)
        {
            head = NULL;
            delete temp;
            return;
        }
        tail->pnx = xorNodes(tail->pnx, temp);
        delete temp;
    }
    void traverseRight()
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            next = xorNodes(curr->pnx, prev);
            prev = curr;
            curr = next;
        }
        cout << "\n";
    }
    void traverseLeft()
    {
        Node *curr = tail;
        Node *next = NULL;
        Node *prev;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            prev = xorNodes(curr->pnx, next);
            next = curr;
            curr = prev;
        }
        cout << "\n";
    }
    ~xorLinkedList()
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next;
        while (curr != NULL)
        {
            next = xorNodes(curr->pnx, prev);
            prev = curr;
            curr = next;
            delete prev;
        }
        head = tail = NULL;
        delete head;
        delete tail;
    }
};

int main()
{
    xorLinkedList xl;
    bool cont = true;
    while (cont)
    {
        cout << "1.PushFirst  2.PushLast  3.PopFirst  4.PopLast  5.TraverseRight  6.TraverseLeft  7.Exit\n";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int data;
            cin >> data;
            xl.pushFirst(data);
            break;
        }
        case 2:
        {
            int data;
            cin >> data;
            xl.pushLast(data);
            break;
        }
        case 3:
            xl.popFirst();
            break;
        case 4:
            xl.popLast();
            break;
        case 5:
            xl.traverseRight();
            break;
        case 6:
            xl.traverseLeft();
            break;
        default:
            cont = false;
            break;
        }
    }
    return 0;
}