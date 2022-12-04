/**
Thomas Matz
CIS 1202.201
December 5, 2022
*/

#include <string>
#include <iostream>
	
using namespace std;

//Function Prototypes
char Character_Offset(char, int);

int main()
{
	char startLetter,returnedLetter;
	int offset;
	bool playAgain=1;
	while (playAgain)
	{
		cout << "\nEnter a start letter> ";
		cin >> startLetter;
		cout << "\nEnter an offset value> ";
		cin >> offset;
		try
		{
			returnedLetter = Character_Offset(startLetter, offset);
			cout << "\n\tFor the start letter of: " << startLetter;
			cout << "\n\t\tThe Offset character is: " << returnedLetter;
			cout << "\nEnter 1 to play again. or 0 to quit> ";
			cin >> playAgain;//we need to read playAgain here
					//after a successful offset
		}
		catch (string exceptionString)
		{
			cout << endl << exceptionString;
			//as we are in the catch block, playAgain is still true
		}
	}
	
	cout << endl << endl;
	system("pause");
	return 0;
}


char Character_Offset(char start, int offset)
{
	string invalidStartChar = "\n\tException for invalid character.  Start value is not a letter, try again.";
	int startEquivalentInASCII;
	int targetEquivalentInASCII;
	char targetChar;
	string invalidRangeChar = "\n\tException for invalid range. Try again.";
	
	if (!isalpha(start))
	{
		throw (invalidStartChar);
	}
	//compute the target value
	startEquivalentInASCII = toascii(start);
	//cout << "/n/tstart = " << startEquivalentInASCII;
	targetEquivalentInASCII = startEquivalentInASCII + offset;
	//cout << "/n/t/ttarget = " << targetEquivalentInASCII;
	targetChar = char(targetEquivalentInASCII);
	
	cout << endl << "\ttarget char is " << targetChar;

	bool targetIsInRange = true;
	
	if (!isalpha(targetChar))
		{
		cout << "\n\t  Not an alpha!";
			targetIsInRange = 0;
		}
	else if (!islower(targetChar) && islower(start))
		{
			cout << "\n\t  Not an alpha lower!";
			targetIsInRange = 0;
		}
	else if (!isupper(targetChar) && isupper(start))
		{
			cout << "\n\t  Not an alpha upper!";
			targetIsInRange = 0;
		}

	if (!targetIsInRange)
	{
		throw(invalidRangeChar);
	}

	//if made it to here.  Code did not throw an exception.
	// so return the value
	return targetChar;
}

