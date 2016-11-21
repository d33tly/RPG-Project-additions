/*
Project 1.1
Team 1 -
Dalton McClain
Elliot Wolff
Nicanor Lapaix
9/23/16

Create a RP word game for all users who play it to be amazed at how awesome it is!
*/
//Pre-processor stuff
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <ios>
#include <iomanip>
#include <ctime>
using namespace std;

//Declaring the functions for use in main
int youLose(int gold);
int heroStats(int hp, int hero_hp, int gold);
int storyContinued(int hero_hp, int total_hero_hp, int hero_dmg, int gold, int gold_mod, int gold_drop, int race_choice, string cont_break, int bandit_hp, int bandit_dmg, int user_choice, int user_try, int user_input, int user_final_choice, int minotaur_hp, int minotaur_dmg, int evil_wizard_hp, int evil_wizard_dmg);
void resetVariable(int &hero_hp, int &total_hero_hp, int &hero_dmg, int &zombie_hp, int &bandit_hp, int &minotaur_hp, int &evil_wizard_hp, int &zombie_dmg, int &bandit_dmg, int &minotaur_dmg, int &evil_wizard_dmg, int &gold, int &gold_mod, int &gold_drop, int &race_choice, int &hallway_choice, int &user_choice, int &user_try, int &user_final_choice, int &user_input, int &play_again);
void credits();
void Write_Score(int score);
void Read_Score();
int attack_value(int race_choice);
int mainMenu(int user_choice);
void Rules();
void compare_score(string uname, int score);
void raceChoice(int &race_choice, int &gold_mod, int &total_hero_hp, int &hero_hp, string &cont_break);
void ReplaceScores(string usname0, string usname1, string usname2, int uscore0, int uscore1, int uscore2);
void Beginning(int &hero_hp, int &total_hero_hp, int &hero_dmg, int &zombie_hp, int &bandit_hp, int &minotaur_hp, int &evil_wizard_hp, int &zombie_dmg, int &bandit_dmg, int &minotaur_dmg, int &evil_wizard_dmg, int &gold, int &gold_mod, int &gold_drop, int &race_choice, int &hallway_choice, int &user_choice, int &user_try, int &user_final_choice, int &user_input, int &play_again, string cont_break);


//Define the main function
int main()
{
		//Declare and initiate variables
		int hero_hp = 0,         //HERO HP
			total_hero_hp = 0,   /////////
								 //-------------------
			hero_dmg = 0,        //HERO DAMAGE
								 //-------------------
			zombie_hp = 20,      //ENEMY HEALTH POINTS
			bandit_hp = 75,      /////////////////////
			minotaur_hp = 150,   /////////////////////
			evil_wizard_hp = 200,/////////////////////
								 //-------------------
			zombie_dmg = 5,      //ENEMY DAMAGE
			bandit_dmg = 12,     //////////////
			minotaur_dmg = 10,   //////////////
			evil_wizard_dmg = 20,//////////////
								 //-------------------
			gold = 0,            //GOLD STUFF
			gold_mod = 0,        ////////////
			gold_drop = 0,       ////////////
								 //-------------------
			race_choice = 0,     //ASSORTED
			hallway_choice = 0,  //////////
			user_choice = 0,     //////////
			user_try = 1,        //////////
			user_final_choice = 0,/////////
			user_input = 0,      //////////
			play_again = 0;		 //////////
								 //Strings------------
		string cont_break;   //STRING
		cout << "\t\t\tWELCOME TO TEAM 1's GAME!\n\n";
		cout << "\t\t\t#########################";
		cout << "\n\t\t\t#++ Quest for Midgard ++#";
		cout << "\n\t\t\t#########################\n";

	//While loop to handle the validation of user choice
	do {
		resetVariable(hero_hp,total_hero_hp,hero_dmg,zombie_hp,bandit_hp,minotaur_hp,evil_wizard_hp,zombie_dmg,bandit_dmg,minotaur_dmg,evil_wizard_dmg,gold,gold_mod,gold_drop,race_choice,hallway_choice,user_choice,user_try,user_final_choice,user_input,play_again);
		//Display menu for user
		user_choice = mainMenu(user_choice);

		if (user_choice == 1) {
		Rules();
		}
		else if (user_choice == 2)
		{
			raceChoice(race_choice, gold_mod, total_hero_hp, hero_hp, cont_break);
			Beginning(hero_hp, total_hero_hp, hero_dmg, zombie_hp, bandit_hp, minotaur_hp, evil_wizard_hp, zombie_dmg, bandit_dmg, minotaur_dmg, evil_wizard_dmg, gold, gold_mod, gold_drop, race_choice, hallway_choice, user_choice, user_try, user_final_choice, user_input, play_again, cont_break);
		}
		//EXIT GAME
		else if (user_choice == 4) {
			cout << "\nPress any key to exit!\n";
			user_choice = 0;
		}
		else if (user_choice == 3) {
			Read_Score();
		}
		else {
			cout << "\nPlease choose from the menu above ...\n";
		}

	} while (user_choice != 0);



	return 0;
}

