#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
//Added Library
#include <map>
#include <sstream>
#include "BusSystem.cpp"
using namespace std;

#define TEST01 "1\n1\n-1\n2\n3\n1\n2\n3\n0\n1\n-1\n"
#define TEST02 "1\n1\n2\n3\n4\n3\n44C2-73847\n32C1-55555\n"
#define TEST03 "1\n1\n1\n1\n1\n1\n2\n1\n2\n"
#define TEST04 "1\n1\n1\n1\n1\n1\n2\n1\n2\n0\n0\n1\n32C-55555\n-1\n"
#define TEST05 "1\n1\n1\n1\n1\n2\n2\n1\n1\n0\n0\n-1\n1\n"
#define TEST06 "1\n-1\n1\n1\n1\n-1\n-1\n2\n1\n-1\n-1\n-1\n1\nBrand\n1\n2\n0\n"
#define TEST07 "-1\n1\n-1\n-1\n1\n-1\n1\n-1\n-1\n1\n-1\n2\n1\n2\n3\n56DB-11211\n1\n55KT-1251\n3\n0\n1\n1\n0\n"
#define TEST08 "1\n1\n2\n3\n4\n2\n2\n-1\n1\n2\n3\n4\n-1\n2\n34B-1235\n32C1-55555\n"
#define TEST09 "1\n1\n2\n-1\n0\n"
#define TEST10 "1\n1\n2\n-1\n2\n"
#define TEST11 "1\n1\n2\n-1\n2\n2\n"
#define TEST12 "1\n1\n2\n-1\n2\n0\n"
#define TEST13 "1\n1\n2\n3\n2\n1\n50D1-23342\n"
#define TEST14 "1\n1\n2\n50D1-23342\n"
#define TEST15 "1\n1\n2\n50D1-23341\n"
#define TEST16 "1\n1\n2\n-1\n"
#define TEST17 "1\n1\n2\n-1\n"
#define TEST18 "1\n1\n2\n50D1-23342\n"
#define TEST19 "1\n1\n2\n50D1-23342\n-1\n3\n4\n5\n50D1-23341\n3\n-1\n"
#define TEST20 "1\n-1\n1\n1\n2\n50D1-23342\n-1\n3\n-1\n-1\n50D1-23341\n2\n1\n"
int main() {
    BusSystem* bs = new BusSystem();
    ios::sync_with_stdio(false);
    cin.tie(0);
    stringstream Out;
    clock_t start, end;
    float runTime;
    //TEST01
    start = clock();
    Out << bs->query("SQ 10") << "\n";
    Out << bs->query("INS 50 50D1-23342 1234 5678") << "\n";
    Out << bs->query("INS 50 50D1-23342 1234 5679") << "\n";
    Out << bs->query("INS 50 59A3-18965 1244 1754") << "\n";
    Out << bs->query("INS 50 54B3-18365 1245 1754") << "\n";
    Out << bs->query("INS 33 54F1-21076 1 1232 1345") << "\n";
    Out << bs->query("INS 33 51B5-22451 0 1235 1412") << "\n";
    Out << bs->query("DEL 50") << "\n";
    Out << bs->query("CS 50 1300") << "\n";
    Out << bs->query("CE 33 1400 1") << "\n";
    Out << bs->query("GS 50 1240 0") << "\n";
    end = clock();

    cout << "TEST 01: ";
    if (Out.str() == TEST01) {
        cout << "Successfully!\t";
    } else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 01: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;

    //TETS 02
    bs = new BusSystem();
    Out.str("");
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23342 1 1235 5678") << endl;
    Out << bs->query("INS 50 32C1-55555 0 1235 9121") << endl;
    Out << bs->query("INS 50 54D1-89391 0 1277 2100") << endl;
    Out << bs->query("INS 50 44C2-73847 1 1299 9121") << endl;
    Out << bs->query("CS 50 2134") << endl;
    Out << bs->query("GS 50 2111") << endl;
    Out << bs->query("GE 50 10000") << endl;
    end = clock();

    cout << "TEST 02: ";
    if (Out.str() == TEST02) {
        cout << "Successfully!\t";
    } else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 02: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;

    //TEST 03
    bs = new BusSystem();
    Out.str("");
    start = clock();
    Out << bs->query("SQ 10") << endl;
    Out << bs->query("INS A12 50D-23342 1 1235 5678") << endl;
    Out << bs->query("INS B23 32C-55555 0 1235 9121") << endl;
    Out << bs->query("INS C4 54D1-89391 0 1277 2100") << endl;
    Out << bs->query("INS D43 44C2-73847 1299 9121") << endl;
    Out << bs->query("INS A1 51DA-23244 1 1211 5655") << endl;
    Out << bs->query("INS B23 32C-66563 657 912") << endl;
    Out << bs->query("INS 43A 51D6-89191 0 277 1100") << endl;
    Out << bs->query("INS D43 AD-738 5699 9121") << endl;
    end = clock();

    cout << "TEST 03: ";
    if (Out.str() == TEST03)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 03: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;

    //TEST 04
    start = clock();
    Out << bs->query("DEL 50 1234") << endl;
    Out << bs->query("DEL A1 1200") << endl;
    Out << bs->query("DEL A1") << endl;
    Out << bs->query("GS B23 2111") << endl;
    Out << bs->query("GE 50 11000") << endl;
    end = clock();

    cout << "TEST 04: ";
    if (Out.str() == TEST04)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 04: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 05
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 10") << endl;
    Out << bs->query("INS A12B 5D23342 1235 5678") << endl;
    Out << bs->query("INS B23A 31RE-555 0 1235 9121") << endl;
    Out << bs->query("INS C400 54D143-111 0 12778 21001") << endl;
    Out << bs->query("INS D33 14C2-738 121 912") << endl;
    Out << bs->query("INS A12B 51D23244 1 1235 5655") << endl;
    Out << bs->query("INS B23A 32C-66563 657 9121") << endl;
    Out << bs->query("INS 43A 51D6-89191 0 277 1100") << endl;
    Out << bs->query("INS D43 AD-738 5699 9121") << endl;
    Out << bs->query("CS 43A 100") << endl;
    Out << bs->query("CE A12B 1236") << endl;
    Out << bs->query("GE B23A 4000") << endl;
    Out << bs->query("DEL 43A 100 280") << endl;
    end = clock();

    cout << "TEST 05: ";
    if (Out.str() == TEST05)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 05: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 06
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 5") << endl;                                    //OK
    Out << bs->query("INS A1252342 12355678") << endl;                   //FAILED
    Out << bs->query("INS A AKKO_3087 0 1235 9121") << endl;             //OK
    Out << bs->query("INS C4 SimpleX 0 12778 21001") << endl;            //OK
    Out << bs->query("INS CO200 MT19 121 912") << endl;                  //OK
    Out << bs->query("INS A CORSAIR_K 1235 5655") << endl;               //FAILED
    Out << bs->query("INS -239521fjkjw@32C66563 657 135 9121") << endl;  //FAILED
    Out << bs->query("INS C4 Brand 0 21002 22000") << endl;              //OK
    Out << bs->query("INS D43 AD-738 5699 9121") << endl;                //OK
    Out << bs->query("INS 104  59DA-11211 135 9121") << endl;            //FAILED
    Out << bs->query("INS C4 Brand 0 21A2 2B000") << endl;               //FAILED
    Out << bs->query("INS CO200 AD-738 56999121") << endl;               //FAILED
    Out << bs->query("CS A 2000") << endl;
    Out << bs->query("GS C4 22100") << endl;
    Out << bs->query("CE CO200 999") << endl;
    Out << bs->query("DEL C4") << endl;
    Out << bs->query("DEL A 2000 3800") << endl;
    end = clock();

    cout << "TEST 06: ";
    if (Out.str() == TEST06)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 06: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 07
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SO 5") << endl;                              //FAILED
    Out << bs->query("SQ 7") << endl;                              //OK
    Out << bs->query("INS A12523478") << endl;                     //FAILED
    Out << bs->query("INS ABCDEF LOGITECH 1235 9121") << endl;     //FAILED
    Out << bs->query("INS 114 50D1-12362 0 0909 1100") << endl;    //OK
    Out << bs->query("INS 115 59D-45151 1210 0912") << endl;       //OK
    Out << bs->query("INS 150 55KT-1251 1235 1655") << endl;       //OK
    Out << bs->query("INS 12A 12345 A146 B100") << endl;           //FAILED
    Out << bs->query("INS 23C 34B1_12061 [1] 2102 2200") << endl;  //FAILED
    Out << bs->query("INS 30 34R1-17932 1 1600 1800") << endl;     //OK
    Out << bs->query("INS 30 59DA-11211  1352 2121") << endl;      //FAILED
    Out << bs->query("INS 114 45T9-3452 0 2120 3000") << endl;     //OK
    Out << bs->query("INS CO2 NaCO3 135 140") << endl;             //FAILED
    Out << bs->query("INS 30 59DB-11211 1 1352 2121") << endl;     //OK
    Out << bs->query("INS 30 56DB-11211 1400 2121") << endl;       //OK
    Out << bs->query("GE 30 2200") << endl;
    Out << bs->query("CS 114 1000") << endl;
    Out << bs->query("GS 150 1240") << endl;
    Out << bs->query("CE 30 2122") << endl;
    Out << bs->query("DEL C4") << endl;
    Out << bs->query("DEL 30 1600") << endl;
    Out << bs->query("DEL 114 1000 2800") << endl;
    Out << bs->query("DEL 12A") << endl;
    end = clock();

    cout << "TEST 07: ";
    if (Out.str() == TEST07)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 07: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 08
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;                         //OK
    Out << bs->query("INS 50 50D1-23342 1 1235 5678") << endl;  //OK
    Out << bs->query("INS 50 32C1-55555 0 1235 9121") << endl;  //OK
    Out << bs->query("INS 50 54D1-89391 0 1277 2100") << endl;  //OK
    Out << bs->query("INS 50 44C2-73847 1 1299 9121") << endl;  //OK
    Out << bs->query("DEL 50 1270 1300") << endl;               //50 54D1-89391 and 50 44C2-73847 will be deleted
    Out << bs->query("CS 50 1240") << endl;                     //50 50D1-23342 and 50 32C1-55555
    Out << bs->query("INS 33 34A-1235 -1 1345 1500") << endl;   //FAILED
    Out << bs->query("INS 104 34A-1235 1345 1500") << endl;     //OK
    Out << bs->query("INS 104 34A-1235 1600 1812") << endl;     //OK
    Out << bs->query("INS 104 34B-1235 1900 2100") << endl;     //OK
    Out << bs->query("INS 104 33A1-1237 1000 1200") << endl;    //OK
    Out << bs->query("INS 104 33A1-1237 0001 0900") << endl;    //FAILED
    Out << bs->query("CS 50 2134") << endl;                     //2
    Out << bs->query("GS 104 2000") << endl;                    //34B-1235
    Out << bs->query("GE 50 10000") << endl;                    //32C1-5555
    end=clock();
    //cout << Out.str();
    cout << "TEST 08: ";
    if (Out.str() == TEST08)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 08: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 09
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23342 1234 5678") << endl;
    Out << bs->query("INS 50 50D1-23343 0 4000 5000") << endl;
    Out << bs->query("INS 50 50D1-23342 1 1200 1222") << endl;
    Out << bs->query("CS 50 1210") << endl;
    end = clock();
    cout << "TEST 09: ";
    if (Out.str() == TEST09)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 09: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 10
    start = clock();
    bs = new BusSystem();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23342 1234 5678") << endl;
    Out << bs->query("INS 50 50D1-23343 0 4000 5000") << endl;
    Out << bs->query("INS 50 50D1-23342 1 1200 1222") << endl;
    Out << bs->query("CS 50 4500 0") << endl;
    end = clock();
    cout << "TEST 10: ";
    if (Out.str() == TEST10)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 10: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 11
    start = clock();
    bs = new BusSystem();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23342 1234 5678") << endl;
    Out << bs->query("INS 50 50D1-23343 0 4000 5000") << endl;
    Out << bs->query("INS 50 50D1-23342 1 1200 1222") << endl;
    Out << bs->query("CS 50 4500 0") << endl;
    Out << bs->query("CE 50 6000") << endl;
    end = clock();
    cout << "TEST 11: ";
    if (Out.str() == TEST11)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 11: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 12
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23342 1234 5678") << endl;
    Out << bs->query("INS 50 50D1-23343 0 4000 5000") << endl;
    Out << bs->query("INS 50 50D1-23342 1 1200 1222") << endl;
    Out << bs->query("CS 50 4500 0") << endl;
    Out << bs->query("CE 50 4500") << endl;
    end = clock();
    cout << "TEST 12: ";
    if (Out.str() == TEST12)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 12: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 13
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23341 5 10") << endl;
    Out << bs->query("INS 50 50D1-23342 0 6 15") << endl;
    Out << bs->query("INS 50 50D1-23343 1 4 9") << endl;
    Out << bs->query("CS 50 10") << endl;
    Out << bs->query("CE 50 10") << endl;
    Out << bs->query("GS 50 7") << endl;
    end = clock();
    cout << "TEST 13: ";
    if (Out.str() == TEST13)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 13: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 14
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23341 1 5 10") << endl;
    Out << bs->query("INS 50 50D1-23342 1 8 9") << endl;
    Out << bs->query("GS 50 8") << endl;
    end = clock();
    cout << "TEST 14: ";
    if (Out.str() == TEST14)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 14: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 15
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23341 6 10") << endl;
    Out << bs->query("INS 50 50D1-23342 5 9") << endl;
    Out << bs->query("GS 50 8") << endl;
    end = clock();
    cout << "TEST 15: ";
    if (Out.str() == TEST15)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 15: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 16
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23341 6 10") << endl;
    Out << bs->query("INS 50 50D1-23342 5 9") << endl;
    Out << bs->query("GS 50 4") << endl;
    end = clock();
    cout << "TEST 16: ";
    if (Out.str() == TEST16)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 16: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 17
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23341 6 10") << endl;
    Out << bs->query("INS 50 50D1-23342 5 9") << endl;
    Out << bs->query("GE 50 6") << endl;
    end = clock();
    cout << "TEST 17: ";
    if (Out.str() == TEST17)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 17: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 18
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23341 6 10") << endl;
    Out << bs->query("INS 50 50D1-23342 5 9") << endl;
    Out << bs->query("GE 50 10") << endl;
    end = clock();
    cout << "TEST 18: ";
    if (Out.str() == TEST18)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 18: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 19
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 500") << endl;
    Out << bs->query("INS 50 50D1-23341 6 10") << endl;
    Out << bs->query("INS 50 50D1-23342 5 9") << endl;
    Out << bs->query("GE 50 10") << endl;
    Out << bs->query("INS 50 50D2-23341 6 10") << endl;
    Out << bs->query("INS 50 50D2-23342 11 12") << endl;
    Out << bs->query("INS 50 51D2-23341 1 6 10") << endl;
    Out << bs->query("INS 50 53D2-23342 1 13 15") << endl;
    Out << bs->query("GE 50 11") << endl;
    Out << bs->query("CS 50 7") << endl;
    Out << bs->query("DEL 50 5 2") << endl;
    end = clock();
    cout << "TEST 19: ";
    if (Out.str() == TEST19)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 19: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");

    //TEST 20
    bs = new BusSystem();
    start = clock();
    Out << bs->query("SQ 0") << endl;
    Out << bs->query("INS 50 50D1-23341 6 10") << endl;
    Out << bs->query("SQ 3") << endl;
    Out << bs->query("INS 50 50D1-23341 6 10") << endl;
    Out << bs->query("INS 50 50D1-23342 5 9") << endl;
    Out << bs->query("GE 50 10") << endl;
    Out << bs->query("INS 50 50D2-23341 6 10") << endl;
    Out << bs->query("INS 50 50D2-23342 11 12") << endl;
    Out << bs->query("INS 50 51D2-23341 1 6 10") << endl;
    Out << bs->query("INS 50 53D2-23342 1 13 15") << endl;
    Out << bs->query("GS 50 7") << endl;
    Out << bs->query("CS 50 8") << endl;
    Out << bs->query("DEL 50 6") << endl;
    end = clock();
    cout << "TEST 20: ";
    if (Out.str() == TEST20)
        cout << "Successfully!\t";
    else
        cout << "Failed!\t";
    runTime = (float)(end - start) / CLOCKS_PER_SEC;
    cout << "Run Time of TEST 20: " << setiosflags(ios::fixed) << setprecision(20) << runTime << endl;
    delete bs;
    Out.str("");
    return 0;
}