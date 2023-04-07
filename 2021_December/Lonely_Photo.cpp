#include <iostream>
using namespace std;

#define int long long
signed main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  int pre[n+1];
  pre[0]=0;
  for(int i=0;i<n;i++)
  {
    pre[i+1]=pre[i]+(s[i]=='G');
  }
  int ans=0;
  for(int i=0;i<n;i++)
  {
    int zeros=i+2,zeroe=n+1;
    int s=i+3,e=n+1;
    while(s+1<e)
    {
        int j=(e+s)/2;
        int cur=min((pre[j]-pre[i]),((j-i)-(pre[j]-pre[i])));
        if(cur<=1)
        {
            s=j;
        }
        else
        {
            e=j;
        }
    }
    while(zeros+1<zeroe)
    {
        int j=(zeroe+zeros)/2;
        int cur=min((pre[j]-pre[i]),((j-i)-(pre[j]-pre[i])));
        if(cur<1)
        {
            zeros=j;
        }
        else
        {
            zeroe=j;
        }
    }
    int cur=min((pre[s]-pre[i]),((s-i)-(pre[s]-pre[i])));
    if(s>=i+3 and s<=n and cur==1)
    {
        ans+=(s-zeros);
    }
  }
  cout<<ans<<endl;
  return 0;
}
