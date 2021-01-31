#include<iostream>
#include<cstring>
#include<cmath>
#include <fstream>

using namespace std;
class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        this->title = NULL;
        this->authors = NULL;
        this->publishingYear = 0;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        this->title = new char[strlen(title)+1]; //cstring not string
        this->authors = new char[strlen(authors)+1];
        strcpy(this->title, title);
        strcpy(this->authors, authors);
        this->publishingYear = publishingYear;

    }

    Book(const Book &book)
    {
        this->title = new char[strlen(book.title)+1]; //cstring not string
        this->authors = new char[strlen(book.authors)+1];
        strcpy(this->title, book.title);
        strcpy(this->authors, book.authors);
        this->publishingYear = book.publishingYear;
    }
    
    void setTitle(const char* title)
    {
        this->title = new char[strlen(title)+1]; //cstring not string
        strcpy(this->title, title);
    }

    void setAuthors(const char* authors)
    {
        this->authors = new char[strlen(authors)+1]; //cstring not string
        strcpy(this->authors, authors);
    }

    void setPublishingYear(int publishingYear)
    {
        this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        return this->title;
    }

    char* getAuthors() const
    {
        return this->authors;
    }

    int getPublishingYear() const
    {
        return this->publishingYear;
    }

    ~Book()
    {
        delete[] title;
        delete[] authors;
        publishingYear = 0;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};

int main(){
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
    Book book2 = book1;
    book2.printBook();
    return 0;
}



/*
for (int i = 0; i < (int)(strlen(book.authors)); i++) {
            if (*(author + 0) == book.authors[i]) {
                for (int j = i+1, k=1; j < (int)(strlen(book.authors)); j++, k++) {
                    if (book.authors[j] != ',') {
                        if ((int)strlen(author) < k + 1) return false;
                        if (*(author + k) != book.authors[j]) return false;
                    }
                    else return true;
                }
            }
        }
        return false;
*/
