#include <iostream>
#include <algorithm>

using namespace std;

int row_count, col_count;

char board[20][20];
bool visit[65 + 30];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool isInBound(int row, int col) {
  if (row < 0 || row >= row_count) {
    return false;
  }
  if (col < 0 || col >= col_count) {
    return false;
  }
  return true;
}

int DFS(int row, int col) {
  int max_length = 1;
  for (int d = 0; d < 4; ++d) {
    int new_row = row + dy[d];
    int new_col = col + dx[d];
    if (!isInBound(new_row, new_col)) {
      continue;
    }
    char alphabet = board[new_row][new_col];
    if (!visit[alphabet]) {
      visit[alphabet] = true;
      max_length = max(max_length, 1 + DFS(new_row, new_col));
      visit[alphabet] = false;
    }
  }
  return max_length;
}

int main() {
  cin >> row_count >> col_count;
  for (int i = 0; i < row_count; ++i) {
    for (int j = 0; j < col_count; ++j) {
      cin >> board[i][j];
    }
  }

  int max_length = 1;
  visit[board[0][0]] = true;
  max_length = max(max_length, DFS(0, 0));
  cout << max_length << endl;
  return 0;
}
