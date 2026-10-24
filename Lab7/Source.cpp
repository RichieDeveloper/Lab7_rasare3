#include<iostream>
#include "Account.h"

/**
@file Lab7_rasare3.cpp
@author Richie
@date 2026-10-24
@brief A banking application that allows users to make deposits, withdrawals, and close of business operations on a bank account.
*/


void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;


/*
* @brief Entry point of the banking application.
* @return 0 on successful execution.
*/
int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    Account account("5423678409", 100.00, customer);
    account.printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
        case DEPOSIT:
        {
            double amount;
            cout << "Enter the amount to deposit: ";
            cin >> amount;

            if (isAmountValid(amount))
            {
                account.deposit(amount);
            }
            else
            {
                cout << "Invalid amount. Please try again." << endl;
            }

            break;
        }

        case WITHDRAWAL:
        {
            double amount;
            cout << "Enter the amount to withdraw: ";
            cin >> amount;

            if (isAmountValid(amount))
            {
                account.withdraw(amount);
            }
            else
            {
                cout << "Invalid amount. Please try again." << endl;
            }

            break;
        }

        case CLOSE_OF_BUSINESS:

            account.closeOfBusiness();

            break;

        }

        menuChoice = getMenuOption();
    }
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT and choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}