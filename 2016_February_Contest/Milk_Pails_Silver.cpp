#include <iostream>
#include <climits>
#include <map>
#include <vector>
using namespace std;
int  main(){
  int x,y,k,m;
  cin>>x>>y>>k>>m;
  vector<tuple<int,int,int>> hg;
  hg.push_back({0,0,k});
  map<tuple<int,int,int>,bool> vis;
  vis[{0,0,k}]=1;
  int ans=INT_MAX;
  int a,b,c;
  while(hg.size())
  {
    tie(a,b,c)=hg.back();
    hg.pop_back();
    ans=min(ans,abs(a+b-m));
    if(c==0)
    {
      continue;
    }
    if(a==0 and !vis[{a+x,b,c-1}])
    {
      vis[{a+x,b,c-1}]=1;
      hg.push_back({a+x,b,c-1});
    }
    if(b==0 and !vis[{a,b+y,c-1}])
    {
      vis[{a,b+y,c-1}]=1;
      hg.push_back({a,b+y,c-1}); 
    }
    if(!vis[{0,b,c-1}])
    {
      vis[{0,b,c-1}]=1;
      hg.push_back({0,b,c-1});
    }
    if(!vis[{a,0,c-1}])
    {
      vis[{a,0,c-1}]=1; 
      hg.push_back({a,0,c-1});
    }
    if(a+b<=x and !vis[{a+b,0,c-1}])
    {
      vis[{a+b,0,c-1}]=1;
      hg.push_back({a+b,0,c-1});
    }
    if(a+b>x and !vis[{x,(a+b)-x,c-1}])
    {
      vis[{x,(a+b)-x,c-1}]=1; 
      hg.push_back({x,a+b-x,c-1});
    }
    if(a+b<=y and !vis[{0,a+b,c-1}])
    {
      vis[{0,a+b,c-1}]=1;
      hg.push_back({0,a+b,c-1});
    }
    if(a+b>y and !vis[{(a+b)-y,y,c-1}])
    {
      vis[{(a+b)-y,y,c-1}]=1; 
      hg.push_back({(a+b)-y,y,c-1});
    }
  }
  cout<<ans<<endl;
  return 0;
}
