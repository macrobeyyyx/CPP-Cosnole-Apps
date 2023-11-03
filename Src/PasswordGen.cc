#include <iostream>
#include <random>

std::string SifreOlustur(int uzunluk) {
    const std::string karakterler = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, karakterler.size() - 1);

    std::string sifre;
    for (int i = 0; i < uzunluk; i++) {
        int rastgeleIndex = distribution(generator);
        sifre += karakterler[rastgeleIndex];
    }

    return sifre;
}

int main() {
    std::cout << "Şifre uzunluğunu girin: ";
    int uzunluk;
    std::cin >> uzunluk;

    std::string sifre = SifreOlustur(uzunluk);

    std::cout << "Oluşturulan şifre: " << sifre << std::endl;

    return 0;
}
