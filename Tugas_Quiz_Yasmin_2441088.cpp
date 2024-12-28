#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Untuk fungsi sleep() (simulasi waktu)

// Fungsi untuk simulasi motor
void putar_motor_utama() {
    printf("Motor utama: Berputar 180 derajat.\n");
    sleep(1); // Simulasi waktu operasi
}

void gerakkan_motor_lengan() {
    printf("Motor lengan: Naik/turun sebesar 45 derajat.\n");
    sleep(1); // Simulasi waktu operasi
}

void aktifkan_motor_tangan() {
    printf("Motor tangan: Mendekatkan alat pengelasan ke objek.\n");
    sleep(1); // Simulasi waktu operasi
}

// Fungsi untuk menghitung nilai tengah dari array
int hitung_nilai_tengah(int arr[], int n) {
    return arr[n / 2];
}

// Fungsi untuk mengurutkan array
void urutkan_array(int arr[], int waktu[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar ketebalan
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Tukar waktu
                temp = waktu[j];
                waktu[j] = waktu[j + 1];
                waktu[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Array ketebalan pengelasan
    int ketebalan[] = {6, 8, 12, 18, 24, 30, 36, 42, 49, 50};
    int waktu[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int n = sizeof(ketebalan) / sizeof(ketebalan[0]);

    // Tombol Start
    printf("Tekan tombol START untuk memulai proses pengelasan.\n\n");
    getchar(); // Menunggu input pengguna

    // Hitung nilai tengah
    int nilai_tengah = hitung_nilai_tengah(ketebalan, n);
    printf("Nilai tengah ketebalan pengelasan: %d mm\n\n", nilai_tengah);

    // Urutkan array berdasarkan ketebalan terkecil ke terbesar
    urutkan_array(ketebalan, waktu, n);

    printf("\n=== Program Robot Pengelasan ===\n\n");

    for (int i = 0; i < n; i++) {
        printf("Ketebalan pengelasan: %d mm\n", ketebalan[i]);

        // Simulasi pergerakan motor
        putar_motor_utama();
        gerakkan_motor_lengan();
        aktifkan_motor_tangan();

        // Menampilkan waktu pengelasan
        printf("Waktu pengelasan: %d detik\n", waktu[i]);
        printf("\n--------------------------\n\n");
    }

    printf("Proses pengelasan selesai!\n");

    return 0;
}

