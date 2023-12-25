#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        // for (int i = n - 1; i >= 0; --i)
        //     cout << arr[i] << " ";
        for (int i = 0; i < n / 2; ++i)
        {
            arr[i] = arr[n - 1 - i] ^ arr[i];
            arr[n - 1 - i] = arr[n - i - 1] ^ arr[i];
            arr[i] = arr[n - 1 - i] ^ arr[i];
        }
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
    return 0;
}