/*************************************************************************************************
 * * Program name: 	HarryPotter.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Declaration of the HarryPotter class, publicly inherits Character. Harry
 * * 			starts with 10 strength and the special ability Hogwarts, which will bring
 * * 			him up to 20 strength if he dies. Hogwarts can trigger once per combat and
 * * 			is implemented in the overriden defense function. 
**************************************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character
{ private:

   bool usedHogwarts;

  public:

   HarryPotter();

   ~HarryPotter();

   virtual void rollDef(int);
};

#endif
