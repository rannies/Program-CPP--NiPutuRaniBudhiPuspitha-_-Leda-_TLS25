#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk menentukan warna lampu lalu lintas
string warna_lampu(int detik) {
    // Durasi masing-masing lampu
    int durasiHijau = 20;   // 20 detik
    int durasiKuning = 3;   // 3 detik  
    int durasiMerah = 80;   // 80 detik
    
    // Total siklus = 20 + 3 + 80 = 103 detik
    int totalSiklus = 103;
    
    // Offset karena lampu tidak mulai dari hijau
    // Kuning dimulai di detik 45, seharusnya di detik 20
    int offset = 25;
    
    // Sesuaikan waktu dengan offset
    int waktuDisesuaikan = detik - offset;
    
    // Jika negatif, tambah siklus sampai positif
    while (waktuDisesuaikan < 0) {
        waktuDisesuaikan = waktuDisesuaikan + totalSiklus;
    }
    
    // Cari posisi dalam siklus menggunakan modulus
    int Posisi = waktuDisesuaikan % totalSiklus;
    
    // Tentukan warna berdasarkan posisi
    if (Posisi < durasiHijau) {
        return "Hijau";
    } else if (Posisi < durasiHijau + durasiKuning) {
        return "Kuning"; 
    } else {
        return "Merah";
    }
}

// Fungsi untuk menampilkan hasil
void tampilkanWarna(int detik) {
    string warna = warna_lampu(detik);
    cout << "Detik ke-" << detik << " = " << warna << endl;
}

int main() {
    cout << "LAMPU LALU LINTAS" << endl;
    cout << "Urutan: Hijau (20 detik) -> Kuning (3 detik) -> Merah (80 detik)" << endl;
    cout << "Total siklus: 103 detik" << endl;
    cout << "Kuning pertama muncul di detik 45-47" << endl << endl;
    
    // Tes soal yang diminta
    cout << "JAWABAN SOAL:" << endl;
    tampilkanWarna(80);
    tampilkanWarna(135);
    tampilkanWarna(150);
    tampilkanWarna(212);
    
    cout << endl << "CONTOH BEBERAPA DETIK LAINNYA:" << endl;
    // Tampilkan transisi lampu
    int contohDetik[] = {43, 44, 45, 48, 49, 125, 128, 148};
    int jumlahContoh = 8;
    
    for (int i = 0; i < jumlahContoh; i++) {
        tampilkanWarna(contohDetik[i]);
    }
    
    cout << endl << "SIMULASI 1 SIKLUS PENUH (mulai detik 25):" << endl;
    cout << "Detik 25-44: Hijau (20 detik)" << endl;
    cout << "Detik 45-47: Kuning (3 detik)" << endl;  
    cout << "Detik 48-127: Merah (80 detik)" << endl;
    cout << "Detik 128: Kembali ke Hijau (siklus baru)" << endl;
    
    return 0;
}