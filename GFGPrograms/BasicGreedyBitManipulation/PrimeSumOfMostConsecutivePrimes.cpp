// Find the prime numbers which can written as sum of most consecutive primes

#include <iostream>
#include <vector>

#define PRLEN 1000

using namespace std;

void printVector(vector<int> &vec)
{
    for (auto el : vec)
        cout << el << " ";
    cout << "\n";
}

vector<int> getPrimes(int n)
{
    vector<int> primes;
    vector<int> lp(n + 1, 0);
    for (int i = 2; i < n; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            primes.push_back(i);
        }
        for (auto &pr : primes)
        {
            if (pr > lp[i] || i * pr > n)
                break;
            lp[i * pr] = pr;
        }
    }
    return primes;
}

bool isPrime(int pr, vector<int> &primes)
{
    int s = 0, e = primes.size() - 1;
    while (e >= s)
    {
        int m = (e + s) / 2;
        if (primes[m] == pr)
            return true;
        if (primes[m] > pr)
            e = m - 1;
        else
            s = m + 1;
    }
    return false;
}

int getMostConsecutiveSumsPrime(int limit, vector<int> &primes, vector<int> &psPrimes)
{
    int mostCumSum = 0, mostCumLen = 0;
    for (int i = 0; i < primes.size() && primes[i] <= limit; ++i)
    {
        if (isPrime(psPrimes[i], primes))
        {
            if (i + 1 > mostCumLen)
                mostCumLen = i + 1, mostCumSum = psPrimes[i];
            continue;
        }
        for (int j = 0; j < i; ++j)
        {
            if (isPrime(psPrimes[i] - psPrimes[j], primes))
            {
                if (i - j > mostCumLen)
                    mostCumLen = i - j, mostCumSum = psPrimes[i] - psPrimes[j];
                break;
            }
        }
    }
    return mostCumSum;
}

int getMostConsecutiveSumsLessLimitPrime(int limit, vector<int> &primes, vector<int> &psPrimes)
{
    int mostCumSum = 0, mostCumLen = 0;
    for (int i = 0; i < primes.size() && primes[i] <= limit; ++i)
    {
        if (psPrimes[i] <= limit && isPrime(psPrimes[i], primes))
        {
            if (i + 1 > mostCumLen)
                mostCumLen = i + 1, mostCumSum = psPrimes[i];
            continue;
        }
        for (int j = 0; j < i; ++j)
        {
            if (psPrimes[i] - psPrimes[j] > limit)
                continue;
            if (isPrime(psPrimes[i] - psPrimes[j], primes))
            {
                if (i - j > mostCumLen)
                    mostCumLen = i - j, mostCumSum = psPrimes[i] - psPrimes[j];
                break;
            }
        }
    }
    return mostCumSum;
}

int main()
{
    vector<int> primes = getPrimes(PRLEN);
    vector<int> psPrimes(primes.size());
    psPrimes[0] = primes[0];
    for (int i = 1; i < primes.size(); ++i)
        psPrimes[i] = psPrimes[i - 1] + primes[i];
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; ++i)
        cout << getMostConsecutiveSumsPrime(arr[i], primes, psPrimes) << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i)
        cout << getMostConsecutiveSumsLessLimitPrime(arr[i], primes, psPrimes) << " ";
    cout << "\n";
    return 0;
}