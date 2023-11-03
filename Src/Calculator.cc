#include <iostream>

int main() {
    // Kullanıcıdan veri almak için bir Scanner nesnesi yerine std::cin kullanıyoruz
    std::cout << "Basit Hesap Makinesi" << std::endl;
    std::cout << "İşlem seçin (+, -, *, /): ";
    // Kullanıcının seçtiği işlem türünü al
    char islemTuru;
    std::cin >> islemTuru;

    // İşlem için kullanılacak iki sayıyı al
    std::cout << "Birinci sayıyı girin: ";
    int sayi1;
    std::cin >> sayi1;

    std::cout << "İkinci sayıyı girin: ";
    int sayi2;
    std::cin >> sayi2;

    // Sonuç değişkenini başlangıçta sıfıra ayarla
    int sonuc = 0;

    // Eğer işlem türü bölme (/) ise
    if (islemTuru == '/') {
        // Koşul açılıyor: Eğer ikinci sayı sıfıra eşit değilse
        if (sayi2 != 0) {
            // Bölme işlemi yapılır
            double bolme = static_cast<double>(sayi1) / sayi2;
            std::cout << "Sonuç: " << bolme << std::endl;
            return 0; // Programın sonlandırılmasını sağlar
        } else {
            // Eğer ikinci sayı sıfırsa, sıfıra bölme hatası alınır
            std::cout << "Hata: Sıfıra bölme hatası!" << std::endl;
            return 0; // Programın sonlandırılmasını sağlar
        }
    } else if (islemTuru == '+') {
        sonuc = sayi1 + sayi2;
    } else if (islemTuru == '-') {
        sonuc = sayi1 - sayi2;
    } else if (islemTuru == '*') {
        sonuc = sayi1 * sayi2;
    } else {
        // Geçersiz işlem hatası alınır (örneğin: ())
        std::cout << "Geçersiz işlem." << std::endl;
        return 0; // Programın sonlandırılmasını sağlar
    }

    std::cout << "Sonuç: " << sonuc << std::endl;

    return 0;
}
