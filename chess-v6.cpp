#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
 
//pawn class
class pawn{
    public:
      int x,y;
      pawn(){
        x=0;
        y=0;
      }
      pawn(int Xpos,int Ypos){
        x=Xpos;
        y=Ypos;
      }
        
       
};

//king class
class king{
   public:
   int x,y;
   king() {
    x = 0;
    y = 0;
   }
   king(int Xpos,int Ypos){
    x=Xpos;
    y=Ypos;
   }
};

//queen class
class queen{
   public:
   int x,y;
   queen() {
    x = 0;
    y = 0;
   }
   queen(int Xpos,int Ypos){
    x=Xpos;
    y=Ypos;
   }
};

//rook class
class rook{
    public:
    int x,y;
    rook() {
     x = 0;
     y = 0;
    }
    rook(int Xpos,int Ypos){
     x=Xpos;
     y=Ypos;
    }
};

//knight class
class knight{
    public:
    int x,y;
    knight() {
     x = 0;
     y = 0;
    }
    knight(int Xpos,int Ypos){
     x=Xpos;
     y=Ypos;
    }
};

//bishop class
class bishop{
    public:
   int x,y;
   bishop() {
    x = 0;
    y = 0;
   }
   bishop(int Xpos,int Ypos){
    x=Xpos;
    y=Ypos;
   }
};

//board class
class Board {
    public:
        pawn pawns[16];
        king kingw,kingb;
        queen queenw[9],queenb[9];
        rook rookw[10],rookb[10];
        knight knightw[10],knightb[10];
        bishop bishopw[10],bishopb[10];

        int queenwCount = 1, queenbCount = 1;
        int rookwCount = 2, rookbCount = 2;
        int knightwCount = 2, knightbCount = 2;
        int bishopwCount = 2, bishopbCount = 2;
        
        int enPassantX = -1, enPassantY = -1; // -1 means no en passant available

        bool whiteKingMoved = false;
        bool blackKingMoved = false;
        bool whiteKingsideRookMoved = false;
        bool whiteQueensideRookMoved = false;
        bool blackKingsideRookMoved = false;
        bool blackQueensideRookMoved = false;

        // Constructor to initialize pieces positions
        Board() {
            for (int i = 0; i < 16; i++) {
                if (i < 8)
                    pawns[i] = pawn(i, 1);        // White pawns
                else
                    pawns[i] = pawn(i - 8, 6);    // Black pawns
            }
            kingw=king(4,0);
            kingb=king(4,7);
            queenw[0] = queen(3, 0);
            queenb[0] = queen(3, 7);
            rookw[0] = rook(0, 0);
            rookw[1] = rook(7, 0);
            rookb[0] = rook(0, 7); 
            rookb[1] = rook(7, 7);
            knightw[0] = knight(1,0);
            knightw[1] = knight(6,0);
            knightb[0] = knight(1,7);
            knightb[1] = knight(6,7);
            bishopw[0] = bishop(2,0);
            bishopw[1] = bishop(5,0);
            bishopb[0] = bishop(2,7);
            bishopb[1] = bishop(5,7);
        }
        
             
 
    
        // Function to print the board
        void printBoard() {
            char board[8][8];
            // Fill board with empty squares
            for (int y = 0; y < 8; y++)
                for (int x = 0; x < 8; x++)
                    board[y][x] = '.';
    
            // Place pawns on the board
            for (int i = 0; i < 16; i++) {
                int x = pawns[i].x;
                int y = pawns[i].y;
            
                // Skip pawns that have been promoted or captured (marked invalid)
                if (x < 0 || y < 0) continue;
            
                if (i < 8)
                    board[y][x] = 'P';  // White pawn
                else
                    board[y][x] = 'p';  // Black pawn
            }
            //placing kings
            board[kingw.y][kingw.x]='K';
            board[kingb.y][kingb.x]='k';
            //placing queens
            for (int i = 0; i < queenwCount; ++i)
            board[queenw[i].y][queenw[i].x] = 'Q';
            for (int i = 0; i < queenbCount; ++i)
            board[queenb[i].y][queenb[i].x] = 'q';
            //placing rooks
            for (int i = 0; i < rookwCount; ++i)
            board[rookw[i].y][rookw[i].x] = 'R';
            for (int i = 0; i < rookbCount; ++i)
            board[rookb[i].y][rookb[i].x] = 'r';
            //placing knights
            for (int i = 0; i < knightwCount; ++i)
            board[knightw[i].y][knightw[i].x] = 'N';
            for (int i = 0; i < knightbCount; ++i)
            board[knightb[i].y][knightb[i].x] = 'n';
            //placing bishops
            for (int i = 0; i < bishopwCount; ++i)
            board[bishopw[i].y][bishopw[i].x] = 'B';
            for (int i = 0; i < bishopbCount; ++i)
            board[bishopb[i].y][bishopb[i].x] = 'b';
            
    
            // Print the board from top (row 7) to bottom (row 0)
            cout<<"     A B C D E F G H\n\n";
            for (int y = 7; y >= 0; y--) {
                cout<<y+1<<"    ";
                for (int x = 0; x < 8; x++) {
                    cout << board[y][x] << " ";
                }
                cout << endl;
            }
        }

