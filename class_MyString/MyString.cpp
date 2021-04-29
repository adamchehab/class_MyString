#include "MyString.h"
#include <iostream>
using namespace std;


int MyString::ft_strlen(const char* str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void MyString::ft_strlcpy(char* dst, const char* src, int size, int n)
{
    int i = 0;
    for (; i <= size; n++, i++)
        dst[n] = src[i];
}


MyString::MyString()
{
    str = NULL;
    length = 0;
}

MyString::MyString(int size)
{
    length = size;
    this->str = new char[length + 1];
}

MyString::MyString(const char* str)
{
    length = ft_strlen(str);
    this->str = new char[length + 1];
    ft_strlcpy(this->str, str, length, 0);
}

MyString::MyString(const MyString& str1)
{
    this->length = str1.length;
    this->str = new char[length + 1];
    ft_strlcpy(this->str, str1.str, length, 0);
}

MyString::~MyString()
{
    delete[] str;
}


MyString MyString::operator +(const MyString& str_new)
{
    MyString res(this->length + str_new.length);
    res = this->substitution(str_new, this->length + 1);
    return res;
}

MyString& MyString::operator =(const MyString& str_new)
{
    //if str is not empty then clear it
    if (this->str != 0)
        delete[](this->str);

    this->length = str_new.length;
    this->str = new char[length + 1];
    ft_strlcpy(this->str, str_new.str, this->length, 0);
    return (*this);
}


int MyString::find(MyString str_new)
{
    int pos = -1;
    int i = 0;
    int j = 0;

    while ((i <= this->length) && (j != str_new.length))
    {
        if (str_new.str[j] == this->str[i])
        {
            if (pos == -1)
                pos = i;
            j++;
        }
        else
        {
            pos = -1;
            j = 0;
        }
        i++;
    }
    return (pos);
}

MyString MyString::remsubstr(MyString str_new)
{
    int pos;

    if ((pos = this->find(str_new.str)) == -1)
        return (*this);

    MyString res(this->length - str_new.length);
    ft_strlcpy(res.str, this->str, pos - 1, 0);
    ft_strlcpy(res.str, this->str + pos + str_new.length, this->length - pos - str_new.length, pos);
    return (res);
}

MyString MyString::substitution(MyString str_new, int pos)
{
    MyString res(this->length + str_new.length);
    ft_strlcpy(res.str, this->str, pos - 2, 0);
    ft_strlcpy(res.str, str_new.str, str_new.length, pos - 1);
    ft_strlcpy(res.str, this->str + pos - 1, this->length - pos + 1, pos - 1 + str_new.length);
    return res;
}

MyString MyString::contextsub(MyString str1, MyString str2)
{
    int pos;

    pos = this->find(str1);
    if ((pos = this->find(str1)) == -1)
        return (*this);

    MyString res(this->length - str1.length + str2.length);

    ft_strlcpy(res.str, this->str, pos - 1, 0);
    ft_strlcpy(res.str, str2.str, str2.length, pos);
    ft_strlcpy(res.str, this->str + pos + str1.length, this->length - pos - str1.length, pos + str2.length);
    return (res);
}

void MyString::merge(MyString& str1, MyString& str2, int pos)
{
    if (str1.str != 0)
        delete[](str1.str);
    if (str2.str != 0)
        delete[](str2.str);

    str1.length = pos - 1;
    str2.length = this->length - pos + 1;

    str1.str = new char[str1.length + 1];
    str2.str = new char[str2.length + 1];

    str1.str[str1.length] = '\0';
    str2.str[str2.length] = '\0';

    ft_strlcpy(str1.str, this->str, str1.length - 1, 0);
    ft_strlcpy(str2.str, this->str + pos - 1, str2.length, 0);
}


void MyString::print()
{
    cout << this->str << endl;
}
