//board class

#pragma once
#include "../headers/Board.h"

//constructor
Board::Board()
{
    this->initVariables();
    this->initBoard();
    this->initTexture();
    this->startGame();

    //pointers to kings
    this->kingsPointers[0] = board[0][4];
    this->kingsPointers[1] = board[7][4];
}

//check if in chess one of the kings
bool Board::isInChess(Color color) const
{
    //kings current positions
    auto currentKingPointer = this->kingsPointers[(color == WHITE) ? 1 : 0];
    auto currentKingPos = currentKingPointer->getPositionOnBoard();

    for (int i = 0; i < BOARD_LENGTH; i++)
    {
        for (int k = 0; k < BOARD_LENGTH; k++)
        {
            auto currentPiece = board[i][k];
            if (currentPiece == nullptr || currentPiece->getColor() == color)
            {
                continue;
            }
            auto piecePoses = currentPiece->getPossiblePositions(board);
            for (auto pos : piecePoses)
            {
                if (currentKingPos == pos)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

//destructor
Board::~Board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int k = 0; k < BOARD_SIZE; k++)
        {
            delete this->board[i][k];
        }
    }
    for (auto &texture : this->texturePointer)
    {
        delete texture.second;
    }
}

//init variables
void Board::initVariables()
{
    this->kingsPointers[0] = nullptr;
    this->kingsPointers[1] = nullptr;
    this->chess = false;
    this->currentPlayer = WHITE;
    this->saveTo = nullptr;
}

//check if availabe
bool Board::isEmpty(int row, int column) const
{
    if (row >= 0 && column >= 0 && row <= this->board.size() && column <= this->board.size())
        return this->board[row][column] == nullptr; //cuz array
    else
        throw std::invalid_argument("ERROR IsEmpty out of range\n");
}

//init texture
void Board::initTexture()
{
    for (auto pieceName : this->piecesNames)
    {
        this->texturePointer[pieceName] = new sf::Texture;
        if (!this->texturePointer[pieceName]->loadFromFile(this->assertsFolderName + pieceName + ".png"))
        {
            throw std::invalid_argument("ERROR LOADING " + pieceName + ".png\n");
        }
    }
}

//draw
void Board::draw(sf::RenderTarget &target) const
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int k = 0; k < BOARD_SIZE; k++)
        {
            if (this->board[i][k] != nullptr)
            {
                this->board[i][k]->render(target);
            }
        }
    }
}

//init game pieces on board
void Board::startGame()
{

    std::array<char, 16> order = {
        'r', 'k', 'b', 'Q', 'K', 'b', 'k', 'r',
        'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'};

    std::string prefix = "Black";
    Color color = BLACK;

    int row = 0;
    int column = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k < order.size(); k++)
        {
            if (column == 8)
            {
                column = 0;
                row += (color == BLACK) ? 1 : -1;
            }
            auto expr = order[k];
            switch (expr)
            {
            case 'p':
                board[row][column] = new Pawn(row, column,
                                              this->texturePointer[prefix + "Pawn"], color);
                column += 1;
                break;
            case 'r':
                board[row][column] = new Rook(row, column,
                                              this->texturePointer[prefix + "Rook"], color);
                column += 1;
                break;
            case 'b':
                board[row][column] = new Bishop(row, column,
                                                this->texturePointer[prefix + "Bishop"], color);
                column += 1;
                break;
            case 'k':
                board[row][column] = new Knight(row, column,
                                                this->texturePointer[prefix + "Knight"], color);
                column += 1;
                break;

            case 'K':
                board[row][column] = new King(row, column,
                                              this->texturePointer[prefix + "King"], color);
                column += 1;
                break;
            case 'Q':
                board[row][column] = new Queen(row, column,
                                               this->texturePointer[prefix + "Queen"], color);
                column += 1;
                break;
            }
        }
        prefix = "White";
        color = WHITE;
        row = 8;
    }
}

//click to position on board
int Board::clickToPlace(double value)
{
    if (value < 0 || value > 640)
    {
        return -1;
    }
    int key = (int)value;
    key /= 10;
    int loc = 0;
    for (int i = 8; i < 64 && key >= i; i += 8)
    {
        ++loc;
    }
    return loc;
}

