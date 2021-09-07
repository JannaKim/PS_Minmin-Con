![IMG_B6DBB322E9DD-1](https://user-images.githubusercontent.com/74404132/131821381-23f99a6e-9c16-41be-813a-d25f908dd655.jpeg)
![IMG_D8F825D8FBFE-1](https://user-images.githubusercontent.com/74404132/131821386-b5b93a3c-ad8b-4c5b-8975-c6813e51c551.jpeg)
![IMG_3CC8BAB3CDE7-1](https://user-images.githubusercontent.com/74404132/131821427-b24e09c2-dd03-4e66-a5ce-5cc1ecfe28b6.jpeg)
![IMG_219EDC73FA82-1](https://user-images.githubusercontent.com/74404132/131821430-6234e812-73aa-4cb0-ba5e-fb00aa61500a.jpeg)



https://www.youtube.com/watch?v=-MpL0X3AHAs

<br/>

cf)

find rank of the word(or number) in permutation?

4 2 1 3 2 5
s e c r e t



for each, look towards right.

(find how many that is lower) / (repetitions)! * (descending idx)!

s : 4 / 2!    * 5!
e : 1 / 2!    * 4!
c : 0         * 3!
r : 1         * 2!
e : 0         * 1!
t : 0         * 0!

#### + 1

answer : sum of all and + 1

answer = 255


ex2)

question : 2 a 1 b, permutation.
abb
bab
bba

bab kth?

b : 0 / 2! * 2!   = 0
a : 1  * 1!       = 1
b : 0

k = 1 + 1 = 2

bab is 2th.



look towards right, 

(find how many that is lower) / (repetitions)! * (descending idx)!

123
132
213
231
312


ex3)

123 permutation.

312 kth ? 


2 /  1 * 2! : 4
0 
0
+ 1

312 is 5th.


ex4)


2 1 3

1 * 2! = 2
1
0
+ 1

213 is 3th.


<br/>


<br/>

<br/>


https://leetcode.com/problems/next-permutation/

<br/>

![image](https://user-images.githubusercontent.com/74404132/131856073-edd22566-9ecd-4cfd-b3db-f041be22fa9c.png)
![image](https://user-images.githubusercontent.com/74404132/131856244-8f081988-78ac-4ee6-93ef-6a2e0dcd991a.png)
![image](https://user-images.githubusercontent.com/74404132/131855804-80cd0d19-2f12-4348-9f1b-d61035fd9c6d.png)
![image](https://user-images.githubusercontent.com/74404132/131855829-72dab7b5-57c6-480a-a290-f2d0a22056c8.png)
![image](https://user-images.githubusercontent.com/74404132/131855892-d95c4906-b10f-4c08-bbfd-cbacb78dcb10.png)


<br/>



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


<br/>


딕셔너리에 존재하는 문자ㅣ 5개. 문자길이 최대길이가 5다. 

모든 문자별로, 내가 이 문자까지 오는데 자기 뒤에 있는 k개의 문자로 만들수 있는 딕셔너리를 

홀라당 몇번 건너뛰었는지 다 계산해서 모두 누적해주는것.