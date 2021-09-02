#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> split(string line) {
    vector<string> words;
    size_t pos = 0;
    while ((pos = line.find(' ')) != string::npos) {
        words.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
    }
    words.push_back(line.substr(0, pos));
    
    return words;
}

/*


※ compare : 문자열 비교

⇒ 해당 변수와 입력 된 문자열을 비교한다.

사용법 : str.compare(str2);

반환값 : str == str2 이면 0 반환 / str > str2 이면 1 반환 / str < str2 이면 -1 반환

(여기서 str > str2 는 대소 비교가 아니라 사전순으로 비교해서 앞, 뒤를 의미)

*/


map<int, vector<string>, greater <int>> scores; // descending order