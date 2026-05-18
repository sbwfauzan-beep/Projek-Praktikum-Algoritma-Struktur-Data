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
// ================= SEARCH =================

// --- Sequential Search ---
void sequentialSearch() {

    system("cls");

    string cari;

    cout << "Masukkan NIM yang dicari: ";
    cin >> cari;

    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    Mahasiswa *temp = head;
    bool ketemu = false;
    int langkah = 0;

    do {

        langkah++;

        if (temp->nim == cari) {

            cout << "\n===== DATA DITEMUKAN (Sequential Search) =====\n";
            cout << "Ditemukan pada langkah ke-" << langkah << endl;
            cout << "Nama        : " << temp->nama << endl;
            cout << "NIM         : " << temp->nim << endl;
            cout << "Jurusan     : " << temp->jurusan << endl;
            cout << "Nilai       : " << temp->nilai << endl;
            cout << "Nilai Akhir : " << temp->nilaiAkhir << endl;

            ketemu = true;
            break;
        }

        temp = temp->next;

    } while (temp != head);

    if (!ketemu)
        cout << "Data tidak ditemukan!\n";
}

// --- Binary Search ---
void binarySearch() {

    system("cls");

    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    int count = 0;
    Mahasiswa *temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    Mahasiswa **arr = new Mahasiswa*[count];

    temp = head;

    for (int i = 0; i < count; i++) {
        arr[i] = temp;
        temp = temp->next;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (arr[j]->nim > arr[j+1]->nim) {

                Mahasiswa *tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    string cari;

    cout << "Masukkan NIM yang dicari: ";
    cin >> cari;

    int low = 0, high = count - 1, mid;
    bool ketemu = false;

    while (low <= high) {

        mid = (low + high) / 2;

        if (arr[mid]->nim == cari) {

            cout << "\n===== DATA DITEMUKAN (Binary Search) =====\n";
            cout << "Nama        : " << arr[mid]->nama << endl;
            cout << "NIM         : " << arr[mid]->nim << endl;
            cout << "Jurusan     : " << arr[mid]->jurusan << endl;
            cout << "Nilai       : " << arr[mid]->nilai << endl;
            cout << "Nilai Akhir : " << arr[mid]->nilaiAkhir << endl;

            ketemu = true;
            break;

        } else if (arr[mid]->nim < cari) {

            low = mid + 1;

        } else {

            high = mid - 1;
        }
    }

    if (!ketemu)
        cout << "Data tidak ditemukan!\n";

    delete[] arr;
}

void menuSearch() {

    system("cls");

    int pilih;

    cout << "===== Pilihan Searching =====\n";
    cout << "1. Sequential Search\n";
    cout << "2. Binary Search (by NIM)\n";
    cout << "Pilih: ";
    cin >> pilih;

    if (pilih == 1)
        sequentialSearch();

    else if (pilih == 2)
        binarySearch();

    else
        cout << "Pilihan tidak valid!\n";
}