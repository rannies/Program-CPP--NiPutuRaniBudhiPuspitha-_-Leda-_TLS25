#include <iostream>
#include <string>
using namespace std;

// untuk membalik string 
string balik(string kata) {
    string hasil = "";
    for (int i = kata.length() - 1; i >= 0; i--) {
        hasil += kata[i];
    }
    return hasil;
}

// untuk hapus vokal
string hapusVokal(string kata) {
    string hasil = "";
    for (int i = 0; i < kata.length(); i++) {
        char huruf = kata[i];
        // Cek apakah bukan vokal
        if (huruf != 'a' && huruf != 'e' && huruf != 'i' && huruf != 'o' && huruf != 'u' &&
            huruf != 'A' && huruf != 'E' && huruf != 'I' && huruf != 'O' && huruf != 'U') {
            hasil += huruf;
        }
    }
    return hasil;
}

// membuat kata sandi
string buatSandi(string kata) {
    // Ambil huruf pertama
    char hurufPertama = kata[0];
    int ascii = hurufPertama;
    
    // Hapus vokal
    string tanpaVokal = hapusVokal(kata);
    
    // Balik
    string dibalik = balik(tanpaVokal);
    
    // Masukkan ASCII di tengah
    int tengah = dibalik.length() / 2;
    string sandi = dibalik.substr(0, tengah) + to_string(ascii) + dibalik.substr(tengah);
    
    return sandi;
}

// decode sandi
void bacaSandi(string sandi) {
    cout << "\nAnalisis sandi: " << sandi << endl;
    
    // Cari angka
    string angka = "";
    string huruf = "";
    
    for (int i = 0; i < sandi.length(); i++) {
        if (sandi[i] >= '0' && sandi[i] <= '9') {
            angka += sandi[i];
        } else {
            huruf += sandi[i];
        }
    }
    
    // Konversi ASCII ke huruf
    int kodeASCII = stoi(angka);
    char hurufPertama = kodeASCII;
    
    cout << "Kode ASCII: " << kodeASCII << " = '" << hurufPertama << "'" << endl;
    cout << "Huruf pertama kata asli: " << hurufPertama << endl;
    cout << "Huruf tanpa angka: " << huruf << endl;
    
    // Balik lagi
    string kataTanpaVokal = balik(huruf);
    cout << "Kata tanpa vokal: " << kataTanpaVokal << endl;
    
    cout << "Sekarang tambahkan vokal untuk mendapat kata lengkap!" << endl;
}

int main() {
    cout << "MESIN KATA SANDI TIMOTHY" << endl;
    
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Buat sandi" << endl;
        cout << "2. Baca sandi" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        
        int pilihan;
        cin >> pilihan;
        
        if (pilihan == 1) {
            cout << "Masukkan kata: ";
            string kata;
            cin >> kata;
            cout << "Sandi: " << buatSandi(kata) << endl;
        }
        else if (pilihan == 2) {
            cout << "Masukkan sandi: ";
            string sandi;
            cin >> sandi;
            bacaSandi(sandi);
        }
        else if (pilihan == 3) {
            cout << "Thankyou, bye!" << endl;
            break;
        }
        else {
            cout << "Pilihan salah!" << endl;
        }
    }
    
    return 0;
}