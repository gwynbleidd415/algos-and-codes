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
    insertion_sort(arr, n);
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    // auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stopTimer - startTimer);
    cout << "Sorted array : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}