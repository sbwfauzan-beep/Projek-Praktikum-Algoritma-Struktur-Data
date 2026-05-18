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
// ================= EDIT =================
void editData() {

    system("cls");

    string cari;

    cout << "Masukkan NIM yang ingin diedit: ";
    cin >> cari;

    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    Mahasiswa *temp = head;
    bool ketemu = false;

    do {

        if (temp->nim == cari) {

            cout << "\n===== DATA LAMA =====\n";
            cout << "Nama     : " << temp->nama << endl;
            cout << "NIM      : " << temp->nim << endl;
            cout << "Jurusan  : " << temp->jurusan << endl;
            cout << "Nilai    : " << temp->nilai << endl;

            cin.ignore();

            cout << "\n===== INPUT DATA BARU =====\n";
            cout << "Nama baru     : "; getline(cin, temp->nama);
            cout << "Jurusan baru  : "; getline(cin, temp->jurusan);
            cout << "Nilai baru    : "; cin >> temp->nilai;

            temp->nilaiAkhir = hitungNilai(temp->nilai);

            cout << "\nData berhasil diperbarui!\n";

            ketemu = true;
            break;
        }

        temp = temp->next;

    } while (temp != head);

    if (!ketemu)
        cout << "Data tidak ditemukan!\n";
}
// ================= DELETE =================
void deleteData() {

    system("cls");

    string cari;

    cout << "Masukkan NIM: ";
    cin >> cari;

    if (head == NULL)
        return;

    Mahasiswa *temp = head;

    do {

        if (temp->nim == cari) {

            if (temp == head && temp == tail) {

                head = tail = NULL;

            } else if (temp == head) {

                head = head->next;
                head->prev = tail;
                tail->next = head;

            } else if (temp == tail) {

                tail = tail->prev;
                tail->next = head;
                head->prev = tail;

            } else {

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;

            cout << "Data berhasil dihapus!\n";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Data tidak ditemukan!\n";
}
// ================= SORTING =================

void tampilHasilSort(string judulSort) {

    cout << "\n===== HASIL SORTING BY " << judulSort << " =====\n";

    cout << left << setw(20) << "Nama" << " | "
         << setw(15) << "NIM" << " | "
         << setw(20) << "Jurusan" << " | "
         << setw(10) << "Nilai" << endl;

    cout << "-----------------------------------------------------------------\n";

    Mahasiswa *temp = head;

    do {

        cout << left << setw(20) << temp->nama << " | "
             << setw(15) << temp->nim << " | "
             << setw(20) << temp->jurusan << " | "
             << setw(10) << temp->nilai << endl;

        temp = temp->next;

    } while (temp != head);
}

int hitungNode() {

    int count = 0;

    if (head == NULL)
        return 0;

    Mahasiswa *temp = head;

    do {

        count++;
        temp = temp->next;

    } while (temp != head);

    return count;
}

// ======== BUBBLE SORT ========

void bubbleSortNama(int mode) {

    if (head == NULL || head->next == head)
        return;

    Mahasiswa *i, *j;

    for (i = head; i->next != head; i = i->next) {

        for (j = i->next; j != head; j = j->next) {

            if ((mode == 1 && i->nama > j->nama) ||
                (mode == 2 && i->nama < j->nama)) {

                swap(i->nama, j->nama);
                swap(i->nim, j->nim);
                swap(i->jurusan, j->jurusan);
                swap(i->nilai, j->nilai);
                swap(i->nilaiAkhir, j->nilaiAkhir);
            }
        }
    }
}

void bubbleSortNIM(int mode) {

    if (head == NULL || head->next == head)
        return;

    Mahasiswa *i, *j;

    for (i = head; i->next != head; i = i->next) {

        for (j = i->next; j != head; j = j->next) {

            if ((mode == 1 && i->nim > j->nim) ||
                (mode == 2 && i->nim < j->nim)) {

                swap(i->nama, j->nama);
                swap(i->nim, j->nim);
                swap(i->jurusan, j->jurusan);
                swap(i->nilai, j->nilai);
                swap(i->nilaiAkhir, j->nilaiAkhir);
            }
        }
    }
}

void bubbleSortNilai(int mode) {

    if (head == NULL || head->next == head)
        return;

    Mahasiswa *i, *j;

    for (i = head; i->next != head; i = i->next) {

        for (j = i->next; j != head; j = j->next) {

            if ((mode == 1 && i->nilai > j->nilai) ||
                (mode == 2 && i->nilai < j->nilai)) {

                swap(i->nama, j->nama);
                swap(i->nim, j->nim);
                swap(i->jurusan, j->jurusan);
                swap(i->nilai, j->nilai);
                swap(i->nilaiAkhir, j->nilaiAkhir);
            }
        }
    }
}
// ======== QUICK SORT ========

void quickSort(int kriteria, int mode) {

    if (kriteria == 1)
        bubbleSortNama(mode);

    else if (kriteria == 2)
        bubbleSortNIM(mode);

    else if (kriteria == 3)
        bubbleSortNilai(mode);
}

// ======== MENU SORTING ========

void menuSorting() {

    system("cls");

    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    int kriteria, algoritma, mode;

    cout << "===== Pilih Kriteria Sorting =====\n";
    cout << "1. Nama\n";
    cout << "2. NIM\n";
    cout << "3. Nilai\n";
    cout << "Pilih: ";
    cin >> kriteria;

    cout << "\n===== Pilih Algoritma Sorting =====\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Quick Sort\n";
    cout << "Pilih: ";
    cin >> algoritma;

    cout << "\n===== Pilih Urutan =====\n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Pilih: ";
    cin >> mode;

    if (kriteria == 1) {

        if (algoritma == 1)
            bubbleSortNama(mode);
        else
            quickSort(1, mode);

        tampilHasilSort("NAMA");

    } else if (kriteria == 2) {

        if (algoritma == 1)
            bubbleSortNIM(mode);
        else
            quickSort(2, mode);

        tampilHasilSort("NIM");

    } else if (kriteria == 3) {

        if (algoritma == 1)
            bubbleSortNilai(mode);
        else
            quickSort(3, mode);

        tampilHasilSort("NILAI");

    } else {

        cout << "Pilihan tidak valid!\n";
    }
}