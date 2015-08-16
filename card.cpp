#include "card.h"
#include <sstream>

using namespace std;

Card::Card()
{
}

Card::Card( Card::SUITS _suit, Card::COUNT _val )
{
    suit = _suit;
    value= _val;
}

string Card::str()
{
   ostringstream os;
   os << valToStr() << suitToStr();
   return os.str();
}

/* Your code here */
/**
  * Accessor to get this card's suit
  * @return value of this card's suit
 */
Card::SUITS Card::getSuit(){
   return suit;
}

/**
  * Accessor to get this card's value
  * @return value of this card
  */
Card::COUNT Card::getValue(){
   return value;
}

/**
  * Get a string representation of this card's value.
  * @return string in the format similar to this: "10", which would be 
  * TEN
  */
string Card::valToStr(){
   string os;
   /**
    * Switch statement gets the card's value and
    * prints it in required format.
    */
   switch(Card::value){
         case TWO   : os=" 2"; break;
         case THREE : os=" 3"; break;
         case FOUR  : os=" 4"; break;
         case FIVE  : os=" 5"; break;
         case SIX   : os=" 6"; break;
         case SEVEN : os=" 7"; break;
         case EIGHT : os=" 8"; break;
         case NINE  : os=" 9"; break;
         case TEN   : os="10"; break;
         case JACK  : os=" J"; break;
         case QUEEN : os=" Q"; break;
         case KING  : os=" K"; break;
         case ACE   : os=" A"; break;
    }
    return os;
}

/**
  * Get a string representation of this card's suit.
  * @return string in the format similar to this: "D", which would be 
  * of diamonds
  */
string Card::suitToStr(){
    string os;
   /**
    * Switch statement gets the card's suit and
    * prints it in required format.
    */
    switch(Card::suit){
         case DIAMONDS   : os="D"; break;
         case SPADES     : os="S"; break;
         case HEARTS     : os="H"; break;
         case CLUBS      : os="C"; break;
    }
    return os;
}
