/*************************************************************************************************
 * * Program name: 	BlueMen.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Declaration of the BlueMen class, publicly inherits Character. Blue Men
 * *			have the Mob special ability which causes them to lose a defense die
 * *			every time they lose 4 strength points. Mob is implemented inside the
 * * 			overridden rollDef function. 
**************************************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character
{ public:

   BlueMen();

   ~BlueMen();

   virtual void rollDef(int);
};

#endif
