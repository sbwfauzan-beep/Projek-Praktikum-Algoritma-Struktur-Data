#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama, nim, jurusan;
    float nilai, nilaiAkhir;

    Mahasiswa *next;
    Mahasiswa *prev;
};

Mahasiswa *head = NULL;
Mahasiswa *tail = NULL;

// ================= LOGIN =================
void login() {
    string user, pass;
    do {
		cout << "Selamat Datang di Aplikasi Mahasiswa!"<<endl;
        cout << "Ayo Login Terlebih Dahulu!\n";
        cout << "====================================="<<endl;
        cout << "Username : "; cin >> user;
        cout << "Password : "; cin >> pass;

        if (user != "admin" || pass != "123") {
            cout << "Login gagal! Nama atau Password mungin salah!\n\n";
        }
    } while (user != "admin" || pass != "123");

    cout << "Selamat, Login Telah Sukses!\n";
}