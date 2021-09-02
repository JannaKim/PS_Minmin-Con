#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> split(string str) {
  vector<string> words;
  size_t pos;
  while ((pos = str.find(' ')) != string::npos) {
    words.push_back(str.substr(0, pos));
    str.erase(0, pos + 1);
  }
  words.push_back(str.substr(0, pos));
  return words;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
  map<int, vector<string>, greater<>> scores;

  for (string &colStr : table) {
    vector<string> col = split(colStr);
    int score = 0;
    for (int i = 1; i < 6; i++) {
      for (int j = 0; j < languages.size(); j++) {
        if (col[i] == languages[j]) {
          score += preference[j] * (6 - i);
        }
      }
    }
    scores[score].push_back(col[0]);
  }

  vector<string> answers = scores.begin()->second;
  sort(answers.begin(), answers.end());

  return answers[0];
}
