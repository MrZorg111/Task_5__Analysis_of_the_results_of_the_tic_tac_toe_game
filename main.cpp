#include <iostream>
#include <string>

std::string check (std::string a) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != 'X' && a[i] != 'O' && a[i] != '.') {
            return "No!";
            break;
        }
        else if (i == a.length() - 1) {
            return "Yes!";
        }
    }
    return {};
}
std::string check_result (std::string a, std::string b, std::string c) {
    if ((a[0] == 'X' && b[0] == 'X' && c[0] == 'X') || (a[1] == 'X' && b[1] == 'X' && c[1] == 'X')
        || (a[2] == 'X' && b[2] == 'X' && c[2] == 'X') || (a[0] == 'X' && a[1] == 'X' && a[2] == 'X')
        || (b[0] == 'X' && b[1] == 'X' && b[2] == 'X') || (c[0] == 'X' && c[1] == 'X' && c[2] == 'X')
        || (a[0] == 'X' && b[1] == 'X' && c[2] == 'X') || (c[0] == 'X' && b[1] == 'X' && a[2] == 'X')) {
        return "X";
    }
    else if ((a[0] == 'O' && b[0] == 'O' && c[0] == 'O') || (a[1] == 'O' && b[1] == 'O' && c[1] == 'O')
             || (a[2] == 'O' && b[2] == 'O' && c[2] == 'O') || (a[0] == 'O' && a[1] == 'O' && a[2] == 'O')
             || (b[0] == 'O' && b[1] == 'O' && b[2] == 'O') || (c[0] == 'O' && c[1] == 'O' && c[2] == 'O')
             || (a[0] == 'O' && b[1] == 'O' && c[2] == 'O') || (c[0] == 'O' && b[1] == 'O' && a[2] == 'O')) {
        return "O";
    }
    return {};
}
int count_x (std::string a, std::string b, std::string c) {
    int count_x = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] == 'X') {
            count_x++;
        }
        if (b[i] == 'X') {
            count_x++;
        }
        if (c[i] == 'X') {
            count_x++;
        }
    }
    return count_x;
}
int count_o (std::string a, std::string b, std::string c) {
    int count_o = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] == 'O') {
            count_o++;
        }
        if (b[i] == 'O') {
            count_o++;
        }
        if (c[i] == 'O') {
            count_o++;
        }
    }
return count_o;
}
int count_s (std::string a, std::string b, std::string c) {
    int count_s = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] == '.') {
            count_s++;
        }
        if (b[i] == '.') {
            count_s++;
        }
        if (c[i] == '.') {
            count_s++;
        }
    }
    return count_s;
}
std::string total_result (std::string s, std::string u, std::string f) {
    std::string result;
    result = check_result(s,u,f);
    if (result == "X") {
        return "Petya won!";
    }if (result == "O") {
        return "Vanya won!";
    }
    if ((check(s) == "No!" || check(u) == "No!" || check(f) == "No!")
            || (count_x(s,u,f) < count_o(s,u,f)
                || ((count_x(s,u,f) == count_o(s,u,f) && check_result(s,u,f) == "X")))
                    || ((check_result(s,u,f) == "O" && count_x(s,u,f) > count_o(s,u,f))
                        || (check_result(s,u,f) == "X" && count_x(s,u,f) == count_o(s,u,f)))) {
        return "Incorrect!";
    }
    if ((count_x(s,u,f) > count_o(s,u,f) && count_s(s,u,f) == 0)
            || (count_x(s,u,f) == count_o(s,u,f) && (check_result(s,u,f) != "X" || "O"))) {
        return "Nobody!";
    }
    return {};
}

    int main() {
        std::string str_1, str_2, str_3;

            std::cout << "Enter the data from the playing field\n";
            std::cout << "First string:";
            std::cin >> str_1;
            std::cout << "\nSecond sting:";
            std::cin >> str_2;
            std::cout << "\nThird string:";
            std::cin >> str_3;

            std::cout << total_result(str_1, str_2, str_3);
    }
