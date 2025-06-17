#include <iostream>
#include <ctime>

using namespace std;

struct board
{
  int hidden_answer[4];
  int attempts;
};

void board_init(struct board *game, struct board *hidden_answer)
{
  //set hidden_answer to random value
  srand (time(0));
  int range = 6 - 1 + 1;
  int k = 0;
  //int hidden_answer[4];
  int i;
  int random;
  for (i=0; i<4; i++)
  {
    random = (rand() % range) + 1;
    hidden_answer[i] = random; k++;
  }

  *game = 0;
}

void board_make_attempt(struct board *game, int theGuess[4], int *right_color_wrong_position, int *right_color_right_position)
{
  game->attempts++
  for (int i=0; i<4; i++){
    for (int j=0; j<4; j++){
      if (theGuess[j] == board->hidden_answer[i]){
        *right_color_right_position++
      }
      else{
        *right_color_wrong_position++
      }
    }
  }
}

int main()
{
  bool done = false;
  struct board theBoard;
  int right_color_right_position = 0;
  int right_color_wrong_position = 0;
  int theGuess[4];
  board_init(&theBoard);

  while (!done)
  {
    get_user_guess(theGuess);

    board_make_attempt(&theGame, theGuess, &right_color_right_position, &right_color_wrong_position)

    if ((theBoard.attempts > 9) || (right_color_right_position == 4))
    {
      done = true;
    }
  }

  return 0;
}
