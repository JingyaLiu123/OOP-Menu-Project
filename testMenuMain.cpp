#include "MenuClass.h"
#include "BeverageClass.h"
#include "FoodClass.h"

#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

int main()
{
    Color::Modifier red(Color::FG_RED);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier white(Color::FG_DEFAULT);

    std::cout <<"~ Welcome! ~"<< "\n";
    while(true)
    {
    std::cout << "I would like to: " << "\n" << "Add to Beverage Menu --> press 1" << "\n"
    << "See Beverage Menu --> press 2" << "\n" << "Order Beverage --> press 3" << "\n"
    << "Add to Food Menu --> press 4" << "\n" << "See Food Menu --> press 5" << "\n" << "Make Order --> 6" << endl;
    int menu_select;
    std::cin >> menu_select;

    Beverage new_beverage;
    Food new_food;

        switch (menu_select)
        {
            case 1:
                new_beverage.AddBev();
                break;
            case 2:
                new_beverage.SeeBevMenu();
                break;
            case 3:
                new_beverage.BevOrder();
                break;
            case 4:
                new_food.AddFood();
                break;
            case 5:
                new_food.SeeFoodMenu();
                break;
            case 6:

            //while(true)
            //{
                std::string cust_name;
                std::cout << "Enter customer name: ";
                std::cin >> cust_name;
                time_t timetoday;
                time(&timetoday);
                std::string Date_time = asctime(localtime(&timetoday));
                while(true)
                {
                std::cout << "I want to order" << "\n" << "7 --> food" << "\n" << "8 --> beverage"
                << "\n" << "9 --> finish" << endl;
                int order_choice;
                std::cin >> order_choice;
                //while(true)
                //{
                    switch (order_choice)
                    {
                        case 7:
                        {
                            fstream file("FoodMenu.txt");
                            new_food.FoodOrder();
                            continue;
                        }
                        case 8:
                        {
                            fstream file("BeverageMenu.txt");
                            new_beverage.BevOrder();
                            continue;
                        }
                        case 9:
                        {
                            break;
                        }
                    }


                    std::string MenuPrice;
                    int total;
                    ifstream MenuReceiptFile("MenuReceipt.txt");
                    while(getline(MenuReceiptFile, MenuPrice, ' '))
                    {
                        int IntMenuPrice = atoi(MenuPrice.c_str());
                        total = total + IntMenuPrice;
                    }
                    MenuReceiptFile.close();

                    std::cout << "=================================" << endl;
                    cout << "Thank You For Using Menu Program" << "\n" << "|          [ ^ U ^ ]           |" << "\n";
                    cout << "=================================" << "\n"
                    << "customer name: " << cust_name << "\n"
                    << Date_time << "\n" << "---------------------------------" << "\n";


                    cout << "Your Order was: ";
                    /*name << "\n" << temp << ", " << option << ", " << calorie << "\n"*/
                    std::string receiptText;
                    ifstream receiptfile("MenuReceipt.txt");
                    while(getline(receiptfile, receiptText))
                    {
                        std::cout << receiptText << endl;
                    }

                    string name, price, temp, option, calorie;
                    receiptfile >> name >> price >> temp >> option >> calorie;

                    std::cout << "---------------------------------" << "\n" << "Total: $" << total << endl;
                    std::cout << "=================================" << endl;

                    static int counter = 1;
                    //cout << counter << endl;

                    cin.get();

                    //return counter++;
                    break;
                }
                break;
            }

        }
    return 0;
}




    //Declare variables in main function
    string answer;
    string receipt_claim;



   /* if ( answer != "yes"){
        cout<< " Invalid input, please try again "<< "\n";
        return 0;
    } else{

    std::string menuText;
    ifstream MenuReadFile("Menu.txt");
    while(getline (MenuReadFile, menuText))
    {
        cout << menuText << "\n";
    }
    MenuReadFile.close();*/



 //   return 0;
//}