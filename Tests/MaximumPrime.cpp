#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

string trimmedString(string &str)
{
  int start = 0, end = str.length();
  while (start < end && str[start] == '0')
    ++start;
  while (start < end && str[end - 1] == '0')
    --end;
  return str.substr(start, end - start);
}

int power2(int x)
{
  int y = 2;
  int res = 1;
  while (x)
  {
    if (x & 1)
      res *= y;
    y *= y;
    x = x >> 1;
  }
  return res;
}

int stringToNum(string &str)
{
  int res = 1;
  int mult = 2;
  for (auto &&i : str)
  {
    if (i == '1')
      res += mult;
    mult = mult << 1;
  }
  return res + mult;
}

void findMaxPrime(string &str, unordered_set<int> &primes, int &maxPrime, int ind, string str1)
{
  if (ind == str.length())
    return;
  string str2 = str1 + str[ind];
  int numStr2 = stringToNum(str2);
  if (primes.find(numStr2) != primes.end() && maxPrime < numStr2)
    maxPrime = numStr2;
  findMaxPrime(str, primes, maxPrime, ind + 1, str1);
  findMaxPrime(str, primes, maxPrime, ind + 1, str2);
}

int inputOutput()
{
  string str;
  cin >> str;
  string str1 = trimmedString(str);
  int n = str1.length();
  if (n == 0)
    return -1;
  if (n == 1)
  {
    if (str.back() == '1')
      return -1;
    return 2;
  }
  int N = power2(n);
  vector<int> lp(N + 1);
  vector<int> pr;
  for (int i = 2; i <= N; ++i)
  {
    if (lp[i] == 0)
    {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j)
    {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i])
        break;
    }
  }

  unordered_set<int> primes;
  for (auto &&i : pr)
    primes.emplace(i);
  int maxPrime = 3;
  string str2 = str1.substr(1, str1.length() - 2);
  findMaxPrime(str2, primes, maxPrime, 0, "");
  return maxPrime;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);

  int t{};
  cin >> t;
  while (t--)
    cout << inputOutput() << '\n';
  return 0;
}
