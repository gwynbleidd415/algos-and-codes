// Count multiples of 5

#include <iostream>
using namespace std;

int getCount(int arr[], int n, int ind)
{
    int count = 0;
    while (ind >= 0)
    {
        count += arr[ind];
        ind = (ind & (ind + 1)) - 1;
    }
    return count;
}

void updateTree(int arr[], int n, int ind)
{
    while (ind < n)
    {
        arr[ind] += 1;
        ind = (ind | (ind + 1));
    }
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int ftree[n] = {0};
        for (int i = 0; i < n; ++i)
            if (arr[i] % 5 == 0)
                updateTree(ftree, n, i);

        pair<int, int> qarr[n];
        int inp1, inp2;
        for (int i = 0; i < q; ++i)
        {
            cin >> inp1 >> inp2;
            qarr[i].first = inp1 - 1;
            qarr[i].second = inp2 - 1;
        }

        for (int i = 0; i < q; ++i)
            cout << getCount(ftree, n, qarr[i].second) - getCount(ftree, n, qarr[i].first - 1) << " ";
        cout << "\n";
    }
    return 0;
}