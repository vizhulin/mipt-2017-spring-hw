#include <iostream>
#include "String.h"

int main() {
    String s1("Hillo,");
    String s2("Hello,people!");
    String s3 = s2;
    s1[1] = 'e';
    std::cout << s1 + "world" + '!' + s3 << std::endl;
    String s4("P");
    s4.append("eople");
    s4.append('!');
    s4.append(s2);
    std::cout << s4 << std::endl;
    std::cout << s4.find('e') << std::endl;
    std::cout << s4.substring(7,11) << std::endl;
    char *s = s4;
    std::cout << s << std::endl;
    return 0;
}