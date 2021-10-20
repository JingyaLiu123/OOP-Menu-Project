#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <string>
#include <iomanip>
#include "MenuClass.h"

//#include "MenuColour.h"
#include "BeverageClass.h"
#include <fstream>
#include <limits>

#include <fstream>
#include <stdlib.h>

#include <vector>
#include <sstream>
#include <limits>
using namespace std;
Color::Modifier red(Color::FG_RED);
Color::Modifier def(Color::FG_DEFAULT);
/*
#include <ostream>
namespace Color {
    enum fCode {
        fFG_RED      = 31,
        fFG_GREEN    = 32,
        fFG_BLUE     = 34,
        fFG_DEFAULT  = 39,
        fBG_RED      = 41,
        fBG_GREEN    = 42,
        fBG_BLUE     = 44,
        fBG_DEFAULT  = 49
    };
    class fModifier {
        fCode code;
    public:
        Modifier(fCode pfCode) : code(pfCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const fModifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}
    Color::fModifier fred(Color::fFG_RED);
    Color::fModifier fgreen(Color::fFG_GREEN);
    Color::fModifier fblue(Color::fFG_BLUE);
    Color::fModifier fwhite(Color::fFG_DEFAULT);

    std::fstream& GotofLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
    }
*/
class Food: public Menu
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
        std::cout << "Is this served hot? (enter 1 to confirm, any other key to deny): ";
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
        std::cout << "Is this vegetarian? (press 1 to confirm): ";
        std::string option{};
        std::string alcoholic_option;
        std::cin >> alcoholic_option;
        if(alcoholic_option == "1")
        {
            option = "Vegetarian";
        } else
        {
            option = "Non-vegetarian";
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


    int AddFood()
    {
        std::cout << "Foods: " << "\n";
        Food new_food;

        std::string name = new_food.getNameFromUser();
        int price = new_food.getPriceFromUser();
        std::string temp = new_food.getTempFromUser();
        std::string option = new_food.getOptionFromUser();
        int calorie = new_food.getCalorieFromUser();
        new_food.Item();

        ofstream MenuFile("FoodMenu.txt", ofstream::app);

        MenuFile << std::left << std::setw(17) << name << std::left << std::setw(10) << price << std::left << std::setw(12) << temp
        << std::left << setw(20) << option << std::left << std::setw(20) << calorie << endl;

        MenuFile.close();

        std::string menuText;
        ifstream MenuReadFile("FoodMenu.txt");

        static int counter = 0;

        std::cout << red << std::left << std::setw(17) << "Food Option" << std::left << std::setw(10) << "Price ($)" << std::left
        << std::setw(12) << "Served Hot" << std::left << std::setw(20) << "Vegetarian" << std::left << std::setw(20) << "Calories (kCal)" << endl;
        std::cout << def << "===============================================================================" << endl;
        while(getline (MenuReadFile, menuText))
            {
            std::cout << red <<  menuText << endl;
            std::cout << def << "-------------------------------------------------------------------------------" << endl;
            }
        MenuReadFile.close();
        //std::cout << counter << endl;
        counter++;
        return price;
    }

    int SeeFoodMenu()
    {
        std::string menuText;
        ifstream MenuReadFile("BeverageMenu.txt");

        static int counter = 0;

        std::cout << red << std::left << std::setw(17) << "Food Option" << std::left << std::setw(10) << "Price ($)" << std::left
        << std::setw(12) << "Served Hot" << std::left << std::setw(20) << "Vegetarian" << std::left << std::setw(20) << "Calories (kCal)" << endl;
        std::cout << def << "===============================================================================" << endl;
        while(getline (MenuReadFile, menuText))
            {
            std::cout << red <<  menuText << endl;
            std::cout << def << "-------------------------------------------------------------------------------" << endl;
            }
        MenuReadFile.close();
        //std::cout << counter << endl;
        counter++;
        return 0;
    }

    int FoodOrder()
    {
        fstream file("FoodMenu.txt");
        int item_number;
        cout << "Enter item number: ";
        cin >> item_number;
        //std::string cust_name;
        //std::cout << "Enter customer name: ";
        //std::cin >> cust_name;
        //time_t timetoday;
        //time(&timetoday);
        //std::string Date_time = asctime(localtime(&timetoday));

        GotoLine(file, item_number);

        string name, temp, option, calorie;
        int price;
        file >> name >> price >> temp >> option >> calorie;

        ofstream ReceiptFoodFile("MenuReceipt.txt", ofstream::app);
        ReceiptFoodFile << price << " " << name << " " << temp << " " << option << " " << calorie << endl;

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

        return counter++;
        */
        return 0;
    }

};

#endif