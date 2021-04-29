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
	MyString remsubstr(MyString str_new);					// remove substring
	MyString substitution(MyString str_new, int pos);		// insert string to pos index
	MyString contextsub(MyString str1, MyString str2);		// substitute str1 to str2 in  this string
	void merge(MyString& str1, MyString& str2, int pos);	// merge this string into strings srt1 and str2 (pos = start of str2)

	void print();
};