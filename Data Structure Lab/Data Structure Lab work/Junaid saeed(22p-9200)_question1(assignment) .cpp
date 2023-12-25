#include <iostream>
using namespace std;

class date 
{
public:
    int day, month, year;

    date(int d, int m, int y) 
	{
        this->day = d;
        this->month = m;
        this->year = y;
    }
};

struct book 
{
    string isbn;
    string author;
    string title;
    string genre;
    date publication;
    book* next;
    book* prev;

    book(string isbn, string auth, string tit, string gen, date date) : publication(date)
	 {
        this->next = nullptr;
        this->prev = nullptr;
        this->author = auth;
        this->genre = gen;
        this->isbn = isbn;
        this->title = tit;
    }
};

class booklink 
{
private:
    book* head;
    book* tail;

public:
    booklink() 
	{
        this->head = nullptr;
        this->tail = nullptr;
    }

    void addBook(string isbn, string author, string title, string genre, date date) 
	{
        book* newBook = new book(isbn, author, title, genre, date);

        if (head == nullptr) 
		{
            head = tail = newBook;
        } 
		else 
		{
            book* current = head;
            while (current != nullptr && current->publication.year < date.year) 
			{
                current = current->next;
            }
            if (current == head) 
			{
                newBook->next = head;
                head->prev = newBook;
                head = newBook;
            }
			 else if (current == nullptr) 
			 {
                tail->next = newBook;
                newBook->prev = tail;
                tail = newBook;
            }
			 else 
			 {
                newBook->prev = current->prev;
                newBook->next = current;
                current->prev->next = newBook;
                current->prev = newBook;
            }
        }
    }

    book* search(string key) 
	{
        book* current = head;
        while (current != nullptr) 
		{
            if (current->isbn == key || current->title == key) 
			{
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void display()
	 {
        book* current = head;
        while (current != nullptr) 
		{
            cout << "ISBN: " << current->isbn << ", Title: " << current->title << ", Author: " << current->author << ", Genre: " << current->genre << ", Publication Date: " << current->publication.year << "/" << current->publication.month << "/" << current->publication.day << endl;
            current = current->next;
        }
    }

    void filter(string authorName) 
	{
        book* current = head;
        bool found = false;
        while (current != nullptr) 
		{
            if (current->author == authorName) 
			{
                found = true;
                cout << "ISBN: " << current->isbn << ", Title: " << current->title << ", Author: " << current->author << ", Genre: " << current->genre << ", Publication Date: " << current->publication.year << "/" << current->publication.month << "/" << current->publication.day << endl;
            }
            current = current->next;
        }
        if (!found)
		 {
            cout << "No books found for author: " << authorName << endl;
        }
    }

    void recommend(string bookName) 
	{
        book* current = head;
        int count = 0;
        while (current != nullptr && count < 3) 
		{
            if (current->title != bookName && current->genre == search(bookName)->genre) 
			{
                cout << "Recommended Book - ISBN: " << current->isbn << ", Title: " << current->title << ", Author: " << current->author << ", Genre: " << current->genre << ", Publication Date: " << current->publication.year << "/" << current->publication.month << "/" << current->publication.day << endl;
                count++;
            }
            current = current->next;
        }
    }

    void del(string isbn) 
	{
        book* current = head;
        while (current != nullptr) 
		{
            if (current->isbn == isbn) 
			{
                if (current == head) 
				{
                    head = head->next;
                    if (head != nullptr) 
					{
                        head->prev = nullptr;
                    }
                } 
				else if (current == tail) 
				{
                    tail = tail->prev;
                    tail->next = nullptr;
                } 
				else 
				{
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Book with ISBN " << isbn << " deleted successfully." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Book with ISBN " << isbn << " not found." << endl;
    }
};

int main() 
{
    booklink b;
    int choice;
      cout << "\t\t\t\t\t Book Management System Menu:" << endl;
    do 
	{
        cout<<endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\t1. Add a New Book" << endl;
        cout << "\t\t\t2. Search for a Book" << endl;
        cout << "\t\t\t3. Display Books" << endl;
        cout << "\t\t\t4. Filter Books by Author" << endl;
        cout << "\t\t\t5. Recommend Related Books" << endl;
        cout << "\t\t\t6. Delete a Book" << endl;
        cout << "\t\t\t7. Exit" << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
		{
            case 1: {
                string isbn, author, title, genre;
                int day, month, year;
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Genre: ";
                getline(cin, genre);
                cout << "Enter Publication Date (Day Month Year): ";
                cin >> day >> month >> year;
                date date(day, month, year);
                b.addBook(isbn, author, title, genre, date);
                cout << "Book added successfully!" << endl;
                break;
            }
            case 2: 
			{
                string searchKey;
                cout << "Enter ISBN or Title to search: ";
                getline(cin, searchKey);
                book* foundBook = b.search(searchKey);
                if (foundBook != nullptr) 
				{
                    cout << "Book found - ISBN: " << foundBook->isbn << ", Title: " << foundBook->title << ", Author: " << foundBook->author << ", Genre: " << foundBook->genre << ", Publication Date: " << foundBook->publication.year << "/" << foundBook->publication.month << "/" << foundBook->publication.day << endl;
                } 
				else 
				{
                    cout << "Book not found." << endl;
                }
                break;
            }
            case 3: 
			{
                cout << "Displaying all books:" << endl;
                b.display();
                break;
            }
            case 4: {
                string authorName;
                cout << "Enter author's name to filter books: ";
                getline(cin, authorName);
                b.filter(authorName);
                break;
            }
            case 5: 
			{
                string bookName;
                cout << "Enter book name to recommend related books: ";
                getline(cin, bookName);
                b.recommend(bookName);
                break;
            }
            case 6: 
			{
                string isbn;
                cout << "Enter ISBN of the book to delete: ";
                getline(cin, isbn);
                b.del(isbn);
                break;
            }
            case 7:
            	{
            	  cout << "Thank you!" << endl;
                  break;
				}
               
            default:
            	{
            		cout << "Invalid choice." << endl;
				}
                
        }
    } 
	while (choice != 7);
}

