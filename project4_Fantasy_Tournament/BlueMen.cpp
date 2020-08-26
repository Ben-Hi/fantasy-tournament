/*************************************************************************************************
 * * Program name: 	BlueMen.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Definition of the BlueMen class, publicly inherits Character. Blue Men
 * *			have the Mob special ability which causes them to lose a defense die
 * *			every time they lose 4 strength points. Mob is implemented inside the
 * * 			overridden rollDef function. 
**************************************************************************************************/

#include "Character.hpp"
#include "BlueMen.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

BlueMen::BlueMen()
{
   atkDie = 10;

   numAtkDie = 2;

   defDie = 6;

   numDefDie = 3;

   armor = 3;

   strength = 12;

   maxStrength = 12;

   description = "They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies' armor or clothing.";

   type = "(Blue Men)";
}

BlueMen::~BlueMen()
{
   atkDie = 0;

   numAtkDie = 0;

   defDie = 0;

   numDefDie = 0;

   armor = 0;

   strength = 0;

   description = "";

   type = "";
}

void BlueMen::rollDef(int damage)
{
   int defense = 0;

   int roll = 0;

   int lossOfStrength = 0;

   //for each defense die the character has, roll that die and add its
   //result to total defense while printing the value of each roll
   for (int i = 0; i < numDefDie; i++)
   {
      roll = rand() % defDie + 1;

      cout << "Defense roll #" << i + 1 << ": " << roll << "   ";

      defense += roll;
   }

   cout << "Total damage calculation: " << damage << " - " << defense << " - " << armor;

   lossOfStrength = damage - defense - armor;					//damage received calculation

   //if the total damage dealt was less than or equal to 0, inform the user and return 0
   if (lossOfStrength <= 0)
   {
      cout << "\nTotal damage received was less than or equal to 0, no damage was taken for this attack.";
   }

   //if total damage dealt was above 0, subtract from strength and display new strength
   else
   {
      cout << "   Total damage received: " << lossOfStrength;

      strength -= lossOfStrength;

      //check if the blue men took 4 or more damage and reduce their number of defense dice by 1 if they did
      if (strength <= 8 && strength > 4)
      {
	 cout << "\nBLUE MEN MOB - This swarm of Blue Men has been hit so hard they lost a defense die!!\n";
	 cout << "This swarm can only roll 2d6 for future defense rolls.";

	 numDefDie = 2;
      }

      //check if damage received was enough to reduce blue men defense die by 2
      if (strength <= 4 && strength > 0)
      {
	 cout << "\nBLUE MEN MOB - This swarm of Blue Men is nearly defeated, they lost another defense die!!\n";
	 cout << "This swarm can only roll 1d6 for future defense rolls.";

	 numDefDie = 1;
      }
   }
}
