#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(string arr[], int low, int high) {
    string pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortDesc(string arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortDesc(arr, low, pi - 1);
        quickSortDesc(arr, pi + 1, high);
    }
}

void printArray(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
}

void tampilkanMenu(string nama[], int x) {
    bool kembali = false;
    char lanjut;
    do
    {
        string sebelumSort[x];
        for (int i = 0; i < x; i++) sebelumSort[i] = nama[i];
    
        int opsi;
        cout << "\nPilih Menu :" << endl;
        cout << "1. Bubble Sort (Ascending)" << endl;
        cout << "2. Quick Sort (Descending)" << endl;
        cout << "Pilihan : "; cin >> opsi;
    
        switch (opsi)
        {
        case 1:
            cout << "\nSebelum Sort : ";
            printArray(sebelumSort, x);
            bubbleSort(nama, x);
            cout << "Sesudah Sort  : ";
            printArray(nama, x);
            cout << "Apakah ingin lanjut? (y/n): "; cin >> lanjut;
            if (lanjut == 'y' || lanjut == 'Y')
            {
                kembali = true;
            } else {
                kembali = false;
            }
            break;
        case 2:
            cout << "\nSebelum Sort : ";
            printArray(sebelumSort, x);
            quickSortDesc(nama, 0, x - 1);
            cout << "Sesudah Sort  : ";
            printArray(nama, x);
            cout << "Apakah ingin lanjut? (y/n): "; cin >> lanjut;
            if (lanjut == 'y' || lanjut == 'Y')
            {
                kembali = true;
            } else {
                kembali = false;
            }
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    } while (kembali == true);
    
}

int main() {
    int size = 5;
    int x = 0;
    string nama[size];
    bool kembali = false;
    do
    {
        string temp;
        cout << "input nama : "; cin >> temp;
        nama[x] = temp;
        x++;

        if (x >= size) {
            cout << "UDAH GAK SIH" << endl;
            kembali = false;
            tampilkanMenu(nama, x);
        } else {
            char pilihan;
            cout << "apakah akan input nama lagi? (y/n) : "; cin >> pilihan;

            if (pilihan == 'y' || pilihan == 'Y') {
                kembali = true;
            } else if (x < 2) {
                cout << "TAMBAHIN LAGI DONG" << endl;
                kembali = true;
            } else {
                kembali = false;
                tampilkanMenu(nama, x);
            }
        }

    } while (kembali == true);

}