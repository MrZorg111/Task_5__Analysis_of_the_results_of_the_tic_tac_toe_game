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
bool check_result(std::string a, std::string b, std::string c, char d) {
    if ((a[0] == d && b[0] == d && c[0] == d) || (a[1] == d && b[1] == d && c[1] == d)
        || (a[2] == d && b[2] == d && c[2] == d) || (a[0] == d && a[1] == d && a[2] == d)
        || (b[0] == d && b[1] == d && b[2] == d) || (c[0] == d && c[1] == d && c[2] == d)
        || (a[0] == d && b[1] == d && c[2] == d) || (c[0] == d && b[1] == d && a[2] == d)) {

        return true;
    }
    else {
        return false;
    }
}
int count (std::string a, std::string b, std::string c, char d) {
    int count_x = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] == d) {
            count_x++;
        }
        if (b[i] == d) {
            count_x++;
        }
        if (c[i] == d) {
            count_x++;
        }
    }

    return count_x;

}
std::string total_result (std::string s, std::string u, std::string f, char d, char g, char sp) {
    if ((check(s) == "No!" || check(u) == "No!" || check(f) == "No!")
        || (count (s, u, f, d) < count (s, u, f, g)
            || ((count (s, u, f, d) == count (s, u, f, g) && check_result(s, u, f, d))))
        || ((check_result(s, u, f, g) && count (s, u, f, d) > count (s, u, f, g))
            || (check_result(s, u, f, d) == false && check_result(s, u, f, g) == false && count (s, u, f, d) == count (s, u, f, g)))
        || ((check_result(s, u, f, d) && check_result(s, u, f, g)) && (count (s, u, f, d) > count (s, u, f, g) && count (s, u, f, sp) == 0))) {
        return "Incorrect!";
    }
    if (check_result(s, u, f, d)) {
        return "Petya won!";
    }if (check_result(s, u, f, g)) {
        return "Vanya won!";
    }
    if ((count (s, u, f, d) > count (s, u, f, g) && count (s, u, f, sp) == 0)
        || ((check_result(s, u, f, d) && check_result(s, u, f, g) == false) && count (s, u, f, d) == count (s, u, f, g))) {
        return "Nobody!";
    }
    return {};
}

int main() {
    std::string str_1, str_2, str_3;
    char play_x = 88, play_o = 79, play_s = 46;
    std::cout << "Enter the data from the playing field\n";
    std::cout << "First string:";
    std::cin >> str_1;
    std::cout << "\nSecond sting:";
    std::cin >> str_2;
    std::cout << "\nThird string:";
    std::cin >> str_3;

    std::cout << total_result(str_1, str_2, str_3, play_x, play_o, play_s);
}
