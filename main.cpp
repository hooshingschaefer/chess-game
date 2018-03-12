//Hooshing Schaefer hschaefe@ucsc.edu
// This is a chess program that I hope to augment with a quality AI 

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

#include "game.h"
//#include "util.h"
//include "chesspieces.h"

void print_intro() {
   cout << "Welcome to cHesS" << endl
        <<"to play as black, type in \"black\" or \"b\","<<endl
        << "to play as white type in anything else" << endl;

}

int main (int argc, char** argv) {

   int exitstat = 0;

   //print intro message/prompt and collect string determining player's color
   print_intro();
   string str;
   getline(cin, str);
   bool p1_black;
   if (str == "b" or str == "black") p1_black = true;
   else p1_black = false;


   //initialize game object
   game gam(p1_black);

   
    for(;;) {
       //game.print_board();
       
       //smatch match;
       getline(cin, str);
       if (cin.eof()){
          break;
       }
       //dispatch to game to print board, do players move, check validity...
       gam.play_set(str);
       
    }

   return exitstat;
}





