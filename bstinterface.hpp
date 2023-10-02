#ifndef BSTINTERFACE_HPP_INCLUDED
#define BSTINTERFACE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

#include "bst.hpp"

class BSTInterface {
        BST<int> bst;

        void insertData();
        void deleteData();
        void findData();

        void parsePreOrder();
        void parseInOrder();
        void parsePostOrder();

        void retrieveLowest();
        void retrieveHighest();

        void retrieveHeight();

        void exportData();
        void importData();

        void deleteAll();

    public:
        BSTInterface();
    };

#endif // BSTINTERFACE_HPP_INCLUDED
