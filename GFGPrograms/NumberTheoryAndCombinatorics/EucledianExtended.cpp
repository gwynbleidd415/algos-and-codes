#include <iostream>
#include <tuple>

using namespace std;

tuple<int, int, int> getGCD(int a, int b)
{
    bool rev = false;
    if (a < b)
    {
        tie(a, b) = make_tuple(b, a);
        rev = true;
    }
    int x, y, x1, y1;
    x = y1 = 1;
    y = x1 = 0;
    int d;
    while (b)
    {
        d = a / b;
        tie(a, b) = make_tuple(b, a % b);
        tie(x, x1) = make_tuple(x1, x - d * x1);
        tie(y, y1) = make_tuple(y1, y - d * y1);
    }
    if (rev)
        return make_tuple(a, y, x);
    return make_tuple(a, x, y);
}

int main()
{
    int a, b;
    cin >> a >> b;
    tuple<int, int, int> gcd = getGCD(a, b);
    cout << get<0>(gcd) << " " << get<1>(gcd) << " " << get<2>(gcd) << "\n";
    return 0;
}