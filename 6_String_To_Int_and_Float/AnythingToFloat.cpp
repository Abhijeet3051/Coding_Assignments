#include <iostream>
#include <string>
#include <iomanip>

float atof(char* str) {
    float num = 0;
    int i = 0;

    //predecimal
    while (*(i + str) != '\0') {
        if (*(i + str) == '.') {
            i++;
            break;
        }
        num = num * 10 + (*(i + str) - '0');
        i++;
    }

    //postdecimal
    float dec = 0.1;
    while (*(i + str) != '\0') {
        num = num + (*(i + str) - '0') * dec;
        dec /= 10;
        i++;
    }
    return num;
}


int main() {
    std :: string str;
    std:: cout << "Enter a FLoat" << std:: endl;
    std:: cin >> str;
    char* a = &str[0];

    float number;
    number = atof(a);

    std::cout << std::endl << "String to Float: " << number << std::endl;
    return 2;
}