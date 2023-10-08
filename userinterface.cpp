#include "userinterface.hpp"
using namespace std;

void UserInterface::addBook() {
  Book book;
  char op;
  int p;
  string str;

  do{
    system("cls");
    cout<<"*** Agregar Libro ***"<<endl<<endl<<"Título del libro: ";
    getline(cin, str);
    book.setTitle(str);

    cout<<"Autor: ";
    getline(cin, str);
    book.setAuthor(str);

    cout<<"Páginas: ";
    cin>>p;
    cin.ignore();
    book.setPages(p);

    cout<<endl;

    try{
      books->insertData(book);
    }catch(const typename BST<Book>::Exception& ex){
      cout<<"Algo salió mal: "<<ex.what()<<endl;
    }

    cout<<"Desea agregar otro libro? (s/n): ";
    cin>>op;
    op=toupper(op);
    cin.ignore();
  }while(op=='S');

  cout<<endl;

  if(op!='S' and op!='N') cout<<"Opción inválida!"<<endl;

  cout<<"Presione ENTER para continuar. . .";
  getchar();
}

void UserInterface::deleteBook() {
  Book book;
  string str;

  system("cls");
  cout<<"*** Eliminar libro ***"<<endl<<endl<<"Título del libro: ";
  getline(cin, str);
  book.setTitle(str);

  cout<<endl;

  try{
    BST<Book>::Position pos = books->findData(book);
    books->deleteData(pos);
  }catch(const typename BST<Book>::Exception& ex){
    cout<<"Algo salió mal: "<<ex.what()<<endl;
  }

  cout<<"Presione ENTER para continuar. . .";
  getchar();
}

void UserInterface::findBook() {
  Book book;
  string str;

  system("cls");
  cout<<"*** Buscar libro ***"<<endl<<endl<<"Título del libro: ";
  getline(cin, str);
  book.setTitle(str);

  cout<<endl<<"Registro encontrado:"<<endl;

  try{
    BST<Book>::Position pos = books->findData(book);
    cout << books->retrieve(pos).toString()<<endl;
  }catch(const typename BST<Book>::Exception& ex){
    cout<<"Algo salió mal: "<<ex.what()<<endl;
  }

  cout<<endl;

  cout<<"Presione ENTER para continuar. . .";
  getchar();
}

void UserInterface::recorridoPreOrder() {
  system("cls");
  cout <<"Recorrido Pre orden"<<endl
       <<endl
       <<books->parsePreOrder()<<endl
       <<endl
       <<"Presione ENTER para continuar. . .";
  getchar();
}

void UserInterface::recorridoInOrder() {
  system("cls");
  cout <<"Recorrido Pre orden"<<endl
       <<endl
       <<books->parseInOrder()<<endl
       <<endl
       <<"Presione ENTER para continuar. . .";
  getchar();
}

void UserInterface::recorridoPostOrder() {
  system("cls");
  cout <<"Recorrido Pre orden"<<endl
       <<endl
       <<books->parsePostOrder()<<endl
       <<endl
       <<"Presione ENTER para continuar. . .";
  getchar();
}

void UserInterface::deleteAllBooks() {
  books->deleteAll();

  cout <<"Datos eliminados correctamente!"<<endl
       <<endl
       <<"Presione ENTER para continuar. . .";
  getchar();
}

void UserInterface::importBackup() {
  string str;

  system("cls");
  cout <<"*** Recuperar datos de un archivo ***"<<endl
       <<endl
       <<"Nombre del archivo: ";
  getline(cin, str);

  cout<<endl;

  try{
    books->importFromFile(str);
    cout<<"Datos leídos correctamente!"<<endl;
  }catch(const ios_base::failure& ex){
    cout<<"Algo salió mal: "<<ex.what()<<endl;
  }

  cout<<"Presione ENTER para continuar. . .";
  getchar();
}

void UserInterface::exportBackup() {
  string str;

  system("cls");
  cout<<"*** Guardar datos a un archivo ***"<<endl
       <<endl
       <<"Nombre del archivo: ";
  getline(cin, str);

  cout<<endl;

  try{
    books->exportToFile(str);
    cout<<"Datos guardados correctamente!"<<endl;
  }catch(const ios_base::failure& ex){
    cout<<"Algo salió mal: "<<ex.what()<<endl;
  }

  cout<<"Presione ENTER para continuar. . .";
  getchar();
}

UserInterface::UserInterface() {
  unsigned short op;

  do{
    system("cls");
    cout<<"--- -- - M E N Ú - -- ---"<<endl
        <<endl
        <<"1. Agregar un libro"<<endl
        <<"2. Eliminar un libro"<<endl
        <<"3. Buscar un libro"<<endl
        <<"4. Recorrido Pre orden"<<endl
        <<"5. Recorrido In orden"<<endl
        <<"6. Recorrido Post orden"<<endl
        <<"7. Eliminar todos los libros"<<endl
        <<"8. Recuperar"<<endl
        <<"9. Guardar"<<endl
        <<"0. Salir"<<endl
        <<"Opción: ";
    cin>>op;
    cin.ignore();

    cout<<endl;

    switch(op){
      case 1:
        addBook();
        break;

      case 2:
        deleteBook();
        break;

      case 3:
        findBook();
        break;

      case 4:
        recorridoPreOrder();
        break;

      case 5:
        recorridoInOrder();
        break;

      case 6:
        recorridoPostOrder();
        break;

      case 7:
        deleteAllBooks();
        break;

      case 8:
        importBackup();
        break;

      case 9:
        exportBackup();
        break;

      case 0:
        cout<<"Gracias por usar el programa :)"<<endl;
        break;

      default:
        cout<<"Opción inválida!"<<endl
            <<"Presione ENTER para continuar. . .";
        getchar();
        break;
    }
  }while(op != 0);
}

UserInterface::~UserInterface() {
  delete books;
}
