// Hooshing Schaefer hschaefe@ucsc.edu
#include <regex>
#include <iostream>         
#include <string> 

using namespace std;         

class game{
   friend class chess_piece;
   private:
      void print_board();
      bool p1b; 
      //want to add feature "knight to e4" and automatically detect which 
      //knight is being referred to
      bool move(const string&);
      void moveAI();
      chess_piece board[8][8];
   public:
      game(bool);
      void play_set(string);
}