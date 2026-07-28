/*
 * tictactoe.cpp
 *
 *  Created on: Apr 13, 2022
 *      Author: montanab-adm
 */
#include "main.h"

typedef enum
{
    GAME_AI_TURN,
    GAME_HUMAN_TURN,
    GAME_FINISHED
} GAME_STATE;

GAME_STATE GameState = GAME_HUMAN_TURN;

extern uint8_t PositionPressed;
extern uint8_t HumanMove;
extern uint8_t STM32Move;
/* Creation of a virtual board to keep track and the 2 players, human and STM32*/
signed int HumanPlayer = -1;
#define HUMAN_0 'o' //humans plays with circles
signed int STM32Player = 1;
#define STM32_X 'x' //stm32 plays with x


uint8_t board[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};
uint8_t moves[9][2] = {
    {0, 0},
	{0, 1},
	{0, 2},
    {1, 0},
	{1, 1},
	{1, 2},
	{2, 0},
	{2, 1},
	{2, 2}
};
#define MINMAX_INFINIT (signed int) 127
/*Function to test if any of the possible win conditions was achieve and by whom
 * parameters: current state and the player
 * return 1 or 0
 * */
int wins(uint8_t state[3][3], signed int player)
{
	/*
	 * Three rows    [X X X] or [O O O]
	 * Three cols    [X X X] or [O O O]
	 * Two diagonals [X X X] or [O O O]
	 */
	// Checking for Rows for X or O victory.
	for (int row = 0; row<3; row++)
	{
		if (state[row][0]==state[row][1] && state[row][1]==state[row][2])
		{
			if (state[row][0]==STM32_X && player == STM32Player)
				return 1;
			else if (state[row][0]==HUMAN_0 && player == HumanPlayer)
				return 1;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<3; col++)
	{
		if (state[0][col]==state[1][col] && state[1][col]==state[2][col])
		{
			if (state[0][col]==STM32_X && player == STM32Player)
				return 1;
			else if (state[0][col]==HUMAN_0 && player == HumanPlayer)
				return 1;
		}
	}
	// Checking for Diagonals for X or O victory.
	if (state[0][0]==state[1][1] && state[1][1]==state[2][2])
	{
		if (state[0][0]==STM32_X && player == STM32Player)
			return 1;
		else if (state[0][0]==HUMAN_0 && player == HumanPlayer)
			return 1;
	}
	if (state[0][2]==state[1][1] && state[1][1]==state[2][0])
	{
		if (state[0][2]==STM32_X && player == STM32Player)
			return 1;
		else if (state[0][2]==HUMAN_0 && player == HumanPlayer)
			return 1;
	}
	// Else if none of them have won then return 0
	return 0;
}

/*Function to evaluate the heuristic of the current state
 * return: +1 if the stm32 wins; -1 if the human wins; 0 draw*/
signed char evaluate_h(uint8_t state[3][3])
{
	signed int score;
    if (wins(state, STM32Player))
    {
        score = 1;
    }
    else if (wins(state, HumanPlayer))
	{
        score = -1;
	}
    else
    {
        score = 0;
    }
    return score;
}

/*This function test if the human or STM32Player wins
 * return 1 if someone won 0 if no winner was found
 * */
int game_over(uint8_t state[3][3])
{
    if(wins(state, HumanPlayer) || wins(state, STM32Player))
    {
    	return 1;
    }
    else
    	return 0;
}

/*Check if the movement is valid
 * return 1 if possible and 0 if not possible
 * */
int valid_move(uint8_t x, uint8_t y)
{
    if (board[x][y] == 0)
        return 1;
    else
        return 0;
}

/*Select either STM32_X or HUMAN_0 to be played in the board, depending on the player
 * return 1 if move was possible and 0 if not
 * */
int set_move(uint8_t x, uint8_t y, signed int player)
{
	if (valid_move(x, y))
	{
		if(player == HumanPlayer)
		{
			board[x][y] = HUMAN_0;
		}
		else if(player == STM32Player)
		{
			board[x][y] = STM32_X;
		}
		return 1;
	}
	else
		return 0;
}

/*
 * Game AI to find the best row, best col and best score for the current state of the board and thus select the best move
 * best_status[row, col, score]
 * */
void minimax(uint8_t state[3][3], uint8_t depth, signed int player,signed char best_status[3] )
{
	signed char score[3];
	signed int playertmp =  player;
	if (player == STM32Player)
	{
		best_status[0] = -1;
		best_status[1] = -1;
		best_status[2] = -MINMAX_INFINIT;
	}
	else
	{
		best_status[0] = -1;
		best_status[1] = -1;
		best_status[2] = +MINMAX_INFINIT;
	}

    if (depth == 0 || game_over(state))
    {
        score[2] = evaluate_h(state);
		best_status[2] = score[2];
		return;
    }
    for (int i = 0; i<3; i++)
    {
    	for (int j = 0; j<3; j++)
    	{
    		if (board[i][j]==0)
    		{
    			if(player == STM32Player)
    			{
    				state[i][j] = STM32_X;
    				playertmp = HumanPlayer;
    			}
    			else
    			{
    				state[i][j] = HUMAN_0;
    				playertmp = STM32Player;
    			}
    			minimax(state, depth - 1, playertmp, score);
    			state[i][j] = 0;//rollback state
    			score[0] = i;
				score[1] = j;

    			if (player == STM32Player)
    			{
    				if (score[2] >= best_status[2])
    				{
    					best_status[0] = score[0];
    					best_status[1] = score[1];
    					best_status[2] = score[2];  // max value
    				}
    			}
    			else
    			{
    				if (score[2] < best_status[2])
    				{
    					best_status[0] = score[0];
    					best_status[1] = score[1];
    					best_status[2] = score[2]; // min value
    				}
    			}
    		}
    	}
    }
    return;
}

char is_moves_left(void)
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]== 0)
                return 1;
    return 0;
}
/*It calls the minimax function if the depth < 9,
else it choices a random coordinate.
:return:*/
uint8_t ai_turn(void)
{
    int8_t move[3];
    uint8_t depth = 0;
    uint8_t x, y;

    for(uint8_t i = 0; i < 3; i++)
    {
        for(uint8_t j = 0; j < 3; j++)
        {
            if(board[i][j] == 0)
            {
                depth++;
            }
        }
    }

    if(depth == 0 || game_over(board))
    {
        return 0;
    }

    if(depth == 9)
    {
        x = uwTick % 3;
        y = uwTick % 3;
    }
    else
    {
        minimax(board, depth, STM32Player, move);
        x = move[0];
        y = move[1];
    }

    set_move(x, y, STM32Player);

    PositionPressed = (x * 3) + y;
    STM32Move = 1;

    return 1;
}

uint8_t human_turn(void)
{
    int8_t move;

    if(PositionPressed == 0)
    {
        return 0;
    }

    move = PositionPressed - 1;

    if(set_move(moves[move][0], moves[move][1], HumanPlayer))
    {
        HumanMove = 1;
        return 1;
    }

    PositionPressed = 0;
    return 0;
}

void game_task(void)
{
    switch(GameState)
    {
        case GAME_AI_TURN:

            ai_turn();

            if(game_over(board) || !is_moves_left())
            {
                GameState = GAME_FINISHED;
            }
            else
            {
                GameState = GAME_HUMAN_TURN;
            }
            break;

        case GAME_HUMAN_TURN:

            if(human_turn())
            {
                if(game_over(board) || !is_moves_left())
                {
                    GameState = GAME_FINISHED;
                }
                else
                {
                    GameState = GAME_AI_TURN;
                }
            }
            break;

        case GAME_FINISHED:
        default:
        		NVIC_SystemReset();
            break;
    }
}


