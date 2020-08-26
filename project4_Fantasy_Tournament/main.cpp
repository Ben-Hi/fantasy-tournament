/******************************************************************************************************
 * * Program name: 	main.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		23 November 2019
 * * Description: 	Driver for the Menu class, implements the fantasy tournament by making calls
 * * 			to methods of Menu to create fighters, have them battle, and move them
 * * 			around their respective lineups and graveyards.
******************************************************************************************************/

#include "Menu.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Team.hpp"
#include "validateInt.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

int main()
{
   Menu tournament;

   bool hasPlayed = false;

   while (tournament.playGame(hasPlayed))
   {
      tournament.runTournament();

      hasPlayed = true;
   }

   return 0;
}
