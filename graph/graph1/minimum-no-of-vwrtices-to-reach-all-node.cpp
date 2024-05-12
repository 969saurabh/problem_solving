//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> v(n);
        for(int i=0;i<edges.size();i++)
        {
            v[edges[i][1]]=1;
        }
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            result.push_back(i);
        }
        return result;
    }
};