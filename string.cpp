#include <iostream>
#include "string.h"

String::String()
{
    str = nullptr;
    size = 0;
}

String::String(const String &s)
{
    size = s.size;
    str = new char[size];
    strcpy(str, s.str);
}

String::String(const char *p)
{
    size = strlen(p);
    str = new char[size];
    strcpy(str, p);
}

String::String(const char p)
{
    size = 1;
    str = new char[size];
    str[0] = p;
}

String::~String()
{
    delete[] str;
}

int String::length() const
{
    if (str == nullptr)
        return 0;
    else
        return size;
}

const char *String::getString()
{
    return str;
}

// OPERATORS

char &String::operator[](unsigned int i)
{
    return str[i];
}

String &String::operator=(const String &s)
{
    size = s.size;
    str = s.str;
    return *this;
}

String &String::operator=(const char *c)
{
    size = strlen(c);
    str = new char[size];
    strcpy(str, c);
    return *this;
}

String &String::operator=(const char c)
{
    size = 1;
    str = new char[size];
    str[0] = c;
    return *this;
}

ostream &operator<<(ostream &os, const String &s)
{
    for (int i = 0; i < s.size; i++)
    {
        os << s.str[i];
    }
    return os;
}

istream &operator>>(istream &in, String &s)
{
    char *buff = new char[256];
    in.getline(buff, sizeof(buff));
    s.size = strlen(buff);
    s.str = new char[s.size];
    strcpy(s.str, buff);
    delete[] buff;
    return in;
}

bool String::operator==(const String &s) const
{
    if (size != s.length())
        return false;
    else
        return !strcmp(str, s.str);
    return true;
}

bool String::operator==(const char *c) const
{
    if (size != strlen(c))
        return false;
    else
        return !strcmp(str, c);
    return true;
}

bool String::operator!=(const String &s) const
{
    if (size != s.size)
        return true;
    else
        return strcmp(str, s.str);
    return false;
}

bool String::operator!=(const char *c) const
{
    if (size != strlen(c))
        return true;
    else
        return strcmp(str, c);
    return false;
}

String &String::operator+=(const String &s)
{
    size += s.size;
    strcat(str, s.str);
    return *this;
}

String &String::operator+=(const char *c)
{
    size += strlen(c);
    strcat(str, c);
    return *this;
}

String &String::operator+=(const char s)
{
    str[size++] = s;
    str[size] = '\0';
    return *this;
}