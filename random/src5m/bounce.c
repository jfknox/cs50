 //make bricks noticable by detectcollision
        else if (object == brick)
        {
            if (getY(ball) <= (getY(brick) + getHeight(brick) && y_velocity < 0 ) || (getY(ball) >= (getY(brick)) && y_velocity > 0)) 
		    {
		        removeGWindow(window, brick);
                y_velocity = -y_velocity;
		    }
            if ((getX(ball) <= (getX(brick) + getWidth(brick)) && x_velocity < 0 ) || (getX(ball)>= (getX(brick)) && x_velocity > 0))
            {
                removeGWindow(window, brick);
                x_velocity = -x_velocity;
            }       
        }   
            
