#include <bits/stdc++.h>
#define mod 1000000007
#define prod(x,y) ((x%mod)*(y%mod))%mod

using namespace std;

long long int fermatlittle(long long int a,long long int b)
{
	//long long int b=mod-2;
	long long int pow=1;
	while(b)
	{
		//if(b&1)
		//	pow=prod(pow,a);
		//a=prod(a,a);
		if(b&1)
			pow=prod(pow,a);
		a=prod(a,a);
		b>>=1;
	}
	return pow;
}

int main()
{
	long long int a,b;
	cin>>a>>b;
	//cout<<prod(a,b)<<"\n";
	long long int pow=fermatlittle(a,b);
	cout<<pow<<"\n";
}