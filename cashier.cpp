#include<bits/stdc++.h>
using namespace std;

void title();
void shoplist();
void order();   //Atau ditaruh di
void additem(); //fungsi shoplist saja
int removeitem(); 
void menu();
void orderlist(int kode, int jumlah, float harga, float total);
void tambahPesanan();
void keluar();
void clear();
void totalMenu();

void sortlist();
void sortbycode();
void sortbyname();
void sortbyprice();

//Misal 
//dibuat variable globalkah ?
int banyaklist = 3; //Banyak daftar barang + 1 setiap fungsi additem dipanggil ?
// float price[9999]={1000,2000,3000,4000,5000}; // size price juga ?
// string nama[9999]={"alpha","beta","gamma","delta","epsilon"};
int total;

struct Items {
    string nama;
    int harga;
};

Items items[9999];

//----------------------------------------------------------------

int main() {
    clear();
    title();

    cout << "\tTekan Enter untuk Melanjutkan ";
    cin.get();

    clear();
    title();
    shoplist();
    menu();
}

//----------------------------------------------------------------

void title(){
    cout << "\t\t __________________   ____" << endl
         << "\t\t/_  __/  _/_  __/ /  / __/" << endl
         << "\t\t / / _/ /  / / / /__/ _/" << endl
         << "\t\t/_/ /___/ /_/ /____/___/" << endl << endl;
}

//-----------------------------------------------------------------

void clear() {
    system("cls");
    // system("clear");
}

//-----------------------------------------------------------------

void menu() { 
    int s;

    cout << "\n\tApa yang ingin Anda lakukan?" << endl << endl
         << "\t(1) Pemesanan barang" << endl
         << "\t(2) Tambah daftar barang" << endl
         << "\t(3) Hapus barang dari daftar" << endl
         << "\t(4) Urutkan daftar barang" << endl
         << "\t(0) Keluar" << endl << endl
         << "\tPilih opsi: ";

    cin >> s;

    clear();
    shoplist();

    switch(s) {
    case 1 :
        order();
        break;
    case 2 :
        additem();
        break;
    case 3 :
        removeitem();
        break;
    case 4 :
        sortlist();
        break;
    case 0 :
        clear();
        keluar();
        return;
    default :
        cout << "\n\tInput anda salah. Mohon coba lagi." << endl;
        menu();
    }
}

//-----------------------------------------------------------------

int add = 0;
string newItem;
int newHarga;

void itemlist() {
    items[0] = {"beta", 2000};
    items[1] = {"alpha", 1000};
    items[2] = {"gamma", 3000};
}

//-----------------------------------------------------------------

void shoplist() {
    cout << "\tSelamat Datang di Program Point-of-Sales (POS)" << endl << endl;
    cout << "\n\t------------- Daftar Barang -------------" << endl << endl;

    itemlist();
    cout << "\tKode\tNama Barang\t\tHarga(Rp)" << endl;
    for (int i = 0; i < banyaklist; i++) {
        cout << "\t(" << i + 1 << ")\t" << items[i].nama << "\t\t\t" << items[i].harga << endl;
    }

    cout << "\n\t-----------------------------------------" << endl;
}

//-----------------------------------------------------------------

void order(){
  	int i, n;

	cout << "\n\tMasukkan data barang yang akan dipesan:" << endl;
  	cout << "\n\tKode barang: ";
  	cin >> i;

    string namaBarang = items[i-1].nama;

  	cout << "\tJumlah: ";
  	cin >> n;
        
  	float harga = items[i-1].harga * n;
  	total = total + harga; //Var total harus global variable ?
    if(harga != 0) {
        cout << "\n\tNama barang\t= " << namaBarang << endl;
        cout << "\tHarga\t\t= Rp " << items[i-1].harga  << " * " << n << "\n\t\t\t= Rp " << harga << endl << endl;
        cout << "\tTotal harga\t= Rp " << total << endl;
        cout << "\n\t-----------------------------------------" << endl;
        tambahPesanan();
    }
    else if (harga == 0) {
        clear();
        shoplist();
        cout << "\n\tBarang tidak ditemukan. Mohon coba lagi." << endl;
        menu();
    }    
}

//-----------------------------------------------------------------

