#include "deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck()
{
   Shuffle();
}

void Deck::Shuffle()
{
   cards.erase(cards.begin(), cards.end());
   for ( int i = Card::CLUBS; i <= Card::SPADES; i++ )
   {
      for ( int j = Card::TWO; j <= Card::ACE; j++ )
      {
         cards.push_back( Card(Card::SUITS(i),Card::COUNT(j)));
      }
   }
   random_shuffle ( cards.begin(), cards.end() );
}

/**
  * Dump out the contents of the current deck, minus already dealt cards
  */
void Deck::ShowDeck()
{
    for (unsigned int i =0;i<cards.size();i++)
    {
        cout <<cards[i].str()<<" ";
    }
    cout<<endl;
}

/**
  * Return a vector of cards that are dealt.
  * @param count number of cards to deal
  * @return a set of cards from the front of the deck
  */
std::vector<Card> Deck::Deal( int count ){
    
    vector<Card> cardDealt(count);
    /**
      * For loop copies the required number of cards from the deck
      * in vector cardDealt.
      */
    for(int i=0;i<count;i++){
    cardDealt.at(i)=cards.at(i);
    }
    /**
      * Remove the cards that are dealt from the deck.
      */
    cards.erase(cards.begin(),cards.begin()+count);
    return cardDealt;
 }
