/*************************************************************************************************
 * * Program name: 	Medusa.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Declaration of the Medusa class, publicly inherits Character. Medusa will
 * * 			trigger her special ability Glare upon rolling a 12 for her attack die,
 * *			which causes her to deal 99 damage to her opponent. Glare is implemented
 * * 			in the overriden rollAtk function. 
**************************************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{ public:

   Medusa();

   ~Medusa();

   virtual int rollAtk();
};

#endif
