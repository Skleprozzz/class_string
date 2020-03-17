#include <iostream>
#include <cstring>

using namespace std;

class String
{
    size_t size;
    char *str;

public:
    String();
    String(const char ch);
    String(const String &);
    String(const char *);
    ~String();

    int length() const;
    const char * getString();
    void resize(unsigned int, char);
    void insert(unsigned int, String &);

    char &operator[](unsigned int);

    String &operator=(const String &);
    String &operator=(const char *);
    String &operator=(const char c);

    String &operator+=(const String &);
    String &operator+=(const char *);
    String &operator+=(const char c);

    const String operator+(const String &);
    const String operator+(const char *);
    const String operator+(const char p);
    bool operator==(const char *) const;
    bool operator==(const String &) const;
    bool operator!=(const char *) const;
    bool operator!=(const String &) const;
    friend ostream &operator<<(ostream &, const String &);
    friend istream &operator>>(istream &is, String &myString);
};