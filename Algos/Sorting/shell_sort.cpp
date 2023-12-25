#include <bits/stdc++.h>
using namespace std;

template <class T>
void shell_sort(T arr[], int n)
{
    for (int i = n / 2; i > 0; i /= 2)
    {
        for (int j = i; j < n; ++j)
        {
            int k = j - i;
            int val = arr[j];
            while (k >= 0 && arr[k] > val)
                arr[k + i] = arr[k], k -= i;
            arr[k + i] = val;
        }
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
    shell_sort(arr, n);
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    // auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stopTimer - startTimer);
    cout << "Sorted array : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}