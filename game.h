// Hooshing Schaefer hschaefe@ucsc.edu
#ifndef GAME_H
#define GAME_H
#include <iostream>         
#include <string> 
#include <vector>
class chess_piece;
//#include "chesspieces.h"
//#include "util.h"
using namespace std;         
using cp_ptr = chess_piece*;


//POD of a space on the board
struct coord{
   int row;
   int col;
};

using coords = vector<coord>;


//a set of coordinates (moves) and their relative strength in terms of how good the set of moves is
//val is a quantification of the move set and the vector of coordinates is the optimal set of moves
struct move_set {
   int val;
   coords moves;
};

void printvec (coords&);


class cboard{
   private:
      cp_ptr board[8][8];
   public:
      cboard();
      ~cboard();
      void movep(int row, int col, int r, int c);
      void print_board() const;
      cp_ptr at(int r, int c) const{return board[r][c];}
};




//a class to handle the control of the game. dispatches function calls to chesspieces
class game{
   public:
      game(bool);
      //want to add feature "knight to e4" and automatically detect which 
      //knight is being referred to
      cboard cb{};
      void play_set(const string&);
   private:
      void moveAI();
      bool move(const string&);
      bool p1b; 

};


#endif
