#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // Kullanıcıdan veri almak için bir Scanner nesnesi yerine std::cin kullanıyoruz
    std::cout << "Lise mi (L) yoksa Üniversite mi (Ü) okuyorsunuz? (L/Ü): ";
    std::string okulTuru;
    std::cin >> okulTuru;

    // Toplam ders sayısını öğren
    std::cout << "Toplam ders sayısını girin: ";
    int toplamDersSayisi;
    std::cin >> toplamDersSayisi;

    // Sınıf geçme notunu öğren
    std::cout << "Sınıf geçme notunu girin: ";
    double sinifGecmeNotu;
    std::cin >> sinifGecmeNotu;

    // Toplam not değerini saklamak için bir değişken tanımla (double) ve kalan ders sayısını saklamak için bir değişken tanımla (int)
    double toplamNot = 0;
    int kalanDersSayisi = 0;

    // Girilen ders sayısına göre ders notlarını al ve toplam nota ekle
    for (int i = 1; i <= toplamDersSayisi; i++) {
        std::cout << "Ders " << i << " notunu girin: ";
        double dersNotu;
        std::cin >> dersNotu;
        toplamNot += dersNotu;

        // Ders notu sınıf geçme notundan düşükse, kalan ders sayısını artır
        if (dersNotu < sinifGecmeNotu) {
            kalanDersSayisi++;
        }
    }

    // Ortalama notu hesapla
    double ortalamaNot = toplamNot / toplamDersSayisi;
    std::cout << "Ortalama Not: " << std::fixed << std::setprecision(2) << ortalamaNot << std::endl;
    std::cout << "Başarılı Ders Sayısı: " << (toplamDersSayisi - kalanDersSayisi) << std::endl;
    std::cout << "Kalan Ders Sayısı: " << kalanDersSayisi << std::endl;

    // Mantıksal işlem: Kullanıcının okul türüne ve başarı durumuna göre mesaj ver
    if (okulTuru == "L" || okulTuru == "l") { // Lise
        if (kalanDersSayisi > 3 || ortalamaNot < 55) {
            std::cout << "Sınıfta kaldınız!" << std::endl;
        } else {
            std::cout << "Sınıfı geçtiniz!" << std::endl;
        }
    } else if (okulTuru == "Ü" || okulTuru == "ü") { // Üniversite
        if (kalanDersSayisi > 2 || ortalamaNot < 60) {
            std::cout << "Sınıfta kaldınız!" << std::endl;
        } else {
            std::cout << "Sınıfı geçtiniz!" << std::endl;
        }
    } else {
        std::cout << "Geçersiz okul türü seçimi." << std::endl;
    }

    return 0;
}
