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

bool chess_piece::is_valid_move(int r, int c){
	if (r < 0 or r >= 8 or c < 0 or c >= 8) return false;
}

void move(int r, int c){
	board[r][c] = *this;
	row = r;
	col = c;
}


bool pawn::is_valid_move(int r, int c){
	chess_piece::is_valid_move(r,c);
	if  c > col+1 or c < col-1 return false;
	//if is black and isnt moving down or is white and isnt moving up then the move is invalid
	if(isb and r != row +1 or !isb and r != row -1 ){
		return false;
	}
	//if the col is offset by 1 then there must be an opposing player's piece there
	//also if the columns match then the space must be empty
	if(col = c){
		if(board[r][c] == null) return true;
		else return false;

	}else {
		if(board[r][c] == null or board[r][c].isb == isb) return false;
		else return true;
	}

}

bool rook::is_valid_move(int r, int c){
	chess_piece::is_valid_move(r,c);
	if  (c != col and row != r) return false;


	//if theres a piece of the same color at destination, cannot be a valid move
	if(board[r][c] != null and board[r][c].isb == isb) return false;


	int rpath=row, cpath = col;
	if(rpath < r) rpath++;
	if(rpath > r)rpath--;
	if(cpath < c) cpath++;
	if(cpath > c)cpath--;

	while (rpath != r and cpath != c){
		if (board[rpath][cpath] != null) return false;

		if(rpath < r) rpath++;
		if(rpath > r)rpath--;
		if(cpath < c) cpath++;
		if(cpath > c)cpath--;
	}
	return true;
}

bool queen::is_valid_move(int r, int c){
	chess_piece::is_valid_move(r,c);
	if  (c != col and row != r and abs(r-row) != abs (c-col)) return false;
	//if theres a piece of the same color at destination, cannot be a valid move
	if(board[r][c] != null and board[r][c].isb == isb) return false;
	int rpath=row, cpath = col;
	if(rpath < r) rpath++;
	if(rpath > r)rpath--;
	if(cpath < c) cpath++;
	if(cpath > c)cpath--;

	while (rpath != r and cpath != c){
		if (board[rpath][cpath] != null) return false;

		if(rpath < r) rpath++;
		if(rpath > r)rpath--;
		if(cpath < c) cpath++;
		if(cpath > c)cpath--;
	}
	return true;
}

bool king::is_valid_move(int r, int c){
	chess_piece::is_valid_move(r,c);
	if  ( abs(r-row) >1 or abs (c-col) >1) return false;

	//if theres a piece of the same color at destination, cannot be a valid move
	return board[r][c] == null or board[r][c].isb != isb;
}

bool bishop::is_valid_move(int r, int c){
	chess_piece::is_valid_move(r,c);
	if  (abs(r-row) != abs (c-col)) return false;

	//if theres a piece of the same color at destination, cannot be a valid move
	if(board[r][c] != null and board[r][c].isb == isb) return false;
	int rpath=row, cpath = col;
	if(rpath < r) rpath++;
	if(rpath > r)rpath--;
	if(cpath < c) cpath++;
	if(cpath > c)cpath--;

	while (rpath != r and cpath != c){
		if (board[rpath][cpath] != null) return false;

		if(rpath < r) rpath++;
		if(rpath > r)rpath--;
		if(cpath < c) cpath++;
		if(cpath > c)cpath--;
	}
	return true;
}

bool knight::is_valid_move(int r, int c){
	chess_piece::is_valid_move(r,c);
	if  !( abs(r-row) ==1 and abs(c-col)==2 or abs(r-row) ==2 and abs(c-col)==1 ) return false;

	//if theres a piece of the same color at destination, cannot be a valid move
	return board[r][c] == null or board[r][c].isb != isb;
}




ostream& rook::operator<< (ostream& os, const chess_piece& cp){
	if(isb) os << "b";
	else os << "w";
	return os << "r" ;
}
ostream& knight::operator<< (ostream& os, const chess_piece& cp){
	if(isb) os << "b";
	else os << "w";
	return os << "k" ;
}
ostream& bishop::operator<< (ostream& os, const chess_piece& cp){
	if(isb) os << "b";
	else os << "w";
	return os << "b" ;
}
ostream& king::operator<< (ostream& os, const chess_piece& cp){
	if(isb) os << "b";
	else os << "w";
	return os << "*" ;
}
ostream& queen::operator<< (ostream& os, const chess_piece& cp){
	if(isb) os << "b";
	else os << "w";
	return os << "q" ;
}
ostream& pawn::operator<< (ostream& os, const chess_piece& cp){
	if(isb) os << "b";
	else os << "w";
	return os << "p" ;
}