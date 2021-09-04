#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> picture_vec_vec;
bool visit_arr_arr[100][100];
int row_count;
int col_count;

int DFS(int row, int col, int color) {
  visit_arr_arr[row][col] = true;
  int size = 1;

  if (row != 0) { // U
    if (color == picture_vec_vec[row - 1][col]) {
      if (!visit_arr_arr[row - 1][col]) {
        visit_arr_arr[row - 1][col] = true;
        size += DFS(row - 1, col, color);
      }
    }
  }

  if (col != col_count - 1) { // R
    if (color == picture_vec_vec[row][col + 1]) {
      if (!visit_arr_arr[row][col + 1]) {
        visit_arr_arr[row][col + 1] = true;
        size += DFS(row, col + 1, color);
      }
    }
  }

  if (row != row_count - 1) { // D
    if (color == picture_vec_vec[row + 1][col]) {
      if (!visit_arr_arr[row + 1][col]) {
        visit_arr_arr[row + 1][col] = true;
        size += DFS(row + 1, col, color);
      }
    }
  }

  if (col != 0) { // L
    if (color == picture_vec_vec[row][col - 1]) {
      if (!visit_arr_arr[row][col - 1]) {
        visit_arr_arr[row][col - 1] = true;
        size += DFS(row, col - 1, color);
      }
    }
  }

  return size;
}

vector<int> solution(int _row_count, int _col_count, vector<vector<int>> _picture_vec_vec) {
  row_count = _row_count;
  col_count = _col_count;
  picture_vec_vec = std::move(_picture_vec_vec);
  int section_count = 0;
  int max_section_size = 0;

  for (auto &visit_arr : visit_arr_arr) {
    for (bool &visit : visit_arr) {
      visit = false;
    }
  }

  for (int i = 0; i < row_count; ++i) {
    for (int j = 0; j < col_count; ++j) {
      if (!visit_arr_arr[i][j] && picture_vec_vec[i][j] != 0) {
        max_section_size = max(max_section_size, DFS(i, j, picture_vec_vec[i][j]));
        section_count++;
      }
    }
  }

  return {section_count, max_section_size};
}
