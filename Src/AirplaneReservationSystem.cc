#include <iostream>
#include <vector>

void BosKoltuklariGoster(const std::vector<bool>& koltuklar);
void RezervasyonYap(std::vector<bool>& koltuklar);
void RezervasyonIptalEt(std::vector<bool>& koltuklar);

int main() {
    std::vector<bool> koltuklar(10, false); // 10 koltuklu bir uçak

    while (true) {
        // Kullanıcıya seçenekleri göster
        std::cout << "Lütfen aşağıdaki seçeneklerden birini seçin:" << std::endl;
        std::cout << "1. Boş koltukları göster" << std::endl;
        std::cout << "2. Koltuk rezervasyonu yap" << std::endl;
        std::cout << "3. Rezervasyonu iptal et" << std::endl;
        std::cout << "4. Çıkış" << std::endl;

        int secim;
        std::cin >> secim; // Kullanıcının seçimini al

        switch (secim) {
            case 1:
                BosKoltuklariGoster(koltuklar); // Boş koltukları gösterme işlemini çağır
                break;
            case 2:
                RezervasyonYap(koltuklar); // Koltuk rezervasyonu yapma işlemini çağır
                break;
            case 3:
                RezervasyonIptalEt(koltuklar); // Rezervasyonu iptal etme işlemini çağır
                break;
            case 4:
                std::cout << "Çıkış yapılıyor..." << std::endl;
                return 0; // Programı sonlandır
            default:
                std::cout << "Geçersiz seçenek. Lütfen tekrar deneyin." << std::endl;
                break;
        }
    }

    return 0;
}

void BosKoltuklariGoster(const std::vector<bool>& koltuklar) {
    std::cout << "Boş koltuklar:" << std::endl;
    for (size_t i = 0; i < koltuklar.size(); i++) {
        if (!koltuklar[i]) {
            std::cout << "Koltuk " << (i + 1) << std::endl;
        }
    }
}

void RezervasyonYap(std::vector<bool>& koltuklar) {
    std::cout << "Rezervasyon yapmak istediğiniz koltuğun numarasını girin: ";
    int koltukNo;
    std::cin >> koltukNo;

    if (koltukNo < 1 || koltukNo > koltuklar.size()) {
        std::cout << "Geçersiz koltuk numarası. Lütfen tekrar deneyin." << std::endl;
    } else if (koltuklar[koltukNo - 1]) {
        std::cout << "Bu koltuk zaten rezerve edilmiş." << std::endl;
    } else {
        koltuklar[koltukNo - 1] = true;
        std::cout << "Rezervasyon tamamlandı. Koltuk " << koltukNo << " sizin." << std::endl;
    }
}

void RezervasyonIptalEt(std::vector<bool>& koltuklar) {
    std::cout << "Rezervasyonu iptal etmek istediğiniz koltuğun numarasını girin: ";
    int koltukNo;
    std::cin >> koltukNo;

    if (koltukNo < 1 || koltukNo > koltuklar.size()) {
        std::cout << "Geçersiz koltuk numarası. Lütfen tekrar deneyin." << std::endl;
    } else if (!koltuklar[koltukNo - 1]) {
        std::cout << "Bu koltuk zaten boş." << std::endl;
    } else {
        koltuklar[koltukNo - 1] = false;
        std::cout << "Rezervasyon iptal edildi. Koltuk " << koltukNo << " boş." << std::endl;
    }
}
