#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const long long INF = INT64_MAX;

typedef struct Edge {
    long long to, c;
}Ed;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> count(n + 1, 0);
    count[0] = 1;
    for (int j = 1; j <= n; j ++){
        for (int i = 1; i <= j; i ++){
            count[j] = (count[j] + count[i - 1] * count[j - i]) % m;
        }
    }
    cout << count[n];
}