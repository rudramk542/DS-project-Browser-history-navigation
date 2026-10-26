#include <iostream>
#include  <string>
#include <stack>

using namespace std;
class browser{
string  currentpage;
stack<string> backstack;    
stack<string> forwardstack; 
public:
browser(string homepage){
    currentpage = homepage;
    backstack.push(homepage);
    cout<<"currently at homepage"<<endl;
}
void visit(string url){
    currentpage = url;
    backstack.push(url);
    cout<<"opened:"<<url<<endl;
}
void goback(){
    forwardstack.push(currentpage);
    currentpage=backstack.top();
    backstack.pop();
    cout<<"going back to:  "<<currentpage<<endl;
}
void goforward(){
    backstack.push(currentpage);
    currentpage=forwardstack.top();
    forwardstack.pop();
    cout<<"going forward to:  "<<currentpage<<endl;
}
void printcurrentpage(){
    cout<<"current page: "<<currentpage<<endl;
}
};




int main() {
browser browser("www.google.com");
 browser.visit("www.reddit.com");
 browser.visit("www.facebook.com");
 browser.visit("www.youtube.com") ;
 browser.goback();
 browser.goback();
 browser.goforward();
 browser.printcurrentpage();
return 0;
}