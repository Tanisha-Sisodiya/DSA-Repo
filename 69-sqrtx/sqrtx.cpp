class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
        return x;
       
       
       
        else{

        

        int s=0;
        int e=x;
        long long int  mid = s+ (e-s)/2;

        
        while(s<e){
            
            if(mid*mid <= x){
                 s= mid+1;
            }
            else
                e = mid;
               
            mid= s+(e-s)/2;
        }
        return s-1;
        }
        
    }
};