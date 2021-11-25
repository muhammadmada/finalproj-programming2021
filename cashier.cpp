#include<iostream>
#include<algorithm>
using namespace std;

void title();
void welcome();
void clear();
void keluar();

void shoplist();
void itemlist();
void menu();
void order();   //Atau ditaruh di
void tambahPesanan();
void hapusPesanan();
void totalMenu();
void additem(); //fungsi shoplist saja
void removeitem(); 
void orderlist(int kode, string nama, float harga, int n);
void resetlist();
void printorder();

void sortlist();
void sortbycode();
void sortbyname();
void sortbyprice();

void searchlist();
void searchbycode();
void searchbyname();
void searchbyprice();

//Misal 
//dibuat variable globalkah ?
int banyaklist = 3; //Banyak daftar barang + 1 setiap fungsi additem dipanggil ?
// float price[9999]={1000,2000,3000,4000,5000}; // size price juga ?
// string nama[9999]={"alpha","beta","gamma","delta","epsilon"};
int total;

struct Items {
    int kode;
    string nama;
    float harga;
};

Items items[9999];

//---- Fungsi Main ------------------------------------------------

int main() {
    clear();
    title();

    cout << "\tTekan Enter untuk Melanjutkan ";
    cin.get();
    
    itemlist();
    clear();
    title();
    welcome();
    shoplist();
    menu();

    return 0;
}

//---- Print Banner/Judul Program ---------------------------------

void title(){
    cout << "\t\t __________________   ____" << endl
         << "\t\t/_  __/  _/_  __/ /  / __/" << endl
         << "\t\t / / _/ /  / / / /__/ _/" << endl
         << "\t\t/_/ /___/ /_/ /____/___/" << endl << endl;
}

//---- Print Selamat Datang ---------------------------------------

void welcome(){
    cout << "\tSelamat Datang di Program Point-of-Sales (POS)" << endl;
}

//---- Membersihkan Display Terminal ------------------------------

void clear() {
    system("cls");
    // system("clear");
}

//---- Menu Utama -------------------------------------------------

