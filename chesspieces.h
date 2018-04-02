// Hooshing Schaefer hschaefe@ucsc.edu
#ifndef CP_H
#define CP_H
#include <iostream>
#include <string>
#include <vector>
#include "game.h"


using namespace std;
//class cboard;
class chess_piece{
   private:
   protected:
      chess_piece(bool b):isb(b){}
      chess_piece(bool b, cboard* ptr):isb(b), board(ptr){}
      bool is_valid_move(int r, int c) const;
      bool isb;
      cboard* board;
   public:
      bool isbl()const {return isb;}
      virtual bool is_valid_move(int row, int col, int r, int c)const =0;
      virtual string ts()const = 0 ;
      virtual ~chess_piece() {}
      friend ostream& operator<< (ostream&, const chess_piece&) ;
      move_set find_best_moves(coord, coords, int); 
      virtual int value() const =0; //get relative value of taking this piece 
                            //should be increased depending on if they can attack other pieces
      //virtual 
      coords get_valid_moves(int, int) const ;//return a vector of coordinates of all possible moves
};



class rook: public chess_piece{
public:
   rook(bool b): chess_piece(b){}
   rook(bool b, cboard* ptr): chess_piece(b, ptr){}

   bool is_valid_move(int ir, int ic, int r, int c) const override;
   string ts() const override{return "r";}
   ~rook() = default;
   //coords get_valid_moves() const override;
   int value() const {return 16;}
};

class bishop:public chess_piece{
public:
   bishop(bool b): chess_piece(b){}
   bishop(bool b, cboard* ptr): chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c)const override;
   string ts()const{return "b";}
   ~bishop() = default;
   //coords get_valid_moves() const override;
   int value() const {return 18;}
 
};

class knight: public chess_piece{
public:
   knight(bool b): chess_piece(b){}
   knight(bool b, cboard* ptr): chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c)const override;
   string ts()const{return "n";}
   ~knight() = default;
   //coords get_valid_moves() const override;
   int value() const {return 14;}
};

class queen: public chess_piece{
public:
   queen(bool b) : chess_piece(b){}
   queen(bool b, cboard* ptr) : chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c)const override;
   string ts()const{return "q";}
   ~queen() = default;
   //coords get_valid_moves() const override;
   int value() const {return 50;}
};

class king:public chess_piece{
public:
   king(bool b) : chess_piece(b){}
   king(bool b, cboard* ptr) : chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c)const override;
   string ts()const{return "k";}
   ~king() = default;
   int value() const {return 100;}
   //coords get_valid_moves() const override;
};

class pawn: public chess_piece{
public:
   pawn(bool b):chess_piece(b){}
   pawn(bool b, cboard* ptr):chess_piece(b, ptr){}
   bool is_valid_move(int ir, int ic, int r, int c)const override;
   string ts()const{return "p";}
   ~pawn() = default;
   //coords get_valid_moves() const override;
   int value() const {return 1;} 
};
#endif
