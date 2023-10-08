#ifndef USERINTERFACE_HPP_INCLUDED
#define USERINTERFACE_HPP_INCLUDED

#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "book.hpp"
#include "bst.hpp"

class UserInterface {
  BST<Book>* books;

  void addBook();
  void deleteBook();
  void findBook();

  void recorridoPreOrder();
  void recorridoInOrder();
  void recorridoPostOrder();

  void deleteAllBooks();

  void importBackup();
  void exportBackup();

 public:
  UserInterface();
  ~UserInterface();
};

#endif  // USERINTERFACE_HPP_INCLUDED
