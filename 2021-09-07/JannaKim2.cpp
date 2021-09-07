#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {
  int total_count = weights.size();
  vector<vector<double>> info(total_count, vector<double> (4, 0)); // first : valid val, fill others 0
  for (int i = 0; i < total_count; ++i) {
    int win_count = count(head2head[i].begin(), head2head[i].end(), 'W');
    int not_count = count(head2head[i].begin(), head2head[i].end(), 'N');
    if (not_count == total_count)
      info[i][0] = 0;
    else
      info[i][0] = win_count / ((double) total_count - not_count); // zz
    int victory_count = 0;
    for (int j = 0; j < total_count; ++j)
      if (head2head[i][j] == 'W' && weights[i] < weights[j])
        victory_count++;
    info[i][1] = victory_count;
    info[i][2] = weights[i];
    info[i][3] = i + 1;
  }
  sort(info.begin(), info.end(), [](vector<double> &a, vector<double> &b) {
    if (a[0] != b[0]) {
      return a[0] > b[0];
    } else {
      if (a[1] != b[1]) {
        return a[1] > b[1];
      } else {
        if (a[2] != b[2])
          return a[2] > b[2];
        else
          return a[3] < b[3];
      }
    }
  });
  vector<int> answers(total_count);
  for (int i = 0; i < total_count; ++i)
    answers[i] = info[i][3];
  return answers;
}
