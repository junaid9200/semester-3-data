#include<iostream>
using namespace std;

class Date{
	public:
	int day;
	int month;
	int year;
	
	Date(int day, int month, int year){
		this->day = day;
		this->month = month;
		this->year = year;
	}
};

class Book{
	public:
	int isbn_number;
	string author;
	string title;
	string genre;
	Date publication_date;
	
	Book(int isbn_number, string author, string title, string genre, Date date): publication_date(date){
		this->isbn_number = isbn_number;
		this->author = author;
		this->title = title;
		this->genre = genre;		
	}
};

class Node{
	public:
	Book book;
	Node* next_ptr;
	Node* pre_ptr;
	
	Node(Book obj): book(obj){
		// constructor
	}	
};

class class_functions{
	public:
	Node* head;
	Node* current;
	
	class_functions(){
		head = nullptr;
		current = nullptr;
	}
	
	void Add_New_Book(){
		string title, author, genre;
		int isbn_number, day, month, year;
		cin.ignore(25,'\n');
		cout << "Enter Book Title: ";
		getline(cin, title);
		cout << "Enter Book Author: ";
		getline(cin, author);
		cout << "Enter Book Genre: ";
		getline(cin, genre);
		cout << "Enter Book ISBN: ";
		cin >> isbn_number;
		cout << "Enter Book Publication-Date (MM DD YYYY)" <<endl;
		cin >> day >> month >> year;
		
		Date date(day, month, year);
		Book new_book(isbn_number, author, title, genre, date);
		
		insert_book_data(new_book);
	}
	
	void insert_book_data(Book new_book){
		Node* new_node = new Node(new_book);
		
		if(head == nullptr){
	    	head = new_node;
		}
		else{
			current = head;
			while(current->next_ptr != nullptr){
				current = current->next_ptr;
			}
			current->next_ptr = new_node;
			new_node->pre_ptr = current;
			current = new_node;
		}
		
		cout << "Book Successfully Added In Data-Base !" <<endl;
	}
	
	void Search_Book(){
		int isbn_to_search;
		bool found = false;
		cout << "Enter The Book's ISBN Number: ";
		cin >> isbn_to_search;
		
		current = head;
		while(current != nullptr){
			if(current->book.isbn_number == isbn_to_search){
				found = true;
				break;
			}
			current = current->next_ptr;
		}
		if(found){
			cout << "Book Found In Data-Base !" <<endl;
		}
		else{
			cout << "Book Not Found In Data-Base !" <<endl;
		}
	}
	
	void display_Book_detail(){
		int book_no = 1;
		current = head;
		while(current != nullptr){
			cout << endl;
			cout << "Book No: " << book_no <<endl;
			cout << "Book-Title: " << current->book.title <<endl;
			cout << "Book-Author: " << current->book.author <<endl;
			cout << "Book-Genre: " << current->book.genre <<endl;
			cout << "Book-ISBN: " << current->book.isbn_number <<endl;
			cout << "Book-Publication-Date: " << current->book.publication_date.day <<"-"<< current->book.publication_date.month <<"-"<< current->book.publication_date.year <<endl;
			current = current->next_ptr;
			book_no++;
		}
	}
	
	void Book_filter(){
		string author_to_search;
		bool found = false;
		cout << "Enter The Author Name: ";
		cin.ignore(25,'\n');
		getline(cin, author_to_search);
		
		current = head;
		while(current != nullptr){
			if(current->book.author == author_to_search){
				display_Book(current->book);
				found = true;
			}
			current = current->next_ptr;
		}
		if(!found){
			cout << "No Books Found With Author Name: " << author_to_search <<endl;
		}
	}
	
	void Recommended_Book(){
		string title_to_search, genre_to_search;
		int count = 1;
		bool found = false;
		cout << "Enter The Book Title: ";
		cin.ignore(25,'\n');
		getline(cin, title_to_search);
		
		current = head;
		while(current != nullptr){
			if(current->book.title == title_to_search){
				genre_to_search = current->book.genre;
				break;
			}
			current = current->next_ptr;
		}
		
		while(current != nullptr && count <= 3){
			if(current->book.genre == genre_to_search){
				display_Book(current->book);
				found = true;
			}
			current = current->next_ptr;
			count++;
		}
		
		if(!found){
			cout << "Cannot Find Related Books..." <<endl;
		}	
	}
	
	void display_Book(Book book){
			cout << endl;
			cout << "Book-Title: " << book.title <<endl;
			cout << "Book-Author: " << book.author <<endl;
			cout << "Book-Genre: " << book.genre <<endl;
			cout << "Book-ISBN: " << book.isbn_number <<endl;
			cout << "Book-Publication-Date: " << book.publication_date.day <<"-"<< book.publication_date.month <<"-"<< book.publication_date.year <<endl;
	}
	
	void Delete_Book(){
		Node* to_delete = nullptr;
		int isbn_to_delete;
		bool found = false;
		cout << "Enter The Book ISBN To Delete: ";
		cin >> isbn_to_delete;
		
		current = head;
		while(current != nullptr){
			if(current->book.isbn_number == isbn_to_delete){
				to_delete = current;
				found = true;
				break;
			}
			current = current->next_ptr;
		}
		
		if(found){
			if(head == to_delete){
				head = to_delete->next_ptr;
			}
			Node* temp = to_delete->pre_ptr;
			Node* temp2 = to_delete->next_ptr;
			temp->next_ptr = temp2;
			temp2->pre_ptr = temp;
			
			delete to_delete;	
		}
		else{
			cout << "Cannot Find The Book With ISBN..." <<endl;
		}
	}
};
int main(){
	int user_input;
	class_functions obj;
	while(true){
		cout << endl;
		cout << "**C-City-EBook-System**" <<endl;
		cout << "1. Add New Book." <<endl;
		cout << "2. Search Book(ISBN)." <<endl;
		cout << "3. Display Book." <<endl;
		cout << "4. Filter Books By Author." <<endl;
		cout << "5. Recommend-Related-Books." <<endl;
		cout << "6. Delete Book." <<endl;
		cout << "7. Exit." <<endl;
		cout << "Your-Input: ";
		cin >> user_input;
		switch(user_input){
			case 1:
				cout << endl;
				cout << "Enter The Following Details." <<endl;
				obj.Add_New_Book();
				break;
			case 2:
				cout << endl;
				cout << "Enter The Following Details." <<endl;
				obj.Search_Book();
				break;
			case 3:
				cout << endl;
				cout << "Displaying Books Details." <<endl;
				obj.display_Book_detail();
				break;
			case 4:
				cout << endl;
				cout << "Displaying Books VIA Author Filter." <<endl;
				obj.Book_filter();
				break;
			case 5:
				cout << endl;
				cout << "Displaying Related Books." <<endl;
				obj.Recommended_Book();
				break;
			case 6:
				cout << endl;
				cout << "Deleting Book." <<endl;
				obj.Delete_Book();
				break;
			case 7:
				cout << "Thanks For Choosing Ccity-Service. See You Soon !" <<endl;
				return false;
			default:
				cout << "Invalid Input To Generate A Response, Please Try Again." <<endl;	
		}
	}
	return 0;
}
