#include <iostream>
using namespace std;

int main(){
  int n,p,q,r, m=100, a[m],dp0[m], dp1[m], dp2[m];
  cout<<"Unesite broj elemenata niza: ";
  cin>>n;
  cout<<"Unesite vrijednosti p, q, r: ";
  cin>>p>>q>>r;

  cout<<"Unesite vrijednosti ai: ";
  for(int i=0; i<n; i++)
    cin>>a[i];

  dp0[0]=a[0]*p;
  dp1[0]=dp0[0]+a[0]*q;
  dp2[0]=dp1[0] + a[0]*r;

  for(int i=1; i<n; i++)
  {
    dp0[i]=max(dp0[i-1], a[i]*p);
    dp1[i]=max(dp1[i-1], dp0[i]+ a[i]*q);
    dp2[i] = max(dp2[i-1], dp1[i] + a[i]* r);
  }

  cout<<dp2[n-1]<<endl;
}
