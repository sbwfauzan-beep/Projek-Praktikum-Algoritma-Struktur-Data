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

// ================= HITUNG NILAI =================
float hitungNilai(float nilai) {
    return nilai; // bisa kamu ubah jadi lebih kompleks
}

void inputData() {
    int n;
    cout << "====================================="<<endl;
    cout << "| >> Input Mahasiswa >> |"<<endl;
    cout << "====================================="<<endl;
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

        // 🔥 masuk ke linked list
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
// ================= OUTPUT =================
void tampilData() {
    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    // tampil awal
    Mahasiswa *temp = head;

	cout << "===============================================\n";
	cout << "                 DATA MAHASISWA               \n"<<endl;;
	cout << "===============================================\n";

// header tabel
cout << left << setw(20) << "Nama" << " | "
     << setw(15) << "NIM" << " | "
     << setw(20) << "Jurusan" << " | "
     << setw(10) << "Nilai" << endl;

cout << "---------------------------------------------------------------\n";