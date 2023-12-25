// Random number generator in arbitrary probability distribution fashion

#include <iostream>
#include <cstring>

using namespace std;

int getCeil(int freq[], int n, int k)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (freq[mid] == k)
            return mid;
        if (freq[mid] < k)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    int arr[n], freq[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; ++i)
        cin >> freq[i];
    int pfSum[n];
    pfSum[0] = freq[0];
    for (int i = 1; i < n; ++i)
        pfSum[i] = pfSum[i - 1] + freq[i];
    srand(time(0));
    int rns;
    cin >> rns;
    int hm[n];
    memset(hm, 0, sizeof(hm));
    for (int i = 0; i < rns; ++i)
    {
        int ind = getCeil(pfSum, n, rand() % pfSum[n - 1] + 1);
        hm[ind] += 1;
        cout << arr[ind] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i)
        cout << hm[i] << " ";
    cout << "\n";
    return 0;
}