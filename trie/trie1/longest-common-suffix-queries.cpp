//https://leetcode.com/problems/longest-common-suffix-queries/
class Trie{
  public: struct trie{
      trie *child[26];
      int pos;  //index of word
      int size; //used for length compare
      trie()    
      {
        pos=INT_MAX;
        size=INT_MAX;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
      }
   };
   trie *start=new trie(); //initialize node
   void insert(string word,int pos)
   {
     trie *t=start;
     int n=word.length();
     if(t->size>n)
     {
        t->size=n;
        t->pos=pos;
     }
     //for suffix insert word from last
     for(int i=n-1;i>=0;i--)
     {
        if(t->child[word[i]-'a']==NULL)
        {
            t->child[word[i]-'a']=new trie();
        }
        t=t->child[word[i]-'a'];
        if(t->size>n)
        {
            t->size=n;
            t->pos=pos;
        }
     }
   }
   int findIndex(string s)
   {
    trie *t=start;
    //for suffix matching access character from last
    for(int i=s.length()-1;i>=0;i--)
    {
        if(t->child[s[i]-'a']==NULL)
        {
            return t->pos;
        }
        t=t->child[s[i]-'a'];
    }
    return t->pos;
   }

};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> result;
        Trie *t=new Trie();
        //insert word
        for(int i=0;i<wordsContainer.size();i++)
        {
          t->insert(wordsContainer[i],i);
        }
        //search query
        for(int i=0;i<wordsQuery.size();i++)
        {
            result.push_back(t->findIndex(wordsQuery[i]));
        }
        return result;
    }
};