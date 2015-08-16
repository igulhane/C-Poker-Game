#include "hand.h"
#include <iostream>

/* Your code here */
using namespace std;

/**
  * Add in individual card to a player's hand
  */
void Hand::add( Card _card){
    cards.push_back (_card);
    }


/**
  * Dump out the current user's hand. We check for the following
  * combinations:
  *    Four of a kind
  *    Flush (all cards the same suit)
  *    Three of a kind
  *    Two pair
  *    One pair
  */
void Hand::check(){
    bool chk =true;

    /**
      * Checks if the condition is Four of a kind.
      *
      */
    if(chk){
    int j=0;
    int c=0;
    while(j<2){
        c=1;
        /**
          * For loop loops through all the cards and compares the values of card at ith 
          * and jth location. If equal, it increments the count of c by one.
          */
        for(int i=j+1; i< cards.size();i++){
            if(cards[j].getValue()== cards[i].getValue())
            {
                c++;
            }
        }
        /**
          * Check the value of c,if 4 then the required condition is met.
          */
          if(c== 4)
            {
                chk=false;
                cout<<"Four of A Kind";
                break;
            }
            j++;
    };
    }

    /**
      * Checks if the condition is Flush.
      *
      */
    if(chk){
    int c=1;
    /**
      * For loop loops through all the cards and compares the values of card at ith 
      * and jth location. If equal, it increments the count of cvar by one.
      */
    for(int i=1; i< cards.size();i++){
        if(cards[0].getSuit()!= cards[i].getSuit())
        {
            break;
        }
        else
        {
            c++;
        }

        }
          /**
            * Check the value of c,if 5 then the required condition is met.
            */
            if(c==5)
            {
                chk=false;
                cout<<"Flush";
             }
    }

    /**
      * Checks if the condition is Three of a kind.
      *
      */
    if(chk){
    int j=0;
    int cvar=0;
    while(j<3){
        unsigned int i=1;
        cvar=1;
        /**
          * For loop loops through all the cards and compares the values of card at ith 
          * and jth location. If equal, it increments the count of cvar by one.
          */
        for(i=0; i< cards.size();i++){
        if(cards[j].getValue()== cards[i].getValue())
            {
               if(i!=j){
                cvar++;
                }
            }
        }
        /**
          * Check the value of cvar,if 3 then the required condition is met.
          */
            if(cvar== 3)
            {
                chk=false;
                cout<<"Three of A Kind";
                break;
            }
            j++;
    };
    }

    /**
      * Check for pairs.
      *
      */
    if(chk){
        int pairs =0;
        /**
          * For loop loops through all the cards and check for the pairs.
          * If a pair is found it increments the count of pairs by one.
          */
        for(unsigned int i=0;i < cards.size();i++){
            for(unsigned int j=i+1;j < cards.size();j++){
                if(cards[i].getValue()== cards[j].getValue())
                {
                    pairs++;
                    break;
                }
            }
        }

        /**
          * Checks the number of pairs found and print them accordingly.
          *
          */
        if(pairs==2){
                cout<<"Two Pair";
        }
        else if(pairs==1){
            cout<<"One Pair";
          }

    }
}

/**
  * Dump out a user's hand to STDOUT
  */
void Hand::showHand(){
    for(vector<Card> ::iterator i= cards.begin();i!=cards.end();i++){
        cout<<i->str() <<" ";
    }
    cout<<"  ";
    check();
    cout<<endl;
}
