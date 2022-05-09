//
// Created by shaul on 09/05/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel{
    class OrgChart{
    public:
        OrgChart();
        OrgChart & add_root(string name);
        OrgChart & add_sub(string parent , string son);


        friend std::ostream& operator<< (std::ostream& output, const OrgChart& chart);

    public:

        //-------------------------------------------------------------------
        // Create a iterator sub_class which will be implemented by inner class
        //-------------------------------------------------------------------
        class iterator {


        };
    };

}

