/*************************************************************************************************
 * * Program name: 	Vampire.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Definition of the Vampire class, publicly inherits Character. Vampire
 * * 			overrides the rollDef function to implement the Charm special ability,
 * *			which triggers 50% of the time and results in a total damage of 0 being
 * * 			returned by the rollDef() function.	
**************************************************************************************************/

#include "Character.hpp"
#include "Vampire.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Vampire::Vampire()
{
   atkDie = 12;

   numAtkDie = 1;

   defDie = 6;

   numDefDie = 1;

   armor = 1;

   strength = 18;

   maxStrength = 18;

   description = "Suave, debonair, but viscous and surprisingly resilient.";

   type = "(Vampire)";
}

Vampire::~Vampire()
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

void Vampire::rollDef(int damage)
{
   int defense = 0;

   int roll = 0;

   int lossOfStrength = 0;

   int charmRoll = 0;

   charmRoll = rand() % 10;					//generate random numbers for the 
   								//vampire's charm ability

   //if the random number is greater than 4, the vampire will not take any 
   //damage (50% chance assuming total random probability in charmRoll)
   if (charmRoll > 4)
   {
      cout << "\nSPECIAL ABILITY TRIGGERED - VAMPIRIC CHARM!! The vampire receives no ";
      cout << " damage this round.\n";
   }

   //if charm doesn't trigger, then for each defense die the character has, roll that die and add its
   //result to total defense while printing the value of each roll
   else
   {
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
      }
   }
}
