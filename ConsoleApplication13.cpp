#include <iostream>   
#include <vector>   

using namespace std;

enum BookType
{
    ART,
    TECH
};

class Book
{
    const string _author; //_author 
    const string _name;
    const BookType _type;
public:
    Book(const string& author, const string& name, BookType type) : _author(author), _name(name), _type(type) {}//const string& author 

    BookType GetType()const { return _type; }
    string GetAuthor() const { return _author; }
    string GetName() const { return _name; }

    void Print() const
    {
        cout << _author << " " << _name << " ";
        if (_type == ART)
            cout << "(Art)";
        else if (_type == TECH)
            cout << "(Tech)";
        cout << endl;
    }
};

void quantity(const vector<Book*>& library) { //количество книг 
    int art_k = 0;
    int tech_k = 0;

    for (int i = 0; i < library.size(); i++)
    {
        switch (library[i]->GetType())
        {
        case ART:
            art_k++;
            break;
        case TECH:
            tech_k++;
            break;
        }
    }
    cout << "art books: " << art_k << endl;
    cout << "tech books: " << tech_k << endl;

}

void quantity1(const vector<Book*>& library) { //количество книг 
    int art_c = 0;
    int tech_c = 0;

    for (int i = 0; i < library.size(); i++)
    {
        if (library[i]->GetType() == ART)
            art_c++;
        else if (library[i]->GetType() == TECH)
            tech_c++;
    }
    cout << "art books:" << art_c << endl;
    cout << "tech books:" << tech_c << endl;
}


int main() {
    vector<Book*> library =
    {
     new Book("pride and prejudice", "Jane Austen", ART),
     new Book("Jack London", "White Fang", ART),
     new Book("Jack Schwager", "technical analysis", TECH),
     new Book("Yashchenko", "introduction to cryptography", TECH),
    };

    for (int i = 0; i < library.size(); i++)
    {
        if (library[i]->GetAuthor().empty() || library[i]->GetName().empty()) {
            delete library[i];
            library[i] = nullptr;
        }
        library[i]->Print();
    }

    quantity(library);
    quantity(library);

    for (int i = 0; i < library.size(); i++)
    {
        delete library[i];
    }

    return 0;
}