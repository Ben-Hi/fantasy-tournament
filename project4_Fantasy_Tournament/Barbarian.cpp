/*************************************************************************************************
 * * Program name: 	Barbarian.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Definition of the Barbarian class, publicly inherits Character. Barbarian
 * * 			has no special abilities, has two six-sided dice for attack, two six-
 * *			sided dice for defense, no armor, and 12 strength points. 
**************************************************************************************************/

#include "Barbarian.hpp"
#include <string>

Barbarian::Barbarian()
{
   atkDie = 6;

   numAtkDie = 2;

   defDie = 6;

   numDefDie = 2;

   armor = 0;

   strength = 12;

   maxStrength = 12;

   description = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";

   type = "(Barbarian)";
}

Barbarian::~Barbarian()
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
