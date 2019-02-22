#include <iostream>

using namespace std;

int main()
{
	int max_n=100001, n, x, broj=n, dp[max_n], c[max_n];

	cout<<"Unesite broj elemenata niza: ";
  cin>>n;

  cout<<"Unesite elemente niza: ";

	while(n>0) {
		cin>>x;
		c[x]++;
    n--;
	}

	dp[0] = 0;
	dp[1] = c[1];

	for (int i=2; i <broj+1; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + i*c[i]);
	}

	cout<<"Maksimalan broj poena: "<<dp[broj];
}
