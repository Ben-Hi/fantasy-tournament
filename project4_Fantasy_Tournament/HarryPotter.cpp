/*************************************************************************************************
 * * Program name: 	HarryPotter.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Definition of the HarryPotter class, publicly inherits Character. Harry
 * * 			starts with 10 strength and the special ability Hogwarts, which will bring
 * * 			him up to 20 strength if he dies. Hogwarts can trigger once per combat and
 * * 			is implemented in the overriden defense function. 
**************************************************************************************************/

#include "Character.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::cin;
using std::endl;

HarryPotter::HarryPotter()
{
   usedHogwarts = false;

   atkDie = 6;

   numAtkDie = 2;

   defDie = 6;

   numDefDie = 2;

   armor = 0;

   strength = 10;

   maxStrength = 10;

   description = "Harry Potter is a wizard.";

   type = "(Harry Potter)";
}

HarryPotter::~HarryPotter()
{
   usedHogwarts = false;

   atkDie = 0;

   numAtkDie = 0;

   defDie = 0;

   numDefDie = 0;

   armor = 0;

   strength = 0;

   description = "";

   type = "";
}

void HarryPotter::rollDef(int damage)
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

      //if Harry has not triggered the Hogwarts special ability and would die from the damage dealt,
      //trigger Hogwarts, bring Harry up to 20 strength, and set usedHogwarts to true so the ability
      //doesn't trigger again
      if (strength <= 0 && usedHogwarts == false)
      {
	 cout << "\nSPECIAL ABILITY - THE BOY WHO LIVED, HOGWARTS!! The wards of Hogwarts slam into place around Harry,";
	 cout << " boosting his strength up to 20!!!!";

	 strength = 20;

	 maxStrength = 20;

	 usedHogwarts = true;
      }
   }
}
