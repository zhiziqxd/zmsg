#include "zmsg.h"
using namespace std;
zmsg chatmsg;
int main(){
    //仅用于示范用法
    //统一使用10232端口
    chatmsg.version=1;
    chatmsg.laptop=0;
    chatmsg.message="hi";
    string go=to(chatmsg.version,chatmsg.laptop,chatmsg.message);
    put_away(go);
    //可以从队列中提取
    zmsp f=put_ch(go);
    return 0;
}
