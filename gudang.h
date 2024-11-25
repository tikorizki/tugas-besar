#ifndef GUDANG_H_INCLUDED
#define GUDANG_H_INCLUDED
#include <iostream>

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

using namespace std;

struct gudang {
    string nama_cabang;
    string alamat;
    int stok_barang;
    int waktuOP;

};

struct penerima{
    string nama_penerima;
    string alamat;
    int noTelp;
    int berat;
};

typedef gudang infotype_gdg;
typedef penerima infotype_terima;
typedef struct ElmGudang *adr_gudang;
typedef struct ElmPenerima *adr_penerima;
typedef struct ElmRelasi *adr_relasi;

struct elmRelasi{
    adr_penerima penerima;
    adr_relasi next;

};

struct ElmGudang{
    infotype_gdg infoG;
    adr_gudang next;
    adr_gudang prev;
    adr_relasi relasi;
};

struct ListGudang {
    adr_gudang first;
    adr_gudang last;
};

struct ElmPenerima{
    infotype_terima infoP;
    adr_penerima next;

};

struct ListPenerima{
    adr_penerima first;
};

void createListGudang(ListGudang &L);
adr_gudang allocateGudang(infotype_gdg x);
void createListPenerima(ListPenerima &L);
adr_penerima allocatePenerima(infotype_terima y);
void insertGudang(ListGudang &L, adr_gudang P);
void insertPenerima(ListPenerima &L, adr_penerima P);
void insertRelasi(ListGudang &L_Gudang, ListPenerima &L_Penerima, string nama_cabang, string nama_penerima);
void deleteGudang(ListGudang &L, ListPenerima &L_Penerima, string nama_cabang);
void deletePenerima(ListPenerima &L, ListGudang &L_Gudang, string nama_penerima);
void deleteRelasi(adr_gudang gudang, string nama_penerima);
adr_gudang findGudang(ListGudang L, string nama_cabang);
adr_penerima findPenerima(ListPenerima L, string nama_penerima);

#endif // GUDANG_H_INCLUDED
