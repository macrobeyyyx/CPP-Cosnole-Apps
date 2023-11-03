#include <iostream>
#include <map>

void UrunSatinAl(std::map<std::string, double>& urunler, std::map<std::string, int>& siparisler);
void SiparisGecmisiGoruntule(const std::map<std::string, int>& siparisler);

int main() {
    std::cout << "Kafe Sistemi" << std::endl;
    std::cout << "Ürünler:" << std::endl;

    std::map<std::string, double> urunler = {
        { "Çay", 2.0 },
        { "Kahve", 3.0 },
        { "Sandviç", 5.0 },
        { "Meyve Suyu", 4.0 }
    };

    std::map<std::string, int> siparisler;

    bool devamEt = true;
    while (devamEt) {
        std::cout << "Kantin Ürünleri:" << std::endl;
        for (const auto& urun : urunler) {
            std::cout << urun.first << " - " << urun.second << " TL" << std::endl;
        }

        std::cout << "Lütfen bir işlem seçin:" << std::endl;
        std::cout << "1. Ürün Satın Alma" << std::endl;
        std::cout << "2. Sipariş Geçmişi Görüntüle" << std::endl;
        std::cout << "3. Çıkış" << std::endl;

        int secim;
        std::cin >> secim;

        switch (secim) {
            case 1:
                UrunSatinAl(urunler, siparisler);
                break;
            case 2:
                SiparisGecmisiGoruntule(siparisler);
                break;
            case 3:
                std::cout << "Çıkış yapılıyor..." << std::endl;
                devamEt = false;
                break;
            default:
                std::cout << "Geçersiz seçenek. Lütfen tekrar deneyin." << std::endl;
                break;
        }
    }

    return 0;
}

void UrunSatinAl(std::map<std::string, double>& urunler, std::map<std::string, int>& siparisler) {
    std::cout << "Satın almak istediğiniz ürünü seçin: ";
    std::string urun;
    std::cin >> urun;

    if (urunler.count(urun) > 0) {
        std::cout << "Kaç adet almak istiyorsunuz: ";
        int adet;
        std::cin >> adet;

        double toplamFiyat = urunler[urun] * adet;

        if (siparisler.count(urun) > 0) {
            siparisler[urun] += adet;
        }
        else {
            siparisler[urun] = adet;
        }

        std::cout << "Siparişiniz alındı. Toplam Tutar: " << toplamFiyat << " TL" << std::endl;
    }
    else {
        std::cout << "Geçersiz ürün seçimi." << std::endl;
    }
}

void SiparisGecmisiGoruntule(const std::map<std::string, int>& siparisler) {
    std::cout << "Sipariş Geçmişi:" << std::endl;
    for (const auto& siparis : siparisler) {
        std::cout << siparis.first << " - " << siparis.second << " adet" << std::endl;
    }
}
