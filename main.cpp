#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const long long INF = INT64_MAX;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i ++){
        cin >> v[i];
    }
    vector<long long> suff1(n), suff2(n);
    suff1[v.size() - 1] = v[v.size() - 1];
    suff2[v.size() - 1] = v[v.size() - 1];
    for (int i = n - 2; i >= 0; i --){
        suff1[i] = v[i] + suff1[i + 1];
        suff2[i] = suff1[i] + suff2[i + 1];
    }
    cin >> k;
    for (int i = 0; i < k; i ++){
       int l, r;
       cin >> l >> r;
       l --; r --;
       long long res;
       if (r == n - 1){
           res = suff2[l];
       }else{
           res = suff2[l] - suff2[r + 1] - (r - l + 1) * suff1[r + 1];
       }
       cout << res << "\n";
    }

}