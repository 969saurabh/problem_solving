//https://www.geeksforgeeks.org/problems/adjacents-are-not-allowed3528/1
// User function Template for C++

class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
        // code here
        vector<int> ans(N+1);
        if(N==1)
        return max(mat[0][0],mat[1][0]);
        ans[1]=max(mat[0][0],mat[1][0]);
        for(int i=2;i<=N;i++){
            int t=max(mat[0][i-1],mat[1][i-1]);
            ans[i]=max(t+ans[i-2],ans[i-1]);
        }
        return ans[N];
        
    }
};