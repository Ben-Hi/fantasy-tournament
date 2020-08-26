/*************************************************************************************************
 * * Program name: 	Vampire.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Declaration of the Vampire class, publicly inherits Character. Vampire
 * * 			overrides the rollDef function to implement the Charm special ability,
 * *			which triggers 50% of the time and results in a total damage of 0 being
 * * 			returned by the rollDef() function.	
**************************************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character
{ public:

   Vampire();

   ~Vampire();

   virtual void rollDef(int);
};

#endif
