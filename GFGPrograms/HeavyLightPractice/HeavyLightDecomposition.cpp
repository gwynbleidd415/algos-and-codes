#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define vvpii vector<vector<pair<int, int>>>

struct nodeData
{
    int depth, size, sind, hid;
    vector<int> anc;
};

void dfs(vvpii &adj, int strt, int par, nodeData arr[], int depth)
{
    arr[strt].anc.push_back(par);
    arr[strt].depth = depth;
    int size = 1;
    for (auto &a : adj[strt])
    {
        dfs(adj, a.first, strt, arr, depth + 1);
        size += arr[a.first].size;
    }
    arr[strt].size = size;
}

void fillAnc(vvpii &adj, nodeData arr[])
{
    int n = log2(adj.size()) + 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < adj.size(); ++j)
        {
            if (arr[j].anc.size() <= i || arr[arr[j].anc.back()].anc.size() <= i)
                continue;
            arr[j].anc.push_back(arr[arr[j].anc.back()].anc[i]);
        }
    }
}

void hld(vvpii &adj, int sarr[], int strt, int hid, int &ec, nodeData arr[])
{
    int maxSize = INT32_MIN;
    pair<int, int> maxel = {-1, -1};
    for (auto &a : adj[strt])
    {
        if (arr[a.first].size > maxSize)
            maxSize = arr[a.first].size, maxel = a;
    }
    if (maxel.first != -1)
    {
        sarr[ec] = maxel.second;
        arr[maxel.first].sind = ec++;
        arr[maxel.first].hid = hid;
        hld(adj, sarr, maxel.first, hid, ec, arr);
    }
    for (auto &a : adj[strt])
    {
        if (a.first == maxel.first)
            continue;
        sarr[ec] = a.second;
        arr[a.first].sind = ec++;
        arr[a.first].hid = a.first;
        hld(adj, sarr, a.first, a.first, ec, arr);
    }
}

int getStreeSize(int n)
{
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);

    return n * 2 + 1;
}

void constructStree(int stree[], int sarr[], int v, int l, int r)
{
    if (l == r)
    {
        stree[v] = sarr[l];
        return;
    }
    int mid = (l + r) / 2;
    constructStree(stree, sarr, v * 2 + 1, l, mid);
    constructStree(stree, sarr, v * 2 + 2, mid + 1, r);
    stree[v] = max(stree[v * 2 + 1], stree[v * 2 + 2]);
}

int getMaxStree(int stree[], int sarr[], int v, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
        return stree[v];
    int mid = (l + r) / 2;
    if (mid >= qr)
        return getMaxStree(stree, sarr, v * 2 + 1, l, mid, ql, qr);
    else if (mid < ql)
        return getMaxStree(stree, sarr, v * 2 + 2, mid + 1, r, ql, qr);
    return max(getMaxStree(stree, sarr, v * 2 + 1, l, mid, ql, min(qr, mid)), getMaxStree(stree, sarr, v * 2 + 2, mid + 1, r, max(ql, mid + 1), qr));
}

int getLCS(nodeData arr[], int l, int r)
{
    if (arr[l].depth < arr[r].depth)
        swap(l, r);
    int relD = arr[l].depth - arr[r].depth;
    int i = 0;
    while (relD)
    {
        if (relD & 1)
            l = arr[l].anc[i];
        ++i;
        relD >>= 1;
    }
    if (l == r)
        return l;
    i = arr[l].anc.size() - 1;
    while (i >= 0)
    {
        if (arr[l].anc[i] != arr[r].anc[i])
            l = arr[l].anc[i], r = arr[r].anc[i];
        --i;
    }
    return arr[l].anc[0];
}

int getMaxHLD(int n, int stree[], int sarr[], nodeData arr[], int l, int r)
{
    int lcs = getLCS(arr, l, r);
    int maxx = INT32_MIN;
    while (arr[l].hid != arr[lcs].hid)
    {
        maxx = max(maxx, getMaxStree(stree, sarr, 0, 0, n, arr[arr[l].hid].sind, arr[l].sind));
        l = arr[arr[l].hid].anc[0];
    }
    while (arr[r].hid != arr[lcs].hid)
    {
        maxx = max(maxx, getMaxStree(stree, sarr, 0, 0, n, arr[arr[r].hid].sind, arr[r].sind));
        r = arr[arr[r].hid].anc[0];
    }
    if (l != lcs)
        maxx = max(maxx, getMaxStree(stree, sarr, 0, 0, n, arr[lcs].sind + 1, arr[l].sind));
    if (r != lcs)
        maxx = max(maxx, getMaxStree(stree, sarr, 0, 0, n, arr[lcs].sind + 1, arr[r].sind));
    return maxx;
}

int main()
{
    int n;
    cin >> n;
    vvpii adj(n, vector<pair<int, int>>());
    int tempa, tempb, tempc;
    for (int i = 1; i < n; ++i)
    {
        cin >> tempa >> tempb >> tempc;
        adj[tempa].push_back({tempb, tempc});
    }
    nodeData arr[n];
    dfs(adj, 0, -1, arr, 0);
    arr[0].anc.pop_back();
    fillAnc(adj, arr);
    int sarr[n];
    int ec = 0;
    sarr[ec++] = -1, arr[0].sind = 0, arr[0].hid = 0;
    hld(adj, sarr, 0, 0, ec, arr);
    int sn = getStreeSize(n);
    int stree[sn] = {0};
    constructStree(stree, sarr, 0, 0, n);
    int q;
    cin >> q;
    pair<int, int> que[q];
    for (int i = 0; i < q; ++i)
        cin >> que[i].first >> que[i].second;
    for (int i = 0; i < q; ++i)
        cout << getMaxHLD(n, stree, sarr, arr, que[i].first, que[i].second) << "\n";
    return 0;
}

// 11
// 0 1 13
// 0 2 9
// 0 3 23
// 1 4 4
// 1 5 25
// 2 6 29
// 5 7 5
// 6 8 30
// 7 9 1
// 7 10 6
// 2
// 10 8
// 10 3