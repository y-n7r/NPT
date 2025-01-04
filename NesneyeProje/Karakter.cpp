#include "Karakter.h"
#include <cstdlib>
#include <algorithm>


Karakter::Karakter(const string & isim , int can , int guc , int savunma)
    : isim(isim) , can(can) , guc(guc) , savunma(savunma) , sonHasar(0){}


void Karakter:: saldir(Karakter* hedef){
    int hasar = (rand()% guc +1) + sonHasar - hedef -> getSavunma();
    hasar = max(0 , hasar );
    hedef -> canAzalt(hasar);
    sonHasar = hasar / 2;
    cout << isim <<" "<<hedef ->getIsim() <<" Karakterine " << hasar << " hasar verdi! " << endl;
}

void Karakter:: savun(){
    savunma += 5;
    cout << isim << " savunmasini artardi! Gecici savunma: " << savunma << endl;

}

void Karakter::ozelYetenek() {
    cout << isim << " ozel bir yetenek kullandi, ancak bu bir sablon." << endl;
}

void Karakter::canAzalt(int miktar) {
    if (savunma > 0) {
        int kalanHasar = miktar - savunma;
        savunma = max(0, savunma - miktar);
        if (kalanHasar > 0) {
            can -= kalanHasar;
        }
    } else {
        can -= miktar;
    }
    if (can < 0) can = 0;
}

bool Karakter::hayattaMi() const {
    return can > 0;
}

string Karakter::getIsim() const {
    return isim;
    
}

int Karakter::getCan() const {
    return can;
}

int Karakter::getSavunma() const {
    return savunma;
}

void Karakter::sifirlaSavunma() {
    savunma = 0;
}

Karakter::~Karakter() {}

// === Kullanici Implementasyonu ===
Kullanici::Kullanici(const string& isim) : Karakter(isim, 100, 15, 3) {}

void Kullanici::ozelYetenek() {
    cout << isim << " 10 can puani kazandi!" << endl;
    can += 10;
    if (can > 100) can = 100;
}


