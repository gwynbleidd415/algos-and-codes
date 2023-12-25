// Sort an array according to the other

#include <bits/stdc++.h>
using namespace std;

//User function template in C++

class Solution
{
public:
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
    {
        // unordered_map<int, int> um;
        // unordered_map<int, int>::iterator iter;
        // unordered_map<int, int>::iterator iter1;
        // int k = 0;
        // for(int i=0;i<M;++i){
        //     iter = um.find(A2[i]);
        //     if(iter == um.end())
        //         um.insert({A2[i], k++});
        // }
        // sort(A1.begin(), A1.end(), [&um, &iter, &iter1](int a, int b){
        //     iter = um.find(a); iter1 = um.find(b);
        //     if(iter!=um.end()){
        //         if(iter1 == um.end() || (*iter).second < (*iter1).second)
        //             return true;
        //         return false;
        //     }
        //     else if(iter1 != um.end())
        //         return false;
        //     else
        //         return a<b;
        // });
        // return A1;

        unordered_map<int, int> um;
        unordered_map<int, int>::iterator iter;
        for (int i = 0; i < N; ++i)
            ++um[A1[i]];
        vector<int> A3;
        A3.reserve(N);
        for (int i = 0; i < M; ++i)
        {
            iter = um.find(A2[i]);
            if (iter != um.end() && iter->second)
            {
                A3.insert(A3.end(), iter->second, A2[i]);
                iter->second = 0;
            }
        }
        vector<int>::iterator cter = A3.end();
        for (auto &itr : um)
        {
            if (itr.second)
            {
                A3.insert(A3.end(), itr.second, itr.first);
                itr.second = 0;
            }
        }
        sort(cter, A3.end());
        return A3;
    }
};

int main(int argc, char *argv[])
{

    int t;

    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        vector<int> a1(n);
        vector<int> a2(m);

        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }

        Solution ob;
        a1 = ob.sortA1ByA2(a1, n, a2, m);

        for (int i = 0; i < n; i++)
            cout << a1[i] << " ";

        cout << endl;
    }
    return 0;
}