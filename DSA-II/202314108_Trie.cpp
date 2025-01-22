#include <bits/stdc++.h>
using namespace std; /*Yeaser Ahmad
                       202314108*/

class Node {
    public:
    int count;           
    Node* children[4];//specified only 4 children
    bool eow;
};

class Trie {

    Node* root;
    int max_dna_count;

    Node* createNode() {
        Node* node = new Node();
        node->count = 0;
        node->eow = false;
        for (int i = 0; i < 4; i++) {
            node->children[i] = NULL;
        }
        return node;
    }

public:

    Trie() {
        root = createNode();
        max_dna_count = 0;
    }


    void insert(string s) {
        Node* cur = root;
        for (char ch : s) {
            int i;
            if (ch == 'A') i = 0;
            else if (ch == 'C') i = 1;
            else if (ch == 'G') i = 2;
            else if (ch == 'T') i = 3;

            if (cur->children[i] == NULL) {
                cur->children[i] = createNode();
            }
            cur = cur->children[i];
            cur->count++;
            max_dna_count = max(max_dna_count, cur->count);
        }
        cur->eow=true;
    }

string print_best_dna(Node *cur=NULL, string s=""){
    
    string bestDNA="";
    if(cur==NULL) cur=root;

    if (cur->eow && s.size() > bestDNA.size()) { //must be a valid string i.e previously inserted in the trie
            bestDNA = s;
        }

    for(int i=0;i<4;i++){
        if(cur->children[i]!=NULL && cur->children[i]->count==max_dna_count){
            char c;
            if(i==0)c='A';
            else if(i==1)c='C';
            else if(i==2)c='G';
            else if(i==3)c='T';
           string dna=print_best_dna(cur->children[i],s+c);
           if(dna.size()>bestDNA.size()) bestDNA=dna;
        }
    }
        return bestDNA;
    
}

};

int main() {
    Trie trie;

    int q;
    cin >> q;

    while(q--) {
        int a;
        cin >> a;
        if (a== 1) {
            string dna;
            cin >> dna;
            trie.insert(dna);
        } 
        else if (a == 2) {
            string s=trie.print_best_dna();
            cout << s << endl;
        }
    }

}
