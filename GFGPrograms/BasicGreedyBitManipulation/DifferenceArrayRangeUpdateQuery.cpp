#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int df[n];
    df[0] = arr[0];
    for (int i = 1; i < n; ++i)
        df[i] = arr[i] - arr[i - 1];
    bool cont = true;
    while (cont)
    {
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int l, r, x;
            cin >> l >> r >> x;
            df[l] += x;
            if (r != n - 1)
                df[r + 1] -= x;
            break;
        case 2:
            arr[0] = df[0];
            cout << arr[0] << " ";
            for (int i = 1; i < n; ++i)
            {
                arr[i] = arr[i - 1] + df[i];
                cout << arr[i] << " ";
            }
            cout << "\n";
            break;
        default:
            cont = false;
            break;
        }
    }
    return 0;
}