int youLose(int gold) {

	cout << "\n\n///////////////////////////////////";
	cout << "\n//00//////00////000//////0/////0///";
	cout << "\n///00////00////0///0/////0/////0///";
	cout << "\n////00//00////0/////0////0/////0///";
	cout << "\n/////0000/////0/////0////0/////0///";
	cout << "\n//////00//////0/////0////0/////0///";
	cout << "\n//////00///////0///0//////0///0////";
	cout << "\n//////00////////000////////000/////";
	cout << "\n///////////////////////////////////\n";


	cout << "\n\n//////////////////////////////////////////";
	cout << "\n///0///////////000////////0000/////00000//";
	cout << "\n///0//////////0///0//////0/////////0//////";
	cout << "\n///0/////////0/////0/////0/////////0//////";
	cout << "\n///0/////////0/////0//////000//////0000///";
	cout << "\n///0/////////0/////0/////////0/////0//////";
	cout << "\n///0//////////0///0//////////0/////0//////";
	cout << "\n///000000//////000///////0000//////00000//";
	cout << "\n//////////////////////////////////////////\n";

	cout << "\nYou lost the game with " << gold << " pieces of gold\n";

	return 0;
}

int heroStats(int hp, int hero_hp, int gold) {
	cout << "\n#######################################"; //40 # signs
	cout << "\n\tHP = " << hp << "/" << hero_hp << "  Gold = " << gold << endl;
	cout << "#######################################\n"; //30 # signs

	return 0;
}

