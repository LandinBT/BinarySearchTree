#ifndef BST_HPP_INCLUDED
#define BST_HPP_INCLUDED

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <stack>
#include <sstream> //istringstream

template<class T>
class BST { //BinarySearchTree
        class Node;

    public:
        typedef Node* Position;

    private:
        class Node {
                T* dataPtr;
                Position left;
                Position right;

            public:
                class Exception : public std::exception {
                    public:
                        Exception(const std::string& message) : msg(message) {}
                        const char* what() const noexcept override {
                            return msg.c_str();
                            }

                    private:
                        std::string msg;
                    };

                Node();
                Node(const T&);

                ~Node();

                T* getDataPtr() const;
                T getData() const;
                Position& getLeft();
                Position& getRight();

                void setDataPtr(T*);
                void setData(const T&);
                void setLeft(Position&);
                void setRight(Position&);
            };

        Position root;

        void copyAll(const BST<T>&);

        void insertData(Position&, const T&);

        Position getRoot() {
            return root;
            }

        Position& findData(Position&, const T&);
        Position& getLowest(Position&);
        Position& getHighest(Position&);

        std::string parsePreOrder(Position&);
        std::string parseInOrder(Position&);
        std::string parsePostOrder(Position&);

    public:
        class Exception : public std::exception {
            public:
                Exception(const std::string& message) : msg(message) {}
                const char* what() const noexcept override {
                    return msg.c_str();
                    }

            private:
                std::string msg;
            };

        BST();
        BST(const BST&);

        BST& operator=(const BST&);

        ~BST();

        bool isEmpty() const;

        bool isLeaf(Position&) const;

        void insertData(const T&);
        void deleteData(Position&);

        Position& findData(const T&);
        Position& getLowest();
        Position& getHighest();

        T retrieve(Position&) const;

        int getHeight(Position&);
        int getHeight();

        std::string parsePreOrder();
        std::string parseInOrder();
        std::string parsePostOrder();

        void importFromFile(const std::string&);
        void exportToFile(const std::string&);

        void deleteAll();
    };

///IMPLEMENTATION
using namespace std;

/*Node*/
template <class T>
BST<T>::Node::Node() : dataPtr(nullptr), left(nullptr), right(nullptr) {}

template <class T>
BST<T>::Node::Node(const T& d)
    : dataPtr(new T(d)), left(nullptr), right(nullptr) {
    if (dataPtr == nullptr) {
        throw Exception("Memoria insuficiente, createNode");
        }
    }

template <class T>
BST<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T* BST<T>::Node::getDataPtr() const {
    return dataPtr;
    }

template <class T>
T BST<T>::Node::getData() const {
    if (dataPtr == nullptr) {
        throw Exception("Dato inexistente, getData");
        }

    return *dataPtr;
    }

template <class T>
typename BST<T>::Position& BST<T>::Node::getLeft() {
    return left;
    }

template <class T>
typename BST<T>::Position& BST<T>::Node::getRight() {
    return right;
    }

template <class T>
void BST<T>::Node::setDataPtr(T* ptr) {
    dataPtr = ptr;
    }

template <class T>
void BST<T>::Node::setData(const T& d) {
    if (dataPtr == nullptr) {
        if ((dataPtr = new T(d)) == nullptr) {
            throw Exception("Memoria no disponible, setData");
            }
        }
    else {
        *dataPtr = d;
        }
    }

template <class T>
void BST<T>::Node::setLeft(Position& pos) {
    left = pos;
    }

template <class T>
void BST<T>::Node::setRight(Position& pos) {
    right = pos;
    }

/*BST*/
// private
template <class T>
void BST<T>::copyAll(const BST<T>& tree) {
    if (tree.root != nullptr) {
        root = new Node(*(tree.root));
        }
    }

template <class T>
void BST<T>::insertData(Position& pos, const T& d) {
    if (pos == nullptr) {
        try {
            if ((pos = new Node(d)) == nullptr) {
                throw Exception("Memoria no disponible, insertData");
                }
            }
        catch (typename Node::Exception& ex) {
            throw Exception(ex.what());
            }
        }
    else {
        if (d < pos->getData()) {
            insertData(pos->getLeft(), d);
            }
        else {
            insertData(pos->getRight(), d);
            }
        }
    }

template <class T>
typename BST<T>::Position& BST<T>::findData(Position& r, const T& d) {
    if (r == nullptr or r->getData() == d) {
        return r;
        }

    if (d < r->getData()) {
        return findData(r->getLeft(), d);
        }

    return findData(r->getRight(), d);
    }

template <class T>
typename BST<T>::Position& BST<T>::getLowest(Position& r) {
    if (r == nullptr or r->getLeft() == nullptr) {
        return r;
        }

    return getLowest(r->getLeft());
    }

template <class T>
typename BST<T>::Position& BST<T>::getHighest(Position& r) {
    if (r == nullptr or r->getRight() == nullptr) {
        return r;
        }

    return getHighest(r->getRight());
    }

