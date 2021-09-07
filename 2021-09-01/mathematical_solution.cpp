#include <string>
#include <iostream>
using namespace std;

int solution(string word) {
    string v = string("AEIOU");
    int ans = 0;
    int pow5 = 1;

    // 0 1 3 2

    for(int i = 0; i < word.size(); ++i){
        ans += v.rfind(word[i]) * 781 / pow5; // string 내장함수
        ++ans;
        pow5 *= 5;
    }
    return ans;
}

int main(){
    string st = "EEE";

    // 1 + 5 + 25 + 125 + 625

    //  1 + 5 + 25 + 125

    //   1 + 5 + 25

    //   1 + 5

    //   1 

    cout << st.rfind('E') << " " << st.find('E') << "\n";


    cout << solution(st);
}

// # 글자 3 자릿수 4

// ABC, 4제한 : 7 번째

// 5 - 4 - 1

// 0

// AAB

// 1 3 9 27

// 1 3 9

// 1 3

// 1




// 1 + 5 + 25 + 125 + 625


// . . .


// 19
// 20

// 3 4 3 2 1



// 7 2 4 6 5 3 3 2 1
// 7 2 4 1 2 3 3 5 6




// 0 0 0
// 0 0 1
// 0 1 0
// 0 1 1
// 1 0 0
// 1 0 1
// 1
// .
// .
// .