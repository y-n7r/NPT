#include "Karakter.h"
#include <cstdlib>
#include <algorithm>

//* === Karakter Implementasyonu ===

//* Kurucu, karakterin temel özelliklerini başlatır
Karakter::Karakter(const string & isim , int can , int guc , int savunma)
    : isim(isim) , can(can) , guc(guc) , savunma(savunma) , sonHasar(0){}

//* Karakterin bir hedefe saldırmasını sağlar
void Karakter:: saldir(Karakter* hedef){
        //* Hasarı hesaplar (güç + son hasar - hedefin savunması)
    int hasar = (rand()% guc +1) + sonHasar - hedef -> getSavunma();
    hasar = max(0 , hasar ); //* Hasarın negatif olmamasını garanti eder
    hedef -> canAzalt(hasar);   //* Hedefin canını azaltır
    sonHasar = hasar / 2;       // Son hasarı yarıya düşürür
    cout << isim <<" "<<hedef ->getIsim() <<" Karakterine " << hasar << " hasar verdi! " << endl;
}

//* Karakterin savunma yapmasını sağlar
void Karakter:: savun(){
    savunma += 5;   // Savunma puanını artırır
    cout << isim << " savunmasini artardi! Gecici savunma: " << savunma << endl;

}

// Özel yetenek (varsayılan olarak bir şey yapmaz)
void Karakter::ozelYetenek() {
    cout << isim << " ozel bir yetenek kullandi, ancak bu bir sablon." << endl;
}

// Karakterin canını azaltır
void Karakter::canAzalt(int miktar) {
    if (savunma > 0) {      // Eğer savunma puanı varsa, önce onu kullanır
        int kalanHasar = miktar - savunma;
        savunma = max(0, savunma - miktar);
        if (kalanHasar > 0) {
            can -= kalanHasar;      // Eğer savunma yetmezse, kalan hasarı can puanından düşer
        }
    } else {
        can -= miktar;      // Eğer savunma yoksa, direkt can puanından düşer
    }
    if (can < 0) can = 0;       // Can puanını negatif olmaktan korur
}

// Karakterin hayatta olup olmadığını kontrol eder
bool Karakter::hayattaMi() const {
    return can > 0;
}

// Karakterin ismini döndürür
string Karakter::getIsim() const {
    return isim;
    
}

// Karakterin can puanını döndürür
int Karakter::getCan() const {
    return can;
}

// Karakterin savunma puanını döndürür
int Karakter::getSavunma() const {
    return savunma;
}

// Karakterin savunma puanını sıfırlar
void Karakter::sifirlaSavunma() {
    savunma = 0;
}

// Yıkıcı (destructor)
Karakter::~Karakter() {}

//* === Kullanici Implementasyonu ===

//* Kullanici sınıfının kurucusu, oyuncunun özelliklerini başlatır
Kullanici::Kullanici(const string& isim) : Karakter(isim, 100, 15, 3) {}

//? Oyuncunun özel yeteneği, can puanını artırır
void Kullanici::ozelYetenek() {
    cout << isim << " 10 can puani kazandi!" << endl;
    can += 10;
    if (can > 100) can = 100;       // Can puanının maksimum 100 olmasını sağlar
}

//* === Dusman Implementasyonu ===

//? Dusman sınıfının kurucusu, düşmanın özelliklerini başlatır
Dusman::Dusman(const string& isim) : Karakter(isim, 100, 15, 3) {}

// Düşmanın özel yeteneği, saldırı gücünü artırır
void Dusman::ozelYetenek() {
    cout << isim << " saldiri gucunu artirdi!" << endl;
    guc += 5;
}
