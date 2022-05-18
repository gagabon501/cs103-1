/***********************************************************************************
 *    CS-103 Integrated Studio I Assessment 1 - Question6: Personal expenses tracker
 *    @file Q6_ExpensesTracker.cpp
 *    @author Gilberto Gabon
 *    @version 1 / 29-May-2022
 ***********************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
struct Expenses
{
    string dateExpense;
    int transportCost;
    int mealCost;
    int entertainCost;
    int othersCost;

    // Constructor to initialize members
    Expenses(string dateExp = "", int transport = 0, int meal = 0, int entertain = 0, int others = 0)
    {
        dateExpense = dateExp;
        transportCost = transport;
        mealCost = meal;
        entertainCost = entertain;
        othersCost = others;
    }
};

// Function Prototypes

int showMenu();
int totalExpenses(Expenses expenses[], int length);

void Clear();
void getExpenses(Expenses expenses[], int length);
void viewDailyExpenses(Expenses expenses[], int length);
void viewWeeklyExpenses(Expenses expenses[], int length);
void dailyReport(Expenses expenses[], int length);
void weeklyReport(Expenses expenses[], int length);

int main()
{

    // variable definitions
    int menuChoice = 0;
    Expenses dailyExpense[30];

    Clear(); // clear the screen

    while (menuChoice != 6)
    {
        menuChoice = showMenu();
        switch (menuChoice)
        {
        case 1:
            getExpenses(dailyExpense, 3);
            break;
        case 2:
            viewDailyExpenses(dailyExpense, 3);
            break;
        case 3:
            viewWeeklyExpenses(dailyExpense, 3);
            break;
        case 4:
            dailyReport(dailyExpense, 3);
            break;
        case 5:
            weeklyReport(dailyExpense, 3);
            break;
        }
    }

    return 0;
}

void getExpenses(Expenses expenses[], int length)
{

    Clear();

    for (int i = 0; i < length; i++)
    {
        cout << "\nEnter expenses for the day\n";
        cout << "==========================\n";

        cout << "\nDate (DD-MM-YYYY): ";
        cin >> expenses[i].dateExpense;
        cout << "Transport: ";
        cin >> expenses[i].transportCost;
        cout << "Meal: ";
        cin >> expenses[i].mealCost;
        cout << "Entertainment: ";
        cin >> expenses[i].entertainCost;
        cout << "Others: ";
        cin >> expenses[i].othersCost;
    }
}

void viewDailyExpenses(Expenses expenses[], int length)
{
    float dailyExpenses = 0;

    Clear();

    dailyExpenses = totalExpenses(expenses, length) / length;

    cout << "Average Daily Expenses (Total Expenses/Number of Days): " << dailyExpenses;
}

void viewWeeklyExpenses(Expenses expenses[], int length)
{
    float weeklyExpenses = 0;

    Clear();

    weeklyExpenses = totalExpenses(expenses, length) / 7; // 7 days per week

    cout << "Average Weekly Expenses (Total Expenses/7): " << weeklyExpenses;
}

int totalExpenses(Expenses expenses[], int length)
{
    int totalExpenses = 0;

    for (int i = 0; i < length; i++)
    {
        totalExpenses += (expenses[i].transportCost + expenses[i].mealCost + expenses[i].entertainCost + expenses[i].othersCost);
    }

    return totalExpenses;
}

void dailyReport(Expenses expenses[], int length)
{
    int rowTotal = 0;
    int colTotal[4] = {0, 0, 0, 0};
    int overAllTotal = 0;

    Clear();
    cout << "\nDaily Report";
    cout << "\n==================================================================================================";
    cout << "\nDate"
         << "\t\t"
         << "Transport"
         << "\t\t"
         << "Meal"
         << "\t\t"
         << "Entertain"
         << "\t"
         << "Others"
         << "\t\t"
         << "Total\n";

    cout << "==================================================================================================\n";

    for (int i = 0; i < length; i++)
    {
        rowTotal = 0; // Reset row total after every line
        rowTotal += (expenses[i].transportCost + expenses[i].mealCost + expenses[i].entertainCost + expenses[i].othersCost);
        // colTotal[i] +=

        cout << expenses[i].dateExpense
             << "\t\t"
             << expenses[i].transportCost
             << "\t\t"
             << expenses[i].mealCost
             << "\t\t"
             << expenses[i].entertainCost
             << "\t\t"
             << expenses[i].othersCost
             << "\t\t"
             << rowTotal << "\n";
    }
    cout << "==================================================================================================\n";
    cout << "TOTAL";

    // Total the columns
    cout << "\t";
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < length; i++)
        {
            switch (j)
            {
            case 0:
                colTotal[j] += expenses[i].transportCost;
                break;
            case 1:
                colTotal[j] += expenses[i].mealCost;
                break;
            case 2:
                colTotal[j] += expenses[i].entertainCost;
                break;
            case 3:
                colTotal[j] += expenses[i].othersCost;
                break;
            }
        }
        overAllTotal += colTotal[j];
        cout << "\t\t" << colTotal[j];
    }
    cout << "\t\t" << overAllTotal;
    cout << "\n==================================================================================================\n";
}

void weeklyReport(Expenses expenses[], int length)
{
    int rowTotal = 0;
    int colTotal[4] = {0, 0, 0, 0};
    int overAllTotal = 0;

    Clear();
    cout << "\nWeekly Report";
    cout << "\n==================================================================================================";
    cout << "\nWeek#"
         << "\t\t"
         << "Transport"
         << "\t\t"
         << "Meal"
         << "\t\t"
         << "Entertain"
         << "\t"
         << "Others"
         << "\t\t"
         << "Total\n";

    cout << "==================================================================================================\n";

    // Total the columns
    cout << "Week-1"
         << "\t";

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < length; i++)
        {
            switch (j)
            {
            case 0:
                colTotal[j] += expenses[i].transportCost;
                break;
            case 1:
                colTotal[j] += expenses[i].mealCost;
                break;
            case 2:
                colTotal[j] += expenses[i].entertainCost;
                break;
            case 3:
                colTotal[j] += expenses[i].othersCost;
                break;
            }
        }
        overAllTotal += colTotal[j];
        cout << "\t\t" << colTotal[j];
    }
    cout << "\t\t" << overAllTotal;
    cout << "\n==================================================================================================\n";
}

int showMenu()
/*********************************************************************
 * Purpose: Shows the menu. This is the initial screen of the program.
 *********************************************************************/

{
    int menuChoice = 0;
    cout << "\n==================================\n";
    cout << "Personal Expenses Tracking System\n";
    cout << "==================================\n";
    cout << "1. Record expenses\n";
    cout << "2. View daily expense\n";
    cout << "3. View weekly expenses\n";
    cout << "4. Generate daily report\n";
    cout << "5. Generate weekly report\n";
    cout << "6. Exit\n";
    cout << "==================================\n";
    cout << "Choice: ";
    cin >> menuChoice;

    return menuChoice;
}

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}