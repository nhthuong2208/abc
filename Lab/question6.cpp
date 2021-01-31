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

    friend bool checkAuthor(Book book, const char* author)
    {
        /*
         * STUDENT ANSWER
         * TODO: returns true if the author is on the book's authors list, otherwise it returns false
         */
        string temp;
        bool x = false;
        for (int i = 0; i < (int)strlen(book.authors); i++) {
            if (book.authors[i - 1] == ',' && book.authors[i] == ' ') continue;
            if (book.authors[i] != ',') {
                temp += book.authors[i];
            }
            if (book.authors[i] == ',' || i == (int)strlen(book.authors) - 1) {
                for (int j = 0; j < (int)(temp.length()); j++) {
                    if (*(author + j) != temp[j]) {
                        x = true;
                        break;
                    }
                }
                if (!x) {
                    return true;
                }
                else {
                    x = false;
                    temp = "";
                }
            }
        }
        return false;
    }
};
int main() 
{
    Book book1("Giai tich 1","Nguyen Dinh Huy, Nguyen Thi Xuan Anh, Nguyen Dinh Huy Khac",2000);
cout << checkAuthor(book1,"Nguyen Dinh Huy Khac");
    return 0;
}