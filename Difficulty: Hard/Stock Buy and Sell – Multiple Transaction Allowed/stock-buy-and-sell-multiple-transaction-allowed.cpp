//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
    
        int aheadbuy, aheadnotbuy, currbuy, currnotbuy;
        aheadbuy=aheadnotbuy=0;
        
        for(int ind=n-1;ind>=0;ind--){
            
            currnotbuy=max(prices[ind]+aheadbuy, aheadnotbuy);
            
            currbuy= max(-prices[ind]+aheadnotbuy, aheadbuy);
            
            aheadbuy= currbuy;
            aheadnotbuy=currnotbuy;
            
            
        }
        
        return aheadbuy;
    
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends