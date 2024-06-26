//https://leetcode.com/problems/process-restricted-friend-requests/submissions/1267828722/
int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}

bool Union(vector<int> &ds, int i, int j){
	 i = find(ds, i), j = find(ds, j);
	 if(i==j) return false;
	 if(abs(ds[i]) < abs(ds[j])) swap(i,j); 
	 ds[i]+=ds[j]; 
	 ds[j]=i;
	 return true;
}

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> res;
        vector<int> ds(n, -1);
        for(auto &r : requests){
            int u = find(ds,r[0]), v = find(ds,r[1]), can = 1;
			
            for(auto &rt : restrictions){
                int u1 = find(ds,rt[0]), v1 = find(ds, rt[1]);
                if((u1==u && v1 == v) || (u1==v && v1==u)){ 
                    //restricted pair will be connected!! => Do not process the request
                    can = 0;
                    break;
                }
            }
            if(can) Union(ds,u,v);
            res.push_back(can);   
        }
        return res;
    }
};