#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
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
        system("cls");

        cout << "Selamat Datang di Aplikasi Mahasiswa!" << endl;
        cout << "Ayo Login Terlebih Dahulu!\n";
        cout << "=====================================" << endl;
        cout << "Username : "; cin >> user;
        cout << "Password : "; cin >> pass;

        if (user != "admin" || pass != "123") {
            cout << "Login gagal! Nama atau Password mungkin salah!\n\n";
            system("pause");
        }

    } while (user != "admin" || pass != "123");

    cout << "Selamat, Login Telah Sukses!\n";
    system("pause");
    system("cls");
}

// ================= HITUNG NILAI =================
float hitungNilai(float nilai) {
    return nilai;
}
// ================= INPUT DATA =================
void inputData() {

    system("cls");

    int n;

    cout << "=====================================" << endl;
    cout << "|      >> Input Mahasiswa >>        |" << endl;
    cout << "=====================================" << endl;
    cout << "Ingin Input Berapa Data? ";
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {

        Mahasiswa *baru = new Mahasiswa;

        cout << "\nData ke-" << i << endl;
        cout << "Nama     : "; getline(cin, baru->nama);
        cout << "NIM      : "; cin >> baru->nim;
        cin.ignore();
        cout << "Jurusan  : "; getline(cin, baru->jurusan);
        cout << "Nilai    : "; cin >> baru->nilai;
        cin.ignore();

        baru->nilaiAkhir = hitungNilai(baru->nilai);
        baru->next = NULL;
        baru->prev = NULL;

        if (head == NULL) {
            head = tail = baru;
            head->next = head;
            head->prev = head;
        } else {
            baru->prev = tail;
            baru->next = head;
            tail->next = baru;
            head->prev = baru;
            tail = baru;
        }

        cout << "Selamat, Data Kamu berhasil ditambahkan!\n";
    }
}

// ================= TAMPIL DATA =================
void tampilData() {

    system("cls");

    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    Mahasiswa *temp = head;

    cout << "======================================================================\n";
    cout << "             DATA MAHASISWA                    \n" << endl;
    cout << "====================================================================== \n";

    cout << left << setw(20) << "Nama" << " | "
         << setw(15) << "NIM" << " | "
         << setw(20) << "Jurusan" << " | "
         << setw(10) << "Nilai" << endl;

    cout << "---------------------------------------------------------------------\n";

    do {

        cout << left << setw(20) << temp->nama << " | "
             << setw(15) << temp->nim << " | "
             << setw(20) << temp->jurusan << " | "
             << setw(10) << temp->nilai << endl;

        temp = temp->next;

    } while (temp != head);
}