#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <ctime>

using namespace std;

string break_str(string instruction) {
    string res = "";
    int size = instruction.length();
    for (int i = 0; i < size; i++) {
        if (instruction[i] != ' ') res += instruction[i];
        else break;
    }
    return res;
}

bool is_Digit(string a) {
    int size = a.length();
    for (int i = 0; i < size; i++) {
        if (a[i] < '0' || a[i] > '9') return false;
    }
    return true;
}

int so_chuyen(string instruction) {
    string res = "";
    int size = instruction.length();
    int a = 0;
    for (int i = 0; i < size; i++) {
        if (instruction[i] == ' ') {
            ++a;
            continue;
        }
        if (a == 1) res += instruction[i];
        if (a > 1) break;
    }
    int result = 0;
    if (is_Digit(res)) result = stoi(res);
    return result;
}

bool check_input(string instruction) {
    if (instruction[0] == ' ' || instruction[instruction.length() - 1] == ' ') return false;
    int size = instruction.length();
    for (int i = 0; i < size - 1; i++) {
        if (instruction[i] == ' ' && instruction[i + 1] == ' ') return false;
    }
    return true;
}


class BusSystem {
public:
    class Bus_Route;
    class Bus;
private:
    Bus_Route** system1;
    int max_chuyen;
    int count_tuyen;
public:
    BusSystem() {
        system1 = new Bus_Route*[2];
        system1[0] = NULL;
        system1[1] = NULL;
        max_chuyen = 0;
        count_tuyen = 0;
    }
    ~BusSystem() {
        delete[] system1;
    };

    string set_max_chuyen(int N) {
        this->max_chuyen = N;
        return "1";
    }

    // Them mot chuyen xe

    string INS(string CODE, string LP, int CASE, int TIMEA, int TIMEB) {
        Bus* newChuyen = new Bus(CODE, LP, CASE, TIMEA, TIMEB, NULL, NULL);
        if (system1[0] == NULL) {
            if (max_chuyen == 0) return "-1";
            Bus_Route* newRoute = new Bus_Route;
            newRoute->name = CODE;
            system1[0] = system1[1] = newRoute;
            newRoute->chuyen[0] = newChuyen;
            newRoute->chuyen[1] = newChuyen;
            count_tuyen++;
            system1[0]->count++;
            return to_string(newRoute->count);
        }

        else {
            Bus_Route* temp = system1[0];
            while (temp != NULL) {
                if (temp->name == CODE) break;
                temp = temp->next;
            }
            if (temp != NULL) {
                if (temp->count == max_chuyen) return "-1";
                Bus* temp1 = temp->chuyen[0];
                while (temp1 != NULL && temp1->LP != LP) {
                    if (temp1->TIMEA == TIMEA && temp1->CASE == CASE) return "-1";
                    temp1 = temp1->next;
                } 
                while (temp1 != NULL) {
                    if ((temp1->TIMEB >= TIMEA) || (temp1->TIMEB > TIMEA && temp1->CASE != CASE) || (temp1->CASE == CASE && temp1->TIMEA == TIMEA)) {
                        return "-1";
                    }
                    temp1 = temp1->next;
                    while (temp1 != NULL && temp1->LP != LP) {
                        temp1 = temp1->next;
                    }
                }
                temp->chuyen[1]->next = newChuyen;
                newChuyen->prev = temp->chuyen[1];
                temp->chuyen[1] = newChuyen;
                temp->count++;
                return to_string(temp->count);
            }
            else {
                Bus_Route* newRoute = new Bus_Route(CODE, NULL, system1[1]);
                system1[1]->next = newRoute;
                system1[1] = newRoute;
                newRoute->chuyen[0] = newChuyen;
                newRoute->chuyen[1] = newChuyen;
                count_tuyen++;
                newRoute->count++;
                return to_string(newRoute->count);
            }
        }
        return "";
    }

    // delete cac chuyen bus trong khoang thoi gian cho truoc

