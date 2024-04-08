//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class Trie{
  public: struct trie {
        trie* bit[2];
        trie() {
            bit[0]=bit[1]=NULL;
        }
    };
    trie *start=new trie();
    void insert(int number)
    {
       trie *temp=start;
       for(int i=31;i>=0;i--)
       {
        int t=((1<<i)&number)>0?1:0;
        if(temp->bit[t]==NULL)
        {
            temp->bit[t]=new trie();
        }
            temp=temp->bit[t];
       }
    }
    int xorResult(int number)
    {
        int ans=0;
        trie *temp=start;
        for(int i=31;i>=0;i--)
        {
            int t=((1<<i)&number)>0?1:0;
            
            if(temp->bit[1-t]!=NULL){
               ans+=1<<i;
               temp=temp->bit[1-t];
            }
            else
            {
               temp=temp->bit[t];
            }
        }
        return ans;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor=0;
        Trie *t=new Trie();
        for(int i=0;i<nums.size();i++)
        {
           t->insert(nums[i]);
           maxXor=max(maxXor,t->xorResult(nums[i]));
        }
        return maxXor;
    }
};