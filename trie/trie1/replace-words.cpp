//https://leetcode.com/problems/replace-words/
class Trie{
    public:struct trie{
       trie* character[26];
       bool isword;
       trie()
       {
        isword=false;
         for(int i=0;i<26;i++)
         character[i]=NULL;
       }
    };
    trie *start=new trie();
    void insert(string s)
    {
        trie *t=start;
        for(int i=0;i<s.length();i++)
        {
            if(t->character[s[i]-'a']==NULL)
            {
                t->character[s[i]-'a']=new trie();
            }
            t=t->character[s[i]-'a'];
        }
        t->isword=true;
    }
    string rootWord(string s)
    {
        trie* t=start;
        string r;
        for(int i=0;i<s.length();i++)
        {  
            if(t->character[s[i]-'a']==NULL)
            return s;
            t=t->character[s[i]-'a'];
            r+=s[i];
            if(t->isword==true)
            return r;
          
        }
        return s;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie *t=new Trie();
        for(int i=0;i<dictionary.size();i++)
        {
           t->insert(dictionary[i]);
        }
        for(int i=0;i<sentence.length();i++)
        {
            string s;
            int j=i;
            while(j<sentence.length()&&sentence[j]!=' ')
            {
                s+=sentence[j];
                i++;
                j++;
            }
            ans+=t->rootWord(s);
            if(i<(sentence.length()-1))
            ans+=" ";
        }
        return ans;
    }
};