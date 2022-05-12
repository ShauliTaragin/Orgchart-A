//
// Created by shaul on 09/05/2022.
//
#include "doctest.h"
#include "sources/OrgChart.hpp"
#include "string"
using namespace ariel;
using namespace std;
TEST_CASE ("Case 1 Football Team")
{
    //checking integers
    OrgChart<string> chart1;
            CHECK_NOTHROW(chart1.add_root("Owner"));
            CHECK_NOTHROW(chart1.add_root("New_Owner"));
            CHECK_THROWS(chart1.add_sub("Owner" , "General Manager"));//Owner was replaced
            CHECK_THROWS(chart1.add_sub("Lebron James" , "General_Manager"));//no such value
            CHECK_NOTHROW(chart1.add_sub("New_Owner" , "General_Manager"));
            CHECK_NOTHROW(chart1.add_sub("New_Owner" , "Share_Holders"));
            CHECK_NOTHROW(chart1.add_sub("New_Owner" , "Head_of_operations"));
            CHECK_NOTHROW(chart1.add_sub("General_Manager" , "Head_Coach"));
            CHECK_NOTHROW(chart1.add_sub("General_Manager" , "Assistant_Coach"));
            CHECK_NOTHROW(chart1.add_sub("Head_of_operations" , "Team_Doctor"));
            CHECK_NOTHROW(chart1.add_sub("Head_of_operations" , "Head_Scout"));
            CHECK_NOTHROW(chart1.add_sub("Share_Holders" , "Sub_Share_Holder1"));
            CHECK_NOTHROW(chart1.add_sub("Share_Holders" , "Sub_Share_Holder2"));
            CHECK_THROWS(chart1.add_sub("head_of_operations" , "Cheerleader"));//Head not head
            CHECK_NOTHROW(chart1.add_sub("Head_Coach" , "Captain"));
            CHECK_NOTHROW(chart1.add_sub("Team_Doctor" , "Team_Physiotherapist"));
            // test level order
            vector<string> lvl_order;
            for (auto it = chart1.begin_level_order(); it != chart1.end_level_order(); ++it)
            {
               lvl_order.push_back(*it);
            }
            CHECK_EQ(lvl_order.at(0),"New_Owner");
            CHECK_EQ(lvl_order.at(1),"General_Manager");
            CHECK_EQ(lvl_order.at(2),"Share_Holders");
            CHECK_EQ(lvl_order.at(3),"Head_of_operations");
            CHECK_EQ(lvl_order.at(4),"Head_Coach");
            CHECK_EQ(lvl_order.at(5),"Assistant_Coach");
            CHECK_EQ(lvl_order.at(6),"Sub_Share_Holder1");
            CHECK_EQ(lvl_order.at(7),"Sub_Share_Holder2");
            CHECK_EQ(lvl_order.at(8),"Team_Doctor");
            CHECK_EQ(lvl_order.at(9),"Head_Scout");
            CHECK_EQ(lvl_order.at(10),"Captain");
            CHECK_EQ(lvl_order.at(11),"Team_Physiotherapist");
            lvl_order.clear();

            //add another field and check that it works
            CHECK_NOTHROW(chart1.add_sub("Assistant_Coach" , "Water_Boy"));

            //check default iterator
            for (auto name:chart1)
            {
                lvl_order.push_back(name);
            }
            CHECK_EQ(lvl_order.at(0),"New_Owner");
            CHECK_EQ(lvl_order.at(1),"General_Manager");
            CHECK_EQ(lvl_order.at(2),"Share_Holders");
            CHECK_EQ(lvl_order.at(3),"Head_of_operations");
            CHECK_EQ(lvl_order.at(4),"Head_Coach");
            CHECK_EQ(lvl_order.at(5),"Assistant_Coach");
            CHECK_EQ(lvl_order.at(6),"Sub_Share_Holder1");
            CHECK_EQ(lvl_order.at(7),"Sub_Share_Holder2");
            CHECK_EQ(lvl_order.at(8),"Team_Doctor");
            CHECK_EQ(lvl_order.at(9),"Head_Scout");
            CHECK_EQ(lvl_order.at(10),"Captain");
            CHECK_EQ(lvl_order.at(11),"Water_Boy");
            CHECK_EQ(lvl_order.at(12),"Team_Physiotherapist");

            // test reverse level order
            vector<string> rv_lvl_order;
            for (auto it = chart1.begin_reverse_order(); it != chart1.reverse_order(); ++it)
            {
                rv_lvl_order.push_back(*it);
            }
            CHECK_EQ(rv_lvl_order.at(0),"Captain");
            CHECK_EQ(rv_lvl_order.at(1),"Water_Boy");
            CHECK_EQ(rv_lvl_order.at(2),"Team_Physiotherapist");
            CHECK_EQ(rv_lvl_order.at(3),"Head_Coach");
            CHECK_EQ(rv_lvl_order.at(4),"Assistant_Coach");
            CHECK_EQ(rv_lvl_order.at(5),"Sub_Share_Holder1");
            CHECK_EQ(rv_lvl_order.at(6),"Sub_Share_Holder2");
            CHECK_EQ(rv_lvl_order.at(7),"Team_Doctor");
            CHECK_EQ(rv_lvl_order.at(8),"Head_Scout");
            CHECK_EQ(rv_lvl_order.at(9),"General_Manager");
            CHECK_EQ(rv_lvl_order.at(10),"Share_Holders");
            CHECK_EQ(rv_lvl_order.at(11),"Head_of_operations");
            CHECK_EQ(rv_lvl_order.at(12),"New_Owner");

            // Change root check that still works



            //add test when trying to add sub before root for new org
}