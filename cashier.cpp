#include<iostream>
#include<algorithm>
using namespace std;

void title();
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

//---- Membersihkan Display Terminal ------------------------------

void clear() {
    system("cls");
    // system("clear");
}

//---- Menu Utama -------------------------------------------------

void menu() { 
    int s;

    cout << "\n\tApa yang ingin Anda lakukan?" << endl << endl
         << "\t(1) Pemesanan barang" << endl
         << "\t(2) Tambah daftar barang" << endl
         << "\t(3) Hapus barang dari daftar" << endl
         << "\t(4) Urutkan daftar barang" << endl
         << "\t(5) Cari data barang" << endl << endl
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
    cout << "\tSelamat Datang di Program Point-of-Sales (POS)" << endl << endl;
    cout << "\n\t------------- Daftar Barang -------------" << endl << endl;

    cout << "\tKode\tNama Barang\t\tHarga(Rp)" << endl;
    for (int i = 0; i < banyaklist; i++) {
        cout << "\t" << items[i].kode << "\t" << items[i].nama << "\t\t\t" << items[i].harga << endl;
    }

    cout << "\n\t-----------------------------------------" << endl;
}

//---- Menu Pemesanan Barang --------------------------------------

void order(){
  	int kodeBarang, hargaBarang, n;
    bool found = false;
    float harga;
    string namaBarang;

	cout << "\n\tMasukkan data barang yang akan dipesan:" << endl;
  	cout << "\n\tKode barang: ";
  	cin >> kodeBarang;

  	cout << "\tJumlah: ";
  	cin >> n;
    
    for(int i = 0; i < banyaklist; i++) {
        if(kodeBarang == items[i].kode) {
            found = true;
            harga = items[i].harga * n;
          	total = total + harga; //Var total harus global variable ?  
            hargaBarang = items[i].harga;
            namaBarang = items[i].nama;
        }
    }

  	// float harga = items[kode-1].harga * n;
  	// total = total + harga; //Var total harus global variable ?
    if(found) {
        orderlist(kodeBarang, namaBarang, hargaBarang, n);
        // cout << "\n\tNama barang\t= " << namaBarang << endl;
        // cout << "\tHarga\t\t= Rp " << hargaBarang  << " * " << n << "\n\t\t\t= Rp " << harga << endl << endl;
        // cout << "\tTotal belanja\t= Rp " << total << endl;
        // cout << "\n\t-----------------------------------------" << endl;
        tambahPesanan();
    }
    else if (!found) {
        clear();
        shoplist();
        cout << "\n\tBarang tidak ditemukan. Mohon coba lagi." << endl;
        cout << "\n\t-----------------------------------------" << endl;
        order();
    }    
}

//---- Mengurangi Barang yang Telah Dipesan ----------------------- (belum fungsional)

void hapusPesanan() {
    string removeOrder;
    bool removed = false;
    cout<<"\n\tMasukan data barang yang akan dihapus dari daftar pesanan:" << endl;
	cout<<"\n\tNama Barang: ";
    cin >> removeOrder;

    clear();

    shoplist();
    
    if(removed) cout << "\n\t" << removeOrder << " berhasil dihapus dari daftar pesanan" << endl;
    else cout << "\n\t" << removeOrder << " tidak ditemukan dalam daftar pesanan" << endl;
    cout << "\n\t-----------------------------------------" << endl;
    tambahPesanan();
}

//---- Menu Pilihan Pesanan ---------------------------------------

void tambahPesanan() {
    int s;

    cout << "\n\tApa yang ingin Anda lakukan?" << endl << endl;
    cout << "\t(1) Tambah pesanan"<< endl;
    cout << "\t(2) Kurangi pesanan"<< endl;
    cout << "\t(3) Selesai"<< endl << endl;
    cout << "\tPilihan Anda: ";
    cin >> s;

    clear();
    shoplist();


    switch(s) {
    case 1 :
        order();
        break;
    case 2 :
        hapusPesanan();
        break;
    case 3 :
        cout << "\n\tTotal belanja\t\t= Rp " << total << endl << endl;
        total = 0;
        totalMenu();
        //goto main ?
        break;
    default : 
        cout << "\n\tTotal belanja\t\t= Rp " << total << endl;
        cout << "\n\t-----------------------------------------" << endl;
        cout << "\n\tInput Anda salah. Mohon coba lagi." << endl;

        tambahPesanan();
    }
}

//---- Menu Akhir Pemesanan ---------------------------------------

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

