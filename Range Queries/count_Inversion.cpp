#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std::chrono;
using namespace std;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define int long long
#define loop(i, start, end) for (int i = start; i <= end; i++)
#define rloop(i, start, end) for (int i = start; i >= end; i--)
#define read(a,n) loop(i,0,n-1) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define vec(x) vector<x>
#define sz(v) (int)v.size() 
#define UB upper_bound
#define LB lower_bound
#define all(v) (v).begin(),(v).end()
#define arl(v) (v).rbegin(),(v).rend()
#define fsp(a) fixed<<setprecision(a)
#define mem(a,with) memset(a, with, sizeof (a))
#define vmn(a) (*min_element(a.begin(),a.end()))   
#define vmx(a) (*max_element(a.begin(),a.end()))
#define bs(a,key) binary_search(all(a),key)    /// return bool.
#define rotl(a,x) rotate(a.begin(),a.begin()+x,a.end());
#define rotr(a,x) rotl(a,a.size()-x);
#define nl cout<<"\n"
#define dbg(x) cerr << #x << " :: " << x << endl;
#define dbg2(x, y) cerr << #x << " :: " << x << "\t" << #y << " :: " << y << endl;
#define MOD 1000000007
#define f first
#define s second
int add(int x, int y) {int res = x + y; return (res >= MOD ? res - MOD : res);}
int mul(int x, int y) {int res = x * y; return (res >= MOD ? res % MOD : res);}
int power(int x, int y) {int res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}

const int N = 1e5+10;
int bit[N];

void update(int i, int x){
    for(; i < N; i += (i&-i)) bit[i] += x;
}

int sum(int i){
    int ans = 0;
    for(; i > 0; i -= (i&-i)) ans += bit[i];
    return ans;
}

void solve(){
    //code goes here
    int n;
    cin >> n;
    int a[n+10];
    map<int,int> mp;
    loop(i,1,n){
        cin >> a[i];
        mp[a[i]];
    }


    // compression of numbers for the case where a[i] > 10 ^ 6
    int ptr = 1;
    for(auto &pr : mp){
        pr.second = ptr++;
    }

    loop(i,1,n){
        a[i] = mp[a[i]];
    }

    // Finding Inversion count


    int inversion_ct = 0;
    loop(i,1,n){
        inversion_ct += (sum(N-5) - sum(a[i]));
        update(a[i], 1);
    }

    cout << inversion_ct << endl;
    
}

int32_t main()
{
auto start = chrono::high_resolution_clock::now();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
    int t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<microseconds>(stop - start);
    cout<<"\n\nExecuted In: "<<duration.count()<<" ms";
#endif
    return 0;
}
