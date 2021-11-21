#include <iostream>
#include <string>

std::string check (std::string a) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != 'X' && a[i] != 'O' && a[i] != '.') {
            return "No!";
        }
        else if (i == a.length() - 1) {
            return "Yes!";
        }
    }
    return {};
}

std::string coordinates (std::string a, std::string b, std::string c) {
    if ((a[0] == 'X' && b[0] == 'X' && c[0] == 'X') || (a[1] == 'X' && b[1] == 'X' && c[1] == 'X')
            || (a[0] == 'X' && b[2] == 'X' && c[2] == 'X') || (a[0] == 'X' && a[1] == 'X' && a[2] == 'X')
                || (b[0] == 'X' && b[1] == 'X' && b[2] == 'X') || (c[0] == 'X' && c[1] == 'X' && c[2] == 'X')
                    || (a[0] == 'X' && b[1] == 'X' && c[2] == 'X') || (c[0] == 'X' && b[1] == 'X' && a[2] == 'X')) {
        return "Petya won";
    }
    else if ((a[0] == 'O' && b[0] == 'O' && c[0] == 'O') || (a[1] == 'O' && b[1] == 'O' && c[1] == 'O')
            || (a[0] == 'O' && b[2] == 'O' && c[2] == 'O') || (a[0] == 'O' && a[1] == 'O' && a[2] == 'O')
                || (b[0] == 'O' && b[1] == 'O' && b[2] == 'O') || (c[0] == 'O' && c[1] == 'O' && c[2] == 'O')
                    || (a[0] == 'O' && b[1] == 'O' && c[2] == 'O') || (c[0] == 'O' && b[1] == 'O' && a[2] == 'O')) {
        return "Vanya won";
    }
}

    int main() {
        std::string str_1, str_2, str_3;
        do {
            std::cout << "Enter the data from the playing field\n";
            std::cout << "First string:";
            std::cin >> str_1;
            std::cout << "\nSecond sting:";
            std::cin >> str_2;
            std::cout << "\nThird string:";
            std::cin >> str_3;
        } while (check(str_1) == "No!" || check(str_2) == "No!" || check(str_3) == "No!");

        std::cout << coordinates(str_1, str_2, str_3);
    }
