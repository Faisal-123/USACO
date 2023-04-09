#include <iostream>
#include <climits>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n+1];
  int ans=INT_MAX;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int j=0;j<n;j++)
  {
    int cur=0;
    int l=0;
    for(int i=(j+1)%n;i!=j;i++,i%=n)
    {
      l++;
      cur+=(a[i]*(l));
    }
    ans=min(ans,cur);
  }
  cout<<ans<<endl;
  return 0;
}
