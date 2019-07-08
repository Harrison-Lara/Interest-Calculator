// Harrison Lara
// 2/05/2017
// CS 201 ~ Dr. May Zein El Din

#include <iostream> // year loop, wrong monthly and total, enter only a # and stop char inputs
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

// Initializing variables
double down_payment = 0, x, i, monthly_payment, total, answer, years = 10.00;

// Functions
double credit_score()
// Obtains user input for credit score and assigns proper interest rate
{
	double interest_rate;
	while (true)
	{
		cout << "--Please enter your credit score: " << "\n" << endl; // Inquiring users credit score
		cin >> x;

		if (x >= 0 && x <= 500)  // First stage credit score range
		{
			interest_rate = 0.05; // Interest rate for first stage
			cout << "Based on your credit score, your interest rate is 5%" << "\n" << endl; // Tell user their interest rate
			return interest_rate;
		}

		else if (x >= 501 && x <= 700) // Second stage credit score range
		{
			interest_rate = 0.02; // Interest rate for second stage
			cout << "Based on your credit score, your interest rate is 2%" << "\n" << endl; // Tell user their interest rate
			return interest_rate;
		}

		else if (x >= 701 && x <= 850) // Third stage for credit score range
		{
			interest_rate = 0.01; // Interest rate for third stage
			cout << "Based on your credit score, your interest rate is 1%" << "\n" << endl; // Tell user their interest rate
			return interest_rate;
		}
		else // If the credit score enterd is not between 0 and 850
		{
			cout << "Please enter a credit score between 0 and 850" << "\n" << endl; // Tell user their input is out of range
			continue;
		}
		break;
	}
	
}


double calculate_interest_rate(double interest, double price)
// Calculates the interest rate to obtain a monthly payment for the user based on their input
{
	monthly_payment = ((price - down_payment) * (pow(1 + interest, years)) / (12 * years)); // Formula for monthly payment
	return monthly_payment;
}

double total_interest(double price)
// Total interest summed between 10-25 years
{
	total = (monthly_payment * years * 12) - (price - down_payment); // Formula for total interest between 10 and 25 years
	return total;
}

void main()
{  	
	// Initializing variables
	double price;
	double down_payment = 0, monthly_payment, total, answer, years = 10.00;

	cout << "Hello and welcome to the Interest Calculator!" << "\n" << endl; // Greeting
	cout << "--Please enter the price of your luxurious dream home: " << "\n" << endl; // Inquiring house price
	cin >> price;
	cout << "--Will you be making any down payment? [yes: y | no: n] " << "\n" << endl; // Inquiring if a down payment is made or not

	while (true)
	{
		char answer;
		cin >> answer;
		switch (answer)
		{
		case 'y':
			cout << "--Please enter your down payment: " << "\n" << endl; // Aquiring the user input of a down payment
			cin >> down_payment;
			while (down_payment > price) // Checking to make sure down payment is within range
				cout << "--Please enter a down payment that is less than or equal to the price of you house: " << "\n" << endl;
			break;
		case 'n':
			down_payment = 0; // Down payment needs to equal zero
			cout << "No down payment made." << "\n" << endl; // Tell user they are not making a down payment
			break;
		default: //ask user for correct input
			cout << "Please enter a valid response -- [yes: y | no: n] " << "\n" << endl; // Tell user they are not making a down payment
			continue;
		}
		break;
	}
	double interest = credit_score(); // Setting variables to equal functions
	double rate = calculate_interest_rate(price, interest);
	double final_interest = total_interest(price);

	for (years = 10; years < 26; years++)
	{
		calculate_interest_rate(interest, price); // Calling interest rate calculation function

		total_interest(price); // Calling total interest function

		std::cout << "Pay in " << years << " years, monthly payment is $" << std::setprecision(2) << rate
			<< ". Total interest $" << std::setprecision(2) << final_interest << endl;
		///Outputing the year, total monthly payment and total interest to the user
	}

	cout << "\n" << "Thank you for using the Interest Calculator and enjoy your new home!" << "\n" << endl;
	// Thank you user for using the application
}