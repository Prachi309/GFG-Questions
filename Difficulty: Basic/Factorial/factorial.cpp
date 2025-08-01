class Solution {
  public:

    void factorial(int n) {
        // code 
       long long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        cout << fact << endl;
    }
};