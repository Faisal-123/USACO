#include<iostream>
#include<map>
#include<set>
using namespace std;
#define int long long
signed main()
{
  int n;
  cin>>n;
  int a;
  set<int> s;
  map<int,int> cnt;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    s.insert(a);
    cnt[a]+=1;
  }
  int pre=0;
  int ans=0;
  int x=0;
  for(auto i:s)
  {
    if(((n-pre)*i)>ans)
    {
      ans=(n-pre)*i;
      x=i;
    }
    pre+=cnt[i];
  }
  cout<<ans<<' '<<x<<endl;
  return 0;
}
