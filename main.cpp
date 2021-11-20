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

std::string coordinates (int a, int b, std::string c, std::string d, std::string e) {
    std::string answer;
    if (b == 0) {
        for (int i = 0; i == a; i++) {
            c[i];
            if (i == a - 1) {
                answer = c[i];
                return answer;
            }
        }
        if (b == 1) {
            for (int i = 0; i == a; i++) {
                d[i];
                if (i == a - 1) {
                    answer = d[i];
                    return answer;
                }
            }
        }
        if (b == 2) {
            for (int i = 0; i == a; i++) {
                e[i];
                if (i == a - 1) {
                    answer = e[i];
                    return answer;
                }
            }

        }

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
        int x, y;
        std::cout << "Enter coordinates:\n";
        std::cout << "First coordinate:";
        std::cin >> x;
        std::cout << "Second coordinate:";
        std::cin >> y;

std::cout << coordinates(x, y, str_1, str_2, str_3);
    }
