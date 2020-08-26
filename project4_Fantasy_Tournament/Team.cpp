/*****************************************************************************************
 * * Program name: 	Team.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		17 November 2019
 * * Description: 	Definition of the Team class. Contains the information for
 * * 			the team lineup containers and the loser pile, denoted graveyard.
 * *			A Team object has both, but the loser pile is in its seperate
 * * 			object in Menu.cpp (Team graveyard). Team has nodes for a list,
 * * 			a head pointer for teamlineup lists, a head pointer for the 
 * * 			graveyard loser pile, and methods that allow movement of nodes
 * * 			such as removal, addition, printing, and movement from lineup to
 * * 			graveyard when removeFront() is chained with addBackGrave.
*****************************************************************************************/

#include "Team.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

/******************************
 * * Constructor for TeamQueue,
 * * initializes the head
 * * to a NULL pointer
******************************/
Team::Team()
{
   headTeam = NULL;

   headGrave = NULL;
}

/********************************
 * * Destructor for TeamQueue, calls
 * * removeFront() until the
 * * queue is empty
********************************/
Team::~Team()
{
   //Only free memory if there are fighters in the team lineup
   if (headTeam != NULL)
   {
      while (headTeam->next != headTeam)
      {
   
         TeamQueueNode* traverse = headTeam;
   
         TeamQueueNode* badNode = headTeam;
   
         headTeam = headTeam->next;				//move the head pointer forward one node
   
         //move the placeholder pointer to the last node in the circle
         while (traverse->next != badNode)
         {
   	 traverse = traverse->next;
         }
   
         traverse->next = headTeam;				//set the last node's next pointer to the new head
   
         headTeam->prev = traverse;				//set the new head's previous node to the last node in the
         							//circle, isolating badNode
         delete badNode;
      }
   
      delete headTeam;
   
      headTeam = NULL;
   }

   //Only free Grave memory if there are fighters in the graveyard
   if (headGrave != NULL)
   {
      while (headGrave->next != NULL)
      {
         TeamQueueNode* badNode = headGrave;
   
         headGrave = headGrave->next;
   
         headGrave->prev = NULL;
   
         delete badNode;
      }
   
      delete headGrave;
   
      headGrave = NULL;
   }
}

/**********************************************************
 * * 			teamIsEmpty() 
 * * Returns true if the queue has no nodes,
 * * indicated by the head pointer being NULL, or false
 * * otherwise
**********************************************************/
bool Team::teamIsEmpty()
{
   if (headTeam == NULL)
   {
      return true;
   }

   else
   {
      return false;
   }
}

/****************************************************************
 * * 			addBack(int valIn) 
 * * Checks if the queue is empty. If
 * * it is, it sets the head pointer to the dynamically
 * * created new node and points it to itself. If not,
 * * it properly connects the prev and next pointers of the
 * * new node to the last node and the head node,
 * * respectively and ensures the circular format is maintained.
****************************************************************/
void Team::addBackTeam(Character* fighterIn)
{
   TeamQueueNode* inputNode = new TeamQueueNode(fighterIn);

   //if the TeamQueue is empty, set the head ptr to the new node
   //and make the next and prev ptrs point to head
   if (headTeam == NULL)
   {
      inputNode->next = inputNode->prev = inputNode;

      headTeam = inputNode;
   }

   else
   {
      inputNode->next = headTeam;			//the next of the new node is the head

      TeamQueueNode* lastNode = headTeam->prev;		//find the old last node

      lastNode->next = inputNode;		//the next of the old last node is the new node

      inputNode->prev = lastNode;		//the previous of the new node is the old last node

      headTeam->prev = inputNode;			//the previous of the head node is the new node
   }
}

/******************************************************************
 * *				getFront()
 * * Prints an error message if there are no values in the list
 * *  and returns a negative one to indicate this,
 * * otherwise it returns the value of the head node.
******************************************************************/
Character* Team::getFrontTeam()
{
   if (teamIsEmpty())
   {
      cout << "Error: Your queue is empty, no value exists at the front.";
   }

   else
   {
      return headTeam->fighter;
   }
}

/*****************************************************************************
 * *				clearAllFighters()
 * * frees the memory allocated in the list by removing each node in both
 * * the team and graveyard containers and setting their respective heads
 * * to NULL.
*****************************************************************************/
void Team::clearAllFighters()
{
   if (headTeam != NULL)
   {
      while (headTeam->next != headTeam)
      {
   
         TeamQueueNode* traverse = headTeam;
   
         TeamQueueNode* badNode = headTeam;
   
         headTeam = headTeam->next;				//move the head pointer forward one node
   
         //move the placeholder pointer to the last node in the circle
         while (traverse->next != badNode)
         {
   	 traverse = traverse->next;
         }
   
         traverse->next = headTeam;				//set the last node's next pointer to the new head
   
         headTeam->prev = traverse;				//set the new head's previous node to the last node in the
         							//circle, isolating badNode
         delete badNode;
      }
   
      delete headTeam;
   
      headTeam = NULL;
   }

   //Only free Grave memory if there are fighters in the graveyard
   if (headGrave != NULL)
   {
      while (headGrave->next != NULL)
      {
         TeamQueueNode* badNode = headGrave;
   
         headGrave = headGrave->next;
   
         headGrave->prev = NULL;
   
         delete badNode;
      }
   
      delete headGrave;
   
      headGrave = NULL;
   }
}

