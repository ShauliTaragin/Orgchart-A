//
// Created by shaul on 09/05/2022.
//
#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;
using namespace std;
TEST_CASE ("Case 1 Football Team")
{
    //checking integers
    OrgChart chart1{};
            CHECK_NOTHROW(chart1.add_root("Owner"));
            CHECK_NOTHROW(chart1.add_root("New_Owner"));
            CHECK_THROWS(chart1.add_sub("Owner" , "General Manager"));//Owner was replaced
            CHECK_THROWS(chart1.add_sub("Lebron James" , "General Manager"));//no such value
            CHECK_NOTHROW(chart1.add_sub("New_Owner" , "General Manager"));
            CHECK_NOTHROW(chart1.add_sub("New_Owner" , "Share Holders"));
            CHECK_NOTHROW(chart1.add_sub("New_Owner" , "Head of operations"));
}