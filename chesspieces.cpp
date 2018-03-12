// Hooshing Schaefer hschaefe@ucsc.edu

//black on top, can only move in +r dir
//white on bottom, can only move in -r dir

#include <iostream>         
#include <string> 
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h> 
#include <math.h>

#include "game.h"
#include "chesspieces.h"
using namespace std;

//chess_piece board[8][8];

bool chess_piece::is_valid_move(int r, int c){
	return  !(r < 0 or r >= 8 or c < 0 or c >= 8);// return false;
        
}
bool pawn::is_valid_move(int row, int col, int r, int c){
	if (!chess_piece::is_valid_move(r,c)) return false;
	if (c > col+1 or c < col-1){
		return false;
        }
	//if is black and isnt moving down or is white and isnt moving up then the move is invalid
	if((isb and r != row +1) or (!isb and r != row -1) ){
           if ((!isb or r != 3 or row != 1) and (isb or r!=4 or row != 6))
              return false;
	}
	//if the col is offset by 1 then there must be an opposing player's piece there
	//also if the columns match then the space must be empty
	if(col == c){
		if(board->at(r,c) == nullptr ) return true;
		else return false;

	}else {
		if( board->at(r,c)== nullptr  or board->at(r,c)->isbl() == isb) return false;
		else return true;
	}

}

bool rook::is_valid_move(int row, int col, int r, int c){
	if (!chess_piece::is_valid_move(r,c)) return false;
	if  (c != col and row != r) return false;


	//if theres a piece of the same color at destination, cannot be a valid move
	if( board->at(r,c)!= nullptr  and board->at(r,c)->isbl() == isb) return false;


	int rpath=row, cpath = col;
	if(rpath < r) rpath++;
	if(rpath > r)rpath--;
	if(cpath < c) cpath++;
	if(cpath > c)cpath--;

	while (rpath != r and cpath != c){
		if (board->at(rpath,cpath) != nullptr ) return false;

		if(rpath < r) rpath++;
		if(rpath > r)rpath--;
		if(cpath < c) cpath++;
		if(cpath > c)cpath--;
	}
	return true;
}

bool queen::is_valid_move(int row, int col, int r, int c){
	if (!chess_piece::is_valid_move(r,c)) return false;
	if  (c != col and row != r and abs(r-row) != abs (c-col)) return false;
	//if theres a piece of the same color at destination, cannot be a valid move
	if(board->at(r,c) != nullptr  and board->at(r,c)->isbl() == isb) return false;
	int rpath=row, cpath = col;
	if(rpath < r) rpath++;
	if(rpath > r)rpath--;
	if(cpath < c) cpath++;
	if(cpath > c)cpath--;

	while (rpath != r and cpath != c){
		if ( board->at(rpath,cpath)!=nullptr ) return false;

		if(rpath < r) rpath++;
		if(rpath > r)rpath--;
		if(cpath < c) cpath++;
		if(cpath > c)cpath--;
	}
	return true;
}

bool king::is_valid_move(int row, int col, int r, int c){
	if (!chess_piece::is_valid_move(r,c)) return false;
	if  ( abs(r-row) >1 or abs (c-col) >1) return false;

	//if theres a piece of the same color at destination, cannot be a valid move
	return board->at(r,c) == nullptr  or board->at(r,c)->isbl() != isb;
}

bool bishop::is_valid_move(int row, int col, int r, int c){
	if (!chess_piece::is_valid_move(r,c)) return false;
	if  (abs(r-row) != abs (c-col)) return false;

	//if theres a piece of the same color at destination, cannot be a valid move
	if(board->at(r,c)!= nullptr  and board->at(r,c)->isbl() == isb) return false;
	int rpath=row, cpath = col;
	if(rpath < r) rpath++;
	if(rpath > r)rpath--;
	if(cpath < c) cpath++;
	if(cpath > c)cpath--;

	while (rpath != r and cpath != c){
		if ( board->at(rpath,cpath)!= nullptr ) return false;

		if(rpath < r) rpath++;
		if(rpath > r)rpath--;
		if(cpath < c) cpath++;
		if(cpath > c)cpath--;
	}
	return true;
}

bool knight::is_valid_move(int row, int col, int r, int c){
	if (!chess_piece::is_valid_move(r,c)) return false;
	if  (!( (abs(r-row) ==1 and abs(c-col)==2) or (abs(r-row) ==2 and abs(c-col)==1 ))) return false;

	//if theres a piece of the same color at destination, cannot be a valid move
	//return ((game::board[r][c] != nullptr)  or (game::board[r][c]->isb != isb));
	return ((board->at(r,c) == nullptr) or  (board->at(r,c)->isbl() != isb));
}


ostream& operator<< (ostream& os, const chess_piece& cp){
	if(cp.isb) os << "b" ;
	else os << "w";
	return os << cp.ts() ;
}
/*
void chess_piece::move(int r, int c){
	game::board[r][c] = *this;
	row = r;
	col = c;
}
chess_piece::chess_piece(): row(-1), col (-1){}

chess_piece::operator bool() const {
	return row >=0;

}
*/



/*string chess_piece::ts()const{
	if (isb) return "b";
	else return "w";
//	return "   ";
}*/


