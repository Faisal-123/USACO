#include <iostream>
using namespace std;
int main()
{
  int x,y,m;
  cin>>x>>y>>m;
  int ans1=0;
  int ans3=0;
  while(ans1+y<=m)
  {
    ans1+=y;
    ans3=max(ans3,(((m-ans1)/x)*x)+ans1);
  }
  int ans2=0;
  while(ans2+x<=m)
  {
    ans2+=x;
    ans3=max(ans3,((m-ans2)/y)*y + ans2);
  }
  cout<<max(ans2,max(ans3,ans2))<<endl;
  return 0;
}
