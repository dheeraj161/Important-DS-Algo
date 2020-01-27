#include<bits/stdc++.h>
using namespace std;
#define int long long


struct trie{
	bool leaf;
	trie* child[26];
};
trie* create(){
	trie* tmp=new trie();
	tmp->leaf=false;
	for(int i=0;i<26;i++){
		tmp->child[i]=NULL;
	}
	return tmp;
}

void add(trie* root, string s){
	for(int i=0;i<s.length();i++){
		if(root->child[s[i]-'a']==NULL){
			root->child[s[i]-'a']=create();
		}
		root=root->child[s[i]-'a'];
	}
	root->leaf=true;
}

bool ispresent(trie* root, string s){
	for(int i=0;i<s.length();i++){
		if(root->child[s[i]-'a']==NULL){
			return false;
		}
		root = root->child[s[i]-'a'];
	}
	if(root->leaf==true){
		return true;
	}
	return false;
}


int32_t main(){
	int n;cin>>n;
	trie* root=create();
	for(int i=0;i<n;i++){
		string s;cin>>s;
		add(root,s);
	}
	string ss;cin>>ss;
	if(ispresent(root, ss)){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}



	return 0;
}