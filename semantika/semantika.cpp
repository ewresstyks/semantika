#include <iostream>
#include <string>
using namespace std;


class Book {
    char* a;
    char* t;
    int p;
    int y;
public:
    Book() = default;
    Book(const char* _aut, const char* _text, int _pg, int _y)
    {
        a = new char[strlen(_aut) + 1];
        strcpy_s(a, strlen(_aut) + 1, _aut);
        t = new char[strlen(_text) + 1];
        strcpy_s(t, strlen(_text) + 1, _text);
        p = _pg;
        y = _y;
    }
    Book& operator=(const Book& obj) = delete;
    Book(Book& obj) = delete;
    Book& operator=(Book&& obj)
    {
        a = obj.a;
        t = obj.t;
        p = obj.p;
        y = obj.y;
        obj.a = nullptr;
        obj.t = nullptr;
        obj.p = 0;
        obj.y = 0;
        return*this;
    }
    Book(Book&& obj)
    {
        a = obj.a;
        t = obj.t;
        p = obj.p;
        y = obj.y;
        obj.a = nullptr;
        obj.t = nullptr;
        obj.p = 0;
        obj.y = 0;
    }

    void Print() {
        cout << a << endl << t << endl << p << endl << y << endl;
    }
};


int main()
{
    Book a("Lalala", "hipe", 1, 2);

    Book d = move(a);
    d.Print();

}