    string DEL(string CODE, int TIMEA = -1, int TIMEB = -1) {
        int result = 0;
        if (system1[0] == NULL) return "0";

        Bus_Route* temp = system1[0];

        while (temp != NULL && temp->name != CODE) {
            temp = temp->next;
        }

        if (temp != NULL) {
            Bus* res = temp->chuyen[0];
            while (res != NULL) {
                Bus* temp1 = res;
                if (TIMEA == - 1 && TIMEB == -1) {
                    if (temp1->next != NULL) temp1->next->prev = temp1->prev;
                    else temp->chuyen[1] = NULL;
                    temp->chuyen[0] = temp1->next;
                    temp->count--;
                    ++result;
                    delete temp1;
                }
                //else if (TIMEA == -1 || TIMEB == -1) {
                    /*if (TIMEA == -1) {
                        if (temp1 == temp->chuyen[0] && temp1->TIMEB == TIMEB) {
                            if (temp1->next != NULL) temp1->next->prev = temp1->prev;
                            else temp->chuyen[1] = NULL;
                            temp->chuyen[0] = temp1->next;
                            temp->count--;
                            ++result;
                            delete temp1;
                        }
                        else if (temp1 == temp->chuyen[1] && temp1->TIMEB == TIMEB) {
                            if (temp1->prev != NULL) temp1->prev->next = temp1->next;
                            else temp->chuyen[0] = NULL;
                            temp->chuyen[1] = temp1->prev;
                            temp->count--;
                            ++result;
                            delete temp1;
                        }
                        else if (temp1->TIMEB == TIMEB) {
                            if (temp1->prev != NULL) temp1->prev->next = temp1->next;
                            if (temp1->next != NULL) temp1->next->prev = temp1->prev;
                            temp->count--;
                            ++result;
                            delete temp1;
                        }
                    }*/
                    else if (TIMEB == -1) {
                        if (temp1 == temp->chuyen[0] && temp1->TIMEA == TIMEA) {
                            if (temp1->next != NULL) temp1->next->prev = temp1->prev;
                            else temp->chuyen[1] = NULL;
                            temp->chuyen[0] = temp1->next;
                            temp->count--;
                            ++result;
                            delete temp1;
                        }
                        else if (temp1 == temp->chuyen[1] && temp1->TIMEA == TIMEA) {
                            if (temp1->prev != NULL) temp1->prev->next = temp1->next;
                            else temp->chuyen[0] = NULL;
                            temp->chuyen[1] = temp1->prev;
                            temp->count--;
                            ++result;
                            delete temp1;
                        }
                        else if (temp1->TIMEA == TIMEA) {
                            if (temp1->prev != NULL) temp1->prev->next = temp1->next;
                            if (temp1->next != NULL) temp1->next->prev = temp1->prev;
                            temp->count--;
                            ++result;
                            delete temp1;
                        }
                    }
                else {
                    if (temp1 == temp->chuyen[0] && temp1->TIMEA >= TIMEA && temp1->TIMEA <= TIMEB) {
                        if (temp1->next != NULL) temp1->next->prev = temp1->prev;
                        else temp->chuyen[1] = NULL;
                        temp->chuyen[0] = temp1->next;
                        temp->count--;
                        ++result;
                        delete temp1;
                    }
                    else if (temp1 == temp->chuyen[1] && temp1->TIMEA >= TIMEA && temp1->TIMEA <= TIMEB) {
                        if (temp1->prev != NULL) temp1->prev->next = temp1->next;
                        else temp->chuyen[0] = NULL;
                        temp->chuyen[1] = temp1->prev;
                        temp->count--;
                        ++result;
                        delete temp1;
                    }
                    else if (temp1->TIMEA >= TIMEA && temp1->TIMEA <= TIMEB) {
                        if (temp1->prev != NULL) temp1->prev->next = temp1->next;
                        if (temp1->next != NULL) temp1->next->prev = temp1->prev;
                        temp->count--;
                        ++result;
                        delete temp1;
                    }
                }
                res = res->next;
            }
        }
        else return "0";
        return to_string(result);
    }
    
    // tra ve so chuyen da bat dau di nhung chua den ben cua mot tuyen

