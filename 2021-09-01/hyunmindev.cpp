#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char element[] = "XAEIOU";
vector<string> dictionary;

void generate(int depth, string word) {
  if (depth == 5) {
    word.erase(remove(word.begin(), word.end(), 'X'), word.end());
    dictionary.push_back(word);
    return;
  }
  for (int i = 0; i < 6; i++) {
    generate(depth + 1, word + element[i]);
  }
}

int solution(string word) {
  generate(0, "");

  sort(dictionary.begin(), dictionary.end());
  unique(dictionary.begin(), dictionary.end());

  return find(dictionary.begin(), dictionary.end(), word) - dictionary.begin();
}
