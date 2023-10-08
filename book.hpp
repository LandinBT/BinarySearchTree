#ifndef BOOK_HPP_INCLUDED
#define BOOK_HPP_INCLUDED

#include <iostream>
#include <string>

class Book {
  std::string title;
  std::string author;
  int pages;

 public:
  Book();
  Book(const Book&);

  Book& operator=(const Book&);

  std::string getTitle() const;
  std::string getAuthor() const;
  int getPages() const;

  std::string toString() const;

  void setTitle(const std::string&);
  void setAuthor(const std::string&);
  void setPages(const int&);

  bool operator==(const Book&) const;
  bool operator!=(const Book&) const;
  bool operator<(const Book&) const;
  bool operator<=(const Book&) const;
  bool operator>(const Book&) const;
  bool operator>=(const Book&) const;

  friend std::istream& operator>>(std::istream&, Book&);
  friend std::ostream& operator<<(std::ostream&, const Book&);
};

#endif  // BOOK_HPP_INCLUDED
