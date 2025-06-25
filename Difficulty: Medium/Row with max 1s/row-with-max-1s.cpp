// User function template for C++
class Solution {
    public:
    int lower_bound(vector<int> &a, int m, int x) {
    int low = 0, high = m - 1;
    int ans = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    int max_ones = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int first_one_index = lower_bound(a[i], m, 1);
        int num_ones = m - first_one_index;
        if (num_ones > max_ones) {
            max_ones = num_ones;
            index = i;
        }
    }
    return index;
    }
};