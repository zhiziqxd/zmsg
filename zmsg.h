#ifndef msg_H
#define msg_H
#include <iostream>
#include <string>
#include <queue>
#include <unistd.h>
#include <winsock2.h>
using namespace std;
long long int pow1(int a,int b){
    long long int ans;
    for(int i=1;i<=b;i++){
        ans*=a;
    }
    return ans;
}
struct zmsp{
    int version;//版本
    short laptop;//设备
    int strlong;//长度
    string message;//信息
};
queue<char> msg;
string to(int a,short b,string c){//生成新的发送字符串
    char a1=char(a-'0');
    char b1=char(b-'0');
    int l=c.length();
    string lstr="";
    while(l>0){
        lstr+=char(l%10);
        l/=10;
    }
    string str=a1+b1+lstr+c;
    return str;
}
void put_away(string str){
    for(int i=str.length();i>=0;i--){
        msg.push_back(str[i]);
    }
    return;
}
zmsp put_ch(string str){
    zmsp flag;
    flag.version=int(str[0]-'0');
    flag.laptop=short(str[1]-'0');
    int f;
    for(int i=2;i<str.size();i++){
        if(str[i]=='\0'){
            f=i;
            break;
        }
    }
    int cnt=0;
    for(int i=f-1;i>=2;i++){
        cnt+=pow1(10,f-i)*int(str[i]-'0');
    }
    flag.strlong=cnt;
    for(int i=f;i<=str.size();i++){
        flag.message+=str[i];
    }
    return flag;
}

#endif
