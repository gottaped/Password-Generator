#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <locale>
#include <codecvt>
std::string generatePassword(int length) {
    const std::string chars = "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()-_=+";
    std::string password;
    password.reserve(length);
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);
    for (int i = 0; i < length; ++i) {
     password.push_back(chars[dist(rng)]);
    }
    return password;
}
int main() {
    setlocale(LC_ALL, "Russian");
    const int passwordLength = 12;
    std::string password = generatePassword(passwordLength);
    std::cout << "Generated Password: " << password << std::endl;
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}