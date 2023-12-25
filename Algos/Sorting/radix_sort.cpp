#include <bits/stdc++.h>
using namespace std;

template <class T>
class radix_sort
{
public:
    radix_sort(T *arr, int n)
    {
        this->arr = arr;
        this->n = n;
        r_sort();
    }

private:
    T maxx()
    {
        T maxi = arr[0];
        for (int i = 1; i < n; ++i)
            if (arr[i] > maxi)
                maxi = arr[i];
        return maxi;
    }
    void r_sort()
    {
        T maxi = maxx();
        T res[n];
        for (int e = 1; e <= maxi; e *= 10)
        {
            int count[10] = {0};
            for (int i = 0; i < n; ++i)
                ++count[(arr[i] / e) % 10];
            for (int i = 1; i < 10; ++i)
                count[i] += count[i - 1];
            for (int i = n - 1; i >= 0; --i)
            {
                res[count[(arr[i] / e) % 10] - 1] = arr[i];
                --count[(arr[i] / e) % 10];
            }
            for (int i = 0; i < n; ++i)
                arr[i] = res[i];
        }
    }
    int n = 0;
    T *arr;
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
    radix_sort<int>(arr, n);
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    // auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stopTimer - startTimer);
    cout << "Sorted array : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}