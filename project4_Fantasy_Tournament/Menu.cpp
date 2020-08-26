/***********************************************************************************************
 * * Program name: 	Menu.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		23 November 2019
 * * Description: 	Menu class definition for the fantasy tournament simulator, members
 * * 			describe the team lineups/graveyards, rounds played, and individual
 * * 			fighters. Methods allow user to choose to play or quit, setup the
 * * 			roster for both teams, and then watch the teams fight. 
**********************************************************************************************/

#include "Menu.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Team.hpp"
#include "validateInt.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

#define FIGHTERLIM 2
#define FIGHTERMAX 10

using std::cout;
using std::cin;
using std::endl;

/*******************************
 * *	    Menu()
 * * default constructor,
 * * rounds start at 1,
 * * neither team has points,
 * * pointers are set to NULL,
 * * teamSize is 0
*******************************/
Menu::Menu()
{
   rounds = 1;

   team1Points = 0;

   team2Points = 0;

   teamSize = 0;

   numTeam1Fighters = 0;

   numTeam2Fighters = 0;

   team1 = NULL;

   team2 = NULL;
}

/****************************************************************
 * * 			playGame(bool hasPlayed)
 * * prompts user to play or quit if hasPlayed is false, if not
 * * prompts for play again or quit. If user chooses to play,
 * * returns true. If user chooses to quit, returns false.
****************************************************************/
bool Menu::playGame(bool hasPlayed)
{
   std::string userInput = "";

   //ask user if they want to play again
   if (hasPlayed)
   {
      do
      {
	 cout << "\n\n1. Play Again\n2. Quit\n";

	 getline(cin, userInput);

	 if (userInput != "1" && userInput != "2")
	 {
	    cout << "Error: invalid input, please try again.";
	 }
      } while (userInput != "1" && userInput != "2");

      if (userInput == "1")
      {
	 return true;
      }

      else
      {
	 return false;
      }
   }

   //ask user if they want to play
   else
   {
      do
      {
	 cout << "\n\n1. Play\n2. Quit\n";

	 getline(cin, userInput);

	 if (userInput != "1" && userInput != "2")
	 {
	    cout << "Error: invalid input, please try again.";
	 }
      } while (userInput != "1" && userInput != "2");

      if (userInput == "1")
      {
	 return true;
      }

      else
      {
	 return false;
      }
   }
}

