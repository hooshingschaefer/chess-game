// Hooshing Schaefer hschaefe@ucsc.edu
//#include <regex>
#include <iostream>         
#include <string> 

#include "util.h"
#include "chesspieces.h"
#include "game.h"
using namespace std;         
//using cp_ptr = chess_piece*;

cboard::cboard(){
   board[0][0] = new rook(1, this);
   board[0][1] = new knight(1, this);
   board[0][2] = new bishop(1, this);
   board[0][3] = new queen(1, this);
   board[0][4] = new king(1, this);
   board[0][5] = new bishop(1, this);
   board[0][6] = new knight(1, this);
   board[0][7] = new rook(1, this);

 
   board[7][0] = new rook(0, this);
   board[7][1] = new knight(0, this);
   board[7][2] = new bishop(0, this);
   board[7][3] = new queen(0, this);
   board[7][4] = new king(0, this);
   board[7][5] = new bishop(0, this);
   board[7][6] = new knight(0, this);
   board[7][7] = new rook(0, this);

   for(int i = 1; i != 11; i+= 5){
      for(int j = 0; j != 8; j++){
         board[i][j] = new pawn(i%2==1, this);
      }
   }

   for(int i = 2; i != 6; i++){
      for(int j = 0; j != 8; j++){
         board[i][j] = nullptr;
      }
   }
}

game::game(bool b): p1b(b){
   cb.print_board();
  // after making the board, if the human player is black, let the computer move for white
   if (p1b){
      moveAI();
      cb.print_board();
   }
}

cboard::~cboard(){
   for(int i =0; i !=8; i++){
      for(int j = 0; j != 8; j++){
         if (board[i][j] != nullptr ) delete board[i][j];
      }
   }
}



void cboard::print_board()const{
   string bord = " +---+---+---+---+---+---+---+---+";
   cout << "   0";
   for (int i = 1; i < 8; i++){
      cout << "   " <<i;
   }
   cout << endl;
   for (int i = 0; i < 8; ++i)
   {
      cout << bord << endl << i;
      for (int j = 0; j < 8; ++j)
      {
         cout <<"| " ;
         if (board[i][j] == nullptr) cout <<"  ";
         else cout << *board[i][j];
      }
      cout <<"|" <<endl;
   }
   cout << bord << endl;
}

//first tries the player move, if successful then ai moves
void game::play_set(const string& player_move){
   //move returns whether or not the player's move was valid
   if (move(player_move)){
      cb.print_board();
      moveAI();
      cb.print_board();
   }else{
      cout << "invalid move" << endl;
   }
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
      int row = stoi(v[0]);
      int col = stoi(v[1]);
      int r = stoi(v[2]);
      int c = stoi(v[3]);
      cp_ptr selected = cb.at(row, col);
      //if the chp is a nullptr then exit
      if (selected != nullptr and selected->isbl() == p1b and selected->is_valid_move(row,col,r, c) ){
         cb.movep(row, col, r ,c);
         return true;
      }
      return false;
   }

}

void cboard::movep(int row, int col, int r, int c){
   delete board[r][c];
   board[r][c] = board[row][col];
   board[row][col] = nullptr;
}


void printvec(coords& c){
   for (coord x: c){
      cout << "row: " << x.row << " col: " << x.col << endl;
   }
}

void game::moveAI(){
   //any move beats this one
   move_set best_move{ -1, {} };


   for (int i =0 ; i < 8; i++){
      for (int j =0 ; j < 8; j++){
         cp_ptr cp = cb.at(i,j);
         if (cp != nullptr and cp->isbl() != p1b){
            cout << "found moveable piece at " << i << ","<< j << endl;//db
            move_set ms = cp->find_best_moves({i,j}, {}, 1);
            printvec(ms.moves);//db
            cout << endl;//db
            if (ms.val > best_move.val and ms.moves.size() > 1){
               best_move = ms;
            }
         } 
      }
   }
   //ai will always have to move as long as this function is called
   //if there are no pieces to move then the game is over anyways.
   cb.movep (best_move.moves[0].row, best_move.moves[0].col, best_move.moves[1].row, best_move.moves[1].col);
  // cout <<"value: " <<  best_move.val <<endl << "move vector: " ;
   //printvec(best_move.moves);
   //cout <<"best move: " <<best_move.moves[0].row<< best_move.moves[0].col<< best_move.moves[1].row
    //<< best_move.moves[1].col<< endl; //best_move.moves[0].row<< best_move.moves[0].col<<endl;
}
/*
struct move_tuple{
   //arr holds the i,j of the piece and the row and col that is the "best" move 
   int arr[4];
   //eval is the score of the particular move, determined heuristically
   int eval;
};

*/


//need to define what a good move is
//put a value on different pieces
//protect friendly pieces, set up favorable trades
//move to attack opponent whats the timeframe?
//
//
//search for the best move. alpha beta pruning? store moves? 
