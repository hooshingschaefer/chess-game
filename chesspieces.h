// Hooshing Schaefer hschaefe@ucsc.edu
//chesspiece::move(bool this_player is black?, row, col)
#ifndef CP_H
#define CP_H
#include <iostream>
#include <string>
#include <vector>
#include "game.h"


using namespace std;
class cboard;
class chess_piece{
   private:
   protected:
      chess_piece(bool b):isb(b){}
      chess_piece(bool b, cboard* ptr):isb(b), board(ptr){}
      bool is_valid_move(int r, int c);
      bool isb;
      cboard* board;
   public:
      //abstract class
      bool isbl()const {return isb;}
      //game* g = nullptr;
      //chess_piece() = delete;
      //chess_piece(int row, int col, bool isb): row(row), col(col), isb(isb){}
      virtual bool is_valid_move(int row, int col, int r, int c) =0;
      virtual string ts()const = 0 ;//{return "";}
      //operator bool()const ;
      //void move(int r, int c);
      virtual ~chess_piece() {}
      friend ostream& operator<< (ostream&, const chess_piece&) ;
};



class rook: public chess_piece{
public:
   //friend ostream& operator<< (ostream&, const chess_piece&);
   rook(bool b): chess_piece(b){}
   rook(bool b, cboard* ptr): chess_piece(b, ptr){}

   bool is_valid_move(int ir, int ic, int r, int c);
   string ts() const override{return "r";}
   ~rook() = default;
};

class bishop:public chess_piece{
public:
   //friend ostream& operator<< (ostream&, const chess_piece&) ;
   bishop(bool b): chess_piece(b){}
   bishop(bool b, cboard* ptr): chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c);
   string ts()const{return "b";}
   ~bishop() = default;

};

class knight: public chess_piece{
public:
  // friend ostream& operator<< (ostream&, const chess_piece&) ;
   knight(bool b): chess_piece(b){}
   knight(bool b, cboard* ptr): chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c);
   string ts()const{return "n";}
   ~knight() = default;
};

class queen: public chess_piece{
public:
   //friend ostream& operator<< (ostream&, const chess_piece&) ;
   queen(bool b) : chess_piece(b){}
   queen(bool b, cboard* ptr) : chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c);
   string ts()const{return "q";}
   ~queen() = default;
};

class king:public chess_piece{
public:
  // friend ostream& operator<< (ostream&, const chess_piece&) ;
   king(bool b) : chess_piece(b){}
   king(bool b, cboard* ptr) : chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c);
   string ts()const{return "k";}
   ~king() = default;
};

class pawn: public chess_piece{
public:
  // friend ostream& operator<< (ostream&, const chess_piece&);
   pawn(bool b):chess_piece(b){}
   pawn(bool b, cboard* ptr):chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c);
   string ts()const{return "p";}
   ~pawn() = default;
};
#endif
