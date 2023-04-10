#include <iostream>
#include <set>
#include <climits>
#include <vector>
using namespace std;

int main(){
  int n,bas;
  cin>>n>>bas;
  set<int> x;
  set<int> y;
  vector<pair<int,int>> g;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    x.insert(a-1);
    y.insert(b-1);
    g.push_back({a,b});
  }
  int ans=INT_MAX;
  for(auto i:x)
  {
    for(auto j:y)
    {
      int s1=0,s2=0,s3=0,s4=0;
      for(auto [q,w]:g)
      {
        if(q<i and w>j)
        {
          s1++;
        }
        else if(w>j and q>i)
        {
          s2++;
        }
        else if(w<j and q<i)
        {
          s3++;
        }
        else
        {
          s4++;
        }
      }
      ans=min(ans,max(max(s1,s2),max(s3,s4)));
    }
  }
  cout<<ans<<endl;
  return 0;
}
