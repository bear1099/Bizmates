#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int L,S;            //L長針　S短針
    float Lpos,Spos = 0;  //長針と短針の位置
    float result = 0;
    cout << "本プログラムは、入力された時(hour)と分(minute)から短針と長針の位置を求め、それらの角度の差を答えとして出力します。" << endl;
    cout << "時(hour)を入力してください(0~23) : ";
    cin >> S;
    if(S>23||S<0) cerr << "時(hour)は0から23の整数で入力してください" << endl;
    cout << "分(minute)を入力してください(0~59) : ";
    cin >> L;
    if(L>59||L<0) cerr << "分(minute)は0から59の整数で入力してください" << endl;
    //針の位置を決定する
    Lpos = L * 6;
    Spos = S * 30 + L * 0.5;
    result = fabsf(Lpos - Spos);
    if(result > 180) result = 360 - result;
    cout << "短針と長針の角度の差は" << result << "度です。" << endl;
}