        char getPieceAt(int x, int y) const {
            // Check pawns
            for (int i = 0; i < 16; ++i) {
                if (pawns[i].x == x && pawns[i].y == y) {
                    return (i < 8) ? 'P' : 'p';
                }
            }
    
            // Check white king
            if (kingw.x == x && kingw.y == y) return 'K';
            // Check black king
            if (kingb.x == x && kingb.y == y) return 'k';
    
            // Check queens
            if (queenw[0].x == x && queenw[0].y == y) return 'Q';
            if (queenb[0].x == x && queenb[0].y == y) return 'q';
    
            // Check rooks
            if (rookw[0].x == x && rookw[0].y == y) return 'R';
            if (rookw[1].x == x && rookw[1].y == y) return 'R';
            if (rookb[0].x == x && rookb[0].y == y) return 'r';
            if (rookb[1].x == x && rookb[1].y == y) return 'r';
    
            // Check knights
            if (knightw[0].x == x && knightw[0].y == y) return 'N';
            if (knightw[1].x == x && knightw[1].y == y) return 'N';
            if (knightb[0].x == x && knightb[0].y == y) return 'n';
            if (knightb[1].x == x && knightb[1].y == y) return 'n';
    
            // Check bishops
            if (bishopw[0].x == x && bishopw[0].y == y) return 'B';
            if (bishopw[1].x == x && bishopw[1].y == y) return 'B';
            if (bishopb[0].x == x && bishopb[0].y == y) return 'b';
            if (bishopb[1].x == x && bishopb[1].y == y) return 'b';
    
            // Empty square
            return '.';
        }
    };

    // Helper function declarations
    bool validatePawn(int startX, int startY, int endX, int endY, bool isWhite, const Board& board);
    bool validateRook(int startX, int startY, int endX, int endY, const Board& board);
    bool validateKnight(int startX, int startY, int endX, int endY);
    bool validateBishop(int startX, int startY, int endX, int endY, const Board& board);
    bool validateQueen(int startX, int startY, int endX, int endY, const Board& board);
    bool validateKing(int startX, int startY, int endX, int endY);
    
      
    class player{
       public:
       bool iswhite;
       string playername;
       pawn* pawns[8];
       king* King;
       queen* queens[9];
       rook* rooks[10];
       knight* knights[10];
       bishop* bishops[10];

       int queenCount;
       int rookCount;
       int knightCount;
       int bishopCount;


       //constructor
       player(string name,bool white){
         playername=name;
         iswhite=white;
         for (int i = 0; i < 8; i++) pawns[i] = nullptr;
         for (int i = 0; i < 2; i++) {
             rooks[i] = nullptr;
             knights[i] = nullptr;
             bishops[i] = nullptr;
        }
        for(int i=0;i<9;i++) queens[i] = nullptr;
        King = nullptr;
        queenCount=1;
        rookCount=2;
        knightCount=2;
        bishopCount=2;
       }
    };
    
    void GetNames(string &white, string &black);
    void playTurn(player& currentPlayer, Board& board);
    void runGame(Board& board, player& whitePlayer, player& blackPlayer);
    int charToColumn(char c);
    int charToRow(char c);
    bool movePiece(player& currentPlayer,player& opponent,string move, Board& board);
    bool validMove(player& currentPlayer,const string& move, const Board& board, bool silent=false);
    bool validateCastling(const player& currentPlayer, const Board& board, int startX, int endX);
    bool isInCheck(const player& currentPlayer, const player& opponent, const Board& board);
    bool simulateMoveAndCheckSafety(player& currentPlayer, player& opponent, Board& board,int fromX, int fromY, int toX, int toY);
    bool isCheckmate(player& currentPlayer, player& opponent, Board& board);

    void GetNames(string &white, string &black) {
        cout << "Enter name for White player: ";
        cin >> white;
        cout << "Enter name for Black player: ";
        cin >> black;
    }

    void playTurn(player& currentPlayer,player& opponent, Board& board){
        string move;
        //na kanw validate move function ?
        
        do {cout << currentPlayer.playername << " turn (" << (currentPlayer.iswhite ? "White" : "Black") << ")\n";
        cout<<"enter move(e.g e2e4): ";
        cin >> move;
        }while(!movePiece(currentPlayer,opponent,move,board));
        
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
        board.printBoard();
    }

    void runGame(Board& board, player& whitePlayer, player& blackPlayer){
        bool gameRunning=true;
        player* currentPlayer=&whitePlayer;
        player* opponentPlayer=&blackPlayer;

        while(gameRunning){

            playTurn(*currentPlayer,*opponentPlayer,board);

            if (isCheckmate(*opponentPlayer, *currentPlayer, board)) {
                cout << opponentPlayer->playername << " is in checkmate! ";
                cout << currentPlayer->playername << " wins!\n";
                gameRunning = false;
                break;
            }
            
            //looking for check
            if (isInCheck(*opponentPlayer, *currentPlayer, board)) {
                 cout << opponentPlayer->playername << " is in check!\n";
            }

            
            //swap players
            player* temp = currentPlayer;
            currentPlayer = opponentPlayer;
            opponentPlayer = temp;
            //na checkarw gia checkmate kai stalemate ktl.
        }
    }

    int charToColumn(char c){
        return c-'a';
    }

    int charToRow(char c){
        return c - '1';
    }

    bool movePiece(player& currentPlayer, player& opponent, string move, Board& board) {
        if(!validMove(currentPlayer,move,board,false)){
            return false;
        }
        
        
        int startX = move[0] - 'a';   // Convert letter to column (0-indexed)
        int startY =move[1] - '1';  // Convert row to matrix index (reverse)
        int endX = move[2] - 'a';     // Convert letter to column (0-indexed)
        int endY =move[3] - '1';  // Convert row to matrix index (reverse)

        // Prevent moves that leave the king in check
         if (!simulateMoveAndCheckSafety(currentPlayer, opponent, board, startX, startY, endX, endY)) {
           cout << "You cannot make a move that leaves your king in check.\n";
           return false;
          }
        
        //check for capture
        char destPiece = board.getPieceAt(endX, endY);
        bool isCapture = (currentPlayer.iswhite && islower(destPiece)) || 
                         (!currentPlayer.iswhite && isupper(destPiece));
        

                         if (isCapture) {
                            // Capture opponent's piece
                            bool captured = false;
                    
                            // Check pawns
                            for (int i = 0; i < 8; ++i) {
                                if (opponent.pawns[i] && opponent.pawns[i]->x == endX && opponent.pawns[i]->y == endY) {
                                    opponent.pawns[i]->x = -1;
                                    opponent.pawns[i]->y = -1;
                                    opponent.pawns[i] = nullptr;
                                    captured = true;
                                    break;
                                }
                            }
                    
                            if (!captured) {
                                // Check rooks
                                for (int i = 0; i < opponent.rookCount; ++i) {
                                    if (opponent.rooks[i] && opponent.rooks[i]->x == endX && opponent.rooks[i]->y == endY) {
                                        opponent.rooks[i]->x = -1;
                                        opponent.rooks[i]->y = -1;
                                        opponent.rooks[i] = nullptr;
                                        captured = true;
                                        break;
                                    }
                                }
                            }
                    
                            if (!captured) {
                                // Check knights
                                for (int i = 0; i < opponent.knightCount; ++i) {
                                    if (opponent.knights[i] && opponent.knights[i]->x == endX && opponent.knights[i]->y == endY) {
                                        opponent.knights[i]->x = -1;
                                        opponent.knights[i]->y = -1;
                                        opponent.knights[i] = nullptr;
                                        captured = true;
                                        break;
                                    }
                                }
                            }
                    
                            if (!captured) {
                                // Check bishops
                                for (int i = 0; i < opponent.bishopCount; ++i) {
                                    if (opponent.bishops[i] && opponent.bishops[i]->x == endX && opponent.bishops[i]->y == endY) {
                                        opponent.bishops[i]->x = -1;
                                        opponent.bishops[i]->y = -1;
                                        opponent.bishops[i] = nullptr;
                                        captured = true;
                                        break;
                                    }
                                }
                            }
                    
                            if (!captured) {
                                // Check queen
                                for (int i = 0; i < opponent.queenCount; ++i) {
                                    if (opponent.queens[i] && opponent.queens[i]->x == endX && opponent.queens[i]->y == endY) {
                                        opponent.queens[i]->x = -1;
                                        opponent.queens[i]->y = -1;
                                        opponent.queens[i] = nullptr;
                                        captured = true;
                                        break;
                                    }
                                }
                            }
                    
                            if (!captured) {
                                // Check king
                                if (opponent.King && opponent.King->x == endX && opponent.King->y == endY) {
                                    opponent.King->x = -1;
                                    opponent.King->y = -1;
                                    opponent.King = nullptr;
                                    captured = true;
                                }
                            }
                    
                            if (!captured) {
                                cout << "Error: Capture failed.\n";
                                return false;
                            }
                        }
        
        // Check for pawns
        for (int i = 0; i < 8; ++i) {
            if (currentPlayer.pawns[i] && currentPlayer.pawns[i]->x == startX && currentPlayer.pawns[i]->y == startY) {

                // EN PASSANT EXECUTION
        if ((currentPlayer.iswhite && endY == board.enPassantY && endX == board.enPassantX && startY == 4) ||
            (!currentPlayer.iswhite && endY == board.enPassantY && endX == board.enPassantX && startY == 3)) {

            int capturedPawnY = currentPlayer.iswhite ? endY - 1 : endY + 1;

            for (int j = 0; j < 8; ++j) {
                if (opponent.pawns[j] && opponent.pawns[j]->x == endX && opponent.pawns[j]->y == capturedPawnY) {
                    opponent.pawns[j]->x = -1;
                    opponent.pawns[j]->y = -1;
                    opponent.pawns[j] = nullptr;
                    board.pawns[currentPlayer.iswhite ? j + 8 : j].x = -1;
                    board.pawns[currentPlayer.iswhite ? j + 8 : j].y = -1;
                    break;
                }
            }
        }

                currentPlayer.pawns[i]->x = endX;
                currentPlayer.pawns[i]->y = endY;

                // Reset en passant
                board.enPassantX = -1;
                board.enPassantY = -1;

                if (abs(endY - startY) == 2) {
                    board.enPassantX = endX;
                    board.enPassantY = (startY + endY) / 2; // The square behind the pawn
                } 
        
                //  Check for promotion
                bool promote = (currentPlayer.iswhite && endY == 7) || (!currentPlayer.iswhite && endY == 0);

                if (promote) {
                    cout << "Promote pawn to (Q/R/B/N): ";
                    char choice;
                    cin >> choice;
                    choice = toupper(choice);
        
                    // Remove pawn from player
                    currentPlayer.pawns[i] = nullptr;

                    board.pawns[(currentPlayer.iswhite ? i : i + 8)].x = -1;
                    board.pawns[(currentPlayer.iswhite ? i : i + 8)].y = -1;
        
                    if (currentPlayer.iswhite) {
                        switch (choice) {
                            case 'Q':
                                board.queenw[board.queenwCount] = queen(endX, endY);
                                currentPlayer.queens[currentPlayer.queenCount] = &board.queenw[board.queenwCount];
                                board.queenwCount++;
                                currentPlayer.queenCount++;
                                break;
                            case 'R':
                                board.rookw[board.rookwCount] = rook(endX, endY);
                                currentPlayer.rooks[currentPlayer.rookCount] = &board.rookw[board.rookwCount];
                                board.rookwCount++;
                                currentPlayer.rookCount++;
                                break;
                            case 'B':
                                board.bishopw[board.bishopwCount] = bishop(endX, endY);
                                currentPlayer.bishops[currentPlayer.bishopCount] = &board.bishopw[board.bishopwCount];
                                board.bishopwCount++;
                                currentPlayer.bishopCount++;
                                break;
                            case 'N':
                                board.knightw[board.knightwCount] = knight(endX, endY);
                                currentPlayer.knights[currentPlayer.knightCount] = &board.knightw[board.knightwCount];
                                board.knightwCount++;
                                currentPlayer.knightCount++;
                                break;
                            default:
                                cout << "Invalid choice. Defaulting to Queen.\n";
                                board.queenw[board.queenwCount] = queen(endX, endY);
                                currentPlayer.queens[currentPlayer.queenCount] = &board.queenw[board.queenwCount];
                                board.queenwCount++;
                                currentPlayer.queenCount++;
                                break;
                        }
                    } else {
                        // Black player promotion
                        switch (choice) {
                            case 'Q':
                                board.queenb[board.queenbCount] = queen(endX, endY);
                                currentPlayer.queens[currentPlayer.queenCount] = &board.queenb[board.queenbCount];
                                board.queenbCount++;
                                currentPlayer.queenCount++;
                                break;
                            case 'R':
                                board.rookb[board.rookbCount] = rook(endX, endY);
                                currentPlayer.rooks[currentPlayer.rookCount] = &board.rookb[board.rookbCount];
                                board.rookbCount++;
                                currentPlayer.rookCount++;
                                break;
                            case 'B':
                                board.bishopb[board.bishopbCount] = bishop(endX, endY);
                                currentPlayer.bishops[currentPlayer.bishopCount] = &board.bishopb[board.bishopbCount];
                                board.bishopbCount++;
                                currentPlayer.bishopCount++;
                                break;
                            case 'N':
                                board.knightb[board.knightbCount] = knight(endX, endY);
                                currentPlayer.knights[currentPlayer.knightCount] = &board.knightb[board.knightbCount];
                                board.knightbCount++;
                                currentPlayer.knightCount++;
                                break;
                            default:
                                cout << "Invalid choice. Defaulting to Queen.\n";
                                board.queenb[board.queenbCount] = queen(endX, endY);
                                currentPlayer.queens[currentPlayer.queenCount] = &board.queenb[board.queenbCount];
                                board.queenbCount++;
                                currentPlayer.queenCount++;
                                break;
                        }
                    }
                }
        
                return true;
            }
        }
    
        // Check for rooks
        for (int i = 0; i < 2; ++i) {
            if (currentPlayer.rooks[i] && currentPlayer.rooks[i]->x == startX && currentPlayer.rooks[i]->y == startY) {
            currentPlayer.rooks[i]->x = endX;
            currentPlayer.rooks[i]->y = endY;

            if (currentPlayer.iswhite) {
               if (startX == 0) board.whiteQueensideRookMoved = true;
            if (startX == 7) board.whiteKingsideRookMoved = true;
            } else {
           if (startX == 0) board.blackQueensideRookMoved = true;
           if (startX == 7) board.blackKingsideRookMoved = true;
           }

           return true;
             }
        }
    
        // Check for knights
        for (int i = 0; i < 2; ++i) {
            if (currentPlayer.knights[i] && currentPlayer.knights[i]->x == startX && currentPlayer.knights[i]->y == startY) {
                currentPlayer.knights[i]->x = endX;
                currentPlayer.knights[i]->y = endY;
                return true;
            }
        }
    
        // Check for bishops
        for (int i = 0; i < 2; ++i) {
            if (currentPlayer.bishops[i] && currentPlayer.bishops[i]->x == startX && currentPlayer.bishops[i]->y == startY) {
                currentPlayer.bishops[i]->x = endX;
                currentPlayer.bishops[i]->y = endY;
                return true;
            }
        }
    
        // Check for queen
        for (int i = 0; i < currentPlayer.queenCount; ++i) {
            if (currentPlayer.queens[i] && currentPlayer.queens[i]->x == startX && currentPlayer.queens[i]->y == startY)
              {
                currentPlayer.queens[i]->x = endX;
                currentPlayer.queens[i]->y = endY;
                return true;
              }
        }
        // Check for king
        if (currentPlayer.King && currentPlayer.King->x == startX && currentPlayer.King->y == startY) {
            if (abs(endX - startX) == 2 && startY == endY) {
            // Castling
            bool isWhite = currentPlayer.iswhite;
            int row = isWhite ? 0 : 7;
            bool kingside = endX > startX;
            int rookFromX = kingside ? 7 : 0;
            int rookToX = kingside ? 5 : 3;

            // Move king
            currentPlayer.King->x = endX;

           // Move rook
            rook* rookToMove = isWhite ? 
            (kingside ? &board.rookw[1] : &board.rookw[0]) :
            (kingside ? &board.rookb[1] : &board.rookb[0]);

            rookToMove->x = rookToX;
            rookToMove->y = row;

        // Update movement flags
        if (isWhite) {
            board.whiteKingMoved = true;
            if (kingside) board.whiteKingsideRookMoved = true;
            else board.whiteQueensideRookMoved = true;
        } 
        else {
            board.blackKingMoved = true;
            if (kingside) board.blackKingsideRookMoved = true;
            else board.blackQueensideRookMoved = true;
           }

        return true;
       }

          // Regular king move
          currentPlayer.King->x = endX;
          currentPlayer.King->y = endY;

         if (currentPlayer.iswhite) board.whiteKingMoved = true;
         else board.blackKingMoved = true;

         return true;
    }
    
        cout << "No piece found at that location.\n";
        return false;
    }

    bool validMove(player& currentPlayer, const string& move, const Board& board, bool silent) {
        // Validate move format (e.g., "e2e4")
        if (move.size() != 4) {
            cout << "Invalid format. Use format like e2e4.\n";
            return false;
        }
    
        // Parse coordinates
        int startX = move[0] - 'a';
        int startY = move[1] - '1';
        int endX = move[2] - 'a';
        int endY = move[3] - '1';
    
        // Check if coordinates are within the board
        if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
            endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            cout << "Coordinates out of bounds.\n";
            return false;
        }
    
        // Check if the player has a piece at the start position
        bool hasPiece = false;
    
        // Check all pieces
        for (int i = 0; i < 8; ++i) {
            if (currentPlayer.pawns[i] && currentPlayer.pawns[i]->x == startX && currentPlayer.pawns[i]->y == startY) {
                hasPiece = true;
                break;
            }
        }
        if (!hasPiece) {
            for (int i = 0; i < 2; ++i) {
                if (currentPlayer.rooks[i] && currentPlayer.rooks[i]->x == startX && currentPlayer.rooks[i]->y == startY) {
                    hasPiece = true;
                    break;
                }
            }
        }
        if (!hasPiece) {
            for (int i = 0; i < 2; ++i) {
                if (currentPlayer.knights[i] && currentPlayer.knights[i]->x == startX && currentPlayer.knights[i]->y == startY) {
                    hasPiece = true;
                    break;
                }
            }
        }
        if (!hasPiece) {
            for (int i = 0; i < 2; ++i) {
                if (currentPlayer.bishops[i] && currentPlayer.bishops[i]->x == startX && currentPlayer.bishops[i]->y == startY) {
                    hasPiece = true;
                    break;
                }
            }
        }
        for (int i = 0; i < currentPlayer.queenCount; ++i) {
            if (currentPlayer.queens[i] && currentPlayer.queens[i]->x == startX && currentPlayer.queens[i]->y == startY) {
                hasPiece = true;
                break;
            }
        }
        if (!hasPiece && currentPlayer.King && currentPlayer.King->x == startX && currentPlayer.King->y == startY) {
            hasPiece = true;
        }
    
        if (!hasPiece) {
            cout << "No piece at starting position.\n";
            return false;
        }
    
        // Check if destination has a same-color piece
        bool sameColorCollision = false;
    
        // Check pawns
        for (int i = 0; i < 8; ++i) {
            if (currentPlayer.pawns[i] && currentPlayer.pawns[i]->x == endX && currentPlayer.pawns[i]->y == endY) {
                sameColorCollision = true;
                break;
            }
        }
        // Check rooks
        if (!sameColorCollision) {
            for (int i = 0; i < 2; ++i) {
                if (currentPlayer.rooks[i] && currentPlayer.rooks[i]->x == endX && currentPlayer.rooks[i]->y == endY) {
                    sameColorCollision = true;
                    break;
                }
            }
        }
        // Check knights
        if (!sameColorCollision) {
            for (int i = 0; i < 2; ++i) {
                if (currentPlayer.knights[i] && currentPlayer.knights[i]->x == endX && currentPlayer.knights[i]->y == endY) {
                    sameColorCollision = true;
                    break;
                }
            }
        }
        // Check bishops
        if (!sameColorCollision) {
            for (int i = 0; i < 2; ++i) {
                if (currentPlayer.bishops[i] && currentPlayer.bishops[i]->x == endX && currentPlayer.bishops[i]->y == endY) {
                    sameColorCollision = true;
                    break;
                }
            }
        }
        // Check queen
        for (int i = 0; i < currentPlayer.queenCount; ++i) {
            if (currentPlayer.queens[i] && currentPlayer.queens[i]->x == endX && currentPlayer.queens[i]->y == endY) {
                sameColorCollision = true;
                break;
            }
        }
        // Check king
        if (!sameColorCollision && currentPlayer.King && currentPlayer.King->x == endX && currentPlayer.King->y == endY) {
            sameColorCollision = true;
        }
    
        if (sameColorCollision) {
            if (!silent)cout << "Destination occupied by your own piece.\n";
            return false;
        }

        for (int i = 0; i < 8; ++i) {
            if (currentPlayer.pawns[i] && currentPlayer.pawns[i]->x == startX && currentPlayer.pawns[i]->y == startY) {
                return validatePawn(startX, startY, endX, endY, currentPlayer.iswhite, board);
            }
        }
    
        for (int i = 0; i < 2; ++i) {
            if (currentPlayer.rooks[i] && currentPlayer.rooks[i]->x == startX && currentPlayer.rooks[i]->y == startY) {
                return validateRook(startX, startY, endX, endY, board);
            }
        }
    
        for (int i = 0; i < 2; ++i) {
            if (currentPlayer.knights[i] && currentPlayer.knights[i]->x == startX && currentPlayer.knights[i]->y == startY) {
                return validateKnight(startX, startY, endX, endY);
            }
        }
    
        for (int i = 0; i < 2; ++i) {
            if (currentPlayer.bishops[i] && currentPlayer.bishops[i]->x == startX && currentPlayer.bishops[i]->y == startY) {
                return validateBishop(startX, startY, endX, endY, board);
            }
        }
    
        for (int i = 0; i < currentPlayer.queenCount; ++i) {
            if (currentPlayer.queens[i] && currentPlayer.queens[i]->x == startX && currentPlayer.queens[i]->y == startY) {
                return validateQueen(startX, startY, endX, endY, board);
            }
        }
    
        if (currentPlayer.King && currentPlayer.King->x == startX && currentPlayer.King->y == startY) {
            if (abs(endX - startX) == 2 && startY == endY) {
            return validateCastling(currentPlayer, board, startX, endX);
            }
            return validateKing(startX, startY, endX, endY);
        }
    
        cout << "Unknown piece type.\n";
        return false;
    }

        
    
        
    

    bool validatePawn(int startX, int startY, int endX, int endY, bool isWhite, const Board& board) {
        int dx = endX - startX;
        int dy = endY - startY;
    
        if (isWhite) {
            // White pawn moves
            if (dx == 0) {
                // Forward move
                if (dy == 1) {
                    return board.getPieceAt(endX, endY) == '.';
                } else if (dy == 2 && startY == 1) {
                    // Check two squares ahead
                    return board.getPieceAt(startX, startY + 1) == '.' &&
                           board.getPieceAt(startX, startY + 2) == '.';
                }
            } else if (abs(dx) == 1 && dy == 1) {
              char dest = board.getPieceAt(endX, endY);
              if (dest != '.' && islower(dest)) return true;

              // En passant for white
             if (endX == board.enPassantX && endY == board.enPassantY) {
             return true;
                   }
              }
        } else {
            // Black pawn moves
            if (dx == 0) {
                if (dy == -1) {
                    return board.getPieceAt(endX, endY) == '.';
                } else if (dy == -2 && startY == 6) {
                    return board.getPieceAt(startX, startY - 1) == '.' &&
                           board.getPieceAt(startX, startY - 2) == '.';
                }
            } 
            else if (abs(dx) == 1 && dy == -1) {
              char dest = board.getPieceAt(endX, endY);
              if (dest != '.' && isupper(dest)) return true;

               // En passant for black
              if (endX == board.enPassantX && endY == board.enPassantY) {
              return true;
              }
           }
        }
        return false;
    }
    
    bool validateRook(int startX, int startY, int endX, int endY, const Board& board) {
        if (startX != endX && startY != endY) return false;
    
        int stepX = (endX > startX) ? 1 : (endX < startX) ? -1 : 0;
        int stepY = (endY > startY) ? 1 : (endY < startY) ? -1 : 0;
    
        int currentX = startX + stepX;
        int currentY = startY + stepY;
        while (currentX != endX || currentY != endY) {
            if (board.getPieceAt(currentX, currentY) != '.') return false;
            currentX += stepX;
            currentY += stepY;
        }
        return true;
    }
    
    bool validateKnight(int startX, int startY, int endX, int endY) {
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    }
    
    bool validateBishop(int startX, int startY, int endX, int endY, const Board& board) {
        if (abs(endX - startX) != abs(endY - startY)) return false;
    
        int stepX = (endX > startX) ? 1 : -1;
        int stepY = (endY > startY) ? 1 : -1;
    
        int distance = abs(endX - startX);
        for (int i = 1; i < distance; ++i) {
            int currentX = startX + i * stepX;
            int currentY = startY + i * stepY;
            if (board.getPieceAt(currentX, currentY) != '.') return false;
        }
        return true;
    }
    
    bool validateQueen(int startX, int startY, int endX, int endY, const Board& board) {
        return validateRook(startX, startY, endX, endY, board) ||
               validateBishop(startX, startY, endX, endY, board);
    }
    
    bool validateKing(int startX, int startY, int endX, int endY) {
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return dx <= 1 && dy <= 1;
    }

    bool isInCheck(const player& currentPlayer, const player& opponent, const Board& board) {
    int kingX = currentPlayer.King->x;
    int kingY = currentPlayer.King->y;

    // Check opponent pawns
    for (int i = 0; i < 8; ++i) {
        if (opponent.pawns[i]) {
            if (validatePawn(opponent.pawns[i]->x, opponent.pawns[i]->y, kingX, kingY, opponent.iswhite, board)) {
                return true;
            }
        }
    }

    // Rooks
    for (int i = 0; i < 2; ++i) {
        if (opponent.rooks[i]) {
            if (validateRook(opponent.rooks[i]->x, opponent.rooks[i]->y, kingX, kingY, board)) {
                return true;
            }
        }
    }

    // Knights
    for (int i = 0; i < 2; ++i) {
        if (opponent.knights[i]) {
            if (validateKnight(opponent.knights[i]->x, opponent.knights[i]->y, kingX, kingY)) {
                return true;
            }
        }
    }

    // Bishops
    for (int i = 0; i < 2; ++i) {
        if (opponent.bishops[i]) {
            if (validateBishop(opponent.bishops[i]->x, opponent.bishops[i]->y, kingX, kingY, board)) {
                return true;
            }
        }
    }

    // Queens
    for (int i = 0; i < opponent.queenCount; ++i) {
        if (opponent.queens[i]) {
            if (validateQueen(opponent.queens[i]->x, opponent.queens[i]->y, kingX, kingY, board)) {
                return true;
            }
        }
    }

    // King (for adjacent check)
    if (opponent.King) {
        if (validateKing(opponent.King->x, opponent.King->y, kingX, kingY)) {
            return true;
        }
    }

    return false;
}

    bool validateCastling(const player& currentPlayer, const Board& board, int startX, int endX) {
    bool isWhite = currentPlayer.iswhite;
    int row = isWhite ? 0 : 7;
    bool kingside = endX > startX;

    // Check if king or relevant rook has moved
    if ((isWhite && board.whiteKingMoved) || (!isWhite && board.blackKingMoved))
        return false;

    if (kingside) {
        if ((isWhite && board.whiteKingsideRookMoved) || (!isWhite && board.blackKingsideRookMoved))
            return false;
    } else {
        if ((isWhite && board.whiteQueensideRookMoved) || (!isWhite && board.blackQueensideRookMoved))
            return false;
    }

    // Check empty squares between king and rook
    int rookX = kingside ? 7 : 0;
    int direction = kingside ? 1 : -1;
    for (int x = startX + direction; x != rookX; x += direction) {
        if (board.getPieceAt(x, row) != '.') return false;
    }

    // TODO: Add check safety here (king not in check, through check, or into check)
    return true;
}

