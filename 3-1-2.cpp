#include<iostream>
#include<cmath>
using namespace std;
int main(int argc, char *argv[]){
    int L,S;            //L長針　S短針
    float Lpos,Spos = 0;  //長針と短針の位置
    float result = 0;
    S = stoi(argv[1]);
    L = stoi(argv[2]);
    Lpos = L * 6;
    Spos = S * 30 + L * 0.5;
    result = fabsf(Lpos - Spos);
    if(result > 180) result = 360 - result;
    cout << S << "," << L << "," << result << "," << endl;
}
