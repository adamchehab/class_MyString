#include <iostream>
#include "class_MyString.h"
using namespace std;

int main()
{
    MyString str1("HelloDanya");
    MyString str2("str2");
    MyString str3("str3");

    str1.merge(str2, str3, 3);
    str2.print();
    str3.print();
    return 0;
}