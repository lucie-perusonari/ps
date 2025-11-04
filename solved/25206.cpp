#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>  
using namespace std;
//*문제 번호 : 25206번 - 너의 평점은
//*문제 설명 : 
//인하대학교 컴퓨터공학과를 졸업하기 위해서는, 전공평점이 3.3 이상이거나 졸업고사를 통과해야 한다. 그런데 아뿔싸, 치훈이는 깜빡하고 졸업고사를 응시하지 않았다는 사실을 깨달았다!
//치훈이의 전공평점을 계산해주는 프로그램을 작성해보자.
//전공평점은 전공과목별 (학점 × 과목평점)의 합을 학점의 총합으로 나눈 값이다.
//*평점은 4.5점 만점 A~F, +, 0로 이루어져있음. 

//입력 : 
//20줄에 걸쳐 치훈이가 수강한 전공과목의 과목명, 학점, 등급이 공백으로 구분되어 주어진다.

//출력 : 
//치훈이의 전공평점을 출력한다.
//정답과의 절대오차 또는 상대오차가 10^-4 이하이면 정답으로 인정한다.

int main()
{
    string str;
    int count = 0;

    vector<string> point(0);
    vector<string> grade(0);
    //과목명-학점-과목평점 순이므로 학점과 과목 평점을 추출. 
    //cin >> str같은 형태로 ss를 사용하면 간단하게 파싱할 수 있다.
    while(cin >> str){
        if(count%3 == 1){
            point.push_back(str);
        }
        if(count%3 == 2){
            grade.push_back(str);
        }        
        count++; //순환을 위해서 count를 사용.
    };

    int total_count =0; //학점의 합.
    double total_point =0;//(학점*과목 평점)의 합.

    for(int i=0;i<point.size();i++){
        double result_point = 0;
        string grade1 = grade[i];
        if(grade1 != "F" && grade1 != "P"){
            char a = grade1[0]; //A~D
            char b = grade1[1]; //0,+

            if(b == '+') result_point += 0.5;

            if(a == 'A') result_point += 4;
            if(a == 'B') result_point += 3;
            if(a == 'C') result_point += 2;
            if(a == 'D') result_point += 1;
        }else if(grade1 == "F"){
            result_point = 0;
        }else{
            continue; // grade1 == "P"인 경우.
        }

        int a = (point[i][0])-'0'; //학점, char값에 '0'을 넣어 변환 함. 
        total_point += result_point * (double)a; //등급에 따른 학점
        total_count += a; //학점의 총합
    }

    cout << total_point/total_count; // 전공평점

    return 0;
}