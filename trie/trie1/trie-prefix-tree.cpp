//https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
public:
 Trie(){}
  struct trie
  {    
       trie():character(26){} //declare size of vector by creating object
        bool ispresent=false;
        vector<trie*> character;
  };
  trie *start=new trie(); 
    void insert(string word) {
        trie *temp=start;
        for(int i=0;i<word.length();i++)
        {
            if(temp->character[word[i]-'a']==NULL)
            {
                temp->character[word[i]-'a']=new trie();
            }
            temp=temp->character[word[i]-'a'];
        }
        temp->ispresent=true;
    }
    
    bool search(string word) {
        trie *temp=start;
        for(int i=0;i<word.length();i++)
        {
            if(temp->character[word[i]-'a']==NULL)
            return false;
            temp=temp->character[word[i]-'a'];
        }
        return temp->ispresent;
    }
    
    bool startsWith(string prefix) {
        trie* temp=start;
        for(int i=0;i<prefix.length();i++)
        {
            if(temp->character[prefix[i]-'a']==NULL)
            return false;
            temp=temp->character[prefix[i]-'a'];
        }
        return true;
    }
};