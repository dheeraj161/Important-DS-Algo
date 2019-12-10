#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<functional>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int> , rb_tree_tag, tree_order_statistics_node_update> new_data_set;

// #define IOS ios::sync_with_stdio(0); cin.tie(0);


int32_t main(){

	new_data_set st;
	int n;cin>>n;

	for(int i=0;i<n;i++){
		int x;cin>>x;
		st.insert(x);
	}
	for(int i=0;i<n;i++){
		cout<<*st.find_by_order(i)<<endl;
	}
	int x;cin>>x;
	cout<<st.order_of_key(x)<<endl;


	return 0;
}