#include <iostream>
#include <string>

using namespace std;

struct Book {
  string title;
  string author;
  
};


Book getBookDetails(const string& isbn) {
  const int MAX_BOOKS = 3;  
  Book library[MAX_BOOKS] = {
    {"The Hitchhiker's Guide to the Galaxy", "Douglas Adams"},
    {"Pride and Prejudice", "Jane Austen"},
    {"The Lord of the Rings", "J.R.R. Tolkien"}
  };


  for (int i = 0; i < MAX_BOOKS; ++i) {
    if (library[i].title == isbn) {
      return library[i];  
    }
  }


  return Book();
}

int main() {
  string isbn;

  cout << "Enter ISBN: ";
  cin >> isbn;

  Book book = getBookDetails(isbn);

  if (book.title.empty()) {
    cout << "Book not found in the library." << endl;
  } else {
    cout << "Book Found!" << endl;
    cout << "\tTitle: " << book.title << endl;
    cout << "\tAuthor: " << book.author << endl;
  }

  return 0;
}
