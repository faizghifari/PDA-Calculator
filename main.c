#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "stackt.h"

// DEKLARASI DAN SPESIFIKASI FUNGSI DAN PROSEDUR

float stof(char* s);
/* Mengubah string dari sebuah bilangan ke bentuk float
I.S : s terdefinisi sebagai sebuah string berbentuk bilangan dan tidak kosong,
minimal adalah 2 karakter untuk bilangan negatif dan 1 karakter untuk bil. positif
F.S : x mengeluarkan hasil konversi dari string s
*/

// ALGORITMA UTAMA

int main(){
    char s[50];
    scanf("%s",s);
    float x = stof(s);
    printf("%f\n",x);
}


// REALISASI FUNGSI DAN PROSEDUR

float stof(char *s)
{
  float hasil = 0, desimal = 1;
  if (*s == '-')
  {
    s++;
    desimal = -1;
  };
  boolean udah_koma = false;
  for (; *s; s++)
  {
    if (*s == '.')
    {
      udah_koma = true; 
    };
    int d = *s - '0';
    if (d >= 0 && d <= 9)
    {
      if (udah_koma) desimal /= 10;
      hasil = hasil * 10 + (float)d;
    };
  };
  return hasil * desimal;
};
/* Mengubah string dari sebuah bilangan ke bentuk float
I.S : s terdefinisi sebagai sebuah string berbentuk bilangan dan tidak kosong,
minimal adalah 2 karakter untuk bilangan negatif dan 1 karakter untuk bil. positif
F.S : x mengeluarkan hasil konversi dari string s
*/
