#include <iostream>
#include <string>

using namespace std;

void printNumerals()
{
	cout << "Printing relationship between Roman numerals and Arabic numerals..." << endl;
	cout << "I | 1" << endl;
	cout << "V | 5" << endl;
	cout << "X | 10" << endl;
	cout << "L | 50" << endl;
	cout << "C | 100" << endl;
	cout << "D | 500" << endl;
	cout << "M | 1000" << endl;
}

// Convert Roman numeral to corresponding decimal
int romanToInt(char romanNumeral)
{
	if (romanNumeral == 'I') return 1;
	else if (romanNumeral == 'V') return 5;
	else if (romanNumeral == 'X') return 10;
	else if (romanNumeral == 'L') return 50;
	else if (romanNumeral == 'C') return 100;
	else if (romanNumeral == 'D') return 500;
	else return 1000;
}

// Check if the entered Roman numeral is valid
bool isValidNumeral(string userNumeral)
{
	for (unsigned int i = 0; i < userNumeral.size(); ++i)
	{
		if (islower(userNumeral.at(i))) return false; // No lowercase input allowed
		if (userNumeral.at(i) == 'I') continue;
		else if (userNumeral.at(i) == 'V') continue;
		else if (userNumeral.at(i) == 'X') continue;
		else if (userNumeral.at(i) == 'L') continue;
		else if (userNumeral.at(i) == 'C') continue;
		else if (userNumeral.at(i) == 'D') continue;
		else if (userNumeral.at(i) == 'M') continue;
		return false;
	}

	for (unsigned int i = 0; i < userNumeral.size(); ++i)
	{
		for (unsigned int j = i; j < userNumeral.size(); ++j)
		{
			if (romanToInt(userNumeral.at(i)) * 10 < romanToInt(userNumeral.at(j))) return false;
		}
	}

	return true;
}


int main()
{
	char userOption;
	while (true)
	{
		cout << "Please enter an option from the following. Any key entered other than a, b, or c will exit the program" << endl;
		cout << "(a) Print numeral table, (b) Convert Roman numeral to decimal, (c) Convert decimal to Roman numeral" << endl;
		cin >> userOption;
		if (userOption != 'a' && userOption != 'b' && userOption != 'c') break;

		if (userOption == 'a')
		{
			printNumerals();
		}
		else if (userOption == 'b')
		{
			cout << "Please enter a Roman numeral you want to convert to decimal" << endl;
			string userNumeral;
			cin.ignore();
			getline(cin, userNumeral);
			while (!isValidNumeral(userNumeral))
			{
				cout << "Please enter a valid Roman numeral" << endl;
				cout << "Please note that a symbol representing 10^x may not precede any symbol larger than 10^(x+1)" << endl;
				cin.ignore();
				getline(cin, userNumeral);
			}

			int arabicNumeral = 0;
			for (int i = userNumeral.size() - 1; i >= 0; i -= 2)
			{
				if (i == 0)
				{
					arabicNumeral = arabicNumeral + romanToInt(userNumeral.at(i));
				}
				else if (romanToInt(userNumeral.at(i)) - romanToInt(userNumeral.at(i - 1)) > 0)
				{
					arabicNumeral = arabicNumeral + romanToInt(userNumeral.at(i)) - romanToInt(userNumeral.at(i - 1));
				}
				else
				{
					arabicNumeral = arabicNumeral + romanToInt(userNumeral.at(i)) + romanToInt(userNumeral.at(i - 1));
				}
			}

			cout << "Roman numeral \"" << userNumeral << "\" is \"" << arabicNumeral << "\" in decimal" << endl;
		}
		else
		{
			cout << "Please enter an integer from 1 to 3999 you want to convert to Roman numeral" << endl;
			int decimal;
			cin >> decimal;
			while (decimal < 1 && decimal > 3999) // Check input validity
			{
				cout << "Please enter an integer equal to or greater than 1" << endl;
				cin >> decimal;
			}

			string one[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
			string ten[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
			string hundred[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
			string thousand[] = { "", "M", "MM", "MMM" };
			string romanNumeral = "";

			romanNumeral = thousand[decimal / 1000] + hundred[decimal % 1000 / 100] + ten[decimal % 100 / 10] + one[decimal % 10];

			cout << "Decimal \"" << decimal << "\" is \"" << romanNumeral << "\" in Roman numeral" << endl;
		}
		cout << endl;
	}

	cout << endl << "Goodbye" << endl;
	

	return 0;
}