#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool eow;
    Node* children[26];
};

Node* root;

Node* createNode() {
    Node* n = new Node();
    n->eow = false;
    for (int i = 0; i < 26; i++) {
        n->children[i] = NULL;
    }
    return n;
}

void insert(string s) {
    Node* cur = root;
    for (int i = 0; i < s.size(); i++) {
        int j = s[i] - 'a';
        if (cur->children[j] == NULL) {
            cur->children[j] = createNode();
        }
        cur = cur->children[j];
    }
    cur->eow = true;
}

string print(Node* cur = root, string s = "") {
    if (cur->eow) {
        return s;
    }
    for (int i = 0; i < 26; i++) {
        if (cur->children[i] != NULL) {
            char ch = i + 'a';
            string result = print(cur->children[i], s + ch);
            if (!result.empty()) {
                return result; // Return the first valid result
            }
        }
    }
    return "";
}

bool isLeaf(Node*cur){
    bool ret=1;
    for(int i=0;i<26;i++){
        if(cur->children[i]!=NULL) ret=0;// check if children ase naki nai
    }
    return ret;
}

bool isJunction(Node * cur){/// should I not delete ? true means stop deleting
    if(cur->eow) return true;// onno kono word er eow jodi thake
    if(isLeaf(cur)) return false;
    return true;

}


void removeEdge( Node *cur , char c , int d){
if(d==0) return;
int rp=c-'a';
Node *v = cur->children[rp];
cur->children[rp]=NULL;
free(v);
}


int deleteNode(string s , Node*cur=root ,int i=0){
if(cur==NULL) return 0;
if(i==s.size()){
    
    if(cur->eow==0) return 0;// jodi na thake trie er moddhe 
    if(!isLeaf(cur)){// Leaf na hoile shudhu unmark korbo
        cur->eow=0;
        return 0;
    }
    return 1;
}
int j=s[i]-'a';
int d=deleteNode(s,cur->children[j],i+1);
removeEdge(cur , s[i] , d);// 
if(isJunction(cur)) d=0;
return d;

}

void pp(Node *cur , string prefix){
    if(cur==NULL) return;
    if(cur->eow){
        reverse(prefix.begin(),prefix.end());
        cout<<prefix<<endl;
    }
    for(int i=0;i<26;i++){
        if(cur->children[i]==NULL){
            continue;
        }
        char ch= i + 'a';
        pp(cur->children[i] , prefix+ch);
    }
}

void prefix(string s){
    Node *cur=root;
    for(int i=0;i<s.size();i++){
        int j=s[i]-'a';
        if(cur->children[j]==NULL) return;
        cur=cur->children[j];
    }
    pp(cur,s);
}

// void printBEST(Node *cur=NULL , string s=""){
//     if(cur==NULL) cur=root;

//     static bestDNA="";
//     if(cur->eow && s.size()>bestDNA.size()){
//         bestDNA=s;
//     }
//     for(int i=0;i<26;i++){
//         if(cur->children[i]!=NULL && cur->children[i]->cout==maxcount){
//             char ch=i + 'a';
//             printBEST(cur->children[i] , s+ch);
//         }
//     }
//     if(cur==root){
//         cout<<bestDNA<<endl;
//         bestDNA="";
//     }
// }

int main() {
    root = createNode();
    string arr[] = {"mist", "must", "mpst", "sadasd", "ttust"};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
          string s=arr[i];
          reverse(s.begin(),s.end());
          insert(s);
    }
     prefix("ts");
}
