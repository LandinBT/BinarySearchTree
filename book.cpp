#include "book.hpp"
using namespace std;

Book::Book() {}

Book::Book(const Book& b) : title(b.title), author(b.author), pages(b.pages) {}

Book& Book::operator=(const Book& b) {
  title = b.title;
  author = b.author;
  pages = b.pages;

  return *this;
}

string Book::getTitle() const { return title; }

string Book::getAuthor() const { return author; }

int Book::getPages() const { return pages; }

string Book::toString() const {
  return title + " | " + author + " | " + to_string(pages);
}

void Book::setTitle(const string& t) { title = t; }

void Book::setAuthor(const string& a) { author = a; }

void Book::setPages(const int& p) { pages = p; }

bool Book::operator==(const Book& b) const { return title == b.title; }

bool Book::operator!=(const Book& b) const { return !(*this == b); }

bool Book::operator<(const Book& b) const { return title < b.title; }

bool Book::operator<=(const Book& b) const { return *this < b or *this == b; }

bool Book::operator>(const Book& b) const { return !(*this <= b); }

bool Book::operator>=(const Book& b) const { return !(*this < b); }

istream& operator>>(istream& is, Book& b) {
  string str;

  getline(is, b.title, '*');
  getline(is, b.author, '*');
  getline(is, str, '#');
  b.pages = stoi(str);

  return is;
}

ostream& operator<<(ostream& os, const Book& b) {
  os << b.title << "*" << b.author << "*" << b.pages << "#";

  return os;
}
