// Hooshing Schaefer hschaefe@ucsc.edu
//#include <regex>
#include <iostream>         
#include <string> 

#include "util.h"
#include "chesspieces.h"
#include "game.h"
using namespace std;         
using cp_ptr = chess_piece*;
//cp_ptr game::board[8][8];

//cboard game::board{};
//setup game board to pieces in their proper position
//game::game(bool p1bl): p1b(p1bl){
   

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


  // print_board();
   //after making the board, if the human player is black, let the computer move for white
   //if (p1bl){
     // moveAI();
     // print_board();

   //}
}

game::game(bool b): p1b(b){
   cb.print_board();
}
cboard::~cboard(){
   for(int i =0; i !=8; i++){
      for(int j = 0; j != 8; j++){
         if (board[i][j] != nullptr ) delete board[i][j];
         //cout << "board[" << i << "]["<<j << "] deleted" <<endl;
      }
   }
   //cout << "~cboard finished" << endl;
}



//ostream& operator<<(ostream& os, cboard b){
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

void game::moveAI(){
   //do nothing for now
   cout << "ai moving..."<< endl;
}

/*
game::~game(){
   for(int i =0; i !=8; i++){
      for(int j = 0; j != 8; j++){
         if (board[i][j] != nullptr ) delete board[i][j];
      }
   }

}



void game::print_board() const{
   string bord = "+---+---+---+---+---+---+---+---+";
   for (int i = 0; i < 8; ++i)
   {
      cout << bord << endl;
      for (int j = 0; j < 8; ++j)
      {
         cout <<"| " ;
         if (board[i][j] == nullptr) cout<<"  ";
         else cout << *board[i][j];
      }
      cout <<"|" <<endl;
   }
   cout << bord << endl;
}




cboard::cboard(){
   board.at(0,0) = new rook(1);
   game::board[0][1] = new knight(1);
   game::board[0][2] = new bishop(1);
   game::board[0][3] = new queen(1);
   game::board[0][4] = new king(1);
   game::board[0][5] = new bishop(1);
   game::board[0][6] = new knight(1);
   game::board[0][7] = new rook(1);

   board[1][0] =  make_unique<chess_piece>(pawn(1,0,1));
   board[1][1] =  make_unique<chess_piece>(pawn(1,1,1));
   board[1][2] =  make_unique<chess_piece>(pawn(1,2,1));
   board[1][3] =  make_unique<chess_piece>(pawn(1,3,1));
   board[1][4] =  make_unique<chess_piece>(pawn(1,4,1));
   board[1][5] =  make_unique<chess_piece>(pawn(1,5,1));
   board[1][6] =  make_unique<chess_piece>(pawn(1,6,1));
   board[1][7] =  make_unique<chess_piece>(pawn(1,7,1));

   board[6][0] =  make_unique<chess_piece>(pawn(6,0,0));
   board[6][1] =  make_unique<chess_piece>(pawn(6,1,0));
   board[6][2] =  make_unique<chess_piece>(pawn(6,2,0));
   board[6][3] =  make_unique<chess_piece>(pawn(6,3,0));
   board[6][4] =  make_unique<chess_piece>(pawn(6,4,0));
   board[6][5] =  make_unique<chess_piece>(pawn(6,5,0));
   board[6][6] =  make_unique<chess_piece>(pawn(6,6,0));
   board[6][7] =  make_unique<chess_piece>(pawn(6,7,0));
 
   board[7][0] = new rook(0);
   board[7][1] = new knight(0);
   board[7][2] = new bishop(0);
   board[7][3] = new queen(0);
   board[7][4] = new king(0);
   board[7][5] = new bishop(0);
   board[7][6] = new knight(0);
   board[7][7] = new rook(0);

   for(int i = 1; i != 11; i+= 5){
      for(int j = 0; j != 8; j++){
         board[i][j] = new pawn(i%2==1);
      }
   }


  // print_board();
   //after making the board, if the human player is black, let the computer move for white
   //if (p1bl){
     // moveAI();
     // print_board();

   //}
}
*/

