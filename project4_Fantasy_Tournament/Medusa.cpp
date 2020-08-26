/*************************************************************************************************
 * * Program name: 	Medusa.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Definition of the Medusa class, publicly inherits Character. Medusa will
 * * 			trigger her special ability Glare upon rolling a 12 for her attack die,
 * *			which causes her to deal 99 damage to her opponent. Glare is implemented
 * * 			in the overriden rollAtk function. 
**************************************************************************************************/

#include "Character.hpp"
#include "Medusa.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::cin;
using std::endl;

Medusa::Medusa()
{
   atkDie = 6;

   numAtkDie = 2;

   defDie = 6;

   numDefDie = 1;

   armor = 3;

   strength = 8;

   maxStrength = 8;

   description = "Scrawny lady with snakes for hair which helps her during combat. Just don't look at her!";

   type = "(Medusa)";
}

Medusa::~Medusa()
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

int Medusa::rollAtk()
{
   int damage = 0;

   int roll = 0;

   //for each attack die the character has, roll that die and add
   //its result to the total damage dealt while also printing the
   //value of the roll to the user
   for (int i = 0; i < numAtkDie; i++)
   {
      roll = rand() % atkDie + 1;

      cout << "Attack roll #" << i + 1 << ": " << roll << "   ";

      damage += roll;
   }

   //if Medusa rolls 12 for her damage, her glare ability triggers and deals massive
   //damage to the opponent, effectively causing an insta-kill
   if (damage == 12)
   {
      cout << "\nSPECIAL ABILITY - MEDUSA'S GLARE!! Medusa's gaze turns her opponent into stone!!!\n";

      return 99;
   }

   else
   {
      return damage;
   }
}
