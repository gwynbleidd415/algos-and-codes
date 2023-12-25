#include <bits/stdc++.h>
using namespace std;

template <class T>
class merge_sort
{
public:
    merge_sort(T *arr, int n)
    {
        this->arr = arr;
        this->n = n;
        m_sort(0, n - 1);
    }

private:
    void merge(int s, int e)
    {
        int m = (s + e) / 2;
        T temp[e - s + 1];
        int i = s, j = m + 1, k = 0;
        while (i <= m && j <= e)
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else if (arr[i] > arr[j])
                temp[k++] = arr[j++];
        while (i <= m)
            temp[k++] = arr[i++];
        while (j <= e)
            temp[k++] = arr[j++];
        for (k = 0; k < e - s + 1; ++k)
            arr[s + k] = temp[k];
    }
    void m_sort(int s, int e)
    {
        if (s < e)
        {
            int m = (s + e) / 2;
            m_sort(s, m);
            m_sort(m + 1, e);
            merge(s, e);
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
    merge_sort<int>(arr, n);
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    // auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stopTimer - startTimer);
    cout << "Sorted array : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}