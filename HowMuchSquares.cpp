#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

int V[10][10], H[10][10];
int denet[10];
int deneme = 0;

int bul(int, int, int);

void main()
{

	int B, K;
	int isaret;


	fstream inputFile;
	fstream outputFile;

	string buffer[60];
	int i = 0, j = 0, k = 0, m = 0, saya = 0;
	int array[50], array2[50];


	inputFile.open("input.txt", std::fstream::in);

	outputFile.open("output.txt", std::fstream::out);



	cout << "Datas are getting from input.txt by program...";
	for (i = 0; i < 58; i++) {

		inputFile >> buffer[i];

	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {

			H[i][j] = 0;
			denet[i] = 0;
		}
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {


			V[i][j] = 0;
		}
	}

	for (i = 0; i < 48; i++) {
		if (buffer[i] == "H") {
			array[k] = stoi(buffer[i + 1]);
			array[k + 1] = stoi(buffer[i + 2]);

			H[array[k]][array[k + 1]] = 1;


			k += 2;
		}
		if (buffer[i] == "V") {
			array2[m] = stoi(buffer[i + 1]);
			array2[m + 1] = stoi(buffer[i + 2]);

			V[array2[m + 1]][array2[m]] = 1;

			m += 2;
		}
	}

	cout << endl;
	cout << endl;



	while (saya < 2)
	{

		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {

				H[i][j] = 0;
				denet[i] = 0;
			}
		}

		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {


				V[i][j] = 0;
			}
		}

		if (saya == 0) {

			B = stoi(buffer[0]);
			K = stoi(buffer[1]);

			for (i = 0; i < 48; i++) {
				if (buffer[i] == "H") {
					array[k] = stoi(buffer[i + 1]);
					array[k + 1] = stoi(buffer[i + 2]);

					H[array[k]][array[k + 1]] = 1;


					k += 2;
				}
				if (buffer[i] == "V") {
					array2[m] = stoi(buffer[i + 1]);
					array2[m + 1] = stoi(buffer[i + 2]);

					V[array2[m + 1]][array2[m]] = 1;

					m += 2;
				}
			}
		}
		if (saya == 1) {
			k = 0;
			m = 0;
			B = stoi(buffer[50]);
			K = stoi(buffer[51]);



			for (i = 50; i < 56; i++) {
				if (buffer[i] == "H") {
					array[k] = stoi(buffer[i + 1]);
					array[k + 1] = stoi(buffer[i + 2]);

					H[array[k]][array[k + 1]] = 1;


					k += 2;
				}
				if (buffer[i] == "V") {
					array2[m] = stoi(buffer[i + 1]);
					array2[m + 1] = stoi(buffer[i + 2]);

					V[array2[m + 1]][array2[m]] = 1;

					m += 2;
				}
			}
		}

		isaret = 0;

		for (int l = 1; l < B; l++)
		{
			for (i = 1; i <= B - l; i++)
			{
				for (j = 1; j <= B - l; j++)
				{
					if (bul(l, i, j))
						denet[l]++;
				}
			}
		}
		if (deneme != 0)
		{
			cout << "\n**********************************\n\n";
			outputFile << "\n**********************************\n\n";
		}
		cout << "Problem #" << ++deneme << "\n\n";
		outputFile << "Problem #" << deneme << "\n\n";

		for (i = 1; i < B; i++)
		{
			if (denet[i] != 0)
			{
				isaret = 1;
				cout << denet[i] << " square (s) of size " << i << endl;
				outputFile << denet[i] << " square (s) of size " << i << endl;
			}
		}
		if (0 == isaret) {
			cout << "No completed squares can be found.\n";
			outputFile << "No completed squares can be found.\n";
		}
		saya++;
	}
	cout << endl;
	cout << "You can look output.txt now!";
	cout << endl;
	cout << endl;
	system("PAUSE");
}

int bul(int a, int h, int v)
{
	for (int i = h; i < h + a; i++)
	{
		if (V[i][v] == 0 || V[i][v + a] == 0)
			return 0;
	}
	for (int j = v; j < v + a; j++)
	{
		if (H[h][j] == 0 || H[h + a][j] == 0)
			return 0;
	}
	return 1;
}