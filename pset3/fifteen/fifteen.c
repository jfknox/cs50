
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

//create a winning board that is correct to check the answer
int winner_board[MAX][MAX];

// board's dimension
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    //list out d*d - 1 tiles and create variable
    int tile = (d * d) - 1;
    //create winning board variable
    int winner = 1;
  // create a loop within a loop
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            //create array and insert tiles into array
            board[i][j] = tile;
            //create winning array
            winner_board[i][j] = winner;
            //since there is an empty space assign it to X
            if (tile == 0)
            {
                board[i][j] = 'X';
            }
            //for d *d replace the tile with X in order to use the _
            if (winner == (d * d))
            {
                winner_board[i][j] = 'X';
            }
            // count down the tiles for starting board
            tile--;
            //count up the tiles for the winning board
            winner++;
        }
    }
    // if d is even swap 1 and 2 location
    if(d % 2 == 0)
    {
        board[d-1][d-3] = 1;
        board[d-1][d-2] = 2;
    }     
}

/**
 * Prints the board in its current state. No need to print the winner board
 */
void draw(void)
{
    // nest loop inside loop for print function
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            //for the X (ascii 88) print the underscore 
            if (board [i][j] == 88)
                {
                printf("%3c", '_'); 
                }
            //else print the numbers as normal
            else
                {
                printf("%3i" , board[i][j]);
                }
        }
        printf ("\n");
    } 
}


/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    //create loop within loop to access each number
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            //create condition to switch if tiled exsists
            if (board [i][j] == tile)
            {
                //if blank is below
                if (board[i + 1][j] == 88)
                {
                    //replace blank with the tile
                    board[i+1][j] = board[i][j];
                    //place the _ where the tile used to be
                    board[i][j] = 88;
                    return 1;
                } 
                //else blank is above  
                else if (board[i - 1][j] == 88)
                    {
                    board[i - 1][j] = board[i][j];
                    board[i][j] = 88;
                    return 1;
                    } 
                // else blank to the right
                else if (board[i][j + 1] == 88)
                    {
                    board[i][j + 1] = board[i][j];
                    board[i][j] = 88;
                    return 1;
                    }
                //else blank on the left
                else if (board[i][j - 1] == 88)
                    {
                    board[i][j-1] = board [i][j];
                    board[i][j] = 88;
                    return 1;
                    }
                //if illegal move
                else
                {
                    return 0;
                }
            } 
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    //create variable to count numbers in their correct position
    int correct = 0;
    // isolate the tiles in the array
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            //create condition where victory is acheived
            if (board[i][j] - winner_board[i][j] == 0)
            {
                correct++;
            }
            //if the # of tiles in correct spot = # of tiles then win!
            if (correct == (d * d))
            {
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
