#include <string>
#include <iostream>
using namespace std;

string v = "AEIOU";
string w;
string occ = "";
int ans = -1;

bool dfs(int depth); // occurence

int solution(string word) {
    w = word; //
    dfs(0);
    return ans;
}

bool dfs(int depth){
    ++ans;
    if(occ == w) return true; // compare cur with given
    if(depth == 5) return false;

    for(int i = 0; i < 5; ++i){
        occ.push_back(v[i]); // backtrack
        if(dfs(depth + 1)) return true;
        occ.pop_back();
    }
    return false;
}