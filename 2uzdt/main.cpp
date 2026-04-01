#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_MOK = 100;
    const int MAX_PAZ = 10;

    string vardai[MAX_MOK];
    int pazymiai[MAX_MOK][MAX_PAZ];
    int kiekPaz[MAX_MOK];

    int mokKiekis = 0;
    int pasirinkimas;

    do {
        cout << "\n===== PAZYMIU PROGRAMA =====\n";
        cout << "1 - Naujas mokinys\n";
        cout << "2 - Rodyti visus\n";
        cout << "3 - Rodyti viena\n";
        cout << "4 - Keisti pazymi\n";
        cout << "0 - Iseiti\n";
        cin >> pasirinkimas;

        switch (pasirinkimas) {

        case 1: {
            if (mokKiekis >= MAX_MOK) {
                cout << "Sarasas pilnas!\n";
                break;
            }

            cout << "Ivesk varda: ";
            cin >> vardai[mokKiekis];

            cout << "Kiek pazymiu: ";
            cin >> kiekPaz[mokKiekis];

            if (kiekPaz[mokKiekis] < 1 || kiekPaz[mokKiekis] > MAX_PAZ) {
                cout << "Blogas pazymiu kiekis!\n";
                break;
            }

            for (int j = 0; j < kiekPaz[mokKiekis]; j++) {
                cout << "Pazymys " << j + 1 << ": ";
                cin >> pazymiai[mokKiekis][j];

                if (pazymiai[mokKiekis][j] < 1 || pazymiai[mokKiekis][j] > 10) {
                    cout << "Blogas pazymys, vesk is naujo!\n";
                    j--;
                }
            }

            mokKiekis++;
            cout << "Prideta!\n";
            break;
        }

        case 2: {
            if (mokKiekis == 0) {
                cout << "Tuscia.\n";
                break;
            }

            for (int i = 0; i < mokKiekis; i++) {
                cout << vardai[i] << ": ";
                for (int j = 0; j < kiekPaz[i]; j++) {
                    cout << pazymiai[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
            case 3: {
            string v;
            bool rasta = false;

            cout << "Vardas: ";
            cin >> v;

            for (int i = 0; i < mokKiekis; i++) {
                if (vardai[i] == v) {
                    cout << vardai[i] << ": ";
                    for (int j = 0; j < kiekPaz[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                    rasta = true;
                    break;
                }
            }

            if (!rasta) {
                cout << "Nerasta.\n";
            }
            break;
            }

            case 4: {
            string v;
            bool rasta = false;

            cout << "Vardas: ";
            cin >> v;

            for (int i = 0; i < mokKiekis; i++) {
                if (vardai[i] == v) {

                    for (int j = 0; j < kiekPaz[i]; j++) {
                        cout << j + 1 << ":" << pazymiai[i][j] << " ";
                    }
                    cout << endl;

                    int nr, naujas;
                    cout << "Kurio nr keisti: ";
                    cin >> nr;

                    if (nr < 1 || nr > kiekPaz[i]) {
                        cout << "Blogas numeris!\n";
                        rasta = true;
                        break;
                    }

                    cout << "Naujas pazymys: ";
                    cin >> naujas;

                    if (naujas < 1 || naujas > 10) {
                        cout << "Blogas pazymys!\n";
                        rasta = true;
                        break;
                    }

                    pazymiai[i][nr - 1] = naujas;
                    cout << "Pakeista!\n";
                    rasta = true;
                    break;
                }
            }

            if (!rasta) {
                cout << "Nerasta.\n";
            }
            break;
            }

