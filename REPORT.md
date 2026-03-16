# Laporan Programming Assignment 1: Basic C++
pada Assignment kali ini, saya membuat **aplikasi penghitung umur** berdasarkan inputan tanggal lahir menggunakan format DD/MM/YYYY. 

## Tujuan 
1. Melatih pemahaman pointer of object dan arrow pointer
2. Sebagai solusi dalam permasalahan perhitungan umur 
   
## Input
Input berupa tanggal lahir dengan penulisan format DD/MM/YYYY. inputan diberikan setelah output
```
year:2026 month:3 day:16
Input tanggal dalam format DD/MM/YYYY:
```
> Contoh Inputan 
```
year:2026 month:3 day:16
Input tanggal dalam format DD/MM/YYYY: 05/05/2007
```

## Process
dalam aplikasi ini terdapat beberapa proses penting yang berjalan. 
### Input Handling and Processing
Menggunakan ``` stringstream ``` untuk melakukan convert string menjadi integer. hasil integer dimasukkan dalam object ``` inputTgl ``` penggunaan operasi aritmatika pada ``` tm_year ``` dan ```tm_mon``` untuk menyesuaikan nilai dengan property pada object ```currentTgl```

### Function
Terdapat 3 fungsi yang bekerja sesuai tujuannya masing-masing
1. ```yearsOld(InputTgl, currentTgl)``` <br/>
   digunakan untuk mengeluarkan output umur dalam tahun. penggunaan argumen <br/>```(currentTgl->tm_mon < inputTgl->tm_mon || (currentTgl->tm_mon == inputTgl->tm_mon && currentTgl->tm_mday < inputTgl->tm_mday))``` <br/>digunakan untuk mengatasi kesalahan perhitungan ketika inputan nilai bulan dan hari lebih besar daripada nilai bulan dan hari sekarang
2. ```monthsOld(inputTgl, currentTgl)``` <br/>
   digunakan untuk mengeluarkan output umur dalam bulan.
3. ```dayOfDate(inputTgl, currentTgl)``` <br/>
   digunakan untuk mengeluarkan hari dari tanggal input. terdapat Kabisat Handle untuk mengatasi perhitungan hari tambahan karna tahun kabisat. lalu ada perhitungan tambahan yang tidak ikut dalam handle tahun kabisat

## Output
Output yang diberikan adalah satu baris dengan isi
``` <tahun> <bulan> <Hari> ``` <br/>
> contoh 
 
``` 18 226 Sabtu ``` 
