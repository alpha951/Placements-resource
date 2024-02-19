#include <bits/stdc++.h>
#include <iterator>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mini = INT_MAX, k = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < mini) {
            mini = v[i];
            k = i;
        }
    }

    // rotate left by k
    int j = 1;
    while (j <= k) {
        int last = v[0];
        for (int i = 0; i < n - 1; i++) {
            v[i] = v[i + 1];
        }
        v[n - 1] = last;
        j++;
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
