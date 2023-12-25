#include <bits/stdc++.h>
using namespace std;

template <class T>
class heap_sort
{
    vector<T> arr;

public:
    heap_sort(T arry[], int n)
    {
        for (int i = 0; i < n; ++i)
            push(arry[i]);
        display();
        hsort();
    }
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
    bool minn(T a, T b, T c)
    {
        return (a <= b) ? (a < c) ? true : false : false;
    }
    void hsort()
    {
        int l = arr.size() - 1;
        while (l > 0)
        {
            swap(arr[l], arr[0]);
            int i = 0;
            while (1)
            {
                int j = i * 2 + 1;
                if (j + 1 < l)
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
                else if (j < l)
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
            --l;
        }
        reverse(arr.begin(), arr.end());
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
    cout << "Enter the number of elements\n";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    auto startTimer = chrono::steady_clock::now();
    heap_sort<int> hS(arr, n);
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    cout << "Sorted array : \n";
    hS.display();
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}