void menu() { 
    int s;

    cout << "\n\tApa yang ingin Anda lakukan?" << endl << endl
         << "\t(1) Pemesanan Barang" << endl
         << "\t(2) Tambah Daftar Barang" << endl
         << "\t(3) Hapus Barang dari Daftar" << endl
         << "\t(4) Urutkan Daftar Barang" << endl
         << "\t(5) Cari Data Barang" << endl << endl
         << "\t(0) Keluar" << endl << endl
         << "\tPilih Opsi: ";

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
    case 5 :
        searchlist();
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

//---- Deklarasi Daftar Barang ------------------------------------

void itemlist() {
    items[0] = {103, "beta", 3000};
    items[1] = {102, "alpha", 1000};
    items[2] = {101, "gamma", 2000};
}

//---- Print Tabel Daftar Barang ----------------------------------

void shoplist() {
    cout << "\n\t----------------- Daftar Barang -----------------" << endl << endl;

    cout << "\tKode\tNama Barang\t\tHarga(Rp)" << endl;
    for (int i = 0; i < banyaklist; i++) {
        cout << "\t" << items[i].kode << "\t" << items[i].nama << "\t\t\t" << items[i].harga << endl;
    }

    cout << "\n\t-------------------------------------------------" << endl;
}

//---- Menu Pemesanan Barang --------------------------------------

void order(){
  	int kodeBarang, hargaBarang, n;
    bool found = false;
    float harga;
    string namaBarang;

	cout << "\n\tMasukkan data barang yang akan dipesan:" << endl;
  	cout << "\n\tKode Barang: ";
  	cin >> kodeBarang;

  	cout << "\tJumlah     : ";
  	cin >> n;
    
    for(int i = 0; i < banyaklist; i++) {
        if(kodeBarang == items[i].kode) {
            found = true;
            harga = items[i].harga * n;
            hargaBarang = items[i].harga;
            namaBarang = items[i].nama;
        }
    }

    if(found) {
        orderlist(kodeBarang, namaBarang, hargaBarang, n);
        tambahPesanan();
    }
    else if (!found) {
        clear();
        shoplist();
        cout << "\n\tBarang tidak ditemukan. Mohon coba lagi." << endl;
        cout << "\n\t-------------------------------------------------" << endl;
        order();
    }    
}

struct Pesan {
    int kodePesan;
    string namaPesan;
    float hargaPesan;
    int nPesan; 
    float totalPesan;
    float belanjaPesan;
};
Pesan pesan[9999];
int orderKe;

//---- Daftar Barang Yang Telah Dipesan ---------------------------

void orderlist(int kode, string nama, float harga, int n) {
    bool stack = false;
    int totalPesan = harga * n;
    for(int i = 0; i < orderKe; i++) {
        if(kode == pesan[i].kodePesan) {
            stack = true;
            pesan[i].nPesan += n;
            pesan[i].totalPesan += n * harga;  
        }
    }

    if(!stack) {
        pesan[orderKe].kodePesan = kode;
        pesan[orderKe].namaPesan = nama;
        pesan[orderKe].hargaPesan = harga;
        pesan[orderKe].nPesan = n;
        pesan[orderKe].totalPesan = totalPesan;
        orderKe++;
    }

    total += totalPesan;

    clear();
    printorder();
}

//---- Print Daftar Pesanan ---------------------------------------

void printorder() {
    cout << "\n\t----------------- Pesanan Anda: -----------------" << endl;
    cout << "\n\tKode\tNama\tHarga(Rp)\tJumlah\tTotal(Rp)" << endl;

    for(int i = 0; i < orderKe; i++) {
        cout << "\t" << pesan[i].kodePesan << "\t" << pesan[i].namaPesan << "\t" << pesan[i].hargaPesan << "\t\t" << pesan[i].nPesan << "\t" << pesan[i].totalPesan << endl;
    }
    cout << "\n\t-------------------------------------------------" << endl;
}

//---- Mengurangi Barang yang Telah Dipesan ----------------------- (belum fungsional)

void hapusPesanan() {
    int removeJumlah, removeCode;
    int justN;
    bool removed = false, exceeded = false;
    cout <<"\n\tMasukan data barang yang akan dihapus dari daftar pesanan:" << endl;
	cout <<"\n\tKode Barang: ";
    cin >> removeCode;
	cout <<"\n\tJumlah     : ";
    cin >> removeJumlah;

    for (int i = 0; i < banyaklist; i++) {
        if(pesan[i].kodePesan == removeCode) {
            if(removeJumlah == pesan[i].nPesan) {
                removed = true;
                pesan[i].kodePesan = {};
                pesan[i].namaPesan = {};
                pesan[i].hargaPesan = {};
                orderKe--;
                total -= pesan[i].totalPesan;
                for(int j = i; j < banyaklist; j++) {
                    pesan[j].namaPesan = pesan[j+1].namaPesan;
                    pesan[j].hargaPesan = pesan[j+1].hargaPesan;
                    pesan[j].kodePesan = pesan[j+1].kodePesan;
                }
            }
            else if(removeJumlah < pesan[i].nPesan) {
                removed = true;
                pesan[i].nPesan -= removeJumlah;
                pesan[i].totalPesan -= removeJumlah * pesan[i].hargaPesan;
                total -= pesan[i].hargaPesan * removeJumlah;
            }
            else if(removeJumlah > pesan[i].nPesan) {
                exceeded = true;
                justN = pesan[i].nPesan;
            }
        }
    }

    
    clear();
    printorder();
    
    if(removed && !exceeded)
        cout << "\n\tBarang dengan kode (" << removeCode << ") berhasil dihapus dari pesanan anda" << endl;
    else if(!removed && !exceeded)
        cout << "\n\tBarang dengan kode (" << removeCode << ") tidak ditemukan dalam pesanan anda" << endl;
    else if(!removed && exceeded)
        cout << "\n\tAnda hanya memesan " << justN << " buah barang tersebut" << endl;
    cout << "\n\t-------------------------------------------------" << endl;

    
    tambahPesanan();
}

//---- Menu Pilihan Pesanan ---------------------------------------

void tambahPesanan() {
    int s;

    cout << "\n\tTotal Belanja Anda = Rp " << total << endl;
    cout << "\n\t-------------------------------------------------" << endl;

    cout << "\n\tApa yang ingin Anda lakukan?" << endl << endl;
    cout << "\t(1) Tambah Pesanan"<< endl;
    cout << "\t(2) Kurangi Pesanan"<< endl << endl;
    cout << "\t(0) Selesai"<< endl << endl;
    cout << "\tPilihan Anda: ";
    cin >> s;

    clear();

    switch(s) {
    case 1 :
        shoplist();
        printorder();
        order();
        break;
    case 2 :
        printorder();
        hapusPesanan();
        break;
    case 0 :
        printorder();
        cout << "\n\tTotal Belanja Anda = Rp " << total << endl << endl;
        total = 0;
        resetlist();
        totalMenu();
        //goto main ?
        break;
    default : 
        cout << "\n\tInput Anda salah. Mohon coba lagi." << endl;
        printorder();
        tambahPesanan();
    }
}

//---- Menghapus Data Pesanan Setelah Selesai ---------------------

void resetlist() {
    for(int i = 0; i < orderKe; i++) {
        pesan[i] = {};
    }
    orderKe = 0;
}

//---- Menu Akhir Pemesanan ---------------------------------------

void totalMenu() {
    cout << "\t-------------------------------------------------" << endl;
    cout << "\n\tApa yang ingin Anda lakukan?" << endl;
    cout << "\n\t(1) Belanja Lagi" << endl;
    cout << "\n\t(0) Kembali ke Menu Utama" << endl;
    cout << "\n\tPilih Opsi: ";
    int c;
    cin >> c;

    clear();
    shoplist();

    switch(c) {
    case 1 :
        order();
        break;
    case 0 :
        menu();
        break;
    default :
        cout << "\n\tInput Anda salah. Mohon coba lagi." << endl << endl;
        totalMenu();
    }
}

//---- Menambahkan Barang Ke Daftar Stok Barang -------------------

int newKode;
string newItem;
float newHarga;

void additem(){
	cout<<"\n\tMasukan data barang yang akan ditambahkan ke daftar barang:" << endl;
	cout<<"\n\tKode barang: ";
    cin >> newKode;
	cout<<"\n\tNama Barang: ";
    cin >> newItem;

    bool exist = false;
    for(int i = 0; i < banyaklist; i++) {
        if(newKode == items[i].kode || newItem == items[i].nama) {
            exist = true;
        }
    }
	
    if(exist) {
        clear();
        shoplist();

        cout << "\n\tBarang dengan nama \"" << newItem << "\" atau kode (" << newKode << ") sudah terdaftar." << endl; 
        cout << "\tMohon masukkan data barang lain." << endl;
        cout << "\n\t-------------------------------------------------" << endl;

        menu();
    }
    else {
        cout<<"\n\tHarga Barang: ";
        cin >> newHarga;

        items[banyaklist].kode = newKode;
        items[banyaklist].nama = newItem;
        items[banyaklist].harga = newHarga;

        banyaklist++;
        
        clear();
        shoplist();
        cout << "\n\t" << newItem << " berhasil ditambahkan" << endl;
        menu();
    }
}

//---- Menghapus Barang Dari Daftar Stok Barang -------------------

void removeitem() {
    string removeItem;
    bool removed = false;
    cout<<"\n\tMasukan data barang yang akan dihapus dari daftar barang:" << endl;
	cout<<"\n\tNama Barang: ";
    cin >> removeItem;

    clear();

    for (int i = 0; i < banyaklist; i++) {
        if(items[i].nama == removeItem) {
            removed = true;
            items[i].kode = {};
            items[i].nama = {};
            items[i].harga = {};
            banyaklist--;
            for(int j = i; j < banyaklist; j++) {
                items[j].nama = items[j+1].nama;
                items[j].harga = items[j+1].harga;
                items[j].kode = items[j+1].kode;
            }
        }
    }

    shoplist();
    
    if(removed) cout << "\n\t" << removeItem << " berhasil dihapus dari daftar barang" << endl;
    else cout << "\n\t" << removeItem << " tidak ditemukan dalam daftar barang" << endl;
    cout << "\n\t-------------------------------------------------" << endl;
    menu();
}

//---- Menu Pengurutan Barang di Tabel ----------------------------

void sortlist() {
    int sort;

    cout << "\n\tUrutkan daftar barang berdasarkan:" << endl << endl
         << "\t(1) Kode Barang" << endl
         << "\t(2) Nama Barang" << endl
         << "\t(3) Harga Barang" << endl << endl
         << "\t(0) Kembali ke Menu Utama" << endl << endl
         << "\tPilih Opsi: ";

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
        break;
    default :
        cout << "\n\tInput anda salah. Mohon coba lagi." << endl;
        sortlist();
    }
}

