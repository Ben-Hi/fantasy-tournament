/*************************************************************************************************
 * * Program name: 	character.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		8 November 2019
 * * Description: 	Definition of the abstract Character class, inherited by Barbarian,
 * * 			Vampire, BlueMen, Medusa, and HarryPotter. Data members describe
 * * 			a character's attack and defense capabilities, armor, and strength points.
 * * 			Virtual functions for attacking and defending are included, as well as
 * * 			a base constructor.
**************************************************************************************************/

#include "Character.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Character::Character()
{
   atkDie = 0;

   numAtkDie = 0;

   defDie = 0;

   numDefDie = 0;

   armor = 0;

   strength = 0;

   maxStrength = 0;

   description = "";
}

Character::~Character()
{
   cout << ""; 
}

int Character::rollAtk()
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

   return damage;
}

void Character::rollDef(int damage)
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
   }
}

/*************************************************************************
 * * 				recover()
 * * IMPLEMENTS THE RECOVER REQUIREMENT. checks to see if the fighter
 * * has lost strength. If they have, check how much they have lost
 * * and heal the fighter a random number between 1 and their lost
 * * strength.
*************************************************************************/
void Character::recover()
{
   if (strength != maxStrength)
   {
      int difference = maxStrength - strength;

      int heal = rand() % difference + 1;

      cout << endl << name << " healed " << heal << " points of damage!\n";

      strength += heal;
   }
}

void Character::printDescription()
{
   cout << description << endl;
}

void Character::printType()
{
   cout << type; 
}

void Character::printName()
{
   cout << name;
}

void Character::setName(std::string nameIn)
{
   name = nameIn;
}

int Character::getArmor()
{
   return armor;
}

int Character::getStrength()
{
   return strength;
}
