// Program to find the maximum profit job sequence from a given array of jobs with deadlines and profits

#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class disjointSet
{
private:
    vector<int> parent;

public:
    disjointSet(int n)
    {
        parent.reserve(n + 1);
        for (int i = 0; i <= n; ++i)
            parent.push_back(i);
    }
    int find(int k)
    {
        if (parent[k] == k)
            return k;
        return parent[k] = find(parent[k]);
    }
    void updateParent(int a)
    {
        parent[a] = find(a - 1);
    }
};

class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, [](Job &a, Job &b)
             {
                 if (a.profit == b.profit)
                     return a.dead > b.dead;
                 return a.profit > b.profit;
             });
        int mdead = 0;
        for (int i = 0; i < n; ++i)
            if (arr[i].dead > mdead)
                mdead = arr[i].dead;
        // bool books[mdead+1];
        // memset(books, 0, sizeof(books));
        // int mj, mp;
        // mj = 0, mp = 0;
        // for(int i=0;i<n;++i)
        //     for(int j = arr[i].dead; j>=1;--j)
        //         if(books[j] == false){
        //             books[j] = true;
        //             ++mj, mp+=arr[i].profit;
        //             break;
        //         }
        // return vector<int>{mj, mp};
        disjointSet dj(mdead);
        int mj, mp;
        mj = 0, mp = 0;
        int par;
        for (int i = 0; i < n; ++i)
        {
            par = dj.find(arr[i].dead);
            if (par != 0)
            {
                ++mj, mp += arr[i].profit;
                dj.updateParent(par);
            }
        }
        return vector<int>{mj, mp};
    }
};

int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}