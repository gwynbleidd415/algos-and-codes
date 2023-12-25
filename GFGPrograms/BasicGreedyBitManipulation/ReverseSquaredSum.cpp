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
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int sum = 0;
        bool add = true;
        for (int i = n - 1; i >= 0; --i)
        {
            if (add)
                sum += arr[i] * arr[i];
            else
                sum -= arr[i] * arr[i];
            add != add;
        }
        cout << sum << "\n";
    }
    return 0;
}