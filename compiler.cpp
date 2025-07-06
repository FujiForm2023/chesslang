#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

const int WHITE_PAWN    = 1;
const int WHITE_KNIGHT  = 3;
const int WHITE_BISHOP  = 3;
const int WHITE_ROOK    = 5;
const int WHITE_QUEEN   = 9;
const int WHITE_KING    = 0;

const int BLACK_PAWN    = -1;
const int BLACK_KNIGHT  = -3;
const int BLACK_BISHOP  = -3;
const int BLACK_ROOK    = -5;
const int BLACK_QUEEN   = -9;
const int BLACK_KING    = 0;

const int BOARD_SIZE = 8;
int board[BOARD_SIZE][BOARD_SIZE] = { 0 };

struct Piece {
    char type;
    int x, y;
    bool white;
};

vector<Piece> pieces;
int checkmate_status = -1; // 0 if white wins, 1 if black wins, -2 stalemate

bool whiteKingMoved = false;
bool whiteKingsideRookMoved = false;
bool whiteQueensideRookMoved = false;
bool blackKingMoved = false;
bool blackKingsideRookMoved = false;
bool blackQueensideRookMoved = false;

void initialize(){
    pieces.clear();

    for (int x = 0; x < BOARD_SIZE; ++x) {
        pieces.push_back({ 'P', x, 1, true });
    }
    pieces.push_back({ 'R', 0, 0, true }); pieces.push_back({ 'R', 7, 0, true });
    pieces.push_back({ 'N', 1, 0, true }); pieces.push_back({ 'N', 6, 0, true });
    pieces.push_back({ 'B', 2, 0, true }); pieces.push_back({ 'B', 5, 0, true });
    pieces.push_back({ 'Q', 3, 0, true });
    pieces.push_back({ 'K', 4, 0, true });

    for (int x = 0; x < BOARD_SIZE; ++x) {
        pieces.push_back({ 'P', x, 6, false });
    }
    pieces.push_back({ 'R', 0, 7, false }); pieces.push_back({ 'R', 7, 7, false });
    pieces.push_back({ 'N', 1, 7, false }); pieces.push_back({ 'N', 6, 7, false });
    pieces.push_back({ 'B', 2, 7, false }); pieces.push_back({ 'B', 5, 7, false });
    pieces.push_back({ 'Q', 3, 7, false });
    pieces.push_back({ 'K', 4, 7, false });

    whiteKingMoved = whiteKingsideRookMoved = whiteQueensideRookMoved = false;
    blackKingMoved = blackKingsideRookMoved = blackQueensideRookMoved = false;

}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: program <filename>\n";
        return 1;
    }

    initialize();

    return 0;
}
