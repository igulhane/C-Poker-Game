#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{

   Deck deck;
   int players;
   int seed;
   int sizeOfHand = 5;

   cout << "Enter seed: ";
   cin >> seed;
   srand(unsigned(seed));

   cout << "Enter number of players: ";
   cin >> players;
   vector< Hand > hands(players);
   deck.Shuffle();

   
   /* Deal cards from the deck and do a round robin distribution to the
    * players.  Thus, if you had 5 players, and they each needed 5 cards you
    * would pull 5 cards off the deck and assign the first card to player one,
    * the second to player 2, etc.. Then you would deal 5 more and repeat the
    * process until 25 cards are dealt
    */
   for(int j=0;j<sizeOfHand;j++){
      vector< Card > cardsDeal = deck.Deal(players);
      int k=0;
      for(vector<Hand> ::iterator i= hands.begin();i!=hands.end();i++){
        i->add(cardsDeal.at(k));
        k++;
    }
   }

   /* For loop prints the final output.
    */
   int j=1;
   for(vector<Hand> ::iterator i= hands.begin();i!=hands.end();i++){
        cout<<"Player "<<j<<" hand:  ";
        i->showHand();
        j++;
    }
   return 0;
}
