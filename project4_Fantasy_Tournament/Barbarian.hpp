/*************************************************************************************************
 * * Program name: 	Barbarian.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Declaration of the Barbarian class, publicly inherits Character. Barbarian
 * * 			has no special abilities, has two six-sided dice for attack, two six-
 * *			sided dice for defense, no armor, and 12 strength points. 
**************************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character
{ public:

   Barbarian();

   ~Barbarian();
};

#endif
