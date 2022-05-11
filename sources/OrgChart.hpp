//
// Created by shaul on 09/05/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

namespace ariel{
    template <class T=string>
    class OrgChart{
        struct Node{
            T data;
            vector<Node *> sons;
            Node * father;
            Node(T & info): data(info) , father(nullptr){}
        };

        Node * p_root;
    public:
        OrgChart(){
            p_root = nullptr;
        };
        /**
         * Base function to add/change root of organizational tree
         * @param root_data -> receive the data to input in the tree
         * @return this instance so we can chain actions
         */
        OrgChart & add_root(T root_data){
            //if the org chart is empty
            if(this->p_root == nullptr){
                this->p_root= new Node(root_data);
            }
            //there is a root already in the orgchart
            else{
                //change the data of the root
                this->p_root->data = root_data;
            }
            return *this;
        }
        OrgChart & add_sub(T parent_data , T son_data){
            //if no root throw argument
            if (p_root == nullptr){
                throw invalid_argument("No Chart");
            }
            // search if parent is in organization if so add son else throw error
            bool parent_found = false;
            stack<Node *> traversing_stk;
            Node * temp = p_root;
            traversing_stk.push(temp);
            while(!traversing_stk.empty()){
                if(temp->data == parent_data){
                    parent_found = true;
                    //add node to parent's sons
                    Node * new_node = new Node(son_data);
                    temp->sons.push_back(new_node);
                    //point parent of son
                    //check this works
                    (new_node)->father = temp;
                    break;
                }
                //add all temps sons
                for (auto & son : temp->sons) {
                    traversing_stk.push(son);
                }
                temp = traversing_stk.top();
                traversing_stk.pop();
            }
            if (!parent_found){
                throw invalid_argument("No parent found");
            }
            return *this;
        }

        friend std::ostream& operator<< (std::ostream& output, const OrgChart& chart);

        //maybe fix the destructor and remove kids as well
        ~OrgChart(){
            delete(p_root);
        }
        //-------------------------------------------------------------------
        // Create a iterator sub_class which will be implemented by inner class
        //-------------------------------------------------------------------
        class iterator {
            // 0 is level order
            // 1 is reverse level order
            // 2 is preorder
        private:
            Node * pointer_to_node;
            queue<Node *> lvl_o_que;
            int order_type;
        public:
            /**
             * Constructor for iterator. here we will initialize stacks which we are using to help iterate
             * @param ptr Pointer which is used to instantiate iterator
             * @param order This is my helper enum to tell me which case of traversing are we on
             */
            iterator(Node * ptr = nullptr , int order= 1):
            pointer_to_node(ptr) , order_type(order) {
                //check if ptr points to something
                if (pointer_to_node != nullptr){
                    //check if ptr has kids
                    if(!pointer_to_node->sons.empty()) {
                        //check what case are we on
                        if (order_type == 0) {//level order
                            for (auto & son : pointer_to_node->sons) {
                                lvl_o_que.push(son);
                            }
                        } else if (order_type == 1) {//reverse level order

                        } else {//preorder

                        }
                    }
                }
            }

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
                if(!lvl_o_que.empty()) {
                    if (order_type == 0) {//level order
                        //move pointer to next
                        pointer_to_node = lvl_o_que.front();
                        lvl_o_que.pop();
                        //add sons of new pointer to stack
                        if (pointer_to_node != nullptr) {
                            if (!pointer_to_node->sons.empty()) {
                                for (auto &son: pointer_to_node->sons) {
                                    lvl_o_que.push(son);
                                }
                            }
                        }
                    }
                    else if (order_type == 1) {//reverse level order

                    }
                    else {//preorder

                    }
                    return *this;
                }
                pointer_to_node = nullptr;
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
            return(iterator{p_root , 0});
        }
        iterator end_level_order(){
            return(iterator{nullptr , 0});
        }
        iterator begin_reverse_order(){
            return(iterator{p_root , 1});
        }
        iterator reverse_order(){
            //not sure about this because we need to stop when we reach root
            return(iterator{nullptr , 1});
        }
        iterator begin_preorder(){
            return(iterator{p_root , 2});
        }
        iterator end_preorder(){
            return(iterator{nullptr , 2});
        }
        //for the for each loop. Should work like level order
        iterator begin(){
            return(iterator{p_root , 0});
        }
        iterator end(){
            return(iterator{nullptr , 0});
        }
    };

}

