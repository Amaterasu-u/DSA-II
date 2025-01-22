#include<bits/stdc++.h>
using namespace std;

struct Node{
int Eow;
Node *children[26];
int childCount=0;
};

Node *root;

Node *createNode(){
    Node *n =(Node*) malloc(sizeof(Node));
    n->Eow=0;
    for(int i=0;i<26;i++){
        n->children[i]=NULL;
    }
    return n;
}


void insert(string s){
    Node *cur=root;
    for(int i=0;i<s.size();i++){
        int j=s[i]-'a';
        if(cur->children[j]==NULL){
            cur->children[j]=createNode();
            cur->childCount++;
        }
        cur=cur->children[j];
    }
    int count=cur->Eow;
    cur->Eow= ++count;
}

void printTRIE(Node *cur=root , string s=""){
    if(cur==NULL) return;
    if(cur->Eow>0){
        cout<<s<<endl;
    }
    for(int i=0;i<26;i++){
        if(cur->children[i]==NULL){
            continue;
        }
        char ch= i +'a';
        printTRIE(cur->children[i],s+ch);
    }
    
}


void collectWords(Node *cur, string s, string &result) {
    if(cur == NULL) return;
    if(cur->Eow > 0){
        result += s;
    }
    for(int i = 0; i < 26; i++){
        if(cur->children[i] != NULL){
            char ch = i + 'a';
            collectWords(cur->children[i], s + ch, result);
        }
    }
}

// string printWordsAsSingleString() {
//     string result = "";
//     collectWords(root, "", result);
//     //cout << "Words in Trie as a single string: " << result << endl;
//     return result;
// }

int find(string s){
 Node *cur=root;
 for(int i=0;i<s.size();i++){
    int j=s[i]-'a'; 
    if(cur->children[j]==NULL){
        return 0;
    }
    cur=cur->children[j];
 }   
 return cur->Eow; 
}


void printPrefix(Node *cur, string prefix) {
    if (cur == NULL) return;

    if (cur->Eow > 0) {
        reverse(prefix.begin() , prefix.end());
        cout << prefix<< endl;

    }

    for (int i = 0; i < 26; i++) {
        if (cur->children[i] != NULL) {
            char ch = i + 'a';
            printPrefix(cur->children[i], prefix + ch);
        }
    }
}

void prefixOf(string s) {
    Node *cur = root;
    for (int i = 0; i < s.size(); i++) {
        int j = s[i] - 'a';
        if (cur->children[j] == NULL) {
            return; // Prefix not found
        }
        cur = cur->children[j];
    }
    printPrefix(cur, s); // Print all words with the given prefix
}

void highestWord(string arr[]){
    int max=0;  
    string res="";
    for(int i=0;i<arr->length();i++){
        int temp=find(arr[i]);
        if(temp>max){
            max=temp;
            res=arr[i];
            }
    }
    cout<<res<<endl;
}





bool isLeaf(Node*cur){
    bool res=1;

    for(int i=0;i<26;i++){
        if(cur->children[i]!=NULL){
            res=0;
        }
    }
    return res;
}

void longestPrefix(string &s){
    Node*cur=root;
    root=createNode();
    int i=0;
     while (cur != NULL && cur->childCount == 1 && !isLeaf(cur)) {
    int j=s[i]-'a';
    i++;
    cur=cur->children[j];
    }
    cout<<s.substr(0,i);
}

int main() {
    root = createNode();

    // String array containing all the words
    string words[] = {"miopst","miopnt" , "miopt" , "miopne" };

    // Insert each word into the Trie
    for (const string &word : words) {
        insert(word);
    }

    cout << "Words in Trie:" << endl;
    printTRIE();
    cout << "---" << endl;

    cout << "Words with prefix 'mi':" << endl;
     prefixOf("mi");
//highestWord(words);
//palindrome(words);
//longestPrefix(words[0]);

}
