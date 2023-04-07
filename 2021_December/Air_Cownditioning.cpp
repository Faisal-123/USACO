#include <iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int cur[n+1];
  int want[n+1];
  int d[n+1];
  d[n]=-1;
  for(int i=0;i<n;i++)
  {
    cin>>want[i];
  }
  for(int i=0;i<n;i++)
  {
    cin>>cur[i];
    d[i]=want[i]-cur[i];
  }
  int ans=0;
  int i=0;
  while(i<n)
  {
    if(d[i]==0){
      i++;
      continue;
    }
    int mi=abs(d[i]);
    int j=i;
    while(j<n and ((d[j]>0 and d[i]>0) or (d[j]<0 and d[i]<0)))
    {
      mi=min(abs(d[j]),mi);
      j++;
    }
    for(int k=i;k<j;k++)
    {
      if(d[k]>0)
      {
        d[k]-=mi;
      }
      else
      {
        d[k]+=mi;
      }
    }
    ans+=mi;
  }
  cout<<ans<<endl;
  return 0;
}
