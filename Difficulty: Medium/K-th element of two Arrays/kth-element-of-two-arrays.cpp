class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
         int n1 = a.size(), n2 = b.size();
    if (n1 > n2) return kthElement(b, a, k); 

    int l = max(0, k - n2), h = min(k, n1);

    while (l <= h) {
        int mid1 = (l + h) / 2;
        int mid2 = k - mid1;

        int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            h = mid1 - 1;
        } else {
            l = mid1 + 1;
        }
    }
    return -1;

    }
};