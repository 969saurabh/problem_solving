//https://leetcode.com/problems/count-pairs-with-xor-in-a-range/
class Trie {
public:
    struct trie {
        bool ispresent;
        int countcommonbit = 0;
        trie* bit[2];
        trie() {
            ispresent = false;
            countcommonbit = 1;
            for (int i = 0; i < 2; i++) {
                bit[i] = NULL;
            }
        }
    };
    trie* start = new trie();
    void insert(int number) {
        trie* temp = start;
        int k = 1;
        for (int i = 31; i >= 0; i--) {
            int t = (((k << i) & number) > 0) ? 1 : 0;
            if (temp->bit[t] == NULL) {
                temp->bit[t] = new trie();
                temp = temp->bit[t];
            } else {
                temp = temp->bit[t];
                temp->countcommonbit = temp->countcommonbit + 1;
            }
        }
        temp->ispresent = true;
    }
    int countnicepair(int number, int lsetbit[], int hsetbit[]) {
        trie *temp1 = start, *temp2 = start;
        int count1 = 0, count2 = 0;
        for (int i = 31; i >= 0; i--) {
            int t = ((1 << i) & number) > 0 ? 1 : 0;
            if (temp1 != NULL)
                if (hsetbit[i] == 1) {
                    if (temp1->bit[t] != NULL)
                        count1 += temp1->bit[t]->countcommonbit;
                    if (t == 1) {
                        temp1 = temp1->bit[0];
                    } else {
                        temp1 = temp1->bit[1];
                    }
                } else {
                    temp1 = temp1->bit[t];
                }
            if (temp2 != NULL)
                if (lsetbit[i] == 1) {
                    if (temp2->bit[t] != NULL)
                        count2 += temp2->bit[t]->countcommonbit;
                    if (t == 1) {

                        temp2 = temp2->bit[0];
                    } else {
                        temp2 = temp2->bit[1];
                    }
                } else {
                    temp2 = temp2->bit[t];
                }
        }
        return count1 - count2;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int lsetbit[32], hsetbit[32];
        high += 1;
        for (int i = 31; i >= 0; i--) {
            hsetbit[i] = ((1 << i) & high) > 0 ? 1 : 0;
            lsetbit[i] = ((1 << i) & low) > 0 ? 1 : 0;
        }
        int ans = 0;
        Trie* t = new Trie();
        for (int i = 0; i < nums.size(); i++) {
            t->insert(nums[i]);
            ans += t->countnicepair(nums[i], lsetbit, hsetbit);
        }
        return ans;
    }
};