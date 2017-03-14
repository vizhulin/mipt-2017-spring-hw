//
// Created by Artyom on 25.02.2017.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <iostream>

class String {
private:
    char *values;
    size_t capacity;
public:
    //конструктор по умолчанию
    String(size_t capacity = 1);

    //конструктор от строки
    String(const char *);

    //конструктор копирования
    String(const String &);

    //деструктор
    ~String();

    //длина строки
    size_t length() const;

    //поиск символа в строке
    size_t find(const char);

    void resize(size_t );

    //увеличить строку на символ (поменять сам объект)
    String &append(const char);

    //увеличить строку на строку (поменять сам объект)
    String &append(const char *);

    //увеличить строку на другую строку (поменять сам объект)
    String &append(const String &);

    //подстрока
    String substring(size_t start = 0, size_t finish = -1) const;

    //конкатинация строк
    String operator+(const char ) const;

    //конкатинация строк
    String operator+(const char *) const;

    //конкатинация строк
    String operator+(const String &) const;

    //Обращение к i-тому элементу строки. Удостовериться, что символ можно поменять str[2]='c'
    char &operator[](const int) const;

    //оператор присвания от с-строки String str = "hello";
    String &operator=(const char *);

    //оператор присвания от символа String str = 'A';
    String &operator=(const char);

    //вывод строки через поток cout << str;
    friend std::ostream &operator<<(std::ostream &, const String &);

    //чтение строки с потока cin >> str;
    friend std::istream &operator>>(std::istream &, const String &);

    //кастомизация строки в char*
    operator char *() const;

    //попытка перевода строки в число, можно использовать atoi
    operator int() const;

    //попытка перевода строки в число, можно использовать atof
    operator double() const;
};

#endif //STRING_STRING_H
