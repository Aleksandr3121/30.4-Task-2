#include <iostream>
#include <string>
#include <string_view>
#include <cpr/cpr.h>

using namespace std;

int main() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"));
    string_view str = r.text;
    string tagHeadLeft = "<h1>";
    string tagHeadRight = "</h1>";
    size_t posBegin = str.find(tagHeadLeft);
    if(posBegin == string::npos){
        cerr<<"Error"<<endl;
        return 1;
    }
    posBegin+=tagHeadLeft.size();
    str.remove_prefix(posBegin);
    size_t posEnd=str.find(tagHeadRight);
    if(posEnd == string::npos){
        cerr<<"Error"<<endl;
        return 1;
    }
    str.remove_suffix(str.size() - posEnd);
    cout<<str;
    return 0;
}