void tambahPesanan() {
    int s;

    cout << "\n\tApa yang ingin Anda lakukan?" << endl << endl;
    cout << "\t(1) Tambah pesanan"<< endl;
    cout << "\t(2) Selesai"<< endl << endl;
    cout << "\tPilihan Anda: ";
    cin >> s;

    clear();
    shoplist();

    switch(s) {
    case 1 :
        order();
        break;
    case 2 :
        cout << "\n\tTotal harga\t\t= Rp " << total << endl << endl;
        total = 0;
        totalMenu();
        //goto main ?
        break;
    default : 
        cout << "\n\tTotal harga\t\t= Rp " << total << endl;
        cout << "\n\t-----------------------------------------" << endl;
        cout << "\n\tInput Anda salah. Mohon coba lagi." << endl;

        tambahPesanan();
    }
}

void totalMenu() {
    cout << "\t-----------------------------------------" << endl;
    cout << "\n\tApa yang ingin Anda lakukan?" << endl;
    cout << "\n\t(1) Belanja lagi";
    cout << "\n\t(2) Kembali ke Menu Utama" << endl;
    cout << "\n\tPilih opsi: ";
    int c;
    cin >> c;

    clear();
    shoplist();

    switch(c) {
    case 1 :
        order();
        break;
    case 2 :
        menu();
        break;
    default :
        cout << "\n\tInput Anda salah. Mohon coba lagi." << endl << endl;
        totalMenu();
    }
}

//-----------------------------------------------------------------

// void orderlist(int kode, int jumlah, float harga, float total) {
//     cout << "\n\tPesanan Anda:" << endl;
//     cout << "\t" << kode << "\t" << jumlah << "\t" << harga << "\t" << total << endl; 
// }

//-----------------------------------------------------------------

void additem(){
	cout<<"\n\tMasukan data barang yang akan ditambahkan ke daftar barang:" << endl;
	cout<<"\n\tNama Barang: ";
    cin >> newItem;
	cout<<"\n\tHarga Barang: ";
    cin >> newHarga;

    items[banyaklist].nama = newItem;
    items[banyaklist].harga = newHarga;

    banyaklist++;
    
    clear();
    shoplist();
    cout << "\n\t" << newItem << " berhasil ditambahkan" << endl;
    menu();
}

//-----------------------------------------------------------------

int removeitem() {
    string removeItem;
    bool removed = false;
    cout<<"\n\tMasukan barang yang akan dihapus dari daftar barang:" << endl;
	cout<<"\n\tNama Barang: ";
    cin >> removeItem;

    clear();

    for (int i = 0; i < banyaklist; i++) {
        if(items[i].nama == removeItem) {
            removed = true;
            items[i].nama = {};
            items[i].harga = {};
            banyaklist--;
            for(int j = i; j < banyaklist; j++) {
                items[j].nama = items[j+1].nama;
                items[j].harga = items[j+1].harga;
            }
        }
    }

    shoplist();
    
    if(removed) cout << "\n\t" << removeItem << " berhasil dihapus dari daftar barang" << endl;
    else cout << "\n\t" << removeItem << " tidak ditemukan dalam daftar barang" << endl;
    cout << "\n\t-----------------------------------------" << endl;
    menu();
}

//-----------------------------------------------------------------

void sortlist() {
    int sort;

    cout << "\n\tUrutkan daftar barang berdasarkan:" << endl << endl
         << "\t(1) Kode barang" << endl
         << "\t(2) Nama barang" << endl
         << "\t(3) Harga barang" << endl
         << "\t(0) Kembali ke menu utama" << endl << endl
         << "\tPilih opsi: ";

    cin >> sort;

    clear();
    shoplist();

    switch(sort) {
    case 1 :
        sortbycode();
        break;
    case 2 :
        sortbyname();
        break;
    case 3 :
        sortbyprice();
        break;
    case 0 :
        title();
        menu();
        return;
    default :
        cout << "\n\tInput anda salah. Mohon coba lagi." << endl;
        sortlist();
    }
}

//-----------------------------------------------------------------

void sortbycode() {
    
}
void sortbyname() {

}
void sortbyprice() {

}

//-----------------------------------------------------------------

void keluar() {
    title();
    cout << "\t------------------------------------------" << endl;
    cout << "\n\tTerima Kasih Telah Menggunakan Program Ini" << endl;
    cout << "\n\t------------------------------------------" << endl << endl;
}