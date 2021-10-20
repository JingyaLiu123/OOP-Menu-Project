#ifndef BEVERAGE_H
#define BEVERAGE_H
#include <iostream>
#include <string>
#include <iomanip>
#include "MenuClass.h"
#include "MenuColour.h"
#include <fstream>
#include <limits>
//#include "FoodClass.h"
#include <fstream>
#include <stdlib.h>

#include <vector>
#include <sstream>
#include <limits>
using namespace std;

    //Color::Modifier red(Color::FG_RED);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier white(Color::FG_DEFAULT);

    std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
    }
class Beverage: public Menu
{
    public:
    void Item()
    {

    }
    std::string getNameFromUser()
    {
        std::cout << "enter name: ";
        std::string name{};
        std::cin >> name;
        return name;
    }
    int getPriceFromUser()
    {
        std::cout << "enter price: ";
        float price{};
        std::cin >> price;
        return price;
    }
    std::string getTempFromUser()
    {
        std::cout << "Is this beverage chilled? (enter 1 to confirm): ";
        std::string chilled_temp;
        std::string temp{};
        std::cin >> chilled_temp;
        if(chilled_temp == "1")
        {
            temp = "Yes";
        } else
        {
            temp = "No";
        }
    return temp;
    }
    std::string getOptionFromUser()
    {
        std::cout << "Does this contain alcohol? (press 1 to confirm): ";
        std::string option{};
        std::string alcoholic_option;
        std::cin >> alcoholic_option;
        if(alcoholic_option == "1")
        {
            option = "Alcoholic";
        } else
        {
            option = "Non-alcoholic";
        }
        return option;
    }
    int getCalorieFromUser()
    {
        std::cout << "enter calories: ";
        int calorie{};
        std::cin >> calorie;
        return calorie;
    }
//---------------------------------------------------------------------------------------------------


    int AddBev()
    {
        std::cout << "Beverages: " << "\n";
        Beverage new_beverage;

        std::string name = new_beverage.getNameFromUser();
        int price = new_beverage.getPriceFromUser();
        std::string temp = new_beverage.getTempFromUser();
        std::string option = new_beverage.getOptionFromUser();
        int calorie = new_beverage.getCalorieFromUser();
        new_beverage.Item();

        ofstream MenuFile("BeverageMenu.txt", ofstream::app);

        MenuFile << std::left << std::setw(17) << name << std::left << std::setw(10) << price << std::left << std::setw(12) << temp
        << std::left << setw(20) << option << std::left << std::setw(20) << calorie << endl;

        MenuFile.close();

        std::string menuText;
        ifstream MenuReadFile("BeverageMenu.txt");

        static int counter = 0;

        std::cout << green << std::left << std::setw(17) << "Beverage Option" << std::left << std::setw(10) << "Price ($)" << std::left
        << std::setw(12) << "Temperature" << std::left << std::setw(20) << "Contents" << std::left << std::setw(20) << "Calories (kCal)" << endl;
        std::cout << white << "===============================================================================" << endl;
        while(getline (MenuReadFile, menuText))
            {
            std::cout << green <<  menuText << endl;
            std::cout << white << "-------------------------------------------------------------------------------" << endl;
            }
        MenuReadFile.close();
        //std::cout << counter << endl;
        counter++;
        return 0;
    }

    int SeeBevMenu()
    {
        std::string menuText;
        ifstream MenuReadFile("BeverageMenu.txt");

        static int counter = 0;

        std::cout << green << std::left << std::setw(17) << "Beverage Option" << std::left << std::setw(10) << "Price ($)" << std::left
        << std::setw(12) << "Temperature" << std::left << std::setw(20) << "Contents" << std::left << std::setw(20) << "Calories (kCal)" << endl;
        std::cout << white << "===============================================================================" << endl;
        while(getline (MenuReadFile, menuText))
            {
            std::cout << green <<  menuText << endl;
            std::cout << white << "-------------------------------------------------------------------------------" << endl;
            }
        MenuReadFile.close();
        //std::cout << counter << endl;
        counter++;
        return 0;
    }

    int BevOrder()
    {
        fstream file("BeverageMenu.txt");
        int item_number;
        cout << "Enter item number: ";
        cin >> item_number;
        /*std::string cust_name;
        std::cout << "Enter customer name: ";
        std::cin >> cust_name;
        time_t timetoday;
        time(&timetoday);
        std::string Date_time = asctime(localtime(&timetoday));
        */

        GotoLine(file, item_number);

        string name, temp, option, calorie;
        int price;
        file >> name >> price >> temp >> option >> calorie;

        ofstream ReceiptBevFile("MenuReceipt.txt", ofstream::app);
        ReceiptBevFile << price << " " << name << " " << temp << " " << option << " " << calorie << endl;

        /*std::cout << "=================================" << endl;
        cout << "Thank You For Using Menu Program" << "\n" << "|          [ ^ U ^ ]           |" << "\n";
        cout << "=================================" << "\n"
        << "customer name: " << cust_name << "\n"
        << Date_time << "\n" << "---------------------------------" << "\n";
        cout << "Your Order was: " << name << "\n" << temp << ", " << option << ", " << calorie << "\n"
        << "---------------------------------" << "\n" << "Total: $" << price << endl;
        std::cout << "=================================" << endl;

        static int counter = 1;
        //cout << counter << endl;

        cin.get();

        //return counter++;
        */
        //return price
        return 0;
    }

};

#endif