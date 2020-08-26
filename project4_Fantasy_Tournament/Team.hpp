/*****************************************************************************************
 * * Program name: 	Team.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		17 November 2019
 * * Description: 	Declaration of the Team class. Contains the information for
 * * 			the team lineup containers and the loser pile, denoted graveyard.
 * *			A Team object has both, but the loser pile is in its seperate
 * * 			object in Menu.cpp (Team graveyard). Team has nodes for a list,
 * * 			a head pointer for teamlineup lists, a head pointer for the 
 * * 			graveyard loser pile, and methods that allow movement of nodes
 * * 			such as removal, addition, printing, and movement from lineup to
 * * 			graveyard when removeFront() is chained with addBackGrave.
*****************************************************************************************/

#ifndef TEAMQUEUE_HPP
#define TEAMQUEUE_HPP

#include "Character.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"

class Team
{ protected:

  //List info for both the Roster container and the
  //Loser pile. The Roster container uses headTeam to implement
  //a queue-like circular linked list while the Loser pile uses
  //headGrave to implement a stack-like linked list 
   struct TeamQueueNode
   {
      TeamQueueNode* next;

      TeamQueueNode* prev;

      Character* fighter;

      TeamQueueNode(Character* fighterIn)
      {
	 next = nullptr;

	 prev = nullptr;

	 fighter = fighterIn;
      }
   };

   TeamQueueNode* headTeam;

   TeamQueueNode* headGrave;

  public:
   
   Team();

   ~Team();

   bool teamIsEmpty();

   void clearAllFighters();

   void addBackTeam(Character*);

   void addFrontGrave(Character*);

   Character* getFrontTeam();

   Character* removeFrontTeam();

   void printTeamLineUp();

   void printGraveyard();
};

#endif