//---- Algoritma Pengurutan Barang Berdasarkan Parameter Pilihan --

// ---- Sorting Berdasarkan Kode ----

bool comparecode(Items a, Items b) {
    return a.kode < b.kode;
}

void sortbycode() {
    sort(items, items+banyaklist, comparecode);
    clear();
    shoplist();

    cout << "\n\tDaftar berhasil diurutkan berdasarkan kode barang" << endl;
    cout << "\n\t-------------------------------------------------" << endl;
    menu();
}

// ---- Sorting Berdasarkan Nama ----

bool comparename(Items a, Items b) {
    return a.nama < b.nama;
}

void sortbyname() {
    sort(items, items+banyaklist, comparename);    
    clear();
    shoplist();

    cout << "\n\tDaftar berhasil diurutkan berdasarkan nama barang" << endl;
    cout << "\n\t-------------------------------------------------" << endl;
    menu();
}

// ---- Sorting Berdasarkan Harga ----

bool compareprice(Items a, Items b) {
    return a.harga < b.harga;
}

void sortbyprice() {
    sort(items, items+banyaklist, compareprice);    
    clear();
    shoplist();

    cout << "\n\tDaftar berhasil diurutkan berdasarkan harga barang" << endl;
    cout << "\n\t-------------------------------------------------" << endl;
    menu();
}


