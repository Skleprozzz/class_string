// Поведение должно напоминать std::string. По ссылке можно посмотреть используемые в стандартной библиотеке прототипы функций.
// 	Про перегрузку можно найти информацию здесь: википедия, статья.
// 	При работе с Си-строками желательно использовать специальные функции:
// strlen(str) - возвращает длину строки str без учета ‘\0’.
// strcpy(str1, str2) - копирует str2 в str1 вместе с ‘\0’, но за выделение памяти отвечает программист.
// strcmp(str1, str2) - сравнивает строки, если одинаковые, то вернет 0.
// Требования
// Создан класс для представления строки (хранит длину строки и саму строку).
// Реализованы конструкторы: по умолчанию, с параметром const char*, копирования.
// Реализован деструктор.
// Операции со строкой:
// вернуть длину строки
// вернуть строку (const char*)
// дополнительные функции приветствуются
// Перегружены операторы:
// ввода и вывода в поток (>>, <<)
// присваивания (=) для работы с вашим классом
// сравнения (==, !=)
// доступа по индексу ([])
// сложения как конкатенация строк (+=, +)
// В функции main привести пример работы со строкой. Наличие тестов приветствуется.
// Дополнительно:
// реализовать поддержку инициализации через отдельный символ char
// реализовать поддержку Си-строк и отдельных символов в операторах =, +=, +
// дополнительный функционал для работы со строками (поиск, вставка, итераторы...)

// class MyString {
// private:
//    char* str;
//    size_t length;
// public:
//    MyString();
//    MyString(const char _char);
//    MyString(const char* _string);
//    MyString(const MyString& _string);
//    ~MyString();

//    int GetLength() const;
//    const char* GetString() const;

//    char& operator [] (const size_t index) const;

//    friend ostream& operator << (ostream& os, const MyString& myString);
//    friend istream& operator >> (istream& is, MyString& myString);

//    MyString& operator = (const MyString& rightString);
//    MyString& operator = (const char* rightChars);
//    MyString& operator = (const char rightChar);

//    bool operator == (const MyString& rightString) const;
//    bool operator != (const MyString& rightString) const;

//    MyString& operator += (const MyString& rightString);
//    MyString& operator += (const char* rightString);
//    MyString& operator += (const char rightChar);

//    const MyString operator + (const MyString& rightString) const;
//    const MyString operator + (const char* rightString) const;
//    const MyString operator + (const char rightChar) const;
// };

#include "string.h"
#include <iostream>
#include <cassert>

int main()
{
    String s1; // s1 == ""
    assert(s1.length() == 0);
    String s2("hi");
    assert(s2.length() == 2);
    String s3(s2);
    assert(s3.length() == 2);
    String s4('a');
    assert(s4.length() == 1);
    assert(s4 == 'a');
    assert(s3[0] == 'h');
    assert(s3[1] == 'i');
    assert(s3 != "asd");
    assert(s2 != s1);
    s1 = s2;
    s1 = "s2";
    s2 = s1;
    s3 = s2;
    assert(s3 == "s2");
    s1 = "";
    s3 = "";
    s2 = "addition";
    s1 += "asd";
    s3 += s2;
    assert(s1 == "asd");
    s1 += 'a';
    assert(s1 == "asda");
    assert(s2 == "addition");

    s1 = "asd";
    std::cout << s1.getString() << std::endl;
    assert(!strcmp(s1.getString(), "asd"));
    std::cout << "All tests passed" << std::endl;
    // Manual Testing
    String s5;
    std::cin >> s5;
    std::cout << s5 << std::endl;
    return 0;
}