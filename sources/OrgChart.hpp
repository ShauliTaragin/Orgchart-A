//
// Created by shaul on 09/05/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace ariel{
//    template <class T>
    class OrgChart{
        struct Node{
            string data;
            vector<Node *> sons;
            Node * father;
            Node(string info): data(info) , father(nullptr){}
        };

        Node * root;
    public:
        OrgChart(){
            root = nullptr;
        };
        OrgChart & add_root(string data);
        OrgChart & add_sub(string parent_data , string son_data);


        friend std::ostream& operator<< (std::ostream& output, const OrgChart& chart);


        //-------------------------------------------------------------------
        // Create a iterator sub_class which will be implemented by inner class
        //-------------------------------------------------------------------
        class iterator {
        private:
            Node * pointer_to_node;
        public:
            iterator(Node * ptr = nullptr):pointer_to_node(ptr){}

            string& operator*() const {
                //return *pointer_to_current_node;
                return pointer_to_node->data;
            }

            string* operator->() const {
                return &(pointer_to_node->data);
            }

            // ++i;
            iterator& operator++() {
                //not sure how to do this operator
                //pointer_to_node = pointer_to_node->sons[0];
                return *this;
            }

            bool operator==(const iterator& rhs) const {
                return pointer_to_node == rhs.pointer_to_node;
            }

            bool operator!=(const iterator& rhs) const {
                return pointer_to_node != rhs.pointer_to_node;
            }
        };
        iterator begin_level_order();
        iterator end_level_order();
        iterator begin_reverse_order();
        iterator reverse_order();
        iterator begin_preorder();
        iterator end_preorder();
    };

}

