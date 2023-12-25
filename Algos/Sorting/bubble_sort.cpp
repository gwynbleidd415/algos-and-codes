#include <bits/stdc++.h>
using namespace std;

template <class T>
void bubble_sort(T arr[], int n)
{
    bool swaps;
    for (int i = 0; i < n; ++i)
    {
        swaps = false;
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j + 1] < arr[j])
                swap(arr[j], arr[j + 1]), swaps = true;
        if (swaps == false)
            break;
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
    bubble_sort(arr, n);
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    // auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stopTimer - startTimer);
    cout << "Sorted array : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}