#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

struct MenuItemType{
    string menuItem;
    float menuPrice;
}menuList[8];

vector<int> numbers;


void getData() {
    menuList[0] = { "Kiausiniene", 1.45 };
    menuList[1] = { "Kiaulienos sonine su keptu kiausiniu", 2.45 };
    menuList[2] = { "Keksiukas su vysnia", 0.99 };
    menuList[3] = { "Prancuziskas skrebutis", 1.99 };
    menuList[4] = { "Vaisiu salotos", 2.49 };
    menuList[5] = { "Pusryciu dribsniai", 0.69 };
    menuList[6] = { "Kava", 0.50 };
    menuList[7] = { "Arbata", 0.75 };
}

void showMenu() {
    cout << "Restorano pusryciu meniu:\n";
    for (int i = 0; i < 8; ++i) {
        cout << i + 1 << ". " << setw(40) << left << menuList[i].menuItem << setw(10) << right << fixed << setprecision(2) << menuList[i].menuPrice << "€\n";
    }
    cout << "Uzsakyma pateiktite nurodydami uzsakymo numeri (norint baigti iveskite 0):\n";
}

void printCheck() {
    ofstream saskaita;
    saskaita.open("saskaitos_cekis.txt");
    float mokesciai = 0;
    float galutine_suma = 0;
    if (saskaita.is_open()) {
        saskaita << "Sveiki atvyke i restorana 'Grazma'!" << endl;
        for (int i = 0; i < numbers.size(); ++i) {
            saskaita << setw(40) << left << menuList[numbers[i]-1].menuItem << setw(10) << right << fixed << setprecision(2) << menuList[numbers[i]-1].menuPrice << "€\n";

        }
    }
    

    cout << "Jusu saskaita sekmingai atspausdinta!\n";
}


int main() {

    getData();
    showMenu();

    int number = 1;
    while (number != 0) {
        cout << "Iveskite pasirinkima: ";
        cin >> number;
        if (number > 0) {
            numbers.push_back(number);
        }
        if (number > 8) {
            cout << "Netinkamas pasirinkimas, bandykite dar karta.\n";
        }
        
    }
    
    cout << "pasirinkimai: ";
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }


    printCheck();

    return 0;
}
