// Maximum subarray size, such that all subarrays of that size have sum less than k

#include <iostream>

using namespace std;

int sizeSumLessk(int arr[], int n, int k)
{
    int i = 0, j = 0;
    int ps = arr[0];
    while (j < n - 1 && ps <= k)
        ps += arr[++j];
    if (j == n - 1)
    {
        if (ps <= k)
            return n;
    }
    int maxLen = j;
    ps -= arr[j--];
    while (j < n - 1)
    {
        while (ps > k && i <= j)
            ps -= arr[i++];
        maxLen = min(maxLen, j - i + 1);
        ps += arr[++j] - arr[i++];
    }
    while (ps > k && i <= j)
        ps -= arr[i++];
    maxLen = min(maxLen, j - i + 1);
    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << sizeSumLessk(arr, n, k) << "\n";
    return 0;
}