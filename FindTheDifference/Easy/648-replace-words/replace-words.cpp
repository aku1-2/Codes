class Solution {
    class Node{
        public:
        Node* child[26];
        bool isEnd;
        Node(){
            isEnd= false;
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
        }
    };
    Node* root;
public:
      Solution(){
          root = new Node();
      }

      void insert(string word){
        Node* node = root;
        for(char ch: word){
            int index=ch-'a';
            if(node->child[index]==NULL)
               node->child[index]= new Node();
           node= node->child[index];
        }
        node->isEnd= true;
      }

      string search(string word){
        Node* node= root;
        string ans="";
        for(char ch: word){
            int index= ch-'a';
            if(node->child[index]==NULL)
            return word;
        ans +=ch;
        node=node->child[index];
        if(node->isEnd)
        return ans;
        }
        return word;
      }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string word: dictionary)
            insert(word);

    stringstream ss(sentence);
    string word;
    string result="";
    while(ss>>word){
        result +=search(word);
        result +=" ";
    }
    result.pop_back();
    return result;
    }
};