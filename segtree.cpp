#include <bits/stdc++.h>
using namespace std;

// Header files to implement ordered set
// Common file
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// namespace necessary for GNU based
// policy based data structures
using namespace __gnu_pbds;

// Declaring ordered_set for pair<int,int>
typedef tree<pair<int, int>, null_type,
             less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set_pair;

#define ll long long int
#define viip vector<pair<ll, ll>>
#define ff(i, a, b) for (ll i = a; i < b; ++i)
#define fr(i, a, b) for (ll i = a; i >= b; --i)
#define vs vector<string>
#define vec vector<ll>
#define mpll map<ll, ll>
#define mpcl map<char, ll>
#define mpsl map<string, ll>
#define pb push_back
#define vvi vector<vector<ll>>
#define bs(v, a) binary_search(v.begin(), v.end(), a)
// #define endl
typedef pair<int, int> pi;
typedef long double ld;

#define srtv(v, n) sort(v.begin(), v.end())
#define isortarry(arr, n) sort(arr, arr + n)
#define dsortarry(arr, n) sort(arr, arr + n, greater<int>())
#define mod 1000000007
ll mods = 1000000007;

// build segtree

vec segtree;

void build(ll start, ll end, vec v, ll ind)
{
    // base case
    if (start == end)
    {
        segtree[ind] = v[start];
        return;
    }
    ll mid = (start + end) / 2;
    ll left = 2 * ind + 1;
    ll right = 2 * ind + 2;
    build(start, mid, v, left);
    build(mid + 1, end, v, right);
    segtree[ind] = min(segtree[left], segtree[right]);
}

ll query(ll low, ll high, ll l, ll r, ll ind)
{
    // complete overlap

    if (low >= l && high <= r)
    {
        return segtree[ind];
    }

    // no overlap

    if (high < l || low > r)
    {
        return INT_MAX;
    }

    // partial overlap
    ll mid = (low + high) / 2;

    ll left = query(low, mid, l, r, 2 * ind + 1);
    ll right = query(mid + 1, high, l, r, 2 * ind + 2);
    return min(left, right);
}

int main()
{
    ll n;
    cin >> n;
    // segtree.reserve(4 * n);
    vec v(n);
    for (ll i = 0; i < n; i += 1)

    {
        cin >> v[i];
    }
    segtree.resize(4 * n);
    build(0, n - 1, v, 0);
    cout << query(0, n - 1, 0, 3, 0);

    return 0;
}