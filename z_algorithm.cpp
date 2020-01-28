#include<bits/stdc++.h>
using namespace std;
#define int long long


vector<int> zfunction(string s){
	int n=s.length();
	vector<int> z(n,0);
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i>r){
			l=r=i;
			while(r<n && s[r-l]==s[r]){
				r++;
			}
			z[i]=r-l;
			r--;
		}
		else{
			int k=i-l;
			if(z[k]+i<=r){
				z[i]=z[k];
			}
			else{
				l=i;
				while(r<n && s[r-l]==s[r]){
					r++;
				}
				z[i]=r-l;
				r--;
			}
		}
	}
	return z;
}



int32_t main(){
	string text, pattern;
	cin>>text;
	cin>>pattern;
	string s=pattern+"$"+text;


	vector<int> z=zfunction(s);


	// follwing will pring the indices where the pattern match is found
	for(int i=pattern.length()+1;i<s.length();i++){
		if(z[i]==pattern.length()){
			cout<<i-pattern.length()-1<<" ";
		}
	}
	cout<<endl;



	return 0;
}