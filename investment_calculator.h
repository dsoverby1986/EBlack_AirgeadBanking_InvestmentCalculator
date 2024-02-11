/*
Airgead Banking Investment Calculator
Developer: Emily Black
Date: February 11, 2024
*/ 

#ifndef EMILY_REPOS_AIRGEADBANKING_INVESTMENTCALCULATOR_H
#define EMILY_REPOS_AIRGEADBANKING_INVESTMENTCALCULATOR_H

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class InvestmentCalculator {
// private data members declared using Airgread Banking standards
private: 
	double m_initInvestment;			// the initial investment amount 
	double m_monthlyDeposit;			// the monthly deposit amount
	double m_annualPercentageRate;		// the annual percentage rate 
	int m_numYears;						// the number of years
	inline double getDoubleFromUser(string prompt);
	inline int getIntFromUser(string prompt);
	inline void getInitialInvestment(void);
	inline void getMonthlyDeposit(void);
	inline void getAnnualPercentageRate(void);
	inline void getNumberOfYears(void);

// public data members
public:
	// functions declared
	inline int userInput();	// a function to prompt the user for an initial investment amount, a monthly deposit, the APR, and the number of years
	inline int calculateBalanceWithoutMonthlyDeposit();		// a function to calculate the balance WITHOUT an additional monthly deposit 
	inline int calculateBalanceWithMonthlyDeposit();		// a function to calculate the balance WITH an additional monthly deposit
};

#endif EMILY_REPOS_AIRGEADBANKING_INVESTMENTCALCULATOR_H