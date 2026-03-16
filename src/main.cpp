#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

// Umur dalam tahun
int yearsOld(tm* inputTgl, tm* currentTgl);
// Umur dalam bulan
int monthsOld(tm* inputTgl, tm* currentTgl);
// Hari dalam seminggu (Minggu, Senin, ..., Sabtu)
string dayOfDate(tm* inputTgl, tm* currentTgl);

int main(int argc, char ** argv) 
{
    // time_t -> data structure untuk waktu
    time_t currentTime;

    // set variable currentTime ke data sekarang
    time(&currentTime);

    // ubah ke localtime (UTC+7)
    tm* currentTgl = localtime(&currentTime);

    
    int yearnow = currentTgl->tm_year+1900;    
    int monthnow = currentTgl->tm_mon+1;
    int daynow = currentTgl->tm_mday;
    int dayofweek = currentTgl->tm_wday;       // <-- start dari hari minggu
    
    // print tanggal sekarang (di comment)
    cout    <<" year:" << yearnow // <-- perlu diperhatikan
            <<" month:"<< monthnow
            <<" day:" << daynow <<endl;

    // input tanggal lahir
    int yearinput, monthinput, dayinput;
    string inputstr;
    char ch;
    // silahkan uncomment kode dibawah untuk debugging
    cout << "Input tanggal dalam format DD/MM/YYYY:";
    cin >> inputstr;
    stringstream ss(inputstr);
    ss >> dayinput >> ch >> monthinput >> ch >> yearinput;
    // silahkan uncomment untuk debugging
    cout << "Tanggal Input: " << dayinput << "/" << monthinput << "/" << yearinput << endl;
    
    // buat tm* untuk tanggal input
    tm* inputTgl = new tm();
    inputTgl->tm_year = yearinput-1900;
    inputTgl->tm_mon = monthinput-1;
    inputTgl->tm_mday = dayinput;

    // // ----------------------------------------------------------------------------------------------------------------
    // // --- Ubah di sini
    // // ---  * output yang diinginkan: 32 390 Selasa
    // // ---                  32 -> usia dalam tahun, 390 -> usia dalam bulan, Selasa -> hari dari tanggal input
    // // ----------------------------------------------------------------------------------------------------------------

    cout << "Perbedaan Tahun : " << inputTgl-> tm_year << " - " << currentTgl->tm_year << endl;

    int ageOfYear = yearsOld(inputTgl, currentTgl);
    int ageOfMonth = monthsOld(inputTgl, currentTgl);
    string dayName = dayOfDate(inputTgl, currentTgl);

    cout << ageOfYear << " " << ageOfMonth << " " << dayName;
    // ----------------------------------------------------------------------------------------------------------------

    return 0;
}

//*********************************************************************************************************************
// Silahkan masukkan kode Anda pada fungsi-fungsi berikut
//*********************************************************************************************************************
int yearsOld(tm* inputTgl, tm* currentTgl)
{
    if(currentTgl->tm_mon < inputTgl->tm_mon || (currentTgl->tm_mon == inputTgl->tm_mon && currentTgl->tm_mday < inputTgl->tm_mday)) {
        return currentTgl->tm_year - inputTgl->tm_year - 1;
    } else {
    return currentTgl->tm_year - inputTgl->tm_year;
    }
}
//*********************************************************************************************************************
//*********************************************************************************************************************
int monthsOld(tm* inputTgl, tm* currentTgl)
{
    return (currentTgl->tm_year - inputTgl->tm_year) * 12 + (currentTgl->tm_mon - inputTgl->tm_mon);
}
//*********************************************************************************************************************
//*********************************************************************************************************************
string dayOfDate(tm* inputTgl, tm* currentTgl)
{
    // Daftar Hari
    string days[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    int MounthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfWeek = 0;

    // Kabisat Handle
    for (int year = inputTgl->tm_year+1900 ; year < currentTgl->tm_year + 1900; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            dayOfWeek += 366;
        } else {
            dayOfWeek += 365;
        }
    }
    // Hari dalam tahun sekarang
    int isYearnowKabisat = ((currentTgl->tm_year + 1900) % 4 == 0 && (currentTgl->tm_year + 1900) % 100 != 0) || ((currentTgl->tm_year + 1900) % 400 == 0);
    if (isYearnowKabisat){
        for (int i = 0; i < currentTgl->tm_mon; i++) {
            dayOfWeek += MounthDays[i];
        }
        dayOfWeek += currentTgl->tm_mday;
    } else {
        for (int i = 0; i < currentTgl->tm_mon; i++) {
            dayOfWeek += MounthDays[i];
        }
        dayOfWeek += currentTgl->tm_mday + 1;
    }

    // Hari dalam tahun input
    int isYearInputKabisat = ((inputTgl->tm_year + 1900) % 4 == 0 && (inputTgl->tm_year + 1900) % 100 != 0) || ((inputTgl->tm_year + 1900) % 400 == 0);
    if (isYearInputKabisat){
        for (int i = 0; i < inputTgl->tm_mon; i++) {
            dayOfWeek -= MounthDays[i];
        }
        dayOfWeek -= inputTgl->tm_mday;
    } else {
        for (int i = 0; i < inputTgl->tm_mon; i++) {
            dayOfWeek -= MounthDays[i];
        }
        dayOfWeek -= inputTgl->tm_mday + 1;
    }

    cout << "Total Hari: " << dayOfWeek << endl;
    dayOfWeek = dayOfWeek % 7;
    return days[(currentTgl->tm_wday - dayOfWeek + 7) % 7];
}
//*********************************************************************************************************************
//*********************************************************************************************************************

