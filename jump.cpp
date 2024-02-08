// !! om namah bhagwate vasudevay !!
#include <bits/stdc++.h>
using namespace std;

class segTree {
    vector<int> seg;

public:
    segTree(int size) {
        seg.resize(4 * size);
    }

    void build(int idx, int low, int high, int arr[]) {
        if (low == high) {
            seg[idx] = arr[low];  // Fix: Use arr[low] instead of arr[low]
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r, int arr[]) {
        if (r < low || l > high) {
            return INT_MAX;
        }
        if (low >= l && high <= r) {
            return seg[idx];
        }
        int mid = low + (high - low) / 2;
        int left = query(2 * idx + 1, low, mid, l, r, arr);
        int right = query(2 * idx + 2, mid + 1, high, l, r, arr);
        return min(left, right);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    segTree sg(n);
    sg.build(0, 0, n - 1, arr);
    while (q--) {
        int l, r;
        cin >> l >> r;
        r--;
        l--;
        cout << sg.query(0, 0, n - 1, l, r, arr) << endl;
    }
    return 0;
}
