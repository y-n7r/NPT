#ifndef KARAKTER_H
#define KARAKTER_H

#include <iostream>
#include <string>
using namespace std;

//* Karakter sınıfı, bir karakterin temel özelliklerini temsil eder
class Karakter {
protected:
    string isim;  // Karakterin adı
    int can;     // Can puanı
    int guc;    // Saldırı gücü
    int savunma;    // Savunma puanı
    int sonHasar;   // Son yapılan hasar

    public:

        //* Kurucu, karakterin temel özelliklerini başlatır
    Karakter(const string& isim, int can, int guc, int savunma);
        //* Sanal (virtual) saldırı fonksiyonu
    virtual void saldir(Karakter* hedef);
    //* Sanal savunma fonksiyonu
    virtual void savun();
    //* Sanal özel yetenek fonksiyonu
    virtual void ozelYetenek();
    //* Karakterin canını azaltır
    void canAzalt(int miktar);
    //* Karakterin canı 0'dan küçük olup olmadığını döndürür
    bool hayattaMi() const;
     //* Karakterin ismini döndürür
    string getIsim() const;
    //* Karakterin mevcut can puanını döndürür
    int getCan() const;
    //* Karakterin mevcut savunma puanını döndürür
    int getSavunma() const;
    //* Savunma puanını sıfırlar
    void sifirlaSavunma();
    //* Yıkıcı (destructor)
    virtual ~Karakter();
};

//* Kullanici sınıfı, oyuncuyu temsil eder ve Karakter sınıfından türetilmiştir
class Kullanici : public Karakter {
public:
     //* Kurucu, oyuncunun özelliklerini başlatır
    Kullanici(const string& isim);
    //* Oyuncunun özel yeteneği, canını artırır
    void ozelYetenek() override;
};

//* Dusman sınıfı, düşmanı temsil eder ve Karakter sınıfından türetilmiştir
class Dusman : public Karakter {
public:
    //* Kurucu, düşmanın özelliklerini başlatır
    Dusman(const string& isim);
     //* Düşmanın özel yeteneği, saldırı gücünü artırır
    void ozelYetenek() override;
};

#endif