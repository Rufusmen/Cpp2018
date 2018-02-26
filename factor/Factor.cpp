//
// Created by rufus on 26.02.18.
//
#include <iostream>
#include <vector>
#include <cmath>


int64_t string_to_long(std::string s);

int char_to_int(char i);

bool is_prime(int64_t x);

std::vector<int64_t> factor(int64_t x);

int main(int args, char **argv) {
    if (args <= 1) {
        std::cerr
                <<"Program wywołany bez argumentów.\n"
                <<"Proszę uruchomić program z co najmniej 1 argumentem.\n"
                <<"Przykładowe prawidłowe wywołanie programu: ./factor 32189378 -123131 5"
                << std::endl;
        return 1;
    }
    for (int i = 1; i < args; i++) {
        std::string s(argv[i]);
        int64_t x = 0;
        try {
            x = string_to_long(s);
        } catch (std::invalid_argument &e) {
            std::cout << s << ": error" << std::endl;
            std::cerr << e.what() << std::endl;
            std::cerr.flush();
            continue;
        }
        std::cout << x << ": ";
        if(x==-9223372036854775808){
            std::cout<< "-1*2*";
            x/=2;
            x*=-1;
        }
        if (x == -1 || x == 0 || x == 1)std::cout << std::endl;
        else {
            if (x < 0) {
                std::cout << "-1*";
                x *= (-1);
            }
            if (is_prime(x)) {
                std::cout << x << std::endl;
            } else {
                std::vector<int64_t> vec = factor(x);
                int64_t last = vec.back();
                vec.pop_back();
                for (auto y : vec) {
                    std::cout << y << "*";
                }
                std::cout << last;
                std::cout << std::endl;
            }
        }
    std::cout.flush();
    }
}

std::vector<int64_t> factor(int64_t x) {
    std::vector<int64_t> vec;
    auto sqrt_x = static_cast<int64_t>(sqrt(x));
    for (int i = 2; i <= sqrt_x; i++) {
        while (x % i == 0) {
            vec.push_back(i);
            x /= i;
        }
        sqrt_x = static_cast<int64_t>(sqrt(x));
        if (x <= 1)break;
    }
    if(x>sqrt_x)vec.push_back(x);
    return vec;
}

bool is_prime(int64_t x) {
    auto sqrt_x = static_cast<int64_t>(sqrt(x));
    if(x%2==0)return false;
    for (int64_t i = 3; i <= sqrt_x; i+=2) {
        if (x % i == 0)return false;
    }
    return true;
}

int64_t string_to_long(std::string s) {
    int64_t wyn = 0;
    int64_t mult = 1;
    while (!s.empty()) {
        if (s.size() == 1 && s[0] == '-')wyn *= -1;
        else {
            int64_t digit = char_to_int(s[s.size() - 1]);
            if (digit == -1)throw std::invalid_argument("Błędny argument");
            digit *= mult;
            wyn += digit;
            mult *= 10;
        }
        s.erase(s.size() - 1);
    }
    return wyn;
}

int char_to_int(char i) {
    if (i >= '0' && i <= '9')return i - '0';
    return -1;
}