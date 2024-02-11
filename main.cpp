#include "investment_calculator.cpp"

// implementation of the main method
int main() {
    InvestmentCalculator investment; // creation of the investment object to allow the accessing of the class attributes
    investment.userInput();                                 // calls the userInput function
    investment.calculateBalanceWithoutMonthlyDeposit();     // calls the calculateBalanceWithoutMonthlyDeposit function
    investment.calculateBalanceWithMonthlyDeposit();        // calls the calculateBalanceWithMonthlyDeposit function
    return 0;

    cout << "Press any key to exit...";
}