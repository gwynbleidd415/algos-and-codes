// N meetings in one room

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int ind[n];
        for (int i = 0; i < n; ++i)
            ind[i] = i;
        auto comparator = [&end](int &a, int &b)
        {
            if (end[a] < end[b])
                return true;
            return false;
        };
        sort(ind, ind + n, comparator);
        int nm = 1;
        int et = end[ind[0]];
        for (int i = 1; i < n; ++i)
        {
            if (start[ind[i]] > et)
                et = end[ind[i]], ++nm;
        }
        return nm;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}