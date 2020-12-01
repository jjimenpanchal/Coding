// Problem Link -https://cses.fi/problemset/task/1145/
/*By Jimen Luhar */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define int long long
#define ll 				long long
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
int ans=0;
bool cmp(pii &p1, pii &p2)
{
	if (p1.ff==p2.ff)
		return p1.ss>p2.ss;
	return p1.ff<p2.ff;
}

int query(int *tree, int s, int e, int l, int r, int root)
{
	// if (s==e)
	// 	return tree[root];
	if (l<=s && r>=e)
		return tree[root];
	if (s>r or e<l)
		return 0;

	int mid=(s+e)/2;
	return max(query(tree, s, mid, l, r, root*2),query(tree, mid+1, e, l, r, root*2+1));
}

void update(int *tree, int s, int e, int idx, int value, int root)
{
	if (s==e)
	{
		tree[root]=value;
		return;
	}

	int  mid=(s+e)/2;
	if (idx>mid)
		update(tree, mid+1, e, idx, value, root*2+1);
	else
		update(tree, s, mid, idx, value, root*2);
	tree[root]=max(tree[root*2],tree[root*2 +1]);
	return ;
}


int32_t main() {
	clock_t begin = clock();
	file_i_o();

	int n,x;
	cin>>n;
	vector<pii>arr;
	int *tree=new int[4*n];
	for(int i=0;i<4*n;i++)
		tree[i]=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		arr.pb({x,i});
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<n;i++)
	{
		if (i==0)
		{
			int len=1;
			update(tree,0,n-1,arr[0].ss,len,1);	
			ans=max(ans,len);
			continue;
		}
		int len=query(tree,0,n-1,0,arr[i].ss-1,1);
		ans=max(ans,len+1);
		update(tree,0,n-1,arr[i].ss,len+1,1);
	}
	// for(int i=0;i<4*n;i++)
	// 	cout<<tree[i]<<" ";
	cout<<ans;



	












	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