template <class T>
string BST<T>::parsePreOrder(Position& r) {
    if (r == nullptr) {
        return "Vacío";
        }

    string str = r->getData().toString();
    str += "\n";
    str += parsePreOrder(r->getLeft());
    str += parsePreOrder(r->getRight());

    return str;
    }

template <class T>
string BST<T>::parseInOrder(Position& r) {
    if (r == nullptr) {
        return "Vacío";
        }

    string str;
    str += parseInOrder(r->getLeft());
    str += r->getData().toString();
    str += "\n";
    str += parseInOrder(r->getRight());

    return str;
    }

template <class T>
string BST<T>::parsePostOrder(Position& r) {
    if (r == nullptr) {
        return "Vacío";
        }

    string str;
    str += parsePostOrder(r->getLeft());
    str += parsePostOrder(r->getRight());
    str += r->getData().toString();
    str += "\n";

    return str;
    }

// public
template <class T>
BST<T>::BST() : root(nullptr) {}

template <class T>
BST<T>::BST(const BST& tree) : root(nullptr) {
    copyAll(tree);
    }

template <class T>
BST<T>& BST<T>::operator=(const BST& tree) {
    deleteAll();
    copyAll(tree);

    return *this;
    }

template <class T>
BST<T>::~BST() {
    deleteAll();
    }

template <class T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
    }

template <class T>
bool BST<T>::isLeaf(Position& pos) const {
    return pos != nullptr and pos->getLeft() == pos->getRight();
    }

template <class T>
void BST<T>::insertData(const T& d) {
    insertData(root, d);
    }

template <class T>
void BST<T>::deleteData(Position& pos) {
    if (pos == nullptr) {
        return;
        }

    if (isLeaf(pos)) {
        delete pos;
        pos = nullptr;
        }
    else if (pos->getLeft() != nullptr && pos->getRight() != nullptr) {
        Position& lowestRight = getLowest(pos->getRight());
        pos->setData(lowestRight->getData());
        deleteData(lowestRight);
        }
    else {
        Position temp = (pos->getLeft() != nullptr) ? pos->getLeft() : pos->getRight();
        delete pos;
        pos = temp;
        }
    }

template <class T>
typename BST<T>::Position& BST<T>::findData(const T& d) {
    return findData(root, d);
    }

template <class T>
typename BST<T>::Position& BST<T>::getLowest() {
    return getLowest(root);
    }

template <class T>
typename BST<T>::Position& BST<T>::getHighest() {
    return getHighest(root);
    }

template <class T>
T BST<T>::retrieve(Position& pos) const {
    return pos->getData();
    }

template <class T>
int BST<T>::getHeight(Position& r) {
    if (r == nullptr) {
        return 0;
        }

    int leftHeight(getHeight(r->getLeft()));
    int rightHeight(getHeight(r->getRight()));

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

template <class T>
int BST<T>::getHeight() {
    return getHeight(root);
    }

template <class T>
string BST<T>::parsePreOrder() {
    return parsePreOrder(root);
    }

template <class T>
string BST<T>::parseInOrder() {
    return parseInOrder(root);
    }

template <class T>
string BST<T>::parsePostOrder() {
    return parsePostOrder(root);
    }

template <class T>
void BST<T>::importFromFile(const string& fileName) {
    ifstream myFile(fileName);

    if(!myFile) {
        throw Exception("No se pudo abrir el archivo, importFromFile");
        }

    deleteAll();

    string str;
    stack<Position> stackPos;
    Position temp=nullptr;
    bool isLeftChild=true;

    while(getline(myFile, str, '|')) {
        if(str=="#") {
            if(!stackPos.empty()) {
                temp=stackPos.top();
                stackPos.pop();
                isLeftChild=false;
                }
            }
        else {
            T data;
            istringstream(str)>>data;

            if(temp==nullptr) {
                insertData(data);
                temp=root;
                }
            else {
                Position newNode=new Node(data);

                if(isLeftChild) {
                    temp->setLeft(newNode);
                    }
                else {
                    temp->setRight(newNode);
                    }
                stackPos.push(temp);
                temp=newNode;
                isLeftChild=true;
                }
            }
        }
    }

template <class T>
void BST<T>::exportToFile(const string& fileName) {
    ofstream myFile(fileName);

    if(!myFile) {
        throw Exception("No se pudo abrir el archivo");
        }

    if(root==nullptr) {
        myFile<<"Vacio"; //empty
        return;
        }

    stack<Position> stackPos;
    Position temp=root;
    bool firstNode=true;

    while(temp!=nullptr or !stackPos.empty()) {
        while(temp!=nullptr) {
            if(!firstNode) {
                myFile<<'|';
                }

            myFile<<temp->getData();
            stackPos.push(temp);
            temp=temp->getLeft();
            firstNode=false;
            }

        myFile<<"#";

        if(!stackPos.empty()) {
            temp=stackPos.top();
            stackPos.pop();
            temp=temp->getRight();
            }
        }
    }

template <class T>
void BST<T>::deleteAll() {
    while (root != nullptr) {
        deleteData(root);
        }
    }

#endif // BST_HPP_INCLUDED