int storyContinued(int hero_hp, int total_hero_hp, int hero_dmg, int gold, int gold_mod, int gold_drop, int race_choice, string cont_break, int bandit_hp, int bandit_dmg, int user_choice, int user_try, int user_input, int user_final_choice, int minotaur_hp, int minotaur_dmg, int evil_wizard_hp, int evil_wizard_dmg) {
	cout << "\nPress enter to continue ...";
	getline(cin, cont_break);

	cout << "\nAs you enter the room after finding your way through the winding halls,";
	cout << "\na sense of danger fills you. You look around all too late as you see your ";
	cout << "\nattacker upon you. A man wearing rags with a hood brandishing a ceremonial";
	cout << "\nknife. There would be no reasoning with him, he lay here only to steal from ";
	cout << "\nthose who wished to kill the Wizard.\n\n";

	//Enemy gold
	gold_drop = gold_mod * bandit_hp;

	while (bandit_hp > 0) {
		//PAUSE FOR USER TO ATTACK
		cout << "\n\nPress enter to ATTACK!";
		getline(cin, cont_break);

		//HERO ATTACK
		hero_dmg = attack_value(race_choice);
		cout << "\nYOU ATTACKED IT! Dealing " << hero_dmg << " damage!\n";
		bandit_hp -= hero_dmg;

		//BANDIT ATTACK
		cout << "\nBANDIT HITS YOU! Dealing " << bandit_dmg << " damage!\n";
		hero_hp -= bandit_dmg;

		//COMBAT GUI
		cout << "\n++++++++++++++++++++++++++++++\n";//30 + signs

													 //BANDIT HP
		cout << "\tBandit HP = ";

		//To display 0 if damage takes hp under 0, as to not display a negative number for hp
		if (bandit_hp < 0) {
			cout << 0 << endl;
		}
		else {
			cout << bandit_hp << endl;
		}

		//HERO HP
		cout << "\tHero HP = ";// << hero_hp << endl;

		//To display 0 if damage takes hp under 0, as to not display a negative number for hp
		if (hero_hp < 0) {
			cout << 0 << endl;
		}
		else {
			cout << hero_hp << endl;
		}

		//COMBAT GUI
		cout << "++++++++++++++++++++++++++++++\n";//30 + signs

		if (hero_hp <= 0) {
			youLose(gold);
			user_choice = 0;
			bandit_hp = -1;
		}
		else if (bandit_hp <= 0) {
			cout << "\nWell done!  You killed the bandit!\n";
			cout << "The bandit disappears and you see something on the ground,\n";
			gold += gold_drop;
			cout << "you found " << gold_drop << " gold pieces!\n";


			cout << "\n#######################################"; //40 # signs
			cout << "\n\tHP = " << hero_hp << "/" << total_hero_hp << "  Gold = " << gold << endl;
			cout << "#######################################\n"; //30 # signs

			gold_drop = 0;
		}
	}
	if (hero_hp > 0) {
		cout << "\n\nThis room gave a sense of ease to your body, as you feel invigorated";
		cout << "\njust entering it. The lighting here was not like the others, it was";
		cout << "\nfull of life and dimly lit by slowly burning torches.";
		cout << "\nThe fey spirits in this room illuminated it faintly with a soft";
		cout << "\nblue light, all of which centered upon a set of armor. It lay on a ";
		cout << "\npedestal, the fey spirits protecting it from the evils";
		cout << "\nof Zana.";

		cout << "\n\nPress enter to continue...\n";
		getline(cin, cont_break);

		cout << "\nThe fey spirits whisper something to you,\n";
		cout << "\n\'come here and take this\'\n";
		cout << "\nIt seems they want you to take the armor,";
		cout << "\nAs you approach the armor, you can see an inscription on the";
		cout << "\npedestal itself. It reads \"Here lies the armor of the fallen king.";
		cout << "\nThrough any battle, this armor would not fail him, until his own mind";
		cout << "\nfinally did.\" A smaller inscription below reading...\n";

		cout << "\nPress enter to continue ...";
		getline(cin, cont_break);

		cout << "\nto receive this armor you must solve the following mythical equation ";
		cout << "\nwithin three tries, if you don't, you DIE!";
		cout << "\n(144-(12)*2)*14+12/6 = ";


		do {
			cout << "\nGuess#" << user_try << ": ";
			cin >> user_input;
			cin.ignore();

			if (user_input == 1682 && user_try <= 3) {
				cout << "\nAs you inscribe the answer, the armor floats towards you";
				cout << "\ncarried by the spirits protecting it, the wall behind it opening up,";
				cout << "\nallowing you to pass through most of the castle without stop. Ahead,";
				cout << "\na bright light leading the way through this long and narrow corridor...";
				cout << "\n\nThe spirits put the armor on you and you feel invigorated!";
				cout << "\n\nHP is full, not only that but is has increased!";
				cout << "\nYour HP was at " << hero_hp << "/" << total_hero_hp;
				total_hero_hp *= gold_mod;
				hero_hp = total_hero_hp;
				cout << "\nYour HP is now " << hero_hp << "/" << total_hero_hp << endl;

				//PAUSE FOR USER TO READ
				cout << "\nPress enter to continue ...";
				getline(cin, cont_break);

				break;
			}
			else if (user_input < 0 && user_try <= 2) {//Elliot: Changed the wording
				cout << "\nThe fey spirits whisper into your ears, telling you to remain positive and in high hopes!\n";
				user_try += 1;
			}
			else if (user_input >= 0 && user_try <= 2) {
				cout << "\nTry again!\n";
				user_try += 1;
			}
			else if (user_try >= 3) {
				youLose(gold);
				user_choice = 0;
				break;
			}

		} while (user_try <= 3);

		//CONTINUE!!!
		if (user_input == 1682 && user_try <= 3) {
			cout << "\nAs you walk down the narrow path, you see a faint light in the distance, \nyou move closer...\n";
			cout << "\nThe smell of blood, and the roar of a great beast comes from ahead.";
			cout << "\nA well lit room painted red by fallen enemies lies before you. A massive ";
			cout << "\nminotaur armed with an axe larger than you stands between you and the";
			cout << "\ndoor to the wizard. It's breath smelled of blood and anger, and it";
			cout << "\nseemed more than ready to kill you for entering it's domain.";
			cout << "\nThere would be no getting around it,you must face this threat head on.\n\n";

			//Enemy gold
			gold_drop = gold_mod * minotaur_hp;

			while (minotaur_hp > 0) {//do{
									 //PAUSE FOR USER TO READ
				cout << "\n\nPress enter to ATTACK!";
				getline(cin, cont_break);

				//HERO ATTACK
				hero_dmg = attack_value(race_choice);
				cout << "\nYOU ATTACKED IT! Dealing " << hero_dmg << " damage!\n";
				minotaur_hp -= hero_dmg;

				//MINOTAUR ATTACK
				cout << "\nMINOTAUR HITS YOU! Dealing " << minotaur_dmg << " damage!\n";
				hero_hp -= minotaur_dmg;

				//COMBAT GUI
				cout << "\n++++++++++++++++++++++++++++++\n";//30 + signs

															 //MINOTAUR HP
				cout << "\tMinotaur HP = ";

				//To display 0 if damage takes hp under 0, as to not display a negative number for hp
				if (minotaur_hp < 0) {
					cout << 0 << endl;
				}
				else {
					cout << minotaur_hp << endl;
				}

				//HERO HP
				cout << "\tHero HP = ";// << hero_hp << endl;

				//To display 0 if damage takes hp under 0, as to not display a negative number for hp
				if (hero_hp < 0) {
					cout << 0 << endl;
				}
				else {
					cout << hero_hp << endl;
				}

				//COMBAT GUI
				cout << "++++++++++++++++++++++++++++++\n";//30 + signs

				if (minotaur_hp <= 0) {//Elliot: Changed victory text
					cout << "\nThe hulking creature stumbles before falling to the ground dead.\nOn it's corpse you notice that it had something in it's pocket,\n";
					gold += gold_drop;
					cout << "you found " << gold_drop << " gold pieces!\n";

					cout << "\n#######################################"; //40 # signs
					cout << "\n\tHP = " << hero_hp << "/" << total_hero_hp << "  Gold = " << gold << endl;
					cout << "#######################################\n"; //30 # signs

					gold_drop = 0;

					//PAUSE FOR USER TO READ
					cout << "\nPress enter to continue ...";
					getline(cin, cont_break);

					cout << "\nYou notice something else! Something shiny and red...\n";
					cout << "\nYou pick up what looks to be a gem on a chain, with an inscription on the back, ";
					cout << "\nIt reads... \'The wearer of this gem will be granted great strength\'";
					cout << "\nYou put the chain around your neck and immediately feel different!";
					cout << "\nYou feel as though your strength has doubled, like that of a minotaur's!";//Elliot: Changed some wording
					cout << "\n\nYour damage has doubled!";
					hero_hp = total_hero_hp;
					cout << "\nYou HP is full! " << hero_hp << "/" << total_hero_hp;

				}
				else if (hero_hp <= 0) {
					youLose(gold);
					user_choice = 0;
					minotaur_hp = -1;
				}
			}
			//CONTINUE
			if (hero_hp > 0) {
				//PAUSE FOR USER TO READ
				cout << "\n\nPress enter to continue ...";
				getline(cin, cont_break);

				cout << "\n\nAs you enter the room you can see dark and proface scriptures written";
				cout << "\nupon all of the walls and ground. The gibbering madman, Zana, standing at";
				cout << "\nthe center. \"You are too late, mortal, for my ritual of ascension is complete!";
				cout << "\nWith this, I shall have the immortality which is rightfully mine,";
				cout << "\nwith but just one more sacrifice. YOU!\" as he begins to lift off";
				cout << "\nof the ground, lighting and fire crackling from his hands,";
				cout << "\nhis beard flowing as the winds begin to stir in the room.\n\n";

				//Enemy gold
				gold_drop = gold_mod * evil_wizard_hp;

				while (evil_wizard_hp > 0) {
					//PAUSE FOR USER TO READ
					cout << "\n\nPress enter to ATTACK!";
					getline(cin, cont_break);

					//HERO ATTACK
					hero_dmg = attack_value(race_choice)*2;
					cout << "\nYOU ATTACKED IT! Dealing " << hero_dmg << " damage!\n";
					evil_wizard_hp -= hero_dmg;

					//ZANA ATTACK
					cout << "\nZANA HITS YOU! Dealing " << evil_wizard_dmg << " damage!\n";
					hero_hp -= evil_wizard_dmg;

					//COMBAT GUI
					cout << "\n++++++++++++++++++++++++++++++\n";//30 + signs

																 //ZANA HP
					cout << "\tZana's HP = ";

					//To display 0 if damage takes hp under 0, as to not display a negative number for hp
					if (evil_wizard_hp < 0) {
						cout << 0 << endl;
					}
					else {
						cout << evil_wizard_hp << endl;
					}

					//HERO HP
					cout << "\tHero HP = ";// << hero_hp << endl;

					//To display 0 if damage takes hp under 0, as to not display a negative number for hp
					if (hero_hp < 0) {
						cout << 0 << endl;
					}
					else {
						cout << hero_hp << endl;
					}

					//COMBAT GUI
					cout << "++++++++++++++++++++++++++++++\n";//30 + signs

					if (evil_wizard_hp <= 0) {
						cout << "\nZana falls to the ground, his broken and battered body unable";
						cout << "\nto revive himself. He has lost, and lays bleeding on the ground.";
						cout << "\nYou may end his life, ending any chance of his evil ever returning to Midgard...";
						cout << "\nWhat do you want to do?...\n";

						do {
							cout << "\n1) Kill him\n2) Show mercy\n";
							cout << "Choice: ";
							cin >> user_final_choice;

							if (user_final_choice == 1) {
								cout << "\nYou swiftly bring off Zana's head, which rolls to the center of the room.";
								cout << "\nThe runes across the room light up as you are lifted for a moment.";
								cout << "\nYou can feel power unimaginable coursing through your body as you have";
								cout << "\ncompleted the ritual Zana had spent so long trying to do. You have become";
								cout << "\neverything he had wanted, you are immortal.\n";
							}
							else if (user_final_choice == 2) {//Elliot: Changed "sorrow and regret" into just "Sorrow"
								cout << "\nYou hold your hand out to the dying old man, who looks at you with sorrow";
								cout << "\nin his eyes. He takes it solemnly, knowing he has lost as you";
								cout << "\nlift him. He will pay for his crimes, but he will do so by trial.";
								cout << "\nYou are not his judge nor his executioner,";
								cout << "\nthat shall be left for the now freed people of Midgard,";
								cout << "\nwho shall rejoice in this age of coming light.\n";
							}
							else if (user_final_choice < 1 || user_final_choice > 2) {
								cout << "\nPlease choose from the menu above...\n";
							}
						} while (user_final_choice < 1 || user_final_choice > 2);
						cout << "\nZana has been killed and you find a massive amount of gold pieces";
						gold += gold_drop;
						cout << "\nYou found " << gold_drop << " gold pieces!\n";

						cout << "\n#######################################"; //40 # signs
						cout << "\n\tHP = " << hero_hp << "/" << total_hero_hp << "  Gold = " << gold << endl;
						cout << "#######################################\n"; //30 # signs

						gold_drop = 0;
					}
					else if (hero_hp <= 0) {
						youLose(gold);
						user_choice = 0;
						evil_wizard_hp = -1;
					}
				}
				if (hero_hp > 0) {
					//Display ending story
					if (user_final_choice == 1) {
						//PATH CHOICE LEADS TO DARKNESS
						if (race_choice == 1) {
							cout << "\nWith the new immortality granted by Zana's foul magics,\nThorin began a crusade to free all the dwarves of Midgard.\nHe found anywhere they were enslaved to mines,\nkilling the captors and freeing his people.\nYet, even as more of his people became freed," << endl << "he needed more metals to create his armies.\n He soon turned to enslaving his own people in order to fund\nhis crusade for freedom.\n";
						}
						else if (race_choice == 2) {
							cout << "\nWith immortality attained, it corrupted Leo to the core.\nLeo had merely switched out one tyrant for another,\nbecoming the new dark lord of Midgard. He raised humanity to a new pinnacle,\nwhere all races must bow to them for they were mere slaves to their dark lord.\nEventually, this treatment began killing off the other races,\nuntil only humans remained,killing each other over the scraps\nwhich were left behind in this ruined world.\n";
						}
						else if (race_choice == 3) {
							cout << "\nPlacing her hand to Zana's dying forehead,\nAlice whispered a spell which would end Zana's suffering painlessly.\nThere had been no other way, his body too broken for even the most\npowerful healers to repair. Alice lay there, weeping,\nas the spell of immortality was complete,\nshe was now forced to live an immortal life knowing what she had done.\n";
						}
						else {
							cout << "\nWith Meliodas defeating the wizard Zana, he was welcomed home\nwith grandeur. A feast was held in his honor, and a statue made in his likeness.The elven image as a whole was bolstered by this accomplishment,\nenough so that the elves became the new dominant race in midgard,\ntheir immortal king Meliodas paving the way for their empire in blood.\n";
						}
					}
					else if (user_final_choice == 2) {
						//PATH CHOICE LEADS TO THE LIGHT
						if (race_choice == 1) {
							cout << "\nThorin took Zana alive, travelling to each of the mines\nso Zana could see the folly of his own ways.\nHe forced Zana to look into the eyes of the enslaved\ndwarves, to see how his minions treated Thorin's people.\nZana soon began to change, the pain in every dwarf's eyes shattering the evil\nthat had gripped his heart. Zana, before they travelled to the final mine,\nbegged for redemption and eventually leaving to become a hermit so\nhe may never harm another being.\n";
						}
						else if (race_choice == 2) {
							cout << "\nThe evil wizard Zana showed no redemption when jailed within\nLeo's home town. It was a shame, as the trial began, he raved like a lunatic,\nswearing death to all those around him, calling them\ntraitors to his rightful rule. In the end, he was put to death for his\ncrimes against Midgard, leaving the world without the great mind\nZane had once been.\n";
						}
						else if (race_choice == 3) {
							cout << "\nWith Zana lying on the ground defeated, Alice saw a glimmer in his pocket.\nSmashing what she knew to be the gem which had thrown Zane into this madness,\nan air of calm flowed through the room for a moment before both were brought to tears. Zane had returned once more, and they spent his last\nmoments weeping together. Zana had died on that day,\nand with it he took one of the brightest minds Midgard had ever seen.\n";
						}
						else {
							cout << "\nFeeling generous Meliodas decided to spare the wizard's life,\nand turn him over to the authorities instead. In exchange the town's folk\ngave him all the money they had, and praised as a savior to all of Midgard.\nHowever, upon the elves hearing that he had the chance to kill Zana\nand didn't take it, as well as meddling in the affairs of other races, Meliodas\nwas banished from his homeland to never return.\n";
						}
					}

				}
				Write_Score(gold);
				credits();
				user_choice = 0;

			}

		}//IF FOR PASSING THE EQUATION
	}
	//Declare and initiate variables
	return 0;
}

