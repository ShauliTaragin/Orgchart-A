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
            Node(string & info): data(info) , father(nullptr){}
        };

        Node * root;
    public:
        OrgChart(){
            root = nullptr;
        };
        /**
         * Base function to add/change root of organizational tree
         * @param root_data -> receive the data to input in the tree
         * @return this instance so we can chain actions
         */
        OrgChart & add_root(string & root_data){
            //if the org chart is empty
            if(root == nullptr){
                Node new_root = Node(root_data);
                root = & new_root;
            }
            //there is a root already in the orgchart
            else{
                //change the data of the root
                root->data = root_data;
            }
            return *this;
        }
        OrgChart & add_sub(string parent_data , string son_data);


        friend std::ostream& operator<< (std::ostream& output, const OrgChart& chart);


        //-------------------------------------------------------------------
        // Create a iterator sub_class which will be implemented by inner class
        //-------------------------------------------------------------------
        class iterator {
            // 0 is level order
            // 1 is reverse level order
            // 2 is preorder
        private:
            Node * pointer_to_node;
            int order_type;
        public:
            iterator(Node * ptr = nullptr , int order= 1):
            pointer_to_node(ptr) , order_type(order) {}

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
                // i think i will have to work with getting the index of the son somehow
                //pointer_to_node = pointer_to_node->sons[0];
                if(order_type == 0 ){//level order

                }
                else if(order_type ==1){//reverse level order

                }
                else{//preorder

                }
                return *this;
            }

            bool operator==(const iterator& rhs) const {
                return pointer_to_node == rhs.pointer_to_node;
            }

            bool operator!=(const iterator& rhs) const {
                return pointer_to_node != rhs.pointer_to_node;
            }
        };
        iterator begin_level_order(){
            return(iterator{root , 0});
        }
        iterator end_level_order();
        iterator begin_reverse_order();
        iterator reverse_order();
        iterator begin_preorder();
        iterator end_preorder();
        //for the for each loop. Should work like level order
        iterator begin(){

        }
        iterator end(){

        }
    };

}

