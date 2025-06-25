class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int n1= a.size(), n2=b.size();
        if(n1>n2) return medianOf2(b,a);
        
        int l=0,h=n1;
        int left = (n1+n2+1)/2;
        
        while(l<=h){
            int mid1 =(l+h)/2;
            int mid2 = left-mid1;
            
            int r1=INT_MAX,r2=INT_MAX;
            int l1 =INT_MIN,l2=INT_MIN;
            
            if(mid1<n1) r1= a[mid1];
            if(mid2<n2) r2= b[mid2];
            if(mid1-1 >=0)  l1 =a[mid1-1];
             if(mid2-1 >=0)  l2 =b[mid2-1];
             
             if(l1<=r2 && l2 <=r1){
                 if ((n1 + n2) % 2 == 1) return max(l1, l2);
            else return (max(l1, l2) + min(r1, r2)) / 2.0; 
             }
             else if(l1 >r2) h=mid1-1;
             else l=mid1+1;
        }
        return 0;
    }
};