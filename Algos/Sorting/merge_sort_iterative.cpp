#include <bits/stdc++.h>
using namespace std;

template <class T>
void merge(T arr[], int s, int m, int e)
{
    T temp[e - s + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e)
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= e)
        temp[k++] = arr[j++];
    for (k = s; k <= e; ++k)
        arr[k] = temp[k - s];
}

template <class T>
void merge_sort(T arr[], int n)
{
    for (int i = 1; i < n; i *= 2)
    {
        for (int j = 0; j < n - 1; j += 2 * i)
        {
            int m = min(j + i - 1, n - 1);
            int e = min(j + 2 * i - 1, n - 1);
            merge(arr, j, m, e);
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
    merge_sort(arr, n);
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    // auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stopTimer - startTimer);
    cout << "Sorted array : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}