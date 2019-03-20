/*
Author   : Shalvina Zahwa Aulia
NPM      : 140810180052
Deskripsi:
Tahun    : 2019
*/
#include <iostream>
#include <windows.h>
using namespace std;

struct Pegawai {
    char nama[40];
    char bidang[15];
    int gaji;
    Pegawai* next;
};

typedef Pegawai* pointer;
typedef pointer List;

void createList (List& First){
    First=NULL;
}
void createPegawai (pointer& newP){
    newP = new Pegawai;
    cout << "Nama\t : ";
    cin.ignore();
    cin.getline(newP->nama, 40);
    cout << "Bidang\t : ";
    cin.getline(newP->bidang,15);
    cout << "Gaji\t : "; cin >> newP->gaji;
    cout << endl;
    newP->next=NULL;
}
void inserFirst (List& First, pointer pFirst){
    if (First==NULL){
        First=pFirst;
    }
    else {
        pFirst->next=First;
        First=pFirst;
    }
}
void deleteFirst (List& First, pointer& dFirst){
    if (First==NULL){
        dFirst=NULL;
        cout << "\nDATA KOSONG\n";
    }
    else if (First->next==NULL){
        dFirst=First;
        First=NULL;
    }
    else {
        dFirst=First;
        First=First->next;
        dFirst->next=NULL;
    }
}
void insertLast (List& First, pointer pLast){
    pointer last;
    if (First==NULL){
        First=pLast;
    }
    else {
        last=First;
        while (last->next!=NULL){
            last=last->next;
        }
        last->next=pLast;
    }
}
void deleteLast (List& First, pointer& dLast){
    if (First=NULL){
        dLast=NULL;
        cout << "\nDATA KOSONG\n";

    }
    else if (First->next=NULL){
        dLast=First;
        First=NULL;
    }
    else {
        pointer last=First;
        pointer preclast=NULL;
        while (last->next!=NULL){
            preclast=last;
            last=last->next;
        }
        dLast=last;
        preclast->next=NULL;
    }
}
void traversal (List First){
    pointer pBantu;
    if (First==NULL){
        cout << "\nDATA KOSONG\n";
    }
    else {
        pBantu=First;

        while (pBantu!=NULL){
            cout << "Nama\t : " << pBantu->nama << endl;
            cout << "Bidang\t : "<< pBantu->bidang << endl;
            cout << "Gaji\t : " << pBantu->gaji << endl << endl;
            pBantu=pBantu->next;
        }
    }
}

int main(){
    int menu;
    pointer p;
    List L;

    createList(L);

    while (1){
    system("cls");
    cout << "1. Insert First\n";
    cout << "2. Delete First\n";
    cout << "3. Insert Last\n";
    cout << "4. Delete Last\n";
    cout << "5. Traversal\n";
    cout << "6. Keluar\n";
    cout << "Pilih menu (1/2/3/4/5/6) : "; cin >> menu;
    if (menu<1 || menu>6){
        cout << "\nAnda salah memasukkan angka!\n";
        exit(0);
    }

    switch (menu) {
        case 1:
            createPegawai(p);
            inserFirst(L,p);
            break;
        case 2 :
            deleteFirst(L,p);
            break;
        case 3 :
            createPegawai(p);
            insertLast(L,p);
            break;
        case 4 :
            deleteLast(L,p);
            break;
        case 5 :
            traversal(L);
            break;
        case 6 :
            cout << "\nAnda telah selesai\n";
            exit(0);
            break;
        }
        system("pause");
    }
}
