#pragma once

class MyString
{
private:
	char* str;
	int length; // without null-terminated symbol

	int ft_strlen(const char* str);
	void ft_strlcpy(char* dst, const char* src, int size, int n);

public:
	MyString();
	MyString(int size);
	MyString(const char* str);
	MyString(const MyString& str1);
	~MyString();

	MyString operator +(const MyString& str_new);
	MyString& operator =(const MyString& str_new);

	int find(MyString str_new);
	MyString remsubstr(MyString str_new);
	MyString substitution(MyString str_new, int pos);
	MyString contextsub(MyString str1, MyString str2);
	void merge(MyString& str1, MyString& str2, int pos);

	void print();
};