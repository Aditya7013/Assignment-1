#include <iostream>

class TicTacToe
{
private:
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1_symbol = 'O'; 
    char player2_symbol = 'X'; 
    char current_turn = player1_symbol; 
    bool playing = true;

public:
    void print_board();
    int play_move(int index, char move);
    int check_win(char move);
    void start();
};

int main()
{
    TicTacToe game;
    game.start();
    return 0;
}

void TicTacToe::start()
{
    int input;
    int state;
    while (playing)
    {
        print_board();
        std::cout << "Play your move " << current_turn << std::endl;
        std::cin >> input;

        if (input < 0 || input > 8 || board[input] != ' ')
        {
            std::cout << "Invalid move. Please try again." << std::endl;
            continue;
        }

        if (play_move(input, current_turn) == 0)
        {
            std::cout << "Box already occupied" << std::endl;
            continue;
        }

        state = check_win(current_turn);
        if (state == 1)
        {
            print_board();
            std::cout << current_turn << " wins the game!" << std::endl;
            break;
        }
        else if (state == 2)
        {
            std::cout << "Draw!" << std::endl;
            break;
        }

        current_turn = (current_turn == player1_symbol) ? player2_symbol : player1_symbol;
    }
}

void TicTacToe::print_board()
{
    for (int i = 0; i < 9; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 5 || i == 7 || i == 8)
        {
            std::cout << " | ";
        }
        std::cout << board[i];
        if (i == 2 || i == 5)
        {
            std::cout << std::endl;
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}

int TicTacToe::play_move(int index, char move)
{
    if (index >= 0 && index < 9)
    {
        if (board[index] == ' ')
        {
            board[index] = move;
            return 1;
        }
    }
    return 0;
}

int TicTacToe::check_win(char move)
{
    if ((board[0] == move && board[1] == move && board[2] == move) ||
        (board[3] == move && board[4] == move && board[5] == move) ||
        (board[6] == move && board[7] == move && board[8] == move) ||
        (board[0] == move && board[3] == move && board[6] == move) ||
        (board[1] == move && board[4] == move && board[7] == move) ||
        (board[2] == move && board[5] == move && board[8] == move) ||
        (board[0] == move && board[4] == move && board[8] == move) ||
        (board[2] == move && board[4] == move && board[6] == move))
    {
        return 1;
    }
    else
    {
        bool draw = true;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == ' ')
            {
                draw = false;
                break;
            }
        }
        if (draw)
        {
            return 2;
        }
    }
    return 0;
}
