#include <iostream>
#include <string>

using namespace std;

// Function buat nampilin pola kata (misal: B _ _ A _ _ A)
void tampilkanKata(string kata, string hurufTertebak) {
    for (int i = 0; i < kata.length(); i++) {
        // Huruf pertama (index 0) otomatis kebuka
        if (i == 0) {
            cout << kata[i] << " ";
        } else {
            // Cek apakah huruf kata[i] udah ada di hurufTertebak
            bool ada = false;
            for (int j = 0; j < hurufTertebak.length(); j++) {
                if (kata[i] == hurufTertebak[j]) {
                    ada = true;
                    break;
                }
            }

            // Kalo ada tampilkan hurufnya, kalo ga ada tampilkan _
            if (ada) {
                cout << kata[i] << " ";
            } else {
                cout << "_ ";
            }
        }
    }
    cout << endl;
}

int main() {
    string klue, kata;

    // 1. Pemain A input Klue & Kata Rahasia
    cout << "=== INPUT PEMAIN A ===" << endl;
    cout << "Masukkan Klue        : ";
    cin >> klue;
    cout << "Masukkan Kata Rahasia: ";
    cin >> kata;

    // Ubah kata rahasia jadi huruf besar semua pake loop dasar
    for (int i = 0; i < kata.length(); i++) {
        kata[i] = toupper(kata[i]);
    }

    // Bersihin layar terminal biar Pemain B ga liat jawaban
    cout << string(50, '\n');

    // 2. Mulai Game buat Pemain B
    string hurufTertebak = "";
    char tebakan;

    cout << "=============================" << endl;
    cout << "      GAME TEBAK KATA        " << endl;
    cout << "=============================" << endl;
    cout << "KLUE: " << klue << endl; // Nampilin Klues

    while (true) {
        cout << "\nKata: ";
        tampilkanKata(kata, hurufTertebak);

        // Cek apakah Pemain B udah menang (semua huruf udah kebuka)
        bool menang = true;
        for (int i = 1; i < kata.length(); i++) {
            bool ditebak = false;
            for (int j = 0; j < hurufTertebak.length(); j++) {
                if (kata[i] == hurufTertebak[j]) {
                    ditebak = true;
                    break;
                }
            }
            if (!ditebak) {
                menang = false;
                break;
            }
        }

        // Kalo udah menang, keluar dari loop game
        if (menang) {
            cout << "\nSelamat! Pemain B berhasil menebak katanya: " << kata << endl;
            break;
        }

        // Input tebakan dari Pemain B
        cout << "Tebak 1 huruf: ";
        cin >> tebakan;
        tebakan = toupper(tebakan); // Ubah ke huruf besar

        // Masukin huruf tebakan ke string penampung
        hurufTertebak += tebakan;
    }

    return 0 ;
}