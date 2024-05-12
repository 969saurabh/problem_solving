//https://leetcode.com/problems/jump-game-ii/submissions/
class Solution {
public:
    int jump(vector<int>& nums) {
      /*  int n=nums.size();
        --n;
        vector<int> jump(nums.size(),INT_MAX);
        jump[0]=0;
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=i+1;j<=n&&j<=(i+nums[i]);j++)
            {
                jump[j]=min(jump[j],jump[i]+1);
                if(j==n)
                flag=1;
            }
            if(flag)
            break;
        }
        return jump[n];*/
        int n=nums.size()-1;
        int l=0,r=0,farthest=0;
        int res=0;
        while(r<n){
            int farthest=0;
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            res++;
        }
        return res;
    }
};