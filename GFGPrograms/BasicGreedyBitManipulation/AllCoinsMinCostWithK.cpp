// Minimum cost for acquiring all coins with k extra coins allowed with every coin

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int k;
    cin >> k;
    int acn = (n + k) / (k + 1);
    priority_queue<int> pq;
    for (int i = 0; i < acn; ++i)
        pq.push(arr[i]);
    for (int i = acn; i < n; ++i)
        if (pq.top() > arr[i])
            pq.pop(), pq.push(arr[i]);
    int exp = 0;
    while (!pq.empty())
        exp += pq.top(), pq.pop();
    cout << exp << "\n";
    return 0;
}