#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;




vector<int> ans;
string s;
int n;
void suffixArray(vector<pair<string, int> > vv, int k){
    sort(vv.begin(),vv.end());
    int i=0;
    while(i<vv.size()-1){
        if(vv[i].first==vv[i+1].first){
            int j=i;
            vector<pair<string, int> > v1;
            while(j<vv.size() && vv[j].first==vv[i].first){
                int x=vv[j].second+pow(2,k);
                int y=pow(2,k+1);
                y=min(n-x,y);
                if(x>=s.length()){
                    ans.push_back(vv[j].second);
                    j++;continue;
                }
                v1.push_back({s.substr(x,y),vv[j].second});
                j++;
            }
            i=j;
            suffixArray(v1,k+1);
        }
        else{
            ans.push_back(vv[i].second);
            i++;
        }
    }
    if(i<vv.size()){
        ans.push_back(vv[i].second);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    n=s.length();
    vector<pair<string, int> > vv;
    for(int i=0;i<n-1;i++){
        vv.push_back({s.substr(i,2),i});
    }
    vv.push_back({s.substr(n-1,1),n-1});
   suffixArray(vv,1);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


  return 0;
}