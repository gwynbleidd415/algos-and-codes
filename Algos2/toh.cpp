#include <iostream>
using namespace std;

void toh(int n, char f, char m, char t)
{
	if (n > 0)
	{
		toh(n - 1, f, t, m);
		cout << "Move top disk from " << f << " to " << t << "\n";
		toh(n - 1, m, f, t);
	}
}

int main()
{
	int n;
	cout << "Enter the number of disks : ";
	cin >> n;
	cout << "Select Starting position(a,b,c) : ";
	char f, m, t;
	cin >> f;
	cout << "Select Ending position : ";
	cin >> t;
	m = char('a' + 'b' + 'c' - f - t);
	toh(n, f, m, t);
	return 0;
}