#include <iostream>
using namespace std;

int main() {
  int n, a[200], dp[200][3];

  cout<<"Unesite broj dana odmora: ";
  cin>>n;
  /*
  a1 je 0 ako na itom danu odmora teretana nije otvorena a takmicenje nije odrzano
  a1 je 1 ako na itom danu odmora teretana nije otvorena ali je takmicenje odrzano
  a2 je 2 ako na itom danu odmora teretana je otvorena a takmicenje nije odrzano
  a3 je 3 ako na itom danu odmora teretana je otvorena a takmicenje je odrzano..*/

  cout<<"Unos   Znacenje"<<endl;
  cout<<"   0   Teretana zatvorena, takmicenje nije odrzano."<<endl;
  cout<<"   1   Teretana zatvorena, takmicenje odrzano."<<endl;
  cout<<"   2   Teretana otvorena, takmicenje nije odrzano."<<endl;
  cout<<"   3   Teretana otvorena, takmicenje odrzano."<<endl;
  cout<<"Za svaki dan, unesite odgovarajuci broj: ";

  for(int i=0; i<n; i++)
    cin>>a[i];

  for(int i=0; i<n; i++)
    dp[i][0]=dp[i][1]=dp[i][2]=1000;

  dp[0][0]=1;

  if(a[0]==1 || a[0]==3)
    dp[0][1]=0;

  if(a[0]==2 || a[0]==3)
    dp[0][2]=0;

  for(int i=1; i<n; i++){
    dp[i][0]=1+min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));

    if(a[i]==1 || a[i]==3)
      dp[i][1]=min(dp[i-1][0], dp[i-1][2]);

    if(a[i]==2 || a[i]==3)
      dp[i][2]=min(dp[i-1][0], dp[i-1][1]);

  }
  cout<<"Minimalan broj dana za odmor: ";
  cout<<min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));


}
