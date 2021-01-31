#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         */
        this->title = NULL;
        this->authors = NULL;
        this->publishingYear = 0;
    }

    Book(const char *title, const char *authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = new char[strlen(title)+1]; //cstring not string
        this->authors = new char[strlen(authors)+1];
        strcpy(this->title, title);
        strcpy(this->authors, authors);
        this->publishingYear = publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete[] title;
        delete[] authors;
        publishingYear = 0;
    }

    friend class Printer;
};

class Printer 
{
public:
    static void printBook(const Book book) {
        cout << book.title << endl;
        string temp = "";
        for (int i = 0; i < (int)strlen(book.authors); i++) {
            if (book.authors[i] == ' ' && book.authors[i - 1] == ',') continue;
            if (book.authors[i] != ',') {
                temp += book.authors[i];
            }
            if (book.authors[i] == ',' || i == (int)strlen(book.authors) - 1) {
                cout << temp << endl;
                temp = "";
            }
        }
        cout << book.publishingYear << endl;
    }
};
int main() 
{
    Book book1("Giai tich 1","Nguyen Dinh Huy, Nguyen Thi Xuan Anh, Nguyen Dinh Huy Khac",2000);
    Printer::printBook(book1);
    return 0;
}