/****************************************************************************************
 * * 					setTeam1Roster()
 * * asks user to set the value of teamSize, then initializes team1 and team2 to be 
 * * arrays of pointers to dynamically allocated characters. User then defines the
 * * type and name of each fighter on each roster. Prints out the final roster for 
 * * each team after transferring each Character ptr into the corresponding 
 * * team1LineUp object. THIS FUNCTION IMPLEMENTS THE TEAM LINEUP BY PLACING CHARACTERS
 * * INTO THEIR RESPECTIVE QUEUE-LIKE LINKED LISTS.
****************************************************************************************/
void Menu::setTeam1Roster()
{
   const std::string VAMPIRE = "1";			//Character choice legend

   const std::string BARBARIAN = "2";

   const std::string BLUEMEN = "3";

   const std::string MEDUSA = "4";

   const std::string HARRYPOTTER = "5";

   std::string userInput = "";

   team1 = new Character*[teamSize];

   cout << "\n\n-------------TEAM 1 ROSTER SELECTION INFO-------------\n\n";

   cout << "The fighters of Team 1 have the advantage in combat: they will always";
   cout << " attack first.\nTime to choose the fighters for Team 1!\n\n";

   //prompt the user to fill the team1 lineup with characters and name each character
   for (int i = 0; i < teamSize; i++)
   {
      do
      {
	 cout << "\n\nSELECT " << i + 1 << "TH FIGHTER TYPE\n\n";

	 cout << "1. Vampire --- Attack(atk) = 1d12 --- Defense(def) = 1d6*(Charm) --- Armor = 1 --- Strength Points = 18\n";
         cout << "2. Barbarian --- Atk = 2d6 --- Def = 2d6 --- Armor = 0 --- Strength Points = 12\n";
         cout << "3. Blue Men --- Atk = 2d10 --- Def = 3d6 --- Armor = 3 --- Strength Points = 12*(Mob)\n";
         cout << "4. Medusa --- Atk = 2d6*(Glare) --- Def = 1d6 --- Armor = 3 --- Strength Points = 8\n";
         cout << "5. Harry Potter --- Atk = 2d6 --- Def = 2d6 --- Armor = 0 --- Strength Points = 10/20*(Hogwarts)\n";
   
         cout << "\nSPECIAL ABILITIES\nCharm: for each attack against the vampire, there is a 50% chance that the";
         cout << " opponent does not actually attack them.\nMob: for every 4 points of damage received, Blue Men";
         cout << " lose one defense die.\nGlare: if Medusa rolls a 12, the opponent receives an absurd amount of damage.\n";
         cout << "Hogwarts: if Harry's strength reaches 0 or less, he comes back with 20 strength. Only happens once per game.\n\n";

	 getline(cin, userInput);

         if (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5")
         {
   	 cout << "Error, invalid input. Please enter 1, 2, 3, 4, or 5 for the " << i + 1 << "th fighter\n";
         }
      } while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5");

      //Set the appropriate Character ptr of team1 to the user's specified type
      if (userInput == VAMPIRE)
      {
         team1[i] = new Vampire;
      }
   
      else if (userInput == BARBARIAN)
      {
         team1[i] = new Barbarian;
      }
   
      else if (userInput == BLUEMEN)
      {
         team1[i] = new BlueMen;
      }
   
      else if (userInput == MEDUSA)
      {
         team1[i] = new Medusa;
      }
   
      else if (userInput == HARRYPOTTER)
      {
         team1[i] = new HarryPotter;
      }

      //get name for fighter from user
      cout << "Ok, how about this fighter's name? You can enter anything, anything at all...\n\n";

      getline(cin, userInput);

      team1[i]->setName(userInput);

      //confirm the new fighter's name and description to the user
      cout << "Give a hearty welcome to ";

      team1[i]->printName();

      cout  << ". Let's hear a little about our fighter's type!\n";

      team1[i]->printDescription();

      team1LineUp.addBackTeam(team1[i]);		//adds the fighter to the lineup queue-like structure
   }

   cout << "\n\n\n-----------------------------------------------------------";
   
   cout << "TEAM 1 FINAL ROSTER-----------------------------------------------------------\n\n";

   team1LineUp.printTeamLineUp();

   cout << "-----------------------------------------------------------------------------------";
   cout << "------------------------------------------------------\n\n";

}

/****************************************************************************************
 * * 					setTeam2Roster()
 * * asks user to set the value of teamSize, then initializes team1 and team2 to be 
 * * arrays of pointers to dynamically allocated characters. User then defines the
 * * type and name of each fighter on each roster. Prints out the final roster for 
 * * each team after transferring each Character ptr into the corresponding 
 * * team1LineUp object. THIS FUNCTION IMPLEMENTS THE TEAM LINEUP BY PLACING CHARACTERS
 * * INTO THEIR RESPECTIVE QUEUE-LIKE LINKED LISTS.
****************************************************************************************/
void Menu::setTeam2Roster()
{
   const std::string VAMPIRE = "1";			//Character choice legend

   const std::string BARBARIAN = "2";

   const std::string BLUEMEN = "3";

   const std::string MEDUSA = "4";

   const std::string HARRYPOTTER = "5";

   std::string userInput = "";

   team2 = new Character*[teamSize];

   cout << "\n\n-------------TEAM 2 ROSTER SELECTION INFO-------------\n\n";

   cout << "The fighters of Team 2 have a disadvantage in combat: they will always";
   cout << " defend first.\nTime to choose the fighters for Team 2!\n\n";

   //prompt the user to fill the team2 lineup with characters and name each character
   for (int i = 0; i < teamSize; i++)
   {
      do
      {
	 cout << "\n\nSELECT " << i + 1 << "TH FIGHTER TYPE\n\n";

	 cout << "1. Vampire --- Attack(atk) = 1d12 --- Defense(def) = 1d6*(Charm) --- Armor = 1 --- Strength Points = 18\n";
         cout << "2. Barbarian --- Atk = 2d6 --- Def = 2d6 --- Armor = 0 --- Strength Points = 12\n";
         cout << "3. Blue Men --- Atk = 2d10 --- Def = 3d6 --- Armor = 3 --- Strength Points = 12*(Mob)\n";
         cout << "4. Medusa --- Atk = 2d6*(Glare) --- Def = 1d6 --- Armor = 3 --- Strength Points = 8\n";
         cout << "5. Harry Potter --- Atk = 2d6 --- Def = 2d6 --- Armor = 0 --- Strength Points = 10/20*(Hogwarts)\n";
   
         cout << "\nSPECIAL ABILITIES\nCharm: for each attack against the vampire, there is a 50% chance that the";
         cout << " opponent does not actually attack them.\nMob: for every 4 points of damage received, Blue Men";
         cout << " lose one defense die.\nGlare: if Medusa rolls a 12, the opponent receives an absurd amount of damage.\n";
         cout << "Hogwarts: if Harry's strength reaches 0 or less, he comes back with 20 strength. Only happens once per game.\n\n";

	 getline(cin, userInput);

         if (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5")
         {
   	 cout << "Error, invalid input. Please enter 1, 2, 3, 4, or 5 for the " << i + 1 << "th fighter\n";
         }
      } while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5");

      //Set the appropriate Character ptr of team2 to the user's specified type
      if (userInput == VAMPIRE)
      {
         team2[i] = new Vampire;
      }
   
      else if (userInput == BARBARIAN)
      {
         team2[i] = new Barbarian;
      }
   
      else if (userInput == BLUEMEN)
      {
         team2[i] = new BlueMen;
      }
   
      else if (userInput == MEDUSA)
      {
         team2[i] = new Medusa;
      }
   
      else if (userInput == HARRYPOTTER)
      {
         team2[i] = new HarryPotter;
      }

      //get name for fighter from user
      cout << "Ok, how about this fighter's name? You can enter anything, anything at all...\n\n";

      getline(cin, userInput);

      team2[i]->setName(userInput);

      //confirm the new fighter's name and description to the user
      cout << "Give a hearty welcome to ";

      team1[i]->printName();

      cout  << ". Let's hear a little about our fighter's type!\n";

      team2[i]->printDescription();

      team2LineUp.addBackTeam(team2[i]);		//adds the fighter to the lineup queue-like structure
   }

   cout << "\n\n\n-----------------------------------------------------------";
   
   cout << "TEAM 2 FINAL ROSTER-----------------------------------------------------------\n\n";

   team2LineUp.printTeamLineUp();

   cout << "-----------------------------------------------------------------------------------";
   cout << "------------------------------------------------------\n\n";
}

/*********************************************************************************************
 * * 						fight()
 * * manages combat between fighters at the top of the team1LineUp and team2LineUp Queues
 * * by using project3 code. After determining the winner, the loser is removed from the
 * * appropriate teamLineUp object and sent to the top of the graveyard list. THIS FUNCTION
 * * IMPLEMENTS THE LOSER PILE (NAMED GRAVEYARD) BY REMOVING THE LOSER FROM THEIR LINEUP
 * * AND PLACING THEM AT THE TOP OF THE GRAVEYARD STACK IN THE TEAM GRAVEYARD OBJECT.
 * * After this is performed, the recover() function is called on the winner to restore
 * * a percentage of their maximum strength. See Character.cpp for recover() function
 * * description. THIS FUNCTION IMPLEMENTS THE RECOVER REQUIREMENT FOR THE TOURNAMENT.
********************************************************************************************/
void Menu::fight()
{
   int damage = 0;

   Character* c1 = team1LineUp.getFrontTeam();

   Character* c2 = team2LineUp.getFrontTeam();

   while (c1->getStrength() > 0 && c2->getStrength() > 0)
   {
      //Display fighter types and the round
      cout << "\n\nROUND " << rounds << ": Team 1's ";
      c1->printName();
      c1->printType();
      cout << " VS. Team 2's ";
      c2->printName();
      c2->printType();

      cout << "\n\n";

      damage = c1->rollAtk();				//assume c1 is alive at the start of the round

      c2->rollDef(damage);

      //Case: c2 still has strength after c1 attacks
      if (c2->getStrength() > 0)
      {
	 damage = c2->rollAtk();

	 c1->rollDef(damage);

	 //Case: c1 has no strength left after c2 attacks
	 if (c1->getStrength() <= 0)
	 {
	    cout << "\n\n----------ROUND " << rounds << ": RESULTS----------\n\n";
	    cout << "The fight is over, Team 2's ";

	    c2->printName();

	    c2->printType();
	    cout << " has won the match! For defeating one of Team 1's fighters, Team 2 gets 2 points.\n\n";

	    graveyard.addFrontGrave(team1LineUp.removeFrontTeam());

	    numTeam1Fighters--;

	    team2Points += 2;

	    team2LineUp.addBackTeam(team2LineUp.removeFrontTeam());		//place the victor at the
	 }									//end of the lineup
      }

      //Case: c2 has no strength left after c1 attacks
      else if (c2->getStrength() <= 0)
      {
	 cout << "\n\n----------ROUND " << rounds << ": RESULTS----------\n\n";
	 cout << "The fight is over, Team 1's ";

	 c1->printName();

	 c1->printType();
	 cout << " has won the match! For defeating one of Team 2's fighters, Team 1 gets 2 points.\n\n";

	 graveyard.addFrontGrave(team2LineUp.removeFrontTeam());

	 numTeam2Fighters--;

	 team1Points += 2;

	 team1LineUp.addBackTeam(team1LineUp.removeFrontTeam());
      }
   }

   //if c1 lost the fight, then c2 needs to have the recover function called on it
   if (c1->getStrength() <= 0)
   {
      c2->recover();
   }

   //if c2 lost the fight, then c1 needs to have the recover function called on it
   else if (c2->getStrength() <= 0)
   {
      c1->recover();
   }
}

/********************************************************************************************************
 * *						runTournament()
 * * implements the gameplay flow of the Fantasy Tournament by prompting the user to set the size of
 * * the two teams, making calls to setTeam1Roster() and setTeam2Roster() to fill the lineup containers
 * * with named characters, then has the fighters at the top of each queue fight each other by calling
 * * fight(), then analyzes team points once all the fighters of a lineup have died, declares a winner,
 * * and performs memory management in case the user wants to play again.
********************************************************************************************************/
void Menu::runTournament()
{
   std::string userInput = "";

   cout << "\n\nFANTASY TOURNAMENT INTRODUCTION\n\n";

   cout << "Welcome to the tournament of your imagination! Let's get right to it shall we?\n";

   //loop asking the user to define teamSize until they enter an integer between
   //FIGHTERLIM (2) and FIGHTERMAX (10)
   do
   {
      cout << "\nHow many fighters would you like each team to have? Enter a positive integer between ";
      cout << FIGHTERLIM << " and " << FIGHTERMAX << endl;

      getline(cin, userInput);

      validateInt(userInput);

      teamSize = numTeam1Fighters = numTeam2Fighters = stoi(userInput);

      if (teamSize < FIGHTERLIM || teamSize > FIGHTERMAX)
      {
	 cout << "Error: must have at least " << FIGHTERLIM << " fighters and at most " << FIGHTERMAX;
	 cout << " fighters, try again.\n\n";
      }
   } while (teamSize < FIGHTERLIM || teamSize > FIGHTERMAX);

   cout << "\n\nExcellent, each team will have " << teamSize << " fighters.";
   cout << "\n\nTime to choose the fighters for each team!\n\n";

   setTeam1Roster();				//set up the lineup for each team

   setTeam2Roster();

   //as long as there are still fighters in one of the lineups, have the first fighter in each
   //lineup fight each other
   while (numTeam1Fighters > 0 && numTeam2Fighters > 0)
   {
      cout << "\n\n-----------------------------------------------------------FANTASY TOURNAMENT";
      cout << " ROUND " << rounds << "------------------------------------------" << endl << endl;

      cout << "\n\n\n------------------------------------------------------";
      
      cout << "TEAM 1 ROSTER------------------------------------------------------\n\n";
   
      team1LineUp.printTeamLineUp();
   
      cout << "------------------------------------------------------------------------";
      cout << "-------------------------------------------------\n\n";

      cout << "\n\n\n------------------------------------------------------";
      
      cout << "TEAM 2 ROSTER------------------------------------------------------\n\n";
   
      team2LineUp.printTeamLineUp();
   
      cout << "------------------------------------------------------------------------";
      cout << "-------------------------------------------------\n\n";

      fight();

      rounds++;
   }

   cout << "\n\nTHE TOURNAMENT HAS ENDED!!!\n\n";			//inform the user the tournament is over

   cout << "Team 1's Final Score: " << team1Points << endl;		//print scores

   cout << "Team 2's Final Score: " << team2Points;

   cout << "\n\nWINNER: ";

   //Case: Team 1 has more points than Team 2
   if (team1Points > team2Points)
   {
      cout << "Congratulations to Team 1, they have won the tournament!";
   }

   //Case: Team 2 has more points than Team 1
   else if (team2Points > team1Points)
   {
      cout << "Victory goes to Team 2, they have won the tournament!";
   }

   //Case: Team 1 ties with Team 2
   else
   {
      cout << "It's a dead tie, no winners in this tournament, only losers!";
   }

   cout << "\n\nWould you like to see the graveyard?\n";

   //prompt user to choose to view the graveyard or not
   do
   {
      cout << "1. Display the fallen fighters\n2. Skip the graveyard\n";

      getline(cin, userInput);

      if (userInput != "1" && userInput != "2")
      {
	 cout << "Error: invalid input, please try again\n";
      }
   } while (userInput != "1" && userInput != "2");

   if (userInput == "1")
   {
      graveyard.printGraveyard();

      cout << "\n--------------------------------------------\n\n";
   }

   //Perform memory management
   team1LineUp.clearAllFighters();

   team2LineUp.clearAllFighters();

   graveyard.clearAllFighters();

   //clear out the team arrays
   for (int i = 0; i < teamSize; i++)
   {
      delete team1[i];

      delete team2[i];
   }

   team1 = NULL;

   team2 = NULL;

   rounds = 0;

   team1Points = 0;

   team2Points = 0;
}
