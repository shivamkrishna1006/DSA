class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       int n=spells.size();
       int m=potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n, 0); 
        for(int i=0;i<n;i++){
            long long x=spells[i];
            int left=0;
            int right=m-1;
           
            while(left<=right){
             int mid=(left+right)/2;
             long long product = x*potions[mid];
              if(product>=success){
                  right=mid-1;
              }else{
                left=mid+1;
              }
              
            
            }
             ans[i]=m-left;
        }

        return ans;

    }
};