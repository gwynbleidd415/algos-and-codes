// Maximum subarray sum modulo m

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int m;
    cin >> m;
    set<int> ps;
    int ptn = (arr[0] + m) % m;
    int maxx = ptn;
    for (int i = 1; i < n; ++i)
    {
        ps.insert(ptn);
        ptn = ((arr[i] + m) % m + ptn) % m;
        maxx = max(ptn, maxx);
        auto itr = ps.upper_bound(ptn);
        if (itr != ps.end())
            maxx = max(maxx, (ptn - *itr + m) % m);
    }
    cout << maxx << "\n";
    return 0;
}

// -3 -5 1 2 4
// 5 3 1 2 4
// 5 8 9 11 15
// 5 0 1 3 7