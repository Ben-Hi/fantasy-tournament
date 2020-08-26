/***********************************************************************************************
 * * Program name: 	Menu.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		23 November 2019
 * * Description: 	Menu class declaration for the fantasy tournament simulator, members
 * * 			describe the team lineups/graveyards, rounds played, and individual
 * * 			fighters. Methods allow user to choose to play or quit, setup the
 * * 			roster for both teams, and then watch the teams fight. 
**********************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Team.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

class Menu
{ private:

   Character** team1;

   Character** team2;

   Team team1LineUp;

   Team team2LineUp;

   Team graveyard;

   int rounds,
       damage,
       teamSize,
       team1Points,
       team2Points,
       numTeam1Fighters,
       numTeam2Fighters;

   bool keepPlaying;

  public:

   Menu();

   bool playGame(bool);		//ask user if they want to play/quit or play_again/quit based
					//on bool indicating if game has been played
   void setTeam1Roster();
					//allocate memory for both rosters and fill them with characters,
   void setTeam2Roster();		//then transfer them to TeamQueueNodes

   void fight();

   void runTournament();		//conduct combat between fighters and manage moving dead fighters
   					//to the graveyard of that Team object
};

#endif
