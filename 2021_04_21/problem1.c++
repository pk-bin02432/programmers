//코딩테스트 연습 > 연습문제 > 2016년 문제
//https://programmers.co.kr/learn/courses/30/lessons/12901

#include <string>
#include <vector>

using namespace std;

//기본 생성자
string solution(int a, int b);
void getCanlendarData(vector<int>& pMonth);

//0 - 일요일
//6 - 토요일

//작성 시간 15분
/*
첫 인덱스만 두게하여 처리 속도 향상을 꾀함.
*/
string solution(int a, int b)
{
    vector<int> _Month(12);
    vector<string> _DayOfWeek;
    //메모리에 요일 미리 할당
    _DayOfWeek.push_back("SUN");
    _DayOfWeek.push_back("MON");
    _DayOfWeek.push_back("TUE");
    _DayOfWeek.push_back("WED");
    _DayOfWeek.push_back("THU");
    _DayOfWeek.push_back("FRI");
    _DayOfWeek.push_back("SAT");
    //1일 날의 요일 미리 구하기
    getCanlendarData(_Month);
    //최종 요일 날짜 도출
    int _resultDayOfWeek = (_Month[a - 1] + (b - 1)) % 7;
    string answer = _DayOfWeek[_resultDayOfWeek];
    return answer;
}

//각 달의 1일의 요일을 도출
void getCanlendarData(vector<int>& pMonth)
{
    int i = 0;
    int _First = 5; //금요일
    for (i = 0; i < (int)pMonth.size(); i++)
    {
        pMonth[i] = _First;
        switch (i + 1)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            _First = _First + 31;
            break;
        case 2:
            _First = _First + 29;
            break;
        default:
            _First = _First + 30;
            break;
        }
        _First = _First % 7;
    }
}


int main()
{
    auto ttss = solution(5,24);

    return 0;
}
