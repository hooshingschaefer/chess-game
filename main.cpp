//Hooshing Schaefer hschaefe@ucsc.edu
// This is a chess program that I hope to augment with a quality AI 
//
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <unistd.h>
#include <regex>
#include <fstream>
using namespace std;

#include "listmap.h"
#include "xpair.h"
#include "util.h"

using str_str_map = listmap<string,string>;
using str_str_pair = str_str_map::value_type;



//will take in arg setting their color
void scan_options (int argc, char** argv) {
   opterr = 0;
   for (;;) {
      int option = getopt (argc, argv, "@:");
      if (option == EOF) break;
      switch (option) {
         case '@':
            debugflags::setflags (optarg);
            break;
         default:
            complain() << "-" << char (optopt) << ": invalid option"
                       << endl;
            break;
      }
   }
}

int main (int argc, char** argv) {
   sys_info::execname (argv[0]);
   //scan_options (argc, argv);

   int exitstat = 0;

   print_intro();
   //print intro message/prompt and collect string determining player's color
   string str;
   cin >> str;
   bool p1_black;
   if (str == "b" or str == "black") p1_black = true;
   else p1_black = false;


  // string filename;
   //ifstream infile; 
   //str_str_map map;
   //initialize game object call functions on this object in main
   chessgame game(p1_black);

   //int linenum = 1;
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




void print_intro(){
   cout << "Welcome to cHess" << endl
        <<"to play as black, type in \"black\" or \"b\""
        << "to play as white type in anything else" << endl;
}
