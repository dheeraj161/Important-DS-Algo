#include<bits/stdc++.h>
using namespace std;
#define int long long



vector<int> solve(string s, string ss){
	int a[ss.length()];
	int i=1,j=0;
	a[0]=0;
	for(int i=1;i<ss.length();i++){
		if(ss[i]==ss[j]){
			a[i]=j+1;
			j++;
		}
		else{
			while(j!=0 && ss[i]!=ss[j]){
				j=a[j-1];
			}
			if(ss[j]==ss[i]){
				a[i]=a[j]+1;
			}
			else{
				a[i]=0;
			}
		}
	}
	for(int i=0;i<ss.length();i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	vector<int> v;

	j=0;
	for(int i=0;i<s.length();i++){
		if(s[i]==ss[j]){
			j++;
		}
		else{
			while(j!=0 && s[i]!=ss[j]){
				j=a[j-1];
			}
			if(s[i]==ss[j]){
				j++;
			}
		}
		if(j==ss.length()){
			v.push_back(i-j+1);
			j=a[j-1];
			continue;
		}

	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;




	return v;
}

int32_t main(){
	string str;
	cin>>str;
	string pattern;
	cin>>pattern;
	// it will find all the indeces where the pattern will be found
	vector<int> v=solve(str,pattern);



	return 0;
}