void resetVariable(int &hero_hp, int &total_hero_hp, int &hero_dmg, int &zombie_hp, int &bandit_hp, int &minotaur_hp, int &evil_wizard_hp, int &zombie_dmg, int &bandit_dmg, int &minotaur_dmg, int &evil_wizard_dmg, int &gold, int &gold_mod, int &gold_drop, int &race_choice, int &hallway_choice, int &user_choice, int &user_try, int &user_final_choice, int &user_input, int &play_again)
{
	//Declare and initiate variables
		hero_hp = 0,         //HERO HP
		total_hero_hp = 0,   /////////
							 //-------------------
		hero_dmg = 0,        //HERO DAMAGE
							 //-------------------
		zombie_hp = 20,      //ENEMY HEALTH POINTS
		bandit_hp = 75,      /////////////////////
		minotaur_hp = 150,   /////////////////////
		evil_wizard_hp = 200,/////////////////////
							 //-------------------
		zombie_dmg = 5,      //ENEMY DAMAGE
		bandit_dmg = 12,     //////////////
		minotaur_dmg = 10,   //////////////
		evil_wizard_dmg = 20,//////////////
							 //-------------------
		gold = 0,            //GOLD STUFF
		gold_mod = 0,        ////////////
		gold_drop = 0,       ////////////
							 //-------------------
		race_choice = 0,     //ASSORTED
		hallway_choice = 0,  //////////
		user_choice = 0,     //////////
		user_try = 1,        //////////
		user_final_choice = 0,/////////
		user_input = 0,      //////////
		play_again = 0;		 //////////
}

