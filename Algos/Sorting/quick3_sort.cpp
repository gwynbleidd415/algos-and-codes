#include <bits/stdc++.h>
using namespace std;

template <class T>
class quick3_sort
{
public:
    quick3_sort(T *arr, int n)
    {
        this->arr = arr;
        this->n = n;
        q_sort(0, n - 1);
    }

private:
    tuple<int, int> partition(int s, int e)
    {
        srand(time(NULL));
        swap(arr[s + rand() % (e - s + 1)], arr[e]);
        int j = s, k = s;
        for (int l = s; l < e; ++l)
        {
            if (arr[l] == arr[e])
                swap(arr[k++], arr[l]);
            else if (arr[l] < arr[e])
            {
                swap(arr[k++], arr[j]);
                swap(arr[j++], arr[l]);
            }
        }
        swap(arr[k], arr[e]);
        return make_tuple(j, k);
    }
    void q_sort(int s, int e)
    {
        if (s < e)
        {
            int a, b;
            tie(a, b) = partition(s, e);
            q_sort(s, a - 1);
            q_sort(b + 1, e);
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
    quick3_sort<int>(arr, n);
    auto stopTimer = chrono::steady_clock::now();
    chrono::duration<double, nano> timeElapsed = stopTimer - startTimer;
    // auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(stopTimer - startTimer);
    cout << "Sorted array : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nElapsed time = " << timeElapsed.count() << "\n";
    return 0;
}