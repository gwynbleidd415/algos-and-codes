#include <bits/stdc++.h>
using namespace std;

template <class T>
class quick_sort
{
public:
    quick_sort(T *arr, int n)
    {
        this->arr = arr;
        this->n = n;
        q_sort(0, n - 1);
    }

private:
    int partition(int s, int e)
    {
        srand(time(NULL));
        swap(arr[s + rand() % (e - s + 1)], arr[e]);
        int i = s, j = e - 1;
        while (i <= j)
        {
            if (arr[i] > arr[e] && arr[j] < arr[e])
                swap(arr[i++], arr[j--]);
            while (i < e && arr[i] <= arr[e])
                ++i;
            while (j >= i && arr[j] >= arr[e])
                --j;
        }
        swap(arr[i], arr[e]);
        return i;
    }
    void q_sort(int s, int e)
    {
        if (s < e)
        {
            int p = partition(s, e);
            q_sort(s, p - 1);
            q_sort(p + 1, e);
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
    quick_sort<int>(arr, n);
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    // auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stopTimer - startTimer);
    cout << "Sorted array : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}