    string CS(string CODE, int TIME, int CASE = -1) {
        Bus_Route* temp = system1[0];
        int result = 0;

        while (temp != NULL && temp->name != CODE) {
            temp = temp->next;
        }

        if (temp != NULL) {
            Bus* res = temp->chuyen[0];
            if (CASE == 0) {
                while (res != NULL) {
                    if (res->CASE == 0 && res->TIMEA <= TIME && res->TIMEB >= TIME) ++result;
                    res = res->next;
                }
            }
            else if (CASE == 1) {
                while (res != NULL) {
                    if (res->CASE == 1 && res->TIMEA <= TIME && res->TIMEB >= TIME) ++result;
                    res = res->next;
                }
            }
            else {
                while (res != NULL) {
                    if (res->TIMEA <= TIME && res->TIMEB >= TIME) ++result;
                    res = res->next;
                }
            }
        }
        else return "0";

        return to_string(result);
    }

    // tra ve so chuyen da ket thuc cua mot tuyen

    string CE(string CODE, int TIME, int CASE = -1) {
        Bus_Route* temp = system1[0];
        int result = 0;

        while (temp != NULL && temp->name != CODE) {
            temp = temp->next;
        }

        if (temp != NULL) {
            Bus* res = temp->chuyen[0];
            if (CASE == 0) {
                while (res != NULL) {
                    if (res->CASE == 0 && res->TIMEB < TIME) ++result;
                    res = res->next;
                }
            }
            else if (CASE == 1) {
                while (res != NULL) {
                    if (res->CASE == 1 && res->TIMEB < TIME) ++result;
                    res = res->next;
                }
            }
            else {
                while (res != NULL) {
                    if (res->TIMEB < TIME) ++result;
                    res = res->next;
                }
            }
        }
        else return "0";

        return to_string(result);
    }

    // tra ve chuyen xe co thoi gian xuat phat gan nhat voi thoi gian da cho cua mot tuyen

    string GS(string CODE, int TIME, int CASE = -1) {
        Bus_Route* temp = system1[0];
        string result = "-1";

        while (temp != NULL && temp->name != CODE) {
            temp = temp->next;
        }

        if (temp != NULL) {
            Bus* res = temp->chuyen[0];
            int minTime;
            bool x = false;
             
            while (res != NULL) {
                if (CASE == 0) {
                    if (res->CASE == 0 && res->TIMEA <= TIME) {
                        int minTime1 = TIME - res->TIMEA;
                        if (x == false) {
                            minTime = minTime1 + 1;
                            x = true;
                            continue;
                        }
                        if (minTime1 < minTime) {
                            minTime = minTime1;
                            result = res->LP;
                        }
                    }
                }
                else if (CASE == 1) {
                    if (res->CASE == 1 && res->TIMEA <= TIME) {
                        int minTime1 = TIME - res->TIMEA;
                        if (x == false) {
                            minTime = minTime1 + 1;
                            x = true;
                            continue;
                        }
                        if (minTime1 < minTime) {
                            minTime = minTime1;
                            result = res->LP;
                        }
                    }
                }
                else {
        
                    int minTime1 = TIME - res->TIMEA;
                    if (x == false && minTime1 >= 0) {
                        minTime = minTime1 + 1;
                        x = true;
                        continue;
                    }
                    if (minTime1 >= 0) {
                        if (minTime1 == minTime && res->CASE == 0) {
                            minTime = minTime1;
                            result = res->LP;
                        }
                        else if (minTime1 < minTime) {
                            minTime = minTime1;
                            result = res->LP;
                        }
                    }
                }
                res = res->next;
            }
        }
        else return "-1";

        return result;
    }

    // tra ve chuyen xe co thoi gian ket thuc gan nhat voi thoi gian da cho cua mot tuyen

