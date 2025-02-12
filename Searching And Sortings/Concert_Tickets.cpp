#include <bits/stdc++.h>

using namespace std;


#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e9;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    sort(a.begin(), a.end());

    // freq map
    // vector<int> f(n+1);
    // for(int i=0; i<n; i++){
    //     f[a[i]]++;
    // }

    map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[a[i]]++;
    }

    // 
    set<int> s(a.begin(), a.end());
    for (int x : b) {
        auto it = s.upper_bound(x);
        if (it == s.begin()) {
            cout << -1 << "\n";
        }else {
            --it;
            cout << *it << "\n";
            mp[*it]--;
            if(mp[*it] == 0){
                s.erase(it);
            }
        }
    } 
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}