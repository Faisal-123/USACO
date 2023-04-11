#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <set>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
#define Code  ios_base::sync_with_stdio(false); 
#define Faisal cout.tie(NULL);
#define By cin.tie(NULL);
int main(){
  Code By Faisal
  int n;
  cin>>n;
  set<int> xas;
  set<int> yas;
  vector<pair<int,int>> g;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    xas.insert(a-1);
    yas.insert(b-1);
    g.push_back({a,b});
  }
  int ans=INT_MAX;
  for(auto i:xas)
  {
    vector<int> up,down;
    for(auto as:g)
    {
    	int x=as.first,y=as.second;
        if(x<=i)
        {
            down.push_back(y);
        }
        else
        {
            up.push_back(y);
        }
    }
  sort(begin(up),end(up));
	sort(begin(down),end(down));
    for(auto j:yas)
    {
    	int gr=lower_bound(begin(up),end(up),j)-begin(up);
    	int le=lower_bound(begin(down),end(down),j)-begin(down);
    	ans=min(ans,max(max(gr,(int)up.size()-gr),max(le,(int)down.size()-le)));
    }
  }
  cout<<ans<<endl;
  return 0;
}
