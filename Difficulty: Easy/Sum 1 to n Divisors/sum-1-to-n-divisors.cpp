class Solution {
    
  public:
    long long findsumofdivisor(long long n){
        long long sum=0;
        for(int i=1 ;i*i<=n;i++){
            
            if(n%i==0) {
                sum+=i;
               if((n/i)!= i) sum+=(n/i);
            }
        }
        return sum;
    }
    long long sumOfDivisors(long long n) {
        // Code here
        long long sum=0;
        for(int i=1 ;i<=n;i++){
            sum+= findsumofdivisor(i);
            
        }
        return sum;
    }
};