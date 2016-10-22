#include<iostream>
#include<ctime>
using namespace std;

/*
Type: int
Input types: 1 int
Purpose: To give a randum value based on the user race choice.
*/
int attack_value(int);

int main()
{
	int user_choice = 0, damage = 0;
	do
	{
		cout << "Pick a race from the menu:\n\t1). Dwarf\n\t2). Human\n\t3). Wizard\n\t4). Elf\n";
		cin >> user_choice;
		if (user_choice == 1)
		{
			cout << "\nYou are a dorf.";
		}
		else if (user_choice == 2)
		{
			cout << "\nYou'z a soft 'umie git.";
		}
		else if (user_choice == 3)
		{
			cout << "\nWizards have no sense of right or wrong.";
		}
		else if (user_choice == 4)
		{
			cout << "\nPansie elf lovers.";
		}
		else
		{
			cout << "\nERROR: Please enter a choice defined by the menu.\n";
		}
	} while (user_choice < 1 || user_choice > 4);
	damage = attack_value(user_choice);
	cout << "\nYou deal: " << damage << " damage.\n";
}


int attack_value(int mod)
{
	int attack_rand = 0;
	srand(time(NULL));

	attack_rand = rand() % 15 + 1;
	return attack_rand*mod;

}