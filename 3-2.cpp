#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct data{
    string s;
    int year;
    int month;
    int day;
    string zodiac;  //星座
    string twelve;  //十二支
};

void getDate(data& dt){
    stringstream ss(dt.s);
    vector<string> vec;
    string buf;
    while(getline(ss,buf,'/')) vec.push_back(buf);
    dt.year = stoi(vec[0]);
    dt.month = stoi(vec[1]);
    dt.day = stoi(vec[2]);
    if(dt.month<1 || dt.month>12) cerr << "[Error] " << dt.month << "が入力されました。月は1~12の値で入力してください" << endl;
    if(dt.day<1 || dt.day>31) cerr << "[Error] " << dt.day << "が入力されました。日は1~31の値で入力してください。" << endl;
}

void getZodiac(data& dt){
    switch(dt.month){
        case 1:
        if(dt.day < 20) dt.zodiac = "Capricorn";
        else dt.zodiac = "Aquarius";
        break;

        case 2:
        if(dt.day < 19) dt.zodiac = "Aquarius";
        else dt.zodiac = "Pisces";
        break;
        
        case 3:
        if(dt.day < 21) dt.zodiac = "Pisces";
        else dt.zodiac = "Aries";
        break;

        case 4:
        if(dt.day < 20) dt.zodiac = "Aries";
        else dt.zodiac = "Taurus";
        break;

        case 5:
        if(dt.day < 21) dt.zodiac = "Taurus";
        else dt.zodiac = "Gemini";
        break;

        case 6:
        if(dt.day < 22) dt.zodiac = "Gemini";
        else dt.zodiac = "Cancer";
        break;

        case 7:
        if(dt.day < 23) dt.zodiac = "Cancer";
        else dt.zodiac = "Leo";
        break;

        case 8:
        if(dt.day < 23) dt.zodiac = "Leo";
        else dt.zodiac = "Virgo";
        break;

        case 9:
        if(dt.day < 23) dt.zodiac = "Virgo";
        else dt.zodiac = "Libra";
        break;

        case 10:
        if(dt.day < 24) dt.zodiac = "Libra";
        else dt.zodiac =  "Scorpio";
        break;

        case 11:
        if(dt.day < 23) dt.zodiac = "Scorpio";
        else dt.zodiac = "Sagittarius";
        break;

        case 12:
        if(dt.day < 22) dt.zodiac = "Sagittarius";
        else dt.zodiac = "Capricorn";
        break;
    }
}

void getTwelve(data& dt){
    string twelveArray[12] = {"丑","寅","卯","辰","巳","午","未","申","酉","戌","亥","子"};
    bool negative;                  //true:入力値が2021より小さい（過去） 　false:入力値が2021より大きい（未来）
    int value = dt.year - 2021;
    if(value<0) negative = true;
    else        negative = false;
    value = abs(value) % 12;
    if(negative) value = 12 - value;    //過去だった場合、十二支を逆順に計算する
    dt.twelve = twelveArray[value];
}

void outputVector(vector<data> vec){
    for(int i=0;i<vec.size();i++){
        cout << vec[i].s << " " << vec[i].zodiac << " " << vec[i].twelve << endl;
    }
}

int main(){
    vector<data> input_line;
    data buf;
    int i = 0;
    cout << "本プログラムはYYYY/MM/DD形式の空白で区切られた文字列の入力に応じて\n" << "それぞれの生年月日に対応する星座と干支について出力します" << endl;
    cout << "入力例 : YYYY/MM/DD YYYY/MM/DD EOF" << endl;
    cout << "※EOFはWin(Ctrl+z)、Mac(Ctrl+d)で入力することができます。" << endl;

    while(cin >> buf.s){
        getDate(buf);
        getZodiac(buf);
        getTwelve(buf);
        input_line.push_back(buf);
    }
    outputVector(input_line);
}