//---- Menu Pencarian Barang -------------------------------------

void searchlist() {
    int search;

    cout << "\n\tCari data barang berdasarkan:" << endl << endl
         << "\t(1) Kode Barang" << endl
         << "\t(2) Nama Barang" << endl
         << "\t(3) Harga Barang" << endl << endl
         << "\t(0) Kembali ke Menu Pencarian" << endl << endl
         << "\tPilih Opsi: ";

    cin >> search;

    clear();
    shoplist();

    switch(search) {
    case 1 :
        searchbycode();
        break;
    case 2 :
        searchbyname();
        break;
    case 3 :
        searchbyprice();
        break;
    case 0 :
        searchlist();
        break;
    default :
        cout << "\n\tInput anda salah. Mohon coba lagi." << endl;
        searchlist();
    }
}

//---- Algoritma Pencarian Barang Berdasarkan Parameter Pilihan --

// ---- Pencarian Berdasarkan Kode
void searchbycode() {
    int carikode;
    bool found = false;
    
    clear();
    shoplist();
    
    cout << "\n\tMasukkan kode barang yang ingin dicari: ";
    cin >> carikode;

    for(int i = 0; i < banyaklist; i++) {
        if(carikode == items[i].kode) {
            found = true;
        }
    }

    if(found) {
        clear();
        cout << "\n\tData barang dengan kode (" << carikode << ") ditemukan" << endl;
        cout << "\n\tKode\tNama Barang\t\tHarga(Rp)" << endl;
        for(int i = 0; i < banyaklist; i++) {
            if(carikode == items[i].kode) {
                cout << "\t" << items[i].kode << "\t" << items[i].nama << "\t\t\t" << items[i].harga << endl;
            }
        }
    }
    else cout << "\n\tData barang dengan kode (" << carikode << ") tidak ditemukan" << endl;
    
    cout << "\n\t-------------------------------------------------" << endl;
    searchlist();
}


// ---- Pencarian Berdasarkan Nama
void searchbyname() {
    string carinama;
    bool found = false;
    
    clear();
    shoplist();
    
    cout << "\n\tMasukkan nama barang yang ingin dicari: ";
    cin >> carinama;

    for(int i = 0; i < banyaklist; i++) {
        if(carinama == items[i].nama) {
            found = true;
        }
    }

    if(found) {
        clear();
        cout << "\n\tData barang dengan nama \"" << carinama << "\" ditemukan" << endl;
        cout << "\n\tKode\tNama Barang\t\tHarga(Rp)" << endl;
        for(int i = 0; i < banyaklist; i++) {
            if(carinama == items[i].nama) {
                cout << "\t" << items[i].kode << "\t" << items[i].nama << "\t\t\t" << items[i].harga << endl;
            }
        }
    }
    else cout << "\n\tData barang dengan nama \"" << carinama << "\" tidak ditemukan" << endl;
    
    cout << "\n\t-------------------------------------------------" << endl;
    searchlist();
}


// ---- Pencarian Berdasarkan Harga
void searchbyprice() {
    int cariharga;
    bool found = false;
    
    clear();
    shoplist();
    
    cout << "\n\tMasukkan harga barang yang ingin dicari: ";
    cin >> cariharga;

    for(int i = 0; i < banyaklist; i++) {
        if(cariharga == items[i].harga) {
            found = true;
        }
    }

    if(found) {
        clear();
        cout << "\n\tData barang dengan harga Rp " << cariharga << " ditemukan" << endl;
        cout << "\n\tKode\tNama Barang\t\tHarga(Rp)" << endl;
        for(int i = 0; i < banyaklist; i++) {
            if(cariharga == items[i].harga) {
                cout << "\t" << items[i].kode << "\t" << items[i].nama << "\t\t\t" << items[i].harga << endl;
            }
        }
    }
    else cout << "\n\tData barang dengan harga Rp " << cariharga << " tidak ditemukan" << endl;
    
    cout << "\n\t-------------------------------------------------" << endl;
    searchlist();
}



//---- Print Akhir dari Program -----------------------------------

void keluar() {
    title();
    cout << "\t--------------------------------------------------" << endl;
    cout << "\n\tTerima Kasih Telah Menggunakan Program Ini" << endl;
    cout << "\n\t--------------------------------------------------" << endl << endl;
}
