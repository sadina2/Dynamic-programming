#include <iostream>
using namespace std;


int a, b, n, rezultat, d[100], dp[100];
int main(){

cout<<"Unesite broj svjetionika: ";
cin>>n;
cout<<"Unesite poziciju svjetionika i snagu: ";
for(int i=0; i<n; i++){
    cin>>a>>b;
    d[a]=b;
}

if(d[0]>0)
  dp[0]=1;

for(int i=1; i<100; i++){
  if(d[i]==0)
    dp[i]=dp[i-1];
  else if(d[i]>=i)
    dp[i]=1;
  else
    dp[i]=dp[i-d[i]-1]+1;

    rezultat=max(rezultat,dp[i]);
}

cout<<n-rezultat;

}