void credits()
{
	Sleep(10000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << "\t\t\t#########################";
	cout << "\n\t\t\t#++ Quest for Midgard ++#";
	cout << "\n\t\t\t#########################\n";
	Sleep(1000);
	cout << "\t\t\t      C";
	Sleep(150);
	cout << "r";
	Sleep(150);
	cout << "e";
	Sleep(150);
	cout << "a";
	Sleep(150);
	cout << "t";
	Sleep(150);
	cout << "e";
	Sleep(150);
	cout << "d";
	Sleep(150);
	cout << " b";
	Sleep(150);
	cout << "y:\n";
	Sleep(750);
	cout << endl;
	Sleep(750);
	cout << "\t\t\t      D";
	Sleep(150);
	cout << "a";
	Sleep(150);
	cout << "l";
	Sleep(150);
	cout << "t";
	Sleep(150);
	cout << "o";
	Sleep(150);
	cout << "n";
	Sleep(150);
	cout << " M";
	Sleep(150);
	cout << "c";
	Sleep(150);
	cout << "C";
	Sleep(150);
	cout << "l";
	Sleep(150);
	cout << "a";
	Sleep(150);
	cout << "i";
	Sleep(150);
	cout << "n\n";
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << "\t\t\t      N";
	Sleep(150);
	cout << "i";
	Sleep(150);
	cout << "c";
	Sleep(150);
	cout << "a";
	Sleep(150);
	cout << "o";
	Sleep(150);
	cout << "r";
	Sleep(150);
	cout << " L";
	Sleep(150);
	cout << "a";
	Sleep(150);
	cout << "p";
	Sleep(150);
	cout << "a";
	Sleep(150);
	cout << "i";
	Sleep(150);
	cout << "x\n";
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << "\t\t\t      E";
	Sleep(150);
	cout << "l";
	Sleep(150);
	cout << "l";
	Sleep(150);
	cout << "i";
	Sleep(150);
	cout << "o";
	Sleep(150);
	cout << "t";
	Sleep(150);
	cout << " W";
	Sleep(150);
	cout << "o";
	Sleep(150);
	cout << "l";
	Sleep(150);
	cout << "f";
	Sleep(150);
	cout << "f\n\n";
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
	Sleep(1000);
	cout << endl;
}

void Write_Score(int score)
{
	string usr_name;
	do
	{
		cout << "Enter your name, hero: ";
		cin >> usr_name;
		if (size(usr_name) != 3)
		{
			cout << "\nError, enter a username of 3 characters.\n";
		}
	} while (size(usr_name) != 3);
	compare_score(usr_name, score);
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
		cout << name << "\t" <<"\t"<< setw(13) << score << endl;
	}
	infile.close();
}

