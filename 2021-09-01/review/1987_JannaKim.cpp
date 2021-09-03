#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i, n, m) for (int i = (n) ; i < (m); ++i) 

bool vis[65 + 30]; // A ~ Z
vector <string> board(20, "");
int r, c;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int dfs(int y, int x);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> r >> c;
    for(int i = 0; i < r; ++i) // input
        cin >> board[i];
    
    fill(&vis[0], &vis[65 + 30], false);

    int ans = 1;

    int alp = board[0][0];

    vis[alp] = true;
    ans = max(ans, dfs(0, 0)); // traveling start loc : (0, 0)
    vis[alp] = false;

    cout <<ans;
}

bool bound(int y, int x){
    if(y < 0 || y >= r) return false;
    if(x < 0 || x >= c) return false;
    return true;
}

int ny, nx;


int dfs(int y, int x){
    int step = 1;

    for(int d = 0; d < 4; ++d){ // I
        ny = y + dy[d];
        nx = x + dx[d];
        int alp = board[ny][nx];

        if(bound(ny, nx) && vis[alp] == false){// if this "alp" 'not stepped in MY trace   * loc or sequence doesn't matter *
            vis[alp] = true; // lick!
            step = max(step, 1 + dfs(ny, nx)); // why + 1 ? because "I" (cureent rec) stepped.
            vis[alp] = false; // unlick!
        }
    }

    return step;
}