    string GE(string CODE, int TIME, int CASE = -1) {
        Bus_Route* temp = system1[0];
        string result = "-1";

        while (temp != NULL && temp->name != CODE) {
            temp = temp->next;
        }

        if (temp != NULL) {
            Bus* res = temp->chuyen[0];
            int minTime;
            bool x = false;
            int checkTime;
            int checkCase;

            while (res != NULL) {
                if (CASE == 0) {
                    if (res->CASE == 0 && res->TIMEB < TIME) {
                        int minTime1 = TIME - res->TIMEB;
                        if (x == false) {
                            minTime = minTime1 + 1;
                            x = true;
                            continue;
                        }
                        if (minTime1 == minTime) {
                            if (checkTime < res->TIMEA) {
                                result = res->LP;
                                checkTime = res->TIMEA;
                            }
                        }
                        else if (minTime1 < minTime) {
                            minTime = minTime1;
                            result = res->LP;
                            checkTime = res->TIMEA;
                        }
                    }
                }
                else if (CASE == 1) {
                    if (res->CASE == 1 && res->TIMEB < TIME) {
                        int minTime1 = TIME - res->TIMEB;
                        if (x == false) {
                            minTime = minTime1 + 1;
                            x = true;
                            continue;
                        }
                        if (minTime1 == minTime) {
                            if (checkTime < res->TIMEA) {
                                result = res->LP;
                                checkTime = res->TIMEA;
                            }
                        }
                        else if (minTime1 < minTime) {
                            minTime = minTime1;
                            result = res->LP;
                            checkTime = res->TIMEA;
                        }
                    }
                }
                else {

                    int minTime1 = TIME - res->TIMEB;
                    if (x == false && minTime1 > 0) {
                        minTime = minTime1 + 1;
                        x = true;
                        continue;
                    }
                    
                    if (minTime1 > 0) {
                        if (minTime1 == minTime && res->CASE == 1 && checkCase == 1) {
                            if (checkTime < res->TIMEA) {
                                minTime = minTime1;
                                result = res->LP;
                                checkTime = res->TIMEA;
                                checkCase = res->CASE;
                            }
                        }
                        else if (minTime1 == minTime && res->CASE == 0 && checkCase == 0) {
                            if (checkTime < res->TIMEA) {
                                minTime = minTime1;
                                result = res->LP;
                                checkTime = res->TIMEA;
                                checkCase = res->CASE;
                            }
                        }
                        else if (minTime1 == minTime && res->CASE == 0 && checkCase == 1) {                          
                                minTime = minTime1;
                                result = res->LP;
                                checkTime = res->TIMEA;
                                checkCase = res->CASE;
                        }
                        else if (minTime1 < minTime) {
                            minTime = minTime1;
                            result = res->LP;
                            checkTime = res->TIMEA;
                            checkCase = res->CASE;
                        }
                    }
                }
                res = res->next;
            }
        }
        else return "-1";

        return result;
    }
    string query(string instruction) {
        // TODO: Your implementation

        if (!check_input(instruction)) return "-1"; 

        string require = break_str(instruction);
    
        if (require == "SQ") { 
            int a = so_chuyen(instruction);
            if (a >= 0) return set_max_chuyen(a);
        }
        else if (require == "INS") {
            string x1 = "", x2 = "", x3 = "", x4 = "", x5 = "";
            int count = 0;
            for (int i = 0; i < int(instruction.length()); i++) {
                if (instruction[i] == ' ') {
                    count++;
                    continue;
                }
                if (count == 1) x1 += instruction[i];
                else if (count == 2) x2 += instruction[i];
                else if (count == 3) x3 += instruction[i];
                else if (count == 4) x4 += instruction[i];
                else if (count == 5) x5 += instruction[i];
            }
            if (x4 == "" || x3 == "" || x2 == "" || x1 == "") return "-1";
            int Case, timeA, timeB;
            if (x5 == "") {
                Case = 0;
                if (is_Digit(x3)) timeA = stoi(x3);
                else return "-1";
                if (is_Digit(x4)) timeB = stoi(x4);
                else return "-1";
            }
            else {
                if (is_Digit(x3)) Case = stoi(x3);
                else return "-1";
                if (is_Digit(x4)) timeA = stoi(x4);
                else return "-1";
                if (is_Digit(x5)) timeB = stoi(x5);
                else return "-1";
            }
            if (timeA >= timeB) return "-1";
            if (int(x1.length()) <= 5 && int(x2.length()) <= 10) return INS(x1, x2, Case, timeA, timeB);
        }
        else if (require == "DEL") {
            string x1 = "", x2 = "", x3 = "";
            int count = 0;
            for (int i = 0; i < int(instruction.length()); i++) {
                if (instruction[i] == ' ') {
                    ++count;
                    continue;
                }
                if (count == 1) x1 += instruction[i];
                else if (count == 2) x2 += instruction[i];
                else if (count == 3) x3 += instruction[i];
            }
            if (x1 == "") return "-1";
            int timeA, timeB;
            if (x2 == "" && x3 == "") {
                timeA = -1;
                timeB = -1;
            }
            else if (x2 != "" && x3 == "") {
                if (is_Digit(x2)) timeA = stoi(x2);
                else return "-1";
                timeB = -1;
            }
            else {
                if (is_Digit(x2)) timeA = stoi(x2);
                else return "-1";
                if (is_Digit(x3)) timeB = stoi(x3);
                else return "-1";
                if (timeA > timeB) return "-1";
            }

            return DEL(x1, timeA, timeB);
        }
        else if (require == "CS") {
            string x1 = "", x2 = "", x3 = "";
            int count = 0;
            for (int i = 0; i < int(instruction.length()); i++) {
                if (instruction[i] == ' ') {
                    ++count;
                    continue;
                }
                if (count == 1) x1 += instruction[i];
                else if (count == 2) x2 += instruction[i];
                else if (count == 3) x3 += instruction[i];
            }
            if (x1 == "" || x2 == "") return "-1";
            int time, Case;
            if (x3 == "") {
                if (is_Digit(x2)) time = stoi(x2);
                else return "-1";
                Case = -1;
            }
            else {
                if (is_Digit(x2)) time = stoi(x2);
                else return "-1";
                if (is_Digit(x3)) Case = stoi(x3);
                else return "-1";
            }
            return CS(x1, time, Case);
        }
        else if (require == "CE") {
            string x1 = "", x2 = "", x3 = "";
            int count = 0;
            for (int i = 0; i < int(instruction.length()); i++) {
                if (instruction[i] == ' ') {
                    ++count;
                    continue;
                }
                if (count == 1) x1 += instruction[i];
                else if (count == 2) x2 += instruction[i];
                else if (count == 3) x3 += instruction[i];
            }
            if (x1 == "" || x2 == "") return "-1";
            int time, Case;
            if (x3 == "") {
                if (is_Digit(x2)) time = stoi(x2);
                else return "-1";
                Case = -1;
            }
            else {
                if (is_Digit(x2)) time = stoi(x2);
                else return "-1";
                if (is_Digit(x3)) Case = stoi(x3);
                else return "-1";
            }
            return CE(x1, time, Case);
        }
        else if (require == "GS") {
            string x1 = "", x2 = "", x3 = "";
            int count = 0;
            for (int i = 0; i < int(instruction.length()); i++) {
                if (instruction[i] == ' ') {
                    ++count;
                    continue;
                }
                if (count == 1) x1 += instruction[i];
                else if (count == 2) x2 += instruction[i];
                else if (count == 3) x3 += instruction[i];
            }
            if (x1 == "" || x2 == "") return "-1";
            int time, Case;
            if (x3 == "") {
                if (is_Digit(x2)) time = stoi(x2);
                else return "-1";
                Case = -1;
            }
            else {
                if (is_Digit(x2)) time = stoi(x2);
                else return "-1";
                if (is_Digit(x3)) Case = stoi(x3);
                else return "-1";
            }
            return GS(x1, time, Case);
        }
        else if (require == "GE") {
            string x1 = "", x2 = "", x3 = "";
            int count = 0;
            for (int i = 0; i < int(instruction.length()); i++) {
                if (instruction[i] == ' ') {
                    ++count;
                    continue;
                }
                if (count == 1) x1 += instruction[i];
                else if (count == 2) x2 += instruction[i];
                else if (count == 3) x3 += instruction[i];
            }
            if (x1 == "" || x2 == "") return "-1";
            int time, Case;
            if (x3 == "") {
                if (is_Digit(x2)) time = stoi(x2);
                else return "-1";
                Case = -1;
            }
            else {
                if (is_Digit(x2)) time = stoi(x2);
                else return "-1";
                if (is_Digit(x3)) Case = stoi(x3);
                else return "-1";
            }
            return GE(x1, time, Case);
        }
        return "-1";
    }
public:
    class Bus_Route {
    protected:
        int count;
        string name;
        Bus** chuyen;
        Bus_Route* next;
        Bus_Route* prev;
        friend class BusSystem;
    public:
        Bus_Route() {
            name = "";
            count = 0;
            chuyen = new Bus*[2];
            chuyen[0] = NULL;
            chuyen[1] = NULL;
            next = NULL;
            prev = NULL;
        }
        Bus_Route(string name, Bus_Route* next, Bus_Route* prev) {
            count = 0;
            chuyen = new Bus*[2];
            chuyen[0] = NULL;
            chuyen[1] = NULL;
            this->name = name;
            this->next = next;
            this->prev = prev;
        }
        ~Bus_Route() {
            delete[] chuyen;
        };
    };
    class Bus {
    protected:
        string CODE;
        string LP;
        int CASE;
        int TIMEA;
        int TIMEB;
        Bus* next;
        Bus* prev;
        friend class BusSystem;
    public:
        Bus() {
            CODE = "";
            LP = "";
            CASE = 0;
            TIMEA = TIMEB = 0;
            next = NULL;
            prev = NULL;
        }
        Bus(string CODE, string LP, int CASE, int TIMEA, int TIMEB, Bus* next, Bus* prev) {
            this->CODE = CODE;
            this->LP = LP;
            this->CASE = CASE;
            this->TIMEA = TIMEA;
            this->TIMEB = TIMEB;
            this->next = next;
            this->prev = prev;
        }
        ~Bus() {};
    };

};

