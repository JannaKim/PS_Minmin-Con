#include <string>
#include <iostream>
using namespace std;

int solution(string word) {
    string v = string("AEIOU");
    int ans = 0;
    int pow5 = 1;

    for(int i = 0; i < word.size(); ++i){
        ans += v.rfind(word[i]) * 781 / pow5;
        ++ans;
        pow5 *= 5;
    }

    return ans;
}

int main(){
    string st = "EEE";
    cout << solution(st);
}



// 1 + 5 + 25 + 125 + 625