//overload subscript
const Piece *Board::operator()(int row, int col) const
{
    return this->board[row][col];
}

//get color in place
Color Board::getColor(int row, int col) const
{
    return this->board[row][col]->getColor();
}

//do move on board not yet implement to screen
bool Board::doMove(int rowTo, int columnTo, int rowFrom, int columnFrom)
{
    auto moves = this->board[rowFrom][columnFrom]->getPossiblePositions(board);
    auto p = std::make_pair(rowTo, columnTo);

    if (this->board[rowTo][columnTo] != nullptr &&
            this->board[rowTo][columnTo]->getName() == "King" ||
        this->board[rowFrom][columnFrom] == nullptr) //cant eat king nor move nullptr piece
    {
        return false;
    }
    for (auto move : moves)
    {
        if (move == p)
        {
            //TODO detect check mate!
            this->saveTo = this->board[rowTo][columnTo];
            this->board[rowTo][columnTo] = nullptr;
            this->board[rowTo][columnTo] = this->board[rowFrom][columnFrom];
            this->board[rowTo][columnTo]->setPositionOnBoard(rowTo, columnTo);
            this->board[rowFrom][columnFrom] = nullptr;
            return true;
        }
    }
    return false;
}

//redo last doMove move
void Board::redoLastMove(int rowTo, int columnTo, int rowFrom, int columnFrom)
{
    this->board[rowFrom][columnFrom] = this->board[rowTo][columnTo];
    this->board[rowFrom][columnFrom]->setPositionOnBoard(rowFrom, columnFrom);
    this->board[rowTo][columnTo] = this->saveTo;
    this->saveTo = nullptr;
}

//implement move
void Board::implementLastMove(int rowTo, int columnTo, int rowFrom, int columnFrom)
{
    delete this->saveTo;
    this->saveTo = nullptr;
    this->board[rowTo][columnTo]->setPosition(rowTo, columnTo);
    this->currentPlayer = (this->currentPlayer == WHITE) ? BLACK : WHITE;
    chess = this->isInChess(this->currentPlayer);
}

//check for checkmate
bool Board::isCheckMate(Color color) 
{
    bool chess = this->isInChess(color);
    if (!chess)
    {
        return false;
    }
    auto copy = this->saveTo;
    if (chess)
    {
        for (int i = 0; i < BOARD_LENGTH; i++)
        {
            for (int k = 0; k < BOARD_LENGTH; k++)
            {
                if (this->board[i][k] == nullptr || this->board[i][k]->getColor() != color)
                {
                    continue;
                }
                auto currentPiecePos = this->board[i][k]->getPositionOnBoard();
                auto pieceMoves = this->board[i][k]->getPossiblePositions(this->board);
                for (auto move : pieceMoves)
                {
                    //if legall~
                    if (this->doMove(move.first, move.second, currentPiecePos.first, currentPiecePos.second))
                    {
                        chess = this->isInChess(color);
                        this->redoLastMove(move.first, move.second, currentPiecePos.first, currentPiecePos.second);
                        if (!chess)
                        {
                            this->saveTo = copy;
                            return false;
                        }
                    }
                }
            }
        }
    }
    this->saveTo = copy;
    return true;
}

//move piece one board return boolean if move has been done
bool Board::move(int rowTo, int columnTo, int rowFrom, int columnFrom) //the new position need change
{
    auto moves = this->board[rowFrom][columnFrom]->getPossiblePositions(board);
    auto p = std::make_pair(rowTo, columnTo);

    if (this->doMove(rowTo, columnTo, rowFrom, columnFrom))
    {
        if (isInChess(this->currentPlayer)) //if the move make open to chess, illegal
        {
            this->redoLastMove(rowTo, columnTo, rowFrom, columnFrom);
            return false;
        }
        else if (chess && !isInChess(this->currentPlayer) || !chess) //if move stopped chess or legall
        {
            this->implementLastMove(rowTo, columnTo, rowFrom, columnFrom);
            return true;
        }
        else
        {
            throw std::invalid_argument("ERROR in board nor chess/legall move\n");
        }
    }
    return false;
}

//init board
void Board::initBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int k = 0; k < BOARD_SIZE; k++)
        {
            this->board[i][k] = nullptr;
        }
    }
}