//---- Daftar Barang Yang Telah Dipesan --------------------------- (belum fungsional)

int orderKe;

void orderlist(int kode, string nama, float harga, int n) {
    struct Pesan {
        int kodePesan;
        string namaPesan;
        float hargaPesan;
        int nPesan; 
        float totalPesan;
        float belanjaPesan;
    };
    Pesan pesan[9999];

    total = harga * n;
    
    cout << "Ke: " << orderKe << endl;
    pesan[orderKe].kodePesan = kode;
    pesan[orderKe].namaPesan = nama;
    pesan[orderKe].hargaPesan = harga;
    pesan[orderKe].nPesan = n;
    pesan[orderKe].totalPesan = total;
    orderKe++;

    cout << "\n\t------------- Pesanan Anda: -------------" << endl;
    cout << "\n\tKode\tNama\tHarga(Rp)\tJumlah\tTotal(Rp)" << endl;

    for(int i = 0; i < orderKe; i++) {
        cout << "\t" << pesan[i].kodePesan << "\t" << pesan[i].namaPesan << "\t" << pesan[i].hargaPesan << "\t\t" << pesan[i].nPesan << "\t" << pesan[i].totalPesan << endl;
    }
    
    cout << "\n\t-----------------------------------------" << endl;
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
        cout << "\n\t-----------------------------------------" << endl;

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
    cout << "\n\t-----------------------------------------" << endl;
    menu();
}

//---- Menu Pengurutan Barang di Tabel ----------------------------

void sortlist() {
    int sort;

    cout << "\n\tUrutkan daftar barang berdasarkan:" << endl << endl
         << "\t(1) Kode barang" << endl
         << "\t(2) Nama barang" << endl
         << "\t(3) Harga barang" << endl << endl
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
    cout << "\n\t-----------------------------------------" << endl;
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
    cout << "\n\t-----------------------------------------" << endl;
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
    cout << "\n\t-----------------------------------------" << endl;
    menu();
}


//---- Menu Pencarian Barang -------------------------------------

void searchlist() {
    int search;

    cout << "\n\tCari data barang berdasarkan:" << endl << endl
         << "\t(1) Kode barang" << endl
         << "\t(2) Nama barang" << endl
         << "\t(3) Harga barang" << endl << endl
         << "\t(0) Kembali ke menu utama" << endl << endl
         << "\tPilih opsi: ";

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
        title();
        menu();
        return;
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
        cout << "\n\tData barang dengan kode (" << carikode << ") ditemukan" << endl;
        cout << "\n\tKode\tNama Barang\t\tHarga(Rp)" << endl;
        for(int i = 0; i < banyaklist; i++) {
            if(carikode == items[i].kode) {
                cout << "\t" << items[i].kode << "\t" << items[i].nama << "\t\t\t" << items[i].harga << endl;
            }
        }
    }
    else cout << "\n\tData barang dengan kode (" << carikode << ") tidak ditemukan" << endl;
    
    cout << "\n\t-----------------------------------------" << endl;
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
        cout << "\n\tData barang dengan nama \"" << carinama << "\" ditemukan" << endl;
        cout << "\n\tKode\tNama Barang\t\tHarga(Rp)" << endl;
        for(int i = 0; i < banyaklist; i++) {
            if(carinama == items[i].nama) {
                cout << "\t" << items[i].kode << "\t" << items[i].nama << "\t\t\t" << items[i].harga << endl;
            }
        }
    }
    else cout << "\n\tData barang dengan nama \"" << carinama << "\" tidak ditemukan" << endl;
    
    cout << "\n\t-----------------------------------------" << endl;
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
        cout << "\n\tData barang dengan harga Rp " << cariharga << " ditemukan" << endl;
        cout << "\n\tKode\tNama Barang\t\tHarga(Rp)" << endl;
        for(int i = 0; i < banyaklist; i++) {
            if(cariharga == items[i].harga) {
                cout << "\t" << items[i].kode << "\t" << items[i].nama << "\t\t\t" << items[i].harga << endl;
            }
        }
    }
    else cout << "\n\tData barang dengan harga Rp " << cariharga << " tidak ditemukan" << endl;
    
    cout << "\n\t-----------------------------------------" << endl;
    searchlist();
}



//---- Print Akhir dari Program -----------------------------------

void keluar() {
    title();
    cout << "\t------------------------------------------" << endl;
    cout << "\n\tTerima Kasih Telah Menggunakan Program Ini" << endl;
    cout << "\n\t------------------------------------------" << endl << endl;
}
