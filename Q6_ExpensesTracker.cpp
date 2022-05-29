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

// Define structure data type for Expenses
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
void getExpenses(Expenses expenses[], int length);
void viewDailyExpenses(Expenses expenses[], int length);
void tabularReport(Expenses expenses[], int length, string title);
void weeklyReport(Expenses expenses[], int length);

int main()
{

    // variable definitions
    int menuChoice = 0;
    Expenses dailyExpense[30]; // Defined here an array of Expenses for 30-days. However for purposes of this assignment, only three (3) days are utilized as a demo.

    while (menuChoice != 6)
    {
        menuChoice = showMenu(); // Show menu choices and save choice into the menuChoice variable.

        switch (menuChoice)
        {
        case 1:
            getExpenses(dailyExpense, 3); // Get expenses for three (3) days only - this is just a demo for purposes of this assignment
            break;
        case 2:
            viewDailyExpenses(dailyExpense, 3);
            break;
        case 3:
            tabularReport(dailyExpense, 3, "Weekly Expenses");
            break;
        case 4:
            tabularReport(dailyExpense, 3, "Daily Report");
            break;
        case 5:
            weeklyReport(dailyExpense, 3);
            break;
        case 6:
            break;

        default:
            cout << "\nInvalid choice\n";
            break;
        }
    }

    return 0;
}

void getExpenses(Expenses expenses[], int length)
/**************************************************************************
 * Purpose: This is the entry form for entering expenses for a certain day.
 **************************************************************************/
{

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
/*********************************************************************************
 * Purpose: Displays the expenses for a certain day. User inputs the date to view.
 *********************************************************************************/
{
    string day = "";
    bool found = false;

    cout << "Enter day to view (DD-MM-YYYY): ";
    cin >> day;
    for (int i = 0; i < length; i++)
    {
        if (expenses[i].dateExpense == day)
        {
            found = true;
            cout << "\nExpenses for: " << day << "\n";
            cout << "=============================\n";
            cout << "     Transport: " << expenses[i].transportCost << "\n";
            cout << "          Meal: " << expenses[i].mealCost << "\n";
            cout << " Entertainment: " << expenses[i].entertainCost << "\n";
            cout << "        others: " << expenses[i].othersCost << "\n";
            cout << "=============================\n";
            cout << "Total Expenses: " << expenses[i].transportCost + expenses[i].mealCost + expenses[i].entertainCost + expenses[i].othersCost << "\n";
            cout << "=============================\n";
        }
    }

    if (!found)
    {
        cout << "\nNo record found for: " << day << "\n";
    }
}

int totalExpenses(Expenses expenses[], int length)
/***************************************************
 * Purpose: Utility function to sum all the expenses
 ***************************************************/
{
    int totalExpenses = 0;

    for (int i = 0; i < length; i++)
    {
        totalExpenses += (expenses[i].transportCost + expenses[i].mealCost + expenses[i].entertainCost + expenses[i].othersCost);
    }

    return totalExpenses;
}

void tabularReport(Expenses expenses[], int length, string title)
/**********************************************************************************************************************************************
 * Purpose: Displays the report/expenses in tabular format. This function is called by either "Weekly Expenses" module or "Daily Report" module.
 **********************************************************************************************************************************************/
{
    int rowTotal = 0;
    int colTotal[4] = {0, 0, 0, 0};
    int overAllTotal = 0;

    cout << "\n"
         << title;
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
/*********************************************************************
 * Purpose: Displays the Weekly Report in a tabular form
 *********************************************************************/

{
    int rowTotal = 0;
    int colTotal[4] = {0, 0, 0, 0};
    int overAllTotal = 0;

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