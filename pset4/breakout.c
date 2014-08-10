//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// paddle height and width
#define p_height 10
#define p_width 50

// brick height and width
#define b_width 15
#define b_height 30

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 5

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(int argc, string argv[])
{
    
    // seed pseudorandom number generator
    srand48(time(NULL));
    
    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // initial velocity
    double x_velocity = drand48() * 4.0; 
    double y_velocity = 4.0;
    
    //create label to tell player to click to start
    GLabel click_screen = newGLabel("Click to Start");
    setFont(click_screen, "SansSerif-36");
    add(window, click_screen);
    double q = (getWidth(window) - getWidth(click_screen)) / 2;
    double w = (getHeight(window) - getHeight(click_screen)) / 2 + 25;
    setLocation(click_screen, q, w);
    
    //click to start
    waitForClick();
    //remove lable
    removeGWindow(window, click_screen);
    //pause to give the player time to get ready
    pause(300);
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        //call update scoreboard function to show scoreboard at 0
         updateScoreboard(window, label, points);                
        // check for mouse events
        if (argc > 1 && strcmp(argv[1], "GOD") == 0)
        {
            setLocation(paddle, getX(ball) - (getWidth(paddle) / 2), ((9 * HEIGHT)/10));
        }
        else
        {
        GEvent mouse_move = getNextEvent(MOUSE_EVENT);
        // if there is an event
        
        if (mouse_move != NULL)
        {
            // and if event is movement then react
            if (getEventType(mouse_move) == MOUSE_MOVED)
            {
                //make sure rect follows the bottom center of the cursor
                double x = getX(mouse_move) - getWidth(paddle) / 2;
                double y = ((9 * HEIGHT)/10);
                setLocation(paddle, x, y);
            }
        }
        }
         // move circle along in 2 demensions
        move(ball, x_velocity, y_velocity);
        // make it so that when ball hits left or right side velocity flips
        //this also accounts for corner case by including velocity so the 
        // ball does not stick to the sides
        if ((getX(ball) <= 0 && x_velocity < 0 ) || (getX(ball)>= (WIDTH - RADIUS) && x_velocity > 0)) 
        {
			x_velocity = -x_velocity;
		}
		//same logic with the top wall, no need for bottom wall 
		if (getY(ball) <= 0 && y_velocity < 0 )
		{
            y_velocity = -y_velocity;
		}
		//if ball hits bottom wall, loose life and pause
		if (getY(ball) >= HEIGHT) 
        {
            lives--;
            waitForClick();
            //if there are less than 1 life left then do not reset ball
            if (lives >= 1)
            {
                //reset the balls location before continuing
                setLocation(ball, RADIUS, .33 * HEIGHT);
                pause (500);
            }
            
        }  
          
          // linger before moving again
        pause(10); 
       //call the collision function
    GObject object = detectCollision(window, ball);
        //declare the object to be detected
        if (object == paddle)
        {
            //clear out sticking by including speed variable in the bounce
            if (y_velocity > 0)
            { 
                y_velocity = -y_velocity;   
            }
        }
        // if ball hits any other object other than label remove it,
        // decrease brick#, increase score, and update label to show final
        else if (object != NULL && object != label) 
        {
		   removeGWindow(window, object);
            y_velocity = -y_velocity;
            bricks--;
            points++;   
            updateScoreboard(window, label, points); 
		}   
    }
	//remove the paddle when the game is over	
    removeGWindow(window, paddle);
    
    //put a game over screen up to show the game has ended
    GLabel loose_screen = newGLabel("Game Over");
    setFont(loose_screen, "SansSerif-36");
    add(window, loose_screen);
    double x = (getWidth(window) - getWidth(loose_screen)) / 2;
    double y = (getHeight(window) - getHeight(loose_screen)) / 2 + 25;
    setLocation(loose_screen, x, y);
    
    // wait for click before exiting
    waitForClick();
    closeGWindow(window);
    return 0;
    
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    
    //to create the number of rows neded
    for  (int row = 0; row < ROWS; row++)
    {
        
        // to create the number of cols for each row 
        for (int col = 0; col < COLS; col++)
        {
            //create a pattern to evenly space block in the window
            double	x = ((col * WIDTH) / COLS + 5);
			double	y = (((row * (HEIGHT / 4)) / ROWS) + 60);
            //intantiate window
            GRect block = newGRect (x, y, b_height, b_width);
            add(window, block);
            setFilled(block, true);
         //create pattern of colors different than I have seen
         if (col % 5 == row )
         {
            setColor(block, "RED");
         }
         else if (col % 5 == row + 1 || col % 5 == row - 4 )
         {
            setColor(block, "GREEN");
         }
         else if (col % 5 == row + 2 || col % 5 == row - 3 )
         {
            setColor(block, "BLUE");
         }
         else if (col % 5 == row + 3 || col % 5 == row - 2 )
         {
            setColor(block, "ORANGE");
         }
         else if (col % 5 == row + 4 || col % 5 == row  - 1 )
         {
            setColor(block, "CYAN");
         }  
        }  
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // create ball
    GOval ball = newGOval( RADIUS, .33 * HEIGHT, RADIUS * 2, RADIUS * 2);
    setColor(ball, "DARK_GRAY");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // create rectangle
    GRect paddle = newGRect (((WIDTH/2) - (p_width/2)), ((9 * HEIGHT)/10), p_width, p_height);
    // color and fill paddle
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    // add rectangle to window
    add(window, paddle); 
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("");
    // center label in window
    setFont(label, "SansSerif-48");
    add(window, label);
   
    return label;
    
   
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
