#include <bits/stdc++.h>
using namespace std;

template <class T>
class minHeap
{
    vector<T> arr;

public:
    void push(T data)
    {
        arr.push_back(data);
        int i = arr.size() - 1;
        while (1)
        {
            int j = (i - 1) / 2;
            if (arr[j] > arr[i])
            {
                swap(arr[j], arr[i]);
                i = j;
            }
            else
                break;
        }
    }
    T top()
    {
        return arr[0];
    }
    bool minn(T a, T b, T c)
    {
        return (a <= b) ? (a < c) ? true : false : false;
    }
    void pop()
    {
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        int i = 0;
        while (1)
        {
            int j = i * 2 + 1;
            if (j + 1 < arr.size())
            {
                if (minn(arr[j], arr[j + 1], arr[i]))
                {
                    swap(arr[j], arr[i]);
                    i = j;
                }
                else if (minn(arr[j + 1], arr[j], arr[i]))
                {
                    swap(arr[j + 1], arr[i]);
                    i = j + 1;
                }
                else
                    break;
            }
            else if (j < arr.size())
                if (arr[j] < arr[i])
                {
                    swap(arr[j], arr[i]);
                    i = j;
                }
                else
                    break;
            else
                break;
        }
    }
    void display()
    {
        for (auto itr : arr)
            cout << itr << " ";
        cout << "\n";
    }
};

int main()
{
    int t = 1;
    minHeap<int> mH;
    while (t)
    {
        cout << "Choose one option...\n 1. push  2. pop  3.top  4.display\n";
        int wish;
        cin >> wish;
        switch (wish)
        {
        case 1:
            cout << "Enter the data\n";
            int data;
            cin >> data;
            mH.push(data);
            break;
        case 2:
            mH.pop();
            break;
        case 3:
            cout << mH.top() << "\n";
            break;
        case 4:
            mH.display();
            break;
        default:
            t = 0;
            break;
        }
    }
    return 0;
}