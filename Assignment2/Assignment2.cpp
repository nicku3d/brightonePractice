#include <iostream>

using namespace std;

int main()
{
	int numberOfCases;
	cin >> numberOfCases;

	int *amountOfNumbers= new int[numberOfCases];

	int** Numbers = new int*[numberOfCases];

	//memory allocation
	for (int caseNr = 0; caseNr < numberOfCases; caseNr++)
	{
		cin >> amountOfNumbers[caseNr];

		Numbers[caseNr] = new int[amountOfNumbers[caseNr]];
		for (int elementNr = 0; elementNr < amountOfNumbers[caseNr]; elementNr++)
		{
			cin >> Numbers[caseNr][elementNr];
		}
	}

	//checking cases
	for (int caseNr = 0; caseNr < numberOfCases; caseNr++)
	{
		bool isConditionTrue = false;

		int sumLeft = 0, sumRight = 0, current = 0;

		for (int current = 0; current < amountOfNumbers[caseNr]; current++)
		{
			for (int j = 0; j < amountOfNumbers[caseNr]; j++)
			{
				if (j < current)sumLeft += Numbers[caseNr][j];
				else if (j > current)sumRight += Numbers[caseNr][j];
			}

			if (sumLeft == sumRight)
			{
				isConditionTrue = true;
				cout << "Yes" << endl;
				break;
			}
			sumLeft = sumRight = 0;
		}

		if (isConditionTrue == false) cout << "No" << endl;
	}	////clearing memory
	for (int i = 0; i < numberOfCases; i++)
		delete[]Numbers[i];

	delete[]Numbers;
	Numbers = NULL;
	delete[]amountOfNumbers;	amountOfNumbers = NULL;
	return 0;
}