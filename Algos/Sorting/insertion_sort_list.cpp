#include <bits/stdc++.h>
using namespace std;

template <class T>
void insertion_sort(T arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        T k = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > k)
            arr[j + 1] = arr[j], --j;
        arr[j + 1] = k;
    }
}

template <class T>
struct Node
{
    T data;
    Node<T> *next, *prev;
};

template <class T>
class List
{
    Node<T> *start, *end;
    int n;

public:
    List(int n)
    {
        this->n = n;
        start = NULL, end = NULL;
    }
    void push(T data)
    {
        Node<T> *temp = new Node<T>();
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        if (start == NULL)
        {
            start = temp;
            end = temp;
        }
        else
        {
            temp->prev = end;
            end->next = temp;
            end = temp;
        }
    }
    void iSort()
    {
        display();
        Node<T> *itr = start->next;
        while (itr != NULL)
        {
            Node<T> *temp = itr;
            Node<T> *temp1 = itr->next;
            while (temp->prev != NULL && temp->prev->data > itr->data)
                temp = temp->prev;
            // cout << temp->data << "  " << itr->data << "  " << itr->prev->data << "\n";
            if (temp == start)
            {
                itr->prev->next = itr->next;
                if (itr->next != NULL)
                    itr->next->prev = itr->prev;
                else
                    end = itr->prev;
                // cout << itr->data << "  " << itr->prev->data << "\n";
                itr->next = start;
                start->prev = itr;
                itr->prev = NULL;
                start = itr;
                itr = temp1;
            }
            else if (itr != temp)
            {
                itr->prev->next = itr->next;
                if (itr->next != NULL)
                    itr->next->prev = itr->prev;
                else
                    end = itr->prev;
                itr->next = temp;
                itr->prev = temp->prev;
                temp->prev->next = itr;
                temp->prev = itr;
                itr = temp1;
            }
            else
                itr = itr->next;
            // display();
        }
    }
    void display()
    {
        Node<T> *temp = start;
        while (temp != NULL)
            cout << temp->data << " ", temp = temp->next;
        cout << "\n";
    }
};

int main()
{
    cout << "Enter the number of elements\n";
    int n;
    cin >> n;
    List<int> ls(n);
    cout << "Enter the elements\n";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ls.push(x);
    }
    auto startTimer = chrono::steady_clock::now();
    ls.iSort();
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    // auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stopTimer - startTimer);
    cout << "Sorted array : \n";
    ls.display();
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}