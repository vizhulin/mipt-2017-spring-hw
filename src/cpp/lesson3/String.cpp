//
// Created by Artyom on 25.02.2017.
//

#include <cstring>
#include "String.h"

String::String(size_t capacity) {
    this->capacity = capacity;
    this->values = new char[capacity];
    this->values[0] =0;
}

String::String(const char * s) {
    size_t length = strlen(s);
    this->capacity = length + 1;
    this->values = new char[length + 1];
    std::memcpy(this->values,s, length);
    this->values[length] = 0;
}

String::String(const String &that) {
    this->capacity = that.length() + 1;
    this->values = new char[that.length() + 1];
    std::memcpy(this->values,that.values,that.length());
    this->values[that.length()] = 0;
}

String::~String() {
    delete []this->values;
}

size_t String::length() const {
    return strlen(this->values);
}

size_t String::find(const char symbol) {
    size_t index;
    index = 0;
    while(this->values[index] && this->values[index] != symbol){
        ++index;
    }
    if(this->values[index] == 0)
        index = 0;

    return index;

}

void String::resize(size_t newcapacity) {
    this->capacity = newcapacity;
    char *temp = new char[newcapacity];
    std::memcpy(temp, this->values, this->length());
    temp[this->length()] = 0;
    delete[]this->values;
    this->values = temp;
}

String &String::append(const char symbol) {
    if (this->capacity <= this->length() + 1) {
        this->resize(this->length() + 2);
    }
    this->values[this->length() + 1] = 0;
    this->values[this->length()] = symbol;
    return *this;
}

String &String::append(const char * s) {
    int length = strlen(s);
    if (this->capacity < length + this->length() + 1) {
        this->resize(length + this->length() + 1);
    }
    size_t initialLength = this->length();
    std::memcpy(this->values + initialLength, s, length);
    this->values[length + initialLength] = 0;
    return *this;
}

String &String::append(const String &s) {
    return append(s.values);
}


String String::substring(size_t start, size_t finish) const {
    if(finish == - 1)
        finish = this->length() - 1;
    char *s = new char[finish - start + 2];
    memcpy(s,this->values + start,finish-start + 1);
    s[finish-start + 1] = 0;
    String s1(s);
    return s1;
}

String String::operator+(const char symbol) const {
    String s(*this);
    s.append(symbol);
    return s;
}

String String::operator+(const char *s) const {
    String a(*this);
    a.append(s);
    return a;
}

String String::operator+(const String &that) const {
    String s(*this);
    s.append(that);
    return s;
}

char &String::operator[] (const int index) const {
    return values[index];
}

String& String::operator=(const char *s) {
    delete []this->values;
    size_t length = strlen(s);
    this->values = new char[length + 1];
    for(size_t i = 0; i < length; ++i) {
        this->values[i] = s[i];
    }
    this->values[length] = 0;
    return *this;
}

String& String::operator=(const char symbol) {
    this->operator=(&symbol);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const String &s) {
    out << s.values;
    return out;
}

std::istream &operator>>(std::istream &in, const String &s) {
    in >> s.values;
    return in;
}

String::operator char *() const{
    return this->values; }

String::operator int() const {
    return atoi(this->values);
}

String::operator double() const {
    return atof(this->values);
}
