#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>

class Menu
{
    public: virtual void Item() = 0;
            std::string getNameFromUser();
            int getPriceFromUser();
            std::string getTempFromUser();
            std::string getOptionFromUser();
            int getCalorieFromUser();

            std::string name;
            int price;
            std::string temp;
            std::string option;
            int calorie;

};
#endif