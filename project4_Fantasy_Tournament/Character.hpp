/*************************************************************************************************
 * * Program name: 	character.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		8 November 2019
 * * Description: 	Declaration of the abstract Character class, inherited by Barbarian,
 * * 			Vampire, BlueMen, Medusa, and HarryPotter. Data members describe
 * * 			a character's attack and defense capabilities, armor, and strength points.
 * * 			Virtual functions for attacking and defending are included, as well as
 * * 			a base constructor.
**************************************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character
{ protected:

   int atkDie,
       numAtkDie,
       defDie,
       numDefDie,
       armor,
       strength,
       maxStrength;

   std::string description;

   std::string type;

   std::string name;

  public:

   Character();

   virtual ~Character();

   virtual int rollAtk();

   virtual void rollDef(int);

   virtual void recover();

   virtual void printDescription();

   virtual void printType();

   int getArmor(),
       getStrength();

   virtual void setName(std::string);

   virtual void printName();
};

#endif
