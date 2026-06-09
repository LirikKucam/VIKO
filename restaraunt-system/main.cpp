#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;
const double PVM = 0.21;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

void getData(menuItemType menuList[], int &itemCount);
void showMenu(const menuItemType menuList[], int itemCount);
void printCheck(const menuItemType menuList[], int itemCount);

int main() {
    menuItemType menuList[MAX_ITEMS];
    int itemCount = 0;

    getData(menuList, itemCount);

    if (itemCount == 0) {
        cout << "Nepavyko nuskaityti menu.txt failo." << endl;
        return 1;
    }

    char again;

    do {
        showMenu(menuList, itemCount);
        printCheck(menuList, itemCount);

        cout << endl;
        cout << "Ar norite atlikti dar viena uzsakyma? (t/n): ";
        cin >> again;

    } while (again == 't' || again == 'T');

    cout << "Aciu, kad apsilankete restorane \"Pas Kirila\"!" << endl;

    return 0;
}

void getData(menuItemType menuList[], int &itemCount) {
    ifstream fin("menu.txt");
    itemCount = 0;

    if (!fin) {
        return;
    }

    while (itemCount < MAX_ITEMS && getline(fin, menuList[itemCount].menuItem)) {
        fin >> menuList[itemCount].menuPrice;
        fin.ignore(1000, '\n');
        itemCount++;
    }

    fin.close();
}

void showMenu(const menuItemType menuList[], int itemCount) {
    cout << fixed << setprecision(2);

    cout << endl;
    cout << "Sveiki atvyke i mano  restorana \"Pas Kirila\"" << endl;
    cout << "Pusryciu meniu:" << endl << endl;

    for (int i = 0; i < itemCount; i++) {
        cout << i + 1 << ". "
             << left << setw(35) << menuList[i].menuItem
             << right << menuList[i].menuPrice << " EUR" << endl;
    }

    cout << endl;
    cout << "Uzsakymo pavyzdys: 1 2" << endl;
    cout << "Tai reiskia: pirmas patiekalas, 2 porcijos." << endl;
    cout << "Norint baigti, iveskite: 0 0" << endl;
}

void printCheck(const menuItemType menuList[], int itemCount) {
    ofstream fout("receipt.txt");

    if (!fout) {
        cout << "Nepavyko sukurti receipt.txt failo." << endl;
        return;
    }

    int choice, quantity;
    double subtotal = 0;

    fout << fixed << setprecision(2);

    fout << "Sveiki atvyke i restorana \"Pas Kirila\"" << endl;


    cout << endl;
    cout << "Uzsakymas:" << endl;


    while (true) {
        cout << "Iveskite patiekalo numeri ir kieki: ";
        cin >> choice >> quantity;

        if (choice == 0 && quantity == 0) {
            break;
        }

        if (choice < 1 || choice > itemCount || quantity <= 0) {
            cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
            continue;
        }

        double itemTotal = menuList[choice - 1].menuPrice * quantity;
        subtotal += itemTotal;

        cout << quantity << "  "
             << left << setw(35) << menuList[choice - 1].menuItem
             << right << itemTotal << " EUR" << endl;

        fout << quantity << "  "
             << left << setw(35) << menuList[choice - 1].menuItem
             << right << itemTotal << " EUR" << endl;
    }

    double tax = subtotal * PVM;
    double total = subtotal + tax;

    cout << endl;
    cout << left << setw(35) << "Mokesciai (21%)" << right << tax << " EUR" << endl;
    cout << left << setw(35) << "Galutine suma" << right << total << " EUR" << endl;

    fout << endl;
    fout << left << setw(35) << "Mokesciai (21%)" << right << tax << " EUR" << endl;
    fout << left << setw(35) << "Galutine suma" << right << total << " EUR" << endl;

    fout.close();

    cout << endl << "Saskaita issaugota  (receipt.txt)" << endl;
}