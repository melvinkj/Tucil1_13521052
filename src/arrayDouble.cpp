#include "arrayDouble.hpp"
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabDouble, cara deklarasi dan akses: */
/* Deklarasi : T : TabDouble */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabDouble *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    (*T).TI[IdxMax - IdxMin + 1];
    (*T).Neff = 0;
}
/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabDouble T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return (T.Neff);
}
/* *** Daya tampung container *** */
int MaxNbEl (TabDouble T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return (IdxMax - IdxMin + 1);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabDouble T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return 1;
}

IdxType GetLastIdx (TabDouble T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
{
    return (T.Neff);
}
ElType GetElmt (TabDouble T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return (T.TI[i]);
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabDouble Tin, TabDouble *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
    *Tout = Tin;
}
void SetEl (TabDouble *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
    (*T).TI[i] = v;
}
void SetNeff (TabDouble *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    (*T).Neff = N;
}

void append(TabDouble *T, ElType v)
{
    int N;
    N = (*T).Neff;
    SetEl(T, N, v);
    SetNeff(T, N+1);
}

/* ********** Test Indeks yang valid ********** */
bool IsIdxValid (TabDouble T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= IdxMin) && (i <= IdxMax));
}
bool IsIdxEff (TabDouble T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
bool IsEmpty (TabDouble T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (T.Neff == 0);
}
/* *** Test tabel penuh *** */
bool IsFull (TabDouble T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (T.Neff == (IdxMax - IdxMin + 1));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabDouble T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
    if (T.Neff == 0)
    {
        printf("Tabel kosong");
    } else
    {
        int i;
        for (i = 1; i <= T.Neff ; i++)
        {
            printf("%d:%d\n", i-1, T.TI[i]);
        }
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabDouble PlusTab (TabDouble T1, TabDouble T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
{
    TabDouble Thasil;
    Thasil.Neff = T1.Neff;
    int i;
    for (i = 1; i <= Thasil.Neff; i++)
    {
        Thasil.TI[i] = T1.TI[i] + T2.TI[i];
    }
    return Thasil;
}
TabDouble MinusTab (TabDouble T1, TabDouble T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
{
    TabDouble Thasil;
    Thasil.Neff = T1.Neff;
    int i;
    for (i = 1; i <= Thasil.Neff; i++)
    {
        Thasil.TI[i] = T1.TI[i] - T2.TI[i];
    }
    return Thasil;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabDouble T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    ElType max;
    max = T.TI[1];
    int i;
    for (i = 2; i <= T.Neff; i++)
    {
        if (T.TI[i] > max)
        {
            max = T.TI[i];
        }
    }
    return max;
}

ElType ValMin (TabDouble T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    ElType min;
    min = T.TI[1];
    int i;
    for (i = 2; i <= T.Neff; i++)
    {
        if (T.TI[i] < min)
        {
            min = T.TI[i];
        }
    }
    return min;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabDouble T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
{
    int i = 1;
    while (i <= T.Neff && T.TI[i] != ValMax(T))
    {
        i++;
    }
    return i;
}

IdxType IdxMinTab (TabDouble T)
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
{
    int i = 1;
    while (i <= T.Neff && T.TI[i] != ValMin(T))
    {
        i++;
    }
    return i;
}


bool search (TabDouble T, ElType val) 
{
    bool found = false;
    int idx = 0;

    while (found == false && idx < T.Neff) {
        if (T.TI[idx] == val) {
            found = true;
        }
        idx++;
    }
    return found;
}