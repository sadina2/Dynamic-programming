#include<iostream>
#include <cmath>

using namespace std;

int main(){

  bool dp[200][360];
	int n, x;
  cout<<"Unesite broj rotacija: ";
	cin>>n;
	dp[0][0]=1;
  cout<<"Unesite uglove za svaku rotaciju: ";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		for(int j=0;j<360;j++)
			dp[i+1][j]=(dp[i][(j-x+360)%360] or dp[i][(x-j+360)%360]);
	}
	if(dp[n][0])
		cout<<"YES";
	else
		cout<<"NO";
}
