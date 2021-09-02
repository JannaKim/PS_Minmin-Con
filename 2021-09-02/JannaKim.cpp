#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string line){
    vector<string> words;
    size_t pos = 0;
    while( (pos = line.find(' ')) != string::npos) {
        words.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
    }
    words.push_back(line.substr(0, pos));

    return words;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {

    string ans = "";
    int mx = -1;

    for(string &column : table){
        vector<string> col = split(column);
        int score = 0;
        for(int i = 1; i < 1 + 5; ++i){
            for(int j = 0; j < languages.size(); ++j){
                if(col[i] == languages[j]) score += (6 - i) * preference[j];
            }
        }
        if(score > mx) {
            mx = score;
            ans = col[0];
        }
        else if(score == mx){
            if(ans.compare(col[0]) > 0) ans = col[0];
        }
    }
    
    return ans;
}