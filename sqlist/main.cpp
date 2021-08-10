#include<iostream>
#include"sqlist.h"
using namespace std;

int main(){
    sqlist<int> s(3);
    s.append(5);
    cout<<s.getval(0);
}