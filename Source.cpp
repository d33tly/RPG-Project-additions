#include<iostream>
#include<string>
#include<fstream>
#include<ios>
#include<iomanip>
using namespace std;

/*
Return types: void
Types: 1 string, 1 int
Purpose: write to the highscores.txt
*/
void Write_Score(string name, int score);

/*
Return type: Void
Types: N/A
Purpose: Read the highscores.txt
*/
void Read_Score();

int main()
{
	string usr_name;
	int usr_score = 0;
	do
	{
		cout << "Enter your name: ";
		cin >> usr_name;
		if (size(usr_name) >= 7)
		{
			cout << "\nError, enter a username less than or equal to 6 characters in length.\n";
		}
		else
		{
			cout << "\nThank you.\n";
		}
	} while (size(usr_name)>= 7);
	cout << endl;
	cout << "Enter your score: ";
	cin >> usr_score;
	cout << endl;
	Write_Score(usr_name, usr_score);
	cout << endl << endl << endl;
	Read_Score();

}

void Write_Score(string name, int score)
{
	ofstream outfile;
	outfile.open("Highscores.txt", ios::app);
	outfile << name << "\t\t\t" << score << endl;
	outfile.close();
}

void Read_Score()
{
	int score = 0;
	string name;
	ifstream infile;
	infile.open("Highscores.txt", ios::in);
	cout << "Username\t\tScore\n";
	cout << "-----------------------------\n";
	while (infile >> name >> score)
	{
		cout << name << "\t" << setw(10) << score << endl;
	}
	infile.close();
}