/*******************************************************************
 * *				removeFront()
 * * Prints an error message if the queue is empty, otherwise it
 * * checks to see if the head node is the only node in the queue.
 * * If it is, it deletes head and sets it to NULL. If not, it
 * * isolates the old head node from the list, makes the
 * * appropriate changes to the next and prev pointers of head and
 * * the last node, then deletes the old head node.
*******************************************************************/
Character* Team::removeFrontTeam()
{
   //if there are no nodes in the queue, inform the user and don't remove any values
   if (teamIsEmpty())
   {
      cout << "Error: Your queue is empty, cannot remove values from an empty queue.";
   }

   //if there is only one node in the queue, remove that node and set the head pointer
   //to NULL
   else if (headTeam->next == headTeam)
   {
      TeamQueueNode* copyNode = new TeamQueueNode(headTeam->fighter);

      delete headTeam;

      headTeam = NULL;

      return copyNode->fighter;
   }

   //isolate the first node in the queue by reassigning the head node and the
   //pointers of the last node in the circle, then delete the first node
   else
   {
      TeamQueueNode* traverse = headTeam;

      TeamQueueNode* badNode = headTeam;

      TeamQueueNode* copyNode = new TeamQueueNode(headTeam->fighter);

      headTeam = headTeam->next;				//move the head pointer forward one node

      //move the placeholder pointer to the last node in the circle
      while (traverse->next != badNode)
      {
	 traverse = traverse->next;
      }

      traverse->next = headTeam;				//set the last node's next pointer to the new head

      headTeam->prev = traverse;				//set the new head's previous node to the last node in the
      								//circle, isolating badNode
      delete badNode;

      return copyNode->fighter;					//now that badNode has been disconnected from the circle,
   }								//return that node
}

/******************************************************************
 * *			addFrontGrave(Character*)
 * * takes a pointer to a Character and places that Character
 * * at the top of the graveyard (loser) pile, thus IMPLEMENTING
 * * THE REQUIREMENT FOR A LOSER CONTAINER. THE TEAM GRAVEYARD
 * * OBJECT IN MENU.CPP IS THE ONLY LOSER CONTAINER
******************************************************************/
void Team::addFrontGrave(Character* deadFighter)
{
   TeamQueueNode* inputNode = new TeamQueueNode(deadFighter);

   //check if the graveyard is empty
   if (headGrave == NULL)
   {
      inputNode->next = inputNode->prev = NULL;

      headGrave = inputNode;
   }

   //check if there is only one member in the graveyard
   else
   {
      headGrave->prev = inputNode;

      inputNode->next = headGrave;

      inputNode->prev = NULL;

      headGrave = inputNode;
   }
}

/*********************************************************************
 * *				printTeamQueue()
 * * Prints an error message if there are no nodes in the queue,
 * * otherwise it traverses the queue from head to the last node
 * * before head, printing out the value of each node along the way.
*********************************************************************/
void Team::printTeamLineUp()
{
   int i = 1;

   //if there are no nodes in the queue, tell the user that their queue is empty
   if (teamIsEmpty())
   {
      cout << "There's nobody left in the team!";
   }

   //if there are nodes in the queue, print the head node then move through the rest of the
   //nodes in the list, printing their values until the head node is reached again, head is not
   //double printed
   else
   {
      TeamQueueNode* traverse = headTeam->next;

      cout << i << ". ";

      headTeam->fighter->printName();

      cout << endl;

      i++;

      while (traverse != headTeam)
      {
	cout << i << ". ";
	
	traverse->fighter->printName();

	cout << endl;

	traverse = traverse->next;

	i++;
      }
   }
}

/******************************************************************************
 * *				printGraveyard()
 * * prints the Character's that have been moved to the graveyard by printing
 * * their names.
******************************************************************************/
void Team::printGraveyard()
{
   int i = 1;

   if (headGrave == NULL)
   {
      cout << "The Graveyard lies empty.";
   }

   else if (headGrave->next == NULL)
   {
      cout << "\n\n-----------------GRAVEYARD-----------------\n\n";

      headGrave->fighter->printName();
   }

   else
   {
      cout << "\n\n-----------------GRAVEYARD-----------------\n\n";

      TeamQueueNode* traverse = headGrave;

      while (traverse != NULL)
      {
	 cout << i << ". ";

	 traverse->fighter->printName();

	 cout << endl;

	 traverse = traverse->next;

	 i++;
      }
   }
}
