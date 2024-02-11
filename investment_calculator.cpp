#include <string>
#include "investment_calculator.h"

double InvestmentCalculator::getDoubleFromUser(string prompt)
{
	bool ok;
	double value;
	cout << prompt;

	do
	{
		ok = true;
		cin >> value;

		if (!cin)
		{
			ok = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			string dummy;
			getline(cin, dummy);

			if (dummy.find_first_not_of(" ") != string::npos)
			{
				ok = false;
			}
		}

		if (!ok)
		{
			cout << "Invalid input. Try again.\n";
		}
	} while (!ok);

	return value;
}

int InvestmentCalculator::getIntFromUser(string prompt)
{
	bool ok;
	int value;
	cout << prompt;

	do
	{
		ok = true;
		cin >> value;

		if (!cin)
		{
			ok = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			string dummy;
			getline(cin, dummy);

			if (dummy.find_first_not_of(" ") != string::npos)
			{
				ok = false;
			}
		}

		if (!ok)
		{
			cout << "Invalid input. Try again.\n";
		}
	} while (!ok);

	return value;
}

void InvestmentCalculator::getInitialInvestment()
{
	m_initInvestment = getDoubleFromUser("Initial Investment Amount: $\n");
}

void InvestmentCalculator::getMonthlyDeposit()
{
	m_monthlyDeposit = getDoubleFromUser("Monthly Deposit: $\n");
}

void InvestmentCalculator::getAnnualPercentageRate()
{
	m_annualPercentageRate = getDoubleFromUser("Annual Percentage Rate: %\n");
}

void InvestmentCalculator::getNumberOfYears()
{
	m_numYears = getIntFromUser("Number of years: \n");
}

int InvestmentCalculator::userInput() {					// investment function defined
	cout << "**************************************\n";
	cout << "********** Airgead Banking ***********\n";
	cout << "******* Investment Calculator ********\n";
	cout << " \n";
	getInitialInvestment();
	getMonthlyDeposit();
	getAnnualPercentageRate();
	getNumberOfYears();
	cout << "Press any key to continue...\n";
	return 0;
}

int InvestmentCalculator::calculateBalanceWithoutMonthlyDeposit() {		// calculateBalanceWithoutMonthlyDeposit function defined
	int numMonths = m_numYears * 12; // converts the number of years to months
	
	// prints a report of the balance and interest earned without additional monthly deposits
	cout << "\nBalance & Earned Interest Without Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Interest\n";
	cout << "--------------------------------------------------------------\n";

	double closingBalance = m_initInvestment;
	for (int i = 0; i < m_numYears; i++) {
		double totalInterest = closingBalance * (m_annualPercentageRate / 100);
		closingBalance = closingBalance + totalInterest;
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << closingBalance
			<< "\t\t\t$" << totalInterest << "\n";
	}
	return 0;
}

int InvestmentCalculator::calculateBalanceWithMonthlyDeposit() {		// calculateBalanceWithMonthlyDeposit function defined
	// prints a report of the balance and interest earned with additional monthly deposits
	cout << "\n\nBalance & Earned Interest With Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Interest\n";
	cout << "--------------------------------------------------------------\n";

	// calculation of the closing balance
	double closingBalance = m_initInvestment;
	for (int i = 0; i < m_numYears; i++) {
		double totalInterest = 0;
		for (int j = 0; j < 12; j++) {
			double monthlyInterest = (closingBalance + m_monthlyDeposit) * (m_annualPercentageRate / 100 / 12);
			totalInterest = totalInterest + monthlyInterest;
			closingBalance = closingBalance + m_monthlyDeposit + monthlyInterest;
		}
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << closingBalance
			<< "\t\t\t$" << totalInterest << "\n";
	}
	return 0;
}


