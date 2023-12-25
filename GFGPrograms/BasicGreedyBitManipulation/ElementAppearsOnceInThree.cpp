// Find the element that appears once in array of elements that has 3 same elements for each element except one.

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int bc1, bc2, bc3;
    int tbc1, tbc2, tbc3;
    bc1 = bc2 = bc3 = 0;
    tbc1 = tbc2 = tbc3 = 0;
    for (int i = 0; i < n; ++i)
    {
        tbc2 = (bc1 & arr[i]) | (bc2 ^ (bc2 & arr[i]));
        tbc3 = (bc2 & arr[i]) | (bc3 ^ (bc3 & arr[i]));
        tbc1 = (bc3 & arr[i]) | (bc1 ^ (bc1 & arr[i])) | (arr[i] ^ (arr[i] & tbc2) ^ (arr[i] & tbc3));
        bc1 = tbc1;
        bc2 = tbc2;
        bc3 = tbc3;
    }
    cout << bc1 << "\n";

    // int ones, twos, comm;
    // ones = twos = 0;
    // for (int i = 0; i < n; ++i)
    // {
    //     twos = twos | (ones & arr[i]);
    //     ones ^= arr[i];
    //     comm = ~(ones & twos);
    //     ones = ones & comm;
    //     twos = twos & comm;
    // }
    // cout << ones << "\n";
    return 0;
}