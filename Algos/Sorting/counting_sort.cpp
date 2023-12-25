#include <bits/stdc++.h>
using namespace std;
#define MAXX 100001

int main()
{
    cout << "Enter the number of elements\n";
    int n;
    cin >> n;
    int arr[MAXX] = {0};
    cout << "Enter the elements\n";
    for (int i = 0; i < n; ++i)
    {
        int j;
        cin >> j;
        ++arr[j];
    }
    cout << "Sorted Array:\n";
    for (int i = 0; i < MAXX; ++i)
        while (arr[i] > 0)
            --arr[i], cout << i << " ";
    cout << "\n";
    return 0;
}