//int main()
//{
    /*BusSystem* bs = new BusSystem();
//SQ
cout << "SQ" << endl;
cout << bs->query("SQ6") << endl;
 cout << bs->query("SQ 6") << endl;
 cout << bs->query("TIEN 45")<<endl;//false
 cout<<"**********"<<endl;
//INS
cout << "INS" << endl;
 cout << bs->query("INS 50 50D1-23342 1234 5678") << endl;//true
 cout << bs->query("INS 30 30A2-23562 2563 5445") << endl;//true
 cout << bs->query("INS 19 19E3-6646 1280 7852") << endl;//true
 cout << bs->query("INS 50 50D2-242 4582 5678") << endl;//true
 cout << bs->query("INS 50 50D2-24568 1234 5678") << endl;//cung starttime-->false
 cout << bs->query("INS 50 50D1-23342 6000 7000") << endl;//cung bien xe-->true
 cout << bs->query("INS 30 30A2-23562 1252 5688") << endl;//cung bien xe -->false
 cout << bs->query("INS 19 19D2-242 1 4582 5678") << endl;//true
 cout << bs->query("INS 50 50D2-242 1 4582 5678") << endl;//true
 cout << bs->query("INS 50 50F3-F4567 1 4582 6800") << endl;//true
 cout << bs->query("INS 50 50D3-24782 1 1250 7000") << endl;//true
 cout<<"**********"<<endl;
//DEL
//  cout<<bs->query("DEL 33 1234 5678")<<endl;
//  //cout<<bs->query("DEL 50 1234 5678")<<endl;
//  cout<<bs->query("DEL 19 1234 5678")<<endl;
//  cout<<bs->query("DEL 50 1234")<<endl;//1
//  cout<<bs->query("DEL 30")<<endl;//1
//  cout<< bs->query("INS 19 19D2-24F2 0 452 5678") << endl;
//  cout<<"**********"<<endl;
//CS
cout << "CS" << endl;
cout << bs->query("CS 99 1234") << endl;
 cout << bs->query("CS 50 2134") << endl;
 cout << bs->query("CS 50 2134 0") << endl;
 cout << bs->query("CS 50 2134 1") << endl;
 cout << bs->query("CS 33 2134") << endl;
 cout<<"**********"<<endl;
//CE
cout << "CE" << endl;
 cout << bs->query("CE 50 7500") << endl;
 cout << bs->query("CE 50 7500 0") << endl;
 cout << bs->query("CE 50 7500 1") << endl;
 cout << bs->query("CE 33 7500") << endl;
 cout<<"**********"<<endl;
//GS
cout << "GS" << endl;
  cout<<bs->query("GS 50 1000")<<endl;//don't have any bus start-->-1
  cout<<bs->query("GS 33 1000")<<endl;//don't have bussystem respectively
  cout<<bs->query("GS 50 4600 0")<<endl;//have bus with case=0
  cout<<bs->query("GS 50 4600 1")<<endl;//have bus with case=0
  cout<<bs->query("GS 50 4600")<<endl;//have bus with case=0,1
  cout<<"**********"<<endl;
//GE
cout << "GE" << endl;
  cout<<bs->query("GE 50 5000")<<endl;//don't have any bus end-->-1
  cout<<bs->query("GE 33 5000")<<endl;//don't have bussystem respectively
  cout<<bs->query("GE 50 7500 0")<<endl;
  cout<<bs->query("GE 50 7500 1")<<endl;
  cout<<bs->query("GE 50 7500")<<endl;*/

  /*BusSystem *bs = new BusSystem();
    cout << bs->query("SQ 30000") << '\n';

    cout << "------------------------------\n";
    clock_t begin = clock();
    for (int i = 1; i <= 30000; i++)
    {
        string ins = "INS 50 ";
        ins += to_string(i) + " " + to_string(i * 2) + " " + to_string(100000 + i * 2);
        bs->query(ins);
    }
    clock_t end = clock();
    cout << "INS execution time: " << (double)(end - begin) / CLOCKS_PER_SEC << '\n';
    cout << "------------------------------\n";

    begin = clock();
    cout << bs->query("CS 50 90000") << '\n';
    end = clock();
    cout << "CS execution time: " << (double)(end - begin) / CLOCKS_PER_SEC << '\n';
    cout << "------------------------------\n";

    begin = clock();
    cout << bs->query("CE 50 150000") << '\n';
    end = clock();
    cout << "CE execution time: " << (double)(end - begin) / CLOCKS_PER_SEC << '\n';
    cout << "------------------------------\n";

    begin = clock();
    cout << bs->query("GS 50 45000") << '\n';
    end = clock();
    cout << "GS execution time: " << (double)(end - begin) / CLOCKS_PER_SEC << '\n';
    cout << "------------------------------\n";

    begin = clock();
    cout << bs->query("DEL 50 1000 90000") << '\n';
    end = clock();
    cout << "DEL execution time: " << (double)(end - begin) / CLOCKS_PER_SEC << '\n';
    cout << "------------------------------\n";*/
//      BusSystem* bs = new BusSystem();
// 	cout << bs->query("SQ 5") << endl;
// 	cout << bs->query("INS 50 ABC 10 24") << endl;
// 	cout << bs->query("INS 50 ABC 0 30 35") << endl;
// 	cout << bs->query("INS 50 ABE 1 46 48") << endl;
// 	cout << bs->query("INS 50 ABF 1 52 55") << endl;
// 	cout << bs->query("INS 50 ABG 0 6 7") << endl;
// 	cout << bs->query("INS 50 ABH 1 8 9") << endl;
// 	cout << bs->query("INS 50 ABJ 0 9 15") << endl;
// 	cout << bs->query("INS 50 ABK 1 6 7") << endl;
// 	cout << bs->query("INS 50 ABL 0 7 15") << endl;
// 	cout << bs->query("INS 50 ABM 1 10 14") << endl;
// 	cout << bs->query("INS 49 ABZ 0 7 15") << endl;
// 	cout << bs->query("INS 49 ABK 1 10 14") << endl;
// 	cout << bs->query("CS 49 14") << endl;
//  }