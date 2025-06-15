// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        vector<int> sortedArr(arr, arr + n);
    sort(sortedArr.begin(), sortedArr.end());

    // Map value → queue of indices where it appears in sorted array
    unordered_map<int, queue<int>> positionMap;
    for (int i = 0; i < n; i++) {
        positionMap[sortedArr[i]].push(i);
    }

    for (int i = 0; i < n; i++) {
        int correctIndex = positionMap[arr[i]].front();
        positionMap[arr[i]].pop();

        if (abs(i - correctIndex) > k) {
            return "No";
        }
    }

    return "Yes";
    }
};