//https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
class Trie{
    public:
    struct trie{
        bool ispresent;
        int countcommonprefix=0;
        trie* child[26];
        trie()
        {
            ispresent=false;
            countcommonprefix=1;
             for(int i=0;i<26;i++)
             {
                child[i]=NULL;
             }
        }
    };
    trie* start=new trie();
    void insert(string &word)
    {
        trie* temp=start;
        for(int i=0;i<word.length();i++)
        {
            if(temp->child[word[i]-'a']==NULL)
            {
                temp->child[word[i]-'a']=new trie();
                temp=temp->child[word[i]-'a'];
            }
            else
            {
                temp=temp->child[word[i]-'a'];
                 temp->countcommonprefix=temp->countcommonprefix+1;   
            }
        }
    }
    int countprefixword(string &word)
    {
        trie* temp=start;
        int count=0;
        for(int i=0;i<word.length();i++)
        {
           if(temp->child[word[i]-'a']==NULL)
           return count;
           temp=temp->child[word[i]-'a'];
           count+=temp->countcommonprefix;
        }
        return count;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *t=new Trie();
        vector<int> prefixScores;
        for(int i=0;i<words.size();i++)
        {
            t->insert(words[i]);
        }
        for(int i=0;i<words.size();i++)
        {
            prefixScores.push_back(t->countprefixword(words[i]));
        }
        return prefixScores;
    }
};