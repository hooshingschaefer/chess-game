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

int main (int argc, char** argv) {

   int exitstat = 0;

   //print intro message/prompt and collect string determining player's color
   print_intro();
   string str;
   cin >> str;
   bool p1_black;
   if (str == "b" or str == "black") p1_black = true;
   else p1_black = false;


   //initialize game object
   chessgame game(p1_black);

   
    for(;;) {
       //game.print_board();
       string line;
       //smatch match;
       getline(cin, line);
       if (cin.eof()){
          break;
       }
       //dispatch to game to print board, do players move, check validity...
       game.play_set(line);
       
    }

   return exitstat;
}




void print_intro() const{
   cout << "Welcome to cHess" << endl
        <<"to play as black, type in \"black\" or \"b\""
        << "to play as white type in anything else" << endl;
}
