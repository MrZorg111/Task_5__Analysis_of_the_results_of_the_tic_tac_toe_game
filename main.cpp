#include <iostream>
#include <string>

std::string check (std::string a) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != 'X' || a[i] != 'O' || a[i] != '.') {
            return "No!";
        }
        else if (i == a. length() - 1) {
            return "Yes!";
        }
    }
}

int main() {
    std::string str_1, str_2, str_3;
    do{
        std::cout << "Enter the data from the playing field\n";
        std::cout << "First string:";
        std::cin >> str_1;
        std::cout << "\nSecond sting:";
        std::cin >> str_2;
        std::cout << "\nThird string:";
        std::cin >> str_3;
    }while (check(str_1) == "No!" || check(str_2) == "No!" || check(str_3) == "No!");
}
