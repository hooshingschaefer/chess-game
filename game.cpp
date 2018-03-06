// Hooshing Schaefer hschaefe@ucsc.edu
//#include <regex>
#include <iostream>         
#include <string> 
#include <cstdlib>
//#include <exception>
#include <iostream>
#include <string>
#include <unistd.h>

#include "util.h"
#include "chesspieces.h"

using namespace std;         


//setup game board to pieces in their proper position
game::game(bool p1bl){
   p1b = p1bl;
   board[0][0] = rook(0,0,1);
   board[0][1] = knight(0,1,1);
   board[0][2] = bishop(0,2,1);
   board[0][3] = queen(0,3,1);
   board[0][4] = king(0,4,1);
   board[0][5] = bishop(0,5,1);
   board[0][6] = knight(0,6,1);
   board[0][7] = rook(0,7,1);

   board[1][0] = pawn(1,0,1);
   board[1][1] = pawn(1,1,1);
   board[1][2] = pawn(1,2,1);
   board[1][3] = pawn(1,3,1);
   board[1][4] = pawn(1,4,1);
   board[1][5] = pawn(1,5,1);
   board[1][6] = pawn(1,6,1);
   board[1][7] = pawn(1,7,1);

   board[6][0] = pawn(6,0,0);
   board[6][1] = pawn(6,1,0);
   board[6][2] = pawn(6,2,0);
   board[6][3] = pawn(6,3,0);
   board[6][4] = pawn(6,4,0);
   board[6][5] = pawn(6,5,0);
   board[6][6] = pawn(6,6,0);
   board[6][7] = pawn(6,7,0);

   board[7][0] = rook(7,0,0);
   board[7][1] = knight(7,1,0);
   board[7][2] = bishop(7,2,0);
   board[7][3] = queen(7,3,0);
   board[7][4] = king(7,4,0);
   board[7][5] = bishop(7,5,0);
   board[7][6] = knight(7,6,0);
   board[7][7] = rook(7,7,0);

   print_board();
   //after making the board, if the human player is black, let the computer move for white
   if (p1b){
      moveAI();
      print_board();

   }
}

//first tries the player move, if successful then ai moves
void game::play_set(const string& player_move){
   //move returns whether or not the player's move was valid
   if (move(player_move)){
      print_board();
      moveAI();
      print_board();
   }else{
      cout << "invalid move" << endl;
   }
}


void game::print_board() const{
   string bord = "+---+---+---+---+---+---+---+---+";
   for (int i = 0; i < 8; ++i)
   {
      cout << bord << endl;
      for (int j = 0; j < 8; ++i)
      {
         cout <<"| " <<board[i][j];
      }
      cout <<"|" <<endl;
   }
   cout << bord << endl;
}


/*player movement function.
  first tests the args passed in
  then forwards the move to the chesspiece
  cp tries the move and returns result
*/
bool game::move(const string& str){
   //to better improve move registering
   //regex four_num {R"(^[^[:digit:]]*([:digit:]+)[^[:digit:]]+([:digit:]+)[^[:digit:]]+([:digit:]+)[^[:digit:]]*$)"};
   
   //split along spaces as well as commas
   vector<string> v = split(str, " ,");

   //if 4 ints arent specified then the move is invalid. let piece try the move and return if it fails
   if (v.size() != 4){
      return false;
   }else{
      chess_piece cp = board[stoi(v[0])][stoi(v[1])];
      int r = stoi(v[2]);
      int c = stoi(v[3]);
      if (cp.is_valid_move(r, c) ){
         cp.move(r,c);
         return true;
      }
      return false;
   }

}

void game::moveAI(){
   //do nothing for now

}