int attack_value(int mod)
{
	int attack_rand = 0;
	srand(time(NULL));

	attack_rand = rand() % 18 + 2;
	return attack_rand*mod;

}

int mainMenu(int user_choice)
{
	do {
		cout << "\n1) Rules\n2) Play Game\n3) Highscores\n4) Exit\n";
		cout << "Please choose from the list above: ";
		cin >> user_choice;
		cin.ignore();
		if (user_choice > 4 || user_choice < 1)
		{
			cout << "ERROR: You must select from the given menu.";
		}
	} while (user_choice > 4 || user_choice < 1);
	return user_choice;
}

void Rules()
{
	cout << "\nRules: ";
	cout << "\n\t1) In order to make any choices, use only the menu options available.";
	cout << "\n\t2) Your race chooses your difficulty, which will increase your gold.";
	cout << "\n\t3) Whenever you pick up an item, your health will be replenished.";
	cout << "\n\t4) You want to kill the wizard, don't run.";
	cout << "\n\t5) Don't use letters, or the world will be destroyed.\n";
}

void compare_score(string uname, int score)
{
	int uscore[3] = { 0 };
	string usname[3];
	ifstream infile;
	infile.open("Highscores.txt", ios::in);
	for (int j = 0; j < 3; j++)
	{
		infile >> usname[j] >> uscore[j];
	}
	if (score > uscore[0])
	{
		uscore[2] = uscore[1];
		usname[2] = usname[1];
		uscore[1] = uscore[0];
		usname[1] = usname[0];
		uscore[0] = score;
		usname[0] = uname;
	}
	else if (score > uscore[1])
	{
		uscore[2] = uscore[1];
		usname[2] = usname[1];
		uscore[1] = score;
		usname[1] = uname;
	}
	else if (score > uscore[2])
	{
		uscore[2] = score;
		usname[2] = uname;
	}
	infile.close();
	ReplaceScores(usname[0], usname[1], usname[2], uscore[0], uscore[1], uscore[2]);
}

