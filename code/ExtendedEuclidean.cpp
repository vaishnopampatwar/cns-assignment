#include <bits/stdc++.h>
using namespace std;

// Function for extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
	cout<<a<<" "<<b<<" "<<" " <<*x <<" "<<*y<<"\n";
	// Base Case
	if (b == 0)
	{
		return a;
	}
	long long q = a / b;
	long long x1 = *y;
	long long y1 = *x - q * (*y);
	long long gcd = gcdExtended(b, a % b, &x1, &y1);

	return gcd;
}

// Driver Code
int main()
{
	long long x = 0, y = 1, a, b;
	cout << "\n Enter a and  b to find GCD";
	cout << "\n a = ";
	cin >> a;
	cout << "\n b = ";
	cin >> b;

	long long g = gcdExtended(a, b, &x, &y);
	cout<<"GCD("<<a<<", "<<b<<") = "<<g<<endl;
	return 0;
}