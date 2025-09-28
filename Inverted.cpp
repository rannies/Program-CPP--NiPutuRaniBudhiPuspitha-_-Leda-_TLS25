#include <iostream>
using namespace std;

// Untuk membalikkan angka
int balik_angka(int angka) {
    // Jika angkanya 0, hasilnya tetap 0
    if (angka == 0) {
        return 0;
    }
    
    // Cek apakah angka negatif
    bool negatif = false; //menganggap angkanya TIDAK negatif
    if (angka < 0) {
        negatif = true; //kalau ternyata angkanya negatif, baru diubah jadi true dan fungsi if akan tereksekusi
        angka = angka * -1; // Ubah jadi positif dulu
    }
    
    // Balik angkanya
    int hasil = 0;
    while (angka > 0) {
        int digit = angka % 10;    // Ambil digit terakhir: contoh saat 204 mod 10 = 20 sisa 4, angka 4 inilah yang diambil
        hasil = hasil * 10 + digit; // Tambahkan ke hasil
        angka = angka / 10;        // Buang digit terakhir
    }
    
    // Kalau tadi negatif, balikin jadi negatif lagi
    if (negatif) {
        hasil = hasil * -1;
    }
    
    return hasil;
}

int main() {
    // Input jumlah elemen
    int n;
    cout << "Berapa elemen dalam array? ";
    cin >> n;
    
    // Input elemen-elemen array
    int arr[100]; // Maksimal 100 elemen
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Tampilkan array asli
    cout << "\nArray asli: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Proses transformasi
    int jumlah = 0;
    cout << "\nProses:\n";
    
    for (int i = 0; i < n; i++) {
        int asli = arr[i];
        
        // Cek indeks genap atau ganjil
        if (i % 2 == 0) {
            // Indeks genap (0, 2, 4, ...) - balik angkanya
            arr[i] = balik_angka(arr[i]);
            cout << "Posisi " << i << ": " << asli << " -> " << arr[i] << " (dibalik)\n";
        } else {
            // Indeks ganjil (1, 3, 5, ...) - tidak diubah
            cout << "Posisi " << i << ": " << asli << " -> " << arr[i] << " (tidak diubah)\n";
        }
        
        // Tambahkan ke jumlah total
        jumlah = jumlah + arr[i];
    }
    
    // Tampilkan hasil
    cout << "\nArray setelah transformasi: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Jumlah total: " << jumlah << endl;
    
    return 0;
}
