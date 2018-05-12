#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <fstream>

using namespace std;

int main()
{

	vector<unsigned char> container;
	unsigned char buffer1 = 0, buffer2 = 0;
	bool isHex = false;

	ifstream inputFile("input.txt");
	if (!inputFile.good())
	{
		cout << "Blad : Plik nie istnieje, stworz plik o nazwie input.txt" << endl;
		return -1;
	}
	int counter = 0;
	while (inputFile >> buffer1)
	{

		if (buffer1 >= 48 && buffer1 <= 57)//(0-9)
		{
			buffer1 = buffer1 - 48;
			isHex = true;

		}
		else if (buffer1 >= 65 && buffer1 <= 70)//(A-F)
		{
			buffer1 = buffer1 - 55;
			isHex = true;
		}
		else if (buffer1 >= 97 && buffer1 <= 102)//(a-f)
		{
			buffer1 = buffer1 - 87;
			isHex = true;
		}

		if (isHex)
		{
			counter++;
			if ((counter % 2) == 0)
				buffer2 += buffer1;
			else
				buffer2 = buffer1 << 4;

			if ((counter % 2) == 0)
				container.push_back(buffer2);

			isHex = false;
		}
	}

	if ((counter % 2) == 1)
	{
		container.push_back(buffer1);
	}

	inputFile.close();

	vector <unsigned char> odd, even;

	for (auto it : container)
	{
		bitset<8> bit(it);
		if ((bit.count() % 2) == 0)
			even.push_back(it);
		else
			odd.push_back(it);
	}

	sort(even.begin(), even.end());//ascending sort
	sort(odd.rbegin(), odd.rend());//descending sort

	ofstream outputFile("output.txt");

	if (!outputFile.good())
	{
		cout << "B³¹d, nie uda³o siê zapisaæ wyniku" << endl;
		return -1;
	}


	for (auto element : even)
	{
		outputFile << hex << (int)element<<" ";
	}

	outputFile << endl;

	for (auto element : odd)
	{
		outputFile << hex << (int)element<<" ";
	}
	
	outputFile.close();

	return 0;
}