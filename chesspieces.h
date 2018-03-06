// Hooshing Schaefer hschaefe@ucsc.edu
//chesspiece::move(bool this_player is black?, row, col)
#include <iostream>         
#include <string> 
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h> 

#include "game.h"
//#include "util.h"

class chess_piece{
	//virtual friend ostream& operator<< (ostream&, const chess_piece&) = 0;
	friend class game;
   private:
      bool isb;
      int row, col;
   public:
      virtual chess_piece(int row, int col, bool isb) = 0;
      virtual bool is_valid_move(int r, int c);
      void move(int r, int c);

}

class rook: chess_piece{
public:
   friend ostream& operator<< (ostream&, const chess_piece&);
   rook(int, int,bool) = override;
   bool is_valid_move(int r, int c);
}

class bishop: chess_piece{
public:
   friend ostream& operator<< (ostream&, const chess_piece&) ;
   bishop(int, int, bool) = override;
   bool is_valid_move(int r, int c);
}

class knight: chess_piece{
public:
   friend ostream& operator<< (ostream&, const chess_piece&) ;
   knight(int, int,bool) = override;
   bool is_valid_move(int r, int c);
}

class queen: chess_piece{
public:
   friend ostream& operator<< (ostream&, const chess_piece&) ;
   queen(int, int,bool) = override;
   bool is_valid_move(int r, int c);
}

class king: chess_piece{
public:
   friend ostream& operator<< (ostream&, const chess_piece&) ;
   king(int, int,bool) = override;
   bool is_valid_move(int r, int c);
}

class pawn: chess_piece{
public:
   friend ostream& operator<< (ostream&, const chess_piece&);
   pawn(int, int, bool) = override;
   bool is_valid_move(int r, int c);
}