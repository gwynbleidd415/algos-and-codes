#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

template <class T>
void print(vector<T> topSumm)
{
  for (ll itr : topSumm)
    cout << itr << '\t';
  cout << '\n';
}

vector<ll> mergeSortedArrays(vector<ll> &minns, vector<ll> &temp)
{
  vector<ll> ans(minns.size() + temp.size());
  int i{0}, j{0}, k{0};
  while (i < minns.size() && j < temp.size())
  {
    if (temp[j] < minns[i])
      ans[k++] = temp[j++];
    else
      ans[k++] = minns[i++];
  }
  while (i < minns.size())
    ans[k++] = minns[i++];
  while (j < temp.size())
    ans[k++] = temp[j++];
  return ans;
}

vector<ll> topKSum(vector<int> &arr, int k)
{
  int n{(int)arr.size()};
  ll maxSumm{0};
  for (int i{0}; i < n; ++i)
  {
    if (arr[i] > 0)
      maxSumm += arr[i];
    else
      arr[i] = -arr[i];
  }
  int nk{min(k - 1, n)};
  partial_sort(arr.begin(), arr.begin() + nk, arr.end());
  vector<ll> minns{0, maxSumm};
  ll summ{};
  bool breakOuter{false};
  for (int i{0}; i < nk; ++i)
  {
    vector<ll> temp;
    for (ll nums : minns)
    {
      summ = nums + arr[i];
      if (minns.size() + temp.size() < k)
        temp.push_back(summ);
      else
      {
        if (minns.back() > summ)
        {
          minns.pop_back();
          temp.push_back(summ);
        }
        else
        {
          if (nums == 0)
            breakOuter = true;
          break;
        }
      }
    }
    if (breakOuter)
      break;
    minns = mergeSortedArrays(minns, temp);
  }
  vector<ll> ans(k);
  int i{0};
  for (ll nums : minns)
    ans[i++] = maxSumm - nums;
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    ll maxSumm{0};
    for (int i{0}; i < n; ++i)
      cin >> arr[i];
    vector<ll> topSums = topKSum(arr, k);
    print<ll>(topSums);
  }
  return 0;
}