void raceChoice(int &race_choice, int &gold_mod, int &total_hero_hp, int &hero_hp, string &cont_break)
{
	//Zana backstory
	cout << "\nThe evil wizard Zana has taken over the land of Midgard,\nenslaving all races who could not flee or protect themselves from his power.\nThe world is enslaved and on the brink of destruction, yet it is\nin times like these that heroes rise to the call to push back the\ndarkness so light may reign once more. You are one such hero, having\nbroken through to gates of Zana’s castle, ready to end his reign\nthrough fire and sword.\n";

	//Validation loop
	do {
		//Create race list
		cout << "\n\t1) Dwarf(Easy)";
		cout << "\n\t2) Human(Medium)";
		cout << "\n\t3) Wizard(Hard)";
		cout << "\n\t4) Elf(Ultra-Hard)\n";

		//Prompt user for choice
		cout << "\nPlease choose your desired race from the menu above: ";
		cin >> race_choice;
		cin.ignore();

		//Create validation for race choice and display story for chosen race
		if (race_choice == 1) {

			//Assign dwarf hero variables
			total_hero_hp = 150;
			hero_hp = 150;
			gold_mod = 1;

			//Display users race choice and hero name
			cout << "\nYou have chosen the Dwarfs path ...\n";
			cout << "\nYour characters name is Thorin\n";

			cout << "\nAfter Zana's control over Midgard the dwarves were sentenced to a life within";
			cout << "\nthe caves. Every day they were toiling away at the caves collecting any jewels";
			cout << "\nor gold they came across. It was a harsh life but a tolerable one for Thorin,";
			cout << "\nas long as his family was together everything would be fine, or so he thought.";
			cout << "\nAfter a cave in killed half of his family he pleaded to Zana's underlings to";
			cout << "\nallow him to grieve for the family he lost they were having none of it however,";
			cout << "\nand soon the rest of his family followed. Now alone in a hellish nightmare";
			cout << "\nhe only seeks one thing, VENGEANCE, and he will do anything to achieve it.";
			cout << "\nHe wants Zana to die for everything he's done \nand he will do it with his own two hands.\n";

			//Put a break in so the user isn't overwhelmed by all of the reading
			cout << "\nPress enter to continue ...";
			getline(cin, cont_break);
		}
		else if (race_choice == 2) {

			//Assign human hero variables
			total_hero_hp = 100;
			hero_hp = 100;
			gold_mod = 2;

			//Display users race choice and hero name
			cout << "\nYou have chosen the Humans path ...\n";
			cout << "\nYour characters name is Leo\n";

			cout << "\nAfter being tormented under the rule of Zana since he was born,";
			cout << "\nhis parents had been lesser nobility under his reign. Yet, when his parents";
			cout << "\nwere killed before him for displeasing Zana, he knew what he must do.";
			cout << "\nHe decided to take matters into his own hands, taking up sword";
			cout << "\nto free the people of Midgard from the darkness that it";
			cout << "\nhad been plunged into.\n";

			//Put a break in so the user isn't overwhelmed by all of the reading
			cout << "\nPress enter to continue ...";
			getline(cin, cont_break);
		}
		else if (race_choice == 3) {

			//Assign wizard hero variables
			total_hero_hp = 75;
			hero_hp = 75;
			gold_mod = 3;

			//Display users race choice and hero name
			cout << "\nYou have chosen the Wizards path ...\n";
			cout << "\nYour characters name is Alice\n";

			cout << "\nAlice was the apprentice to Zane.. A very kind wizard that taught";
			cout << "\nany and all people that were willing to seek guidance in wizardry.";
			cout << "\nAlice is one such pupil, in fact she was the best student he ever had.";
			cout << "\nSo much so that they went on journey's together all the time throughout";
			cout << "\nthe land of Midgard. One such journey led them to a cave where a gem of";
			cout << "\npower was said to lie in dormant. Curious by the tale the master and the";
			cout << "\napprentice searched the cave for days, until finally stumbling upon it.";
			cout << "\nAlthough the gem granted immense power, it also changed the user,";
			cout << "\nturning Zane from a kind man into the evil sorcerer Zana. Alice plagued";
			cout << "\nby the loss of her master seeks to turn him back to normal or die trying.\n";

			//Put a break in so the user isn't overwhelmed by all of the reading
			cout << "\nPress enter to continue ...";
			getline(cin, cont_break);
		}
		else if (race_choice == 4) {

			//Assign elf hero variables
			total_hero_hp = 72;
			hero_hp = 72;
			gold_mod = 4;

			//Display users race choice and hero name
			cout << "\nYou have chosen the Elfs path ...\n";
			cout << "\nYour characters name is Meliodas\n";

			cout << "\nThe elves are a very proud and prideful race. Having the ability to";
			cout << "\nlive a long life as well as being skilled in magic and other weapons,";
			cout << "\nmakes them believe that they are the elites. This is also furthered";
			cout << "\nby the fact that Zana's rule didn't effect them, for their forest";
			cout << "\nhomes were protected by ancient and powerful magics so they allowed";
			cout << "\nZana to do whatever he pleased. However, Meliodas believed that the";
			cout << "\npeople of midgard needed a reminder on what the best race was.";
			cout << "\nTo do so he will save the people of Midgard from Zana, not because";
			cout << "\nhe wants to help them, but for the rest of the world to know without";
			cout << "\na shadow of a doubt that the elves were superior in every";
			cout << "\ndefinition of the word.\n";

			//Put a break in so the user isn't overwhelmed by all of the reading
			cout << "\nPress enter to continue ...";
			getline(cin, cont_break);
		}
		else {
			cout << "\nPlease choose from the menu above ...\n";
		}

	} while (race_choice > 4 || race_choice < 1);
}
void ReplaceScores(string usname0, string usname1, string usname2, int uscore0, int uscore1, int uscore2)
{
	ofstream outfile;
	outfile.open("Highscores.txt", ios::out);
	outfile << usname0 << "\t" << uscore0 << endl << usname1 << "\t" << uscore1 << endl << usname0 << "\t" << uscore0 << endl;
	outfile.close();
}
void Beginning(int &hero_hp, int &total_hero_hp, int &hero_dmg, int &zombie_hp, int &bandit_hp, int &minotaur_hp, int &evil_wizard_hp, int &zombie_dmg, int &bandit_dmg, int &minotaur_dmg, int &evil_wizard_dmg, int &gold, int &gold_mod, int &gold_drop, int &race_choice, int &hallway_choice, int &user_choice, int &user_try, int &user_final_choice, int &user_input, int &play_again, string cont_break)
{
	cout << "\nYour character must defeat the horribly deceitful evil wizard, Zana!\n";

	cout << "\nStanding before you is the entrance to Zana's dungeon.";
	cout << "\nHe takes solace in knowing that no one will challenge his power";
	cout << "\nwhile within them. Everyone but you that is. Knowing this";
	cout << "\nyou take your first steps in strengthening your resolve.\n";

	cout << "\nPress enter to continue ...";
	getline(cin, cont_break);

	cout << "\nYou stop for a second and rethink your decision ...\n";

	do {
		cout << "\n1) Enter the Dungeon\n2) Leave";
		cout << "\nWhats your choice?: ";
		cin >> hallway_choice;
		cin.ignore();


		if (hallway_choice == 1) {
			while (zombie_hp > 0) {
				cout << "\nYou enter the castle gates, the smell of moss and magic permeating the air.\nThe sounds of shuffling and sludge echoing through the hallway chambers,\nbeing broken only by the groans of the restless dead,\nor the distant roars of even more ancient and terrifying beasts which lie withinZana's domain. You steel yourself, finding yourself at a crossroad,\nhaving to decide where you may truly begin.\n";

				cout << "\n1) Turn left\n2) Turn right\n3) Hero stats";
				cout << "\nchoice: ";
				cin >> hallway_choice;
				cin.ignore();

				//LEFT
				if (hallway_choice == 1) {
					cout << "\nYou enter a dark room, the sound of shuffling feet echoing around you.\nBefore you can react you see it coming for you, a zombie!\nIt’s decaying flesh and empty eye sockets making your stomach churn,\nthe smell of this once living husk of a human forcing you to retch violently\nbefore baring your weapon for combat.\n";

					//Enemy gold
					gold_drop = gold_mod * zombie_hp;

					while (zombie_hp > 0) {
						//PAUSE FOR USER TO ATTACK
						cout << "\n\nPress enter to ATTACK!";
						getline(cin, cont_break);

						//HERO ATTACK
						hero_dmg = attack_value(race_choice);
						cout << "\nYOU ATTACKED IT! Dealing " << hero_dmg << " damage!\n";
						zombie_hp -= hero_dmg;

						//ZOMBIE ATTACK
						cout << "\nZOMBIE HITS YOU! Dealing " << zombie_dmg << " damage!\n";
						hero_hp -= zombie_dmg;

						//COMBAT GUI
						cout << "\n++++++++++++++++++++++++++++++\n";//30 + signs

																	 //ZOMBIE HP
						cout << "\tZombie HP = ";

						//To display 0 if damage takes hp under 0, as to not display a negative number for hp
						if (zombie_hp < 0) {
							cout << 0 << endl;
						}
						else {
							cout << zombie_hp << endl;
						}

						//HERO HP
						cout << "\tHero HP = ";

						//To display 0 if damage takes hp under 0, as to not display a negative number for hp
						if (hero_hp < 0) {
							cout << 0 << endl;
						}
						else {
							cout << hero_hp << endl;
						}

						//COMBAT GUI
						cout << "++++++++++++++++++++++++++++++\n";//30 + signs

						if (zombie_hp <= 0) {
							cout << "\nWell done!  You killed the zombie!\n";
							cout << "The zombie's corpse falls to the ground and you see something on it,\n";
							gold += gold_drop;
							cout << "you found " << gold_drop << " gold pieces!\n";

							cout << "\n#######################################"; //40 # signs
							cout << "\n\tHP = " << hero_hp << "/" << total_hero_hp << "  Gold = " << gold << endl;
							cout << "#######################################\n"; //30 # signs

							gold_drop = 0;
						}
						else if (hero_hp <= 0) {
							youLose(gold);
							user_choice = 0;
							zombie_hp = -1;
						}

					}

					//Furthering story using a function so the program isn't copying to much
					storyContinued(hero_hp, total_hero_hp, hero_dmg, gold, gold_mod, gold_drop, race_choice, cont_break, bandit_hp, bandit_dmg, user_choice, user_try, user_input, user_final_choice, minotaur_hp, minotaur_dmg, evil_wizard_hp, evil_wizard_dmg);

				}

				//RIGHT
				else if (hallway_choice == 2) {
					cout << "\nYou enter a dark room, the sound of shuffling feet echoing around you.\nBefore you can react you see it coming for you, a zombie!\nIt’s decaying flesh and empty eye sockets making your stomach churn,\nthe smell of this once living husk of a human forcing you to retch violently\nbefore baring your weapon for combat.\n";

					//Zombie gold
					gold_drop = gold_mod * zombie_hp;

					while (zombie_hp > 0) {
						//PAUSE FOR USER TO ATTACK
						cout << "\n\nPress enter to ATTACK!";
						getline(cin, cont_break);

						//HERO ATTACK
						hero_dmg = attack_value(race_choice);
						cout << "\nYOU ATTACKED IT! Dealing " << hero_dmg << " damage!\n";
						zombie_hp -= hero_dmg;

						//ZOMBIE ATTACK
						cout << "\nZOMBIE HITS YOU! Dealing " << zombie_dmg << " damage!\n";
						hero_hp -= zombie_dmg;

						//COMBAT GUI
						cout << "\n++++++++++++++++++++++++++++++\n";//30 + signs

																	 //ZOMBIE HP
						cout << "\tZombie HP = ";

						//To display 0 if damage takes hp under 0, as to not display a negative number for hp
						if (zombie_hp < 0) {
							cout << 0 << endl;
						}
						else {
							cout << zombie_hp << endl;
						}

						//HERO HP
						cout << "\tHero HP = ";// << hero_hp << endl;

											   //To display 0 if damage takes hp under 0, as to not display a negative number for hp
						if (hero_hp < 0) {
							cout << 0 << endl;
						}
						else {
							cout << hero_hp << endl;
						}

						//COMBAT GUI
						cout << "++++++++++++++++++++++++++++++\n";//30 + signs

						if (zombie_hp <= 0) {//Elliot: Changed the victory message
							cout << "\nWell done!  You killed the zombie!\n";
							cout << "The zombie's corpse falls to the ground and you see something on it,\n";
							gold += gold_drop;
							cout << "you found " << gold_drop << " gold pieces!\n";

							cout << "\n#######################################"; //40 # signs
							cout << "\n\tHP = " << hero_hp << "/" << total_hero_hp << "  Gold = " << gold << endl;
							cout << "#######################################\n"; //30 # signs

							gold_drop = 0;
						}
						else if (hero_hp <= 0) {
							youLose(gold);
							user_choice = 0;
							zombie_hp = -1;
						}

					}
					//Furthering story using a function so the program isn't copying to much
					storyContinued(hero_hp, total_hero_hp, hero_dmg, gold, gold_mod, gold_drop, race_choice, cont_break, bandit_hp, bandit_dmg, user_choice, user_try, user_input, user_final_choice, minotaur_hp, minotaur_dmg, evil_wizard_hp, evil_wizard_dmg);

				}
				//STATS
				else if (hallway_choice == 3) {
					heroStats(hero_hp, total_hero_hp, gold);
				}
				else {
					cout << "\nPlease choose from the menu above ...\n";
				}
			}while (hallway_choice > 3 || hallway_choice < 1);
		}
		else if (hallway_choice == 2) {
			cout << "\nPress any key to exit, quitter!\n";
			user_choice = 0;
		}
		else {
			cout << "\nPlease choose from the menu above ...\n";
		}



	} while (hallway_choice > 2 || hallway_choice < 1);//CHOICE BETWEEN ENTERING AND LEAVING

}