#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Declare variables to store input
    float initialInvest, monthlyDep, annualInt, months, years;
    //Declare variables to store year end total amount, interest, and year end interest
    float totalAmt, initialAmt, yearTotalInt;


    //Display form to user
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";

    //Wait for input from user
    system("PAUSE");

    //Get user defined data
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: $";
    cin >> initialInvest;
    cout << "Monthly Deposit: $";
    cin >> monthlyDep;
    cout << "Annual Interest: %";
    cin >> annualInt;
    cout << "Number of years: ";
    cin >> years;
    months = years * 12;

    //Wait for input from user
    system("PAUSE");

    //update total amount to initial amount
    totalAmt = initialInvest;

    //Display year data without monthly deposits
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";


    for (int i = 0; i < years; i++) {

        //Calculate yearly interest
        initialAmt = (totalAmt) * ((annualInt / 100));

        //Calculate year end total
        totalAmt = totalAmt + initialAmt;

        //Print results to table showcasing only two decimal points
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << initialAmt << "\n";

    }

    //Update total amount to Initial Amount
    totalAmt = initialInvest;

    //Display year data with monthly deposits
    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {

        //Set yearly interest to zero at the start of the year
        yearTotalInt = 0;

        for (int j = 0; j < 12; j++) {

            //Calculate monthly interest
            initialAmt = (totalAmt + monthlyDep) * ((annualInt / 100) / 12);

            //Calculate month end interest
            yearTotalInt = yearTotalInt + initialAmt;

            //Calculate month end total
            totalAmt = totalAmt + monthlyDep + initialAmt;

        }

        //Print results to table showcasing only two decimal points
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << yearTotalInt << "\n";


    }

    return 0;
}