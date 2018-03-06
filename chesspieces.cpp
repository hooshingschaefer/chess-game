// Hooshing Schaefer hschaefe@ucsc.edu

//black on top can only move in +r dir
//white on bottom

#include <iostream>         
#include <string> 
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h> 

#include "game.h"
#include "chesspieces.h"
using namespace std;

bool chess_piece::is_valid_move(int r, int c){
	if (r < 0 or r > 8 or c < 0 or c > 8) return false;
	return this->is_valid_move(r, c);

}


bool pawn::is_valid_move(int r, int c){
	if   c > col+1 or c < col-1 return false;
	if(isb){
		if( r != row +1)return false;
		if(col = c){
			if(board[r][c] == null) return true;
			else return false;

		}else {
			if(board[r][c] == null or ) return true;
			else return false;
		}
	}

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