#include <iostream>

using namespace std;

struct Trie{
    //Change the value to 256 if the string is going to have special characters and other chars
    Trie *childrens[26];
    bool wordCompleted; //to keep track if there exist a word completing at the given point
};

Trie* createNode(){

    Trie *node = new Trie;
    node->wordCompleted = false;
    for(int i=0;i<26;i++){
        node->childrens[i] = NULL;
    }
    return node;
};


void insert(Trie *root,string str){

    Trie* curr = root;
    int size = str.size();
    for(int i=0;i<size;i++){

        if(!curr->childrens[str[i]-'a']){
            curr->childrens[str[i]-'a'] = createNode();
        }
        curr = curr->childrens[str[i]-'a'];
    }
    curr->wordCompleted = true;
}

bool find(Trie *root,string required){

    int size = required.size();
    Trie *current = root;
    for(int i=0;i<size;i++){

        if(!current->childrens[required[i]-'a']) return false;
        current = current->childrens[required[i]-'a'];
    }
    return current && current->wordCompleted;
}



int main(){

    Trie *root = createNode();

    string str[] = {"asfd","gdf","sdgfsdfgs","kjdhdgf"};

    for(string s:str) insert(root,s);

    if(find(root,"asfd")) cout << "Present";
    else cout << "Absent";
}
