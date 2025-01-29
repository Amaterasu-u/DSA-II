#include<bits/stdc++.h>
using namespace std;


struct Node{ // Each Node will contain an EoW variable and an array of 26 elements
// the array is a Node type pointer as it must point to the NEXT NODE
bool EoW;
int count;
Node* children[26];
};

Node* root;// root is global because every funtion uses it 

Node *createNode(){
    Node* n= new Node();
    n->EoW=false;
    n->count=0;
    for(int i=0;i<26;i++){
        n->children[i]=NULL;
    }
    return n;
}

void insert(string s){
  Node *cur=root;
  for(int i=0;i<s.size();i++){
    int j = s[i] - 'A';// checking the relative position(index) input a hoile a-a=0
    // b hoile b-a=1 so index peye jacchi
    if(cur->children[j]==NULL){//checking if there is an edge present or not
    // mane amar jei input shei input er jonno kono edge create hoise ki na
        cur->children[j]=createNode();// edge na thakle create korbo ekta new node
    }
    cur = cur->children[j];//new node e ekhon cur point korbe
    cur->count++;
}

cur->EoW=true;// end of word e ashle EoW ke true kore dibe indicating the complete string in TRIE
}

void printTRIE(Node *cur=root , string s=""){// i will traverse the entire trie
// and will print every thing tai s ke null nisi to store the elements of trie i.e the words in it
if(cur->EoW){
    cout<< s << endl;

}
cout<<" string-> "<<s<<" Appearance: "<<cur->count<<endl;
for(int i=0;i<26;i++){// 26 because full trie visit korbo
if(cur->children[i]==NULL){
    continue;
}
char ch = i + 'A';
printTRIE(cur->children[i], s+ch);
}
}

bool find( string s){
     Node *cur=root; // ITERATIVE WAY
  for(int i=0;i<s.size();i++){
    int j = s[i] - 'A';
    if(cur->children[j]==NULL){
        return false;
    }
    cur = cur->children[j];
}
return cur->EoW;
}

// bool isLeaf(Node*cur){
//     bool ret=1;
//     for(int i=0;i<26;i++){
//         if(cur->children[i]!=NULL) ret=0;// check if children ase naki nai
//     }
//     return ret;
// }

// bool isJunction(Node * cur){/// should I not delete ? true means stop deleting
//     if(cur->EoW) return true;// onno kono word er eow jodi thake
//     if(isLeaf(cur)) return false;
//     return true;

// }


// void removeEdge( Node *cur , char c , int d){
// if(d==0) return;
// int rp=c-'a';
// Node *v = cur->children[rp];
// cur->children[rp]=NULL;
// free(v);
// }


// int deleteNode(string s , Node*cur=root ,int i=0){
// if(cur==NULL) return 0;
// if(i==s.size()){
    
//     if(cur->EoW==0) return 0;// jodi na thake trie er moddhe 
//     if(!isLeaf(cur)){// Leaf na hoile shudhu unmark korbo
//         cur->EoW=0;
//         return 0;
//     }
//     return 1;
// }
// int j=s[i]-'a';
// int d=deleteNode(s,cur->children[j],i+1);
// removeEdge(cur , s[i] , d);// 
// if(isJunction(cur)) d=0;
// return d;

// }

int main(){
    root=createNode();//Root always same for all 

    insert("TC");
    insert("ACG");
     insert("TCCGTGC");
     insert("TCGCCGT");
     insert("ACGT");
     insert("ACGTGCGT");
    // insert("exit");
    
    // string a="kire";
    // reverse(a.begin(),a.end());
    // cout<<a<<endl;

    printTRIE();

    // cout<<find("mi")<<endl;
    // cout<<find("mist")<<endl;
    // cout<<find("cuet")<<endl;
    // cout<<find("mis")<<endl;

   // deleteNode("bati");
    //cout<<find("bati")<<endl;
//Node* a=createNode();
// a->EoW=true;
// if(a->children[1]==NULL){
//     cout<<"NULL "<<a->EoW<<endl;
// }
//cout<<find("bap")<<endl;

}