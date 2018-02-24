/*//game.print_board();
         string line;
         //smatch match;
         getline(cin, line);
         if (cin.eof()){
            break;
         }
         //dispatch to game to print board, do players move, check validity...
         game.play_set(line, p1_is_black);/*
         //move(string command, bool black_player)
         game.move(line, p1_is_black);
         game.print_board();
         game.moveAI(p1_is_black);
         game.print_board();*/

#include <regex>
#include <iostream>         
#include <string> 

using namespace std;         

class game{
   friend class chess_piece;
   private:
      
      print_board();
      bool p1b; 
      //want to add feature "knight to e4" and automatically detect which 
      //knight is being referred to
      move(string );
      moveAI();
      chess_piece board[8][8];
   public:
      game(bool);
      play_set(string);
}

game::game(bool p1bl){
   p1b = p1bl;
   board[0][0] = rook(false);
   board[0][1] = knight(false);
   board[0][2] = bishop(false);
   board[0][3] = queen(false);
   board[0][4] = king(false);
   board[0][5] = bishop(false);
   board[0][6] = knight(false);
   board[0][7] = rook(false);

   board[1][0] = pawn(false);
   board[1][1] = pawn(false);
   board[1][2] = pawn(false);
   board[1][3] = pawn(false);
   board[1][4] = pawn(false);
   board[1][5] = pawn(false);
   board[1][6] = pawn(false);
   board[1][7] = pawn(false);

   board[6][0] = pawn(true);
   board[6][1] = pawn(true);
   board[6][2] = pawn(true);
   board[6][3] = pawn(true);
   board[6][4] = pawn(true);
   board[6][5] = pawn(true);
   board[6][6] = pawn(true);
   board[6][7] = pawn(true);

   board[7][0] = rook(true);
   board[7][1] = knight(true);
   board[7][2] = bishop(true);
   board[7][3] = queen(true);
   board[7][4] = king(true);
   board[7][5] = bishop(true);
   board[7][6] = knight(true);
   board[7][7] = rook(true);

   print_board();

   if (p1b){
      moveAI();
      print_board();

   }
}
void game::play_set(string player_move){
   if (move(player_move)){
      moveAI();
   }else{
      cout << "invalid move" << endl;
   }
}
void game::print_board(){
   
}
/*
--+--+--+--+--+--+--+--+--+
wp|bb|bq|wp|bb|bq|wp|bb|bq|
--+--+--+--+--+--+--+--+--+

---+---+---|---+---+---+---+---+---+
 wp| bb| bq| wp| bb| bq|   | bb| bq|
---+---+---|---|---|---+---+---+---+
 wp| bb|w p| wp| bb| bq| bQ| bb| bq|
---+---|---|---|---|---+---+---+---+
 wp| bb| bq| wp|   | bq| wp| bb| bq|
---+---+---|---|---|---+---+---+---+
 wp| bb| bq| wp| bb| bq| wp| bb| bq|
---+---+---|---|---+---+---+---+---+*/

/*player movement
  first tests the args passed in
  then forwards the move to the chesspiece
  cp tries the move and returns result

*/
bool move(const string& str){
   //to better improve move registering
   //regex four_num {R"(^[^[:digit:]]*([:digit:]+)[^[:digit:]]+([:digit:]+)[^[:digit:]]+([:digit:]+)[^[:digit:]]*$)"};
   vector<string> v = split(str, " ,");

   //if 4 ints arent specified then the move is invalid. let piece try the move and return if it fails
   if (v.size() != 4){
      return 1;
   }else{
      chess_piece& cp = board[stoi(v[0])][stoi(v[1])];
      return cp.move(!p1b, stoi(v[2]), stoi(v[3]));
   }

}

---------------------------

//cp util from asg2
