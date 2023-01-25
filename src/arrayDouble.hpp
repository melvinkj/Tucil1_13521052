#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

/* Kamus Umum */

#define IdxMax 999
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef double ElType;

typedef struct
 {
  ElType TI [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
  int Neff; /* banyaknya elemen efektif */
 } TabDouble;

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
void MakeEmpty (TabDouble *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabDouble T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabDouble T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabDouble T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdx (TabDouble T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabDouble T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabDouble Tin, TabDouble *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetEl (TabDouble *T, IdxType i, ElType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeff (TabDouble *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

void append (TabDouble *T, ElType v);

/* ********** Test Indeks yang valid ********** */
bool IsIdxValid (TabDouble T, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
bool IsIdxEff (TabDouble T, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
bool IsEmpty (TabDouble T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
bool IsFull (TabDouble T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabDouble T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabDouble PlusTab (TabDouble T1, TabDouble T2);
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
TabDouble MinusTab (TabDouble T1, TabDouble T2);
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabDouble T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin (TabDouble T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabDouble T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType IdxMinTab (TabDouble T);
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */

bool search (TabDouble T, ElType val);

#endif