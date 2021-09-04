#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool vis[110];
bool root[110];
vector< vector<int> > edge;
int n, a, b, m;
int dfs(int v);

int main(){
    fill(&vis[0], &vis[110], false);
    fill(&root[0], &root[110], true);

    cin >> n;
    cin >> a >> b;
    cin >> m;

    for(int i = 0; i <= n; ++i){ // create edge vec
        vector<int> tmp;
        edge.push_back(tmp);
    }

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y; // par, child
        edge[x].push_back(y); // link.  x -> y
        root[y] = false; // y can never be root.
    }
    if(a == b) return 0;

    int ans = -1e9;
    for(int i = 1; i <= n; ++i){
        
        if(root[i]) {vis[i] = true; ans = max(ans, dfs(i));} // init search
    }
    if(ans <= 0) cout << -1; // a and b aren't a family member.
    else cout << ans; // family tree between a, b is found.
}

int dfs(int v){
    bool flag = false;
    if(v == a || v == b) flag = true; // found a or b
    int cp = -1; // Am if closest parent? if cp == 1: YES
    int converge = 0;
    for(auto v2 : edge[v]){
        if(vis[v2] == false){
            vis[v2] = true;
            int res = dfs(v2);
            if(res != 0){ // sth's found
                if(res < 0 && flag) return -res; // found both a and b,  and one of two is myself. I'm both the party and cp!
                else if(res < 0) { // found a or b. I will test my self if I'm cp at the end of for loop.
                    ++cp; // if cp increased up to 1, I am cp.
                    converge += res; // save valid family tree num
                    }
                else return res; // res > 0. Seems like I'm "the parent" of the "cp". I'll deliver this to ans.
            }

        }
    }
    
    if(cp == 0) return converge - 1; // one of the party is found. -1 it to calculate family tree num correctly.
    else if(cp == 1) return -converge; // I'm NOT the party, but Im cp. 
    else if(flag) return -1; // I'm a or b.
    return 0; // I'm nothing.
}