#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString str1("Hello");
    MyString str2("e");
    MyString str3("AAA");


    str1 = str1.contextsub(str2, str3);
    str1.print();
    return 0;
}