bool simulateMoveAndCheckSafety(
    player& currentPlayer,
    player& opponent,
    Board& board,
    int fromX, int fromY,
    int toX,   int toY
) {
    // 1) Helper to remember which piece we moved & which (if any) we captured
    struct PieceRef {
        enum Type {
            NONE   = -1,
            PAWN   =  0,
            ROOK   =  1,
            KNIGHT =  2,
            BISHOP =  3,
            QUEEN  =  4,
            KING   =  5
        } t;
        int idx;
        bool isWhite;
    };
    PieceRef mover    { PieceRef::NONE, -1, false };
    PieceRef captured { PieceRef::NONE, -1, false };

    char dest = board.getPieceAt(toX, toY);
    // 2) Remove (capture) anything that's on (toX,toY)
    if (dest != '.') {
        // Pawns
        for (int i = 0; i < 16 && captured.t == PieceRef::NONE; ++i) {
            if (board.pawns[i].x == toX && board.pawns[i].y == toY) {
                captured = { PieceRef::PAWN, i, i < 8 };
                board.pawns[i].x = board.pawns[i].y = -1;
            }
        }
        // Rooks
        for (int i = 0; i < 2 && captured.t == PieceRef::NONE; ++i) {
            if (board.rookw[i].x == toX && board.rookw[i].y == toY) {
                captured = { PieceRef::ROOK, i, true };
                board.rookw[i].x = board.rookw[i].y = -1;
            }
            else if (board.rookb[i].x == toX && board.rookb[i].y == toY) {
                captured = { PieceRef::ROOK, i, false };
                board.rookb[i].x = board.rookb[i].y = -1;
            }
        }
        // Knights
        for (int i = 0; i < 2 && captured.t == PieceRef::NONE; ++i) {
            if (board.knightw[i].x == toX && board.knightw[i].y == toY) {
                captured = { PieceRef::KNIGHT, i, true };
                board.knightw[i].x = board.knightw[i].y = -1;
            }
            else if (board.knightb[i].x == toX && board.knightb[i].y == toY) {
                captured = { PieceRef::KNIGHT, i, false };
                board.knightb[i].x = board.knightb[i].y = -1;
            }
        }
        // Bishops
        for (int i = 0; i < 2 && captured.t == PieceRef::NONE; ++i) {
            if (board.bishopw[i].x == toX && board.bishopw[i].y == toY) {
                captured = { PieceRef::BISHOP, i, true };
                board.bishopw[i].x = board.bishopw[i].y = -1;
            }
            else if (board.bishopb[i].x == toX && board.bishopb[i].y == toY) {
                captured = { PieceRef::BISHOP, i, false };
                board.bishopb[i].x = board.bishopb[i].y = -1;
            }
        }
        // Queens
        for (int i = 0; i < board.queenwCount && captured.t == PieceRef::NONE; ++i) {
            if (board.queenw[i].x == toX && board.queenw[i].y == toY) {
                captured = { PieceRef::QUEEN, i, true };
                board.queenw[i].x = board.queenw[i].y = -1;
            }
        }
        for (int i = 0; i < board.queenbCount && captured.t == PieceRef::NONE; ++i) {
            if (board.queenb[i].x == toX && board.queenb[i].y == toY) {
                captured = { PieceRef::QUEEN, i, false };
                board.queenb[i].x = board.queenb[i].y = -1;
            }
        }
        // King
        if (captured.t == PieceRef::NONE) {
            if (board.kingw.x == toX && board.kingw.y == toY) {
                captured = { PieceRef::KING, 0, true  };
                board.kingw.x = board.kingw.y = -1;
            } else if (board.kingb.x == toX && board.kingb.y == toY) {
                captured = { PieceRef::KING, 0, false };
                board.kingb.x = board.kingb.y = -1;
            }
        }
    }

    // 3) Move *your* piece
    //    We only bind the correct board array *after* we know its color.
    //    That prevents us accidentally touching the opponent’s pieces.
    // Pawns
    for (int i = 0; i < 8 && mover.t == PieceRef::NONE; ++i) {
        if (currentPlayer.pawns[i] &&
            currentPlayer.pawns[i]->x == fromX &&
            currentPlayer.pawns[i]->y == fromY) {
            mover = { PieceRef::PAWN,  i, currentPlayer.iswhite };
            int bi = mover.isWhite ? i : i + 8;
            board.pawns[bi].x = toX;
            board.pawns[bi].y = toY;
        }
    }
    // Rooks
    if (mover.t == PieceRef::NONE) {
        for (int i = 0; i < 2 && mover.t == PieceRef::NONE; ++i) {
            if (currentPlayer.rooks[i] &&
                currentPlayer.rooks[i]->x == fromX &&
                currentPlayer.rooks[i]->y == fromY) {
                mover = { PieceRef::ROOK, i, currentPlayer.iswhite };
                auto &arr = mover.isWhite ? board.rookw : board.rookb;
                arr[i].x = toX;
                arr[i].y = toY;
            }
        }
    }
    // Knights
    if (mover.t == PieceRef::NONE) {
        for (int i = 0; i < 2 && mover.t == PieceRef::NONE; ++i) {
            if (currentPlayer.knights[i] &&
                currentPlayer.knights[i]->x == fromX &&
                currentPlayer.knights[i]->y == fromY) {
                mover = { PieceRef::KNIGHT, i, currentPlayer.iswhite };
                auto &arr = mover.isWhite ? board.knightw : board.knightb;
                arr[i].x = toX;
                arr[i].y = toY;
            }
        }
    }
    // Bishops
    if (mover.t == PieceRef::NONE) {
        for (int i = 0; i < 2 && mover.t == PieceRef::NONE; ++i) {
            if (currentPlayer.bishops[i] &&
                currentPlayer.bishops[i]->x == fromX &&
                currentPlayer.bishops[i]->y == fromY) {
                mover = { PieceRef::BISHOP, i, currentPlayer.iswhite };
                auto &arr = mover.isWhite ? board.bishopw : board.bishopb;
                arr[i].x = toX;
                arr[i].y = toY;
            }
        }
    }
    // Queens
    if (mover.t == PieceRef::NONE) {
        for (int i = 0; i < currentPlayer.queenCount; ++i) {
            if (currentPlayer.queens[i] &&
                currentPlayer.queens[i]->x == fromX &&
                currentPlayer.queens[i]->y == fromY) {
                mover = { PieceRef::QUEEN, i, currentPlayer.iswhite };
                auto &arr = mover.isWhite ? board.queenw : board.queenb;
                arr[i].x = toX;
                arr[i].y = toY;
                break;
            }
        }
    }
    // King
    if (mover.t == PieceRef::NONE &&
        currentPlayer.King &&
        currentPlayer.King->x == fromX &&
        currentPlayer.King->y == fromY) {
        mover = { PieceRef::KING, 0, currentPlayer.iswhite };
        auto &kp = mover.isWhite ? board.kingw : board.kingb;
        kp.x = toX;
        kp.y = toY;
    }

    // 4) Check for check on this *mutated* board
    bool stillInCheck = isInCheck(currentPlayer, opponent, board);

    // 5) Undo *your* move
    switch (mover.t) {
      case PieceRef::PAWN: {
        int bi = mover.isWhite ? mover.idx : mover.idx + 8;
        board.pawns[bi].x = fromX;
        board.pawns[bi].y = fromY;
      } break;
      case PieceRef::ROOK: {
        auto &arr = mover.isWhite ? board.rookw : board.rookb;
        arr[mover.idx].x = fromX;
        arr[mover.idx].y = fromY;
      } break;
      case PieceRef::KNIGHT: {
        auto &arr = mover.isWhite ? board.knightw : board.knightb;
        arr[mover.idx].x = fromX;
        arr[mover.idx].y = fromY;
      } break;
      case PieceRef::BISHOP: {
        auto &arr = mover.isWhite ? board.bishopw : board.bishopb;
        arr[mover.idx].x = fromX;
        arr[mover.idx].y = fromY;
      } break;
      case PieceRef::QUEEN: {
        auto &arr = mover.isWhite ? board.queenw : board.queenb;
        arr[mover.idx].x = fromX;
        arr[mover.idx].y = fromY;
      } break;
      case PieceRef::KING: {
        auto &kp = mover.isWhite ? board.kingw : board.kingb;
        kp.x = fromX;
        kp.y = fromY;
      } break;
      default:
        break;
    }

    // 6) Restore any captured piece
    if (captured.t != PieceRef::NONE) {
      switch (captured.t) {
        case PieceRef::PAWN:
          board.pawns[captured.idx].x = toX;
          board.pawns[captured.idx].y = toY;
          break;
        case PieceRef::ROOK: {
          auto &arr = captured.isWhite ? board.rookw : board.rookb;
          arr[captured.idx].x = toX;
          arr[captured.idx].y = toY;
        } break;
        case PieceRef::KNIGHT: {
          auto &arr = captured.isWhite ? board.knightw : board.knightb;
          arr[captured.idx].x = toX;
          arr[captured.idx].y = toY;
        } break;
        case PieceRef::BISHOP: {
          auto &arr = captured.isWhite ? board.bishopw : board.bishopb;
          arr[captured.idx].x = toX;
          arr[captured.idx].y = toY;
        } break;
        case PieceRef::QUEEN: {
          auto &arr = captured.isWhite ? board.queenw : board.queenb;
          arr[captured.idx].x = toX;
          arr[captured.idx].y = toY;
        } break;
        case PieceRef::KING: {
          auto &kp = captured.isWhite ? board.kingw : board.kingb;
          kp.x = toX;
          kp.y = toY;
        } break;
        default:
          break;
      }
    }

    return !stillInCheck;
}


bool isCheckmate(player& currentPlayer, player& opponent, Board& board) {
    if (!isInCheck(currentPlayer, opponent, board))
        return false;  // Can't be checkmate if not in check

    // Try all possible moves for the current player
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            char piece = board.getPieceAt(x, y);
            if (piece == '.' || (currentPlayer.iswhite && islower(piece)) || (!currentPlayer.iswhite && isupper(piece)))
                continue;

            for (int tx = 0; tx < 8; ++tx) {
                for (int ty = 0; ty < 8; ++ty) {
                    string testMove = string(1, 'a' + x) + string(1, '1' + y) + string(1, 'a' + tx) + string(1, '1' + ty);
                    if (validMove(currentPlayer, testMove, board,true)) {
                        if (simulateMoveAndCheckSafety(currentPlayer, opponent, board, x, y, tx, ty)) {
                            return false;  // Found a move that prevents check
                        }
                    }
                }
            }
        }
    }

    return true;  // No legal moves prevent check → checkmate
}
    

int main(){
    
    
    //getting players names
    string wname,bname;
    GetNames(wname,bname);


    player wplayer(wname,true),bplayer(bname,false);
    Board board;
    for (int i = 0; i < 8; i++) {
        wplayer.pawns[i] = &board.pawns[i];
        bplayer.pawns[i] = &board.pawns[i + 8];
    }
    wplayer.King = &board.kingw;
    bplayer.King = &board.kingb;

    wplayer.queens[0] = &board.queenw[0];
    bplayer.queens[0] = &board.queenb[0];

    wplayer.rooks[0] = &board.rookw[0];
    wplayer.rooks[1] = &board.rookw[1];
    bplayer.rooks[0] = &board.rookb[0];
    bplayer.rooks[1] = &board.rookb[1];
    
    wplayer.bishops[0] = &board.bishopw[0];
    wplayer.bishops[1] = &board.bishopw[1];
    bplayer.bishops[0] = &board.bishopb[0];
    bplayer.bishops[1] = &board.bishopb[1];

    wplayer.knights[0] = &board.knightw[0];
    wplayer.knights[1] = &board.knightw[1];
    bplayer.knights[0] = &board.knightb[0];
    bplayer.knights[1] = &board.knightb[1];

    board.printBoard();
    runGame(board, wplayer,bplayer);
    
    return 0;
}