/*
 * Snake.c
 *
 *  Created on: Jun 4, 2015
 *      Author: tansinan
 */

#include "Types.h"
#include "OLEDFB3D.h"
#include "SnakeLogic.h"
#include "Button.h"

const uint8 MAP_NORMAL = 0;
const uint8 MAP_ENERGY_BLOCK = 1;
const uint8 MAP_ACCELERATOR_PATH = 2;
const uint8 MAP_WALL_HARD = 3;
const uint8 MAP_WALL_SOFT = 4;

const uint8 SNAKE_DIRECTION_UP = 0;
const uint8 SNAKE_DIRECTION_DOWN = 1;
const uint8 SNAKE_DIRECTION_LEFT = 2;
const uint8 SNAKE_DIRECTION_RIGHT = 3;

struct Snake_Game
{
	uint8 map[20][20];
	//[0] => head ||  [1] => body closest to head;
	uint8 snakePositions[20][2];
	uint8 snakeHead;
	uint8 snakeLength;
	uint8 viewPortCenterX;
	uint8 viewPortCenterY;
} snakeGame;

//获取 (x2,y2) 相对于 (x1,y1)的相对位置关系
int relativePosition(int x1, int x2, int y1, int y2)
{
	if(x1 == x2)
	{
		if(y2 > y1) return SNAKE_DIRECTION_UP;
		if(y2 < y1) return SNAKE_DIRECTION_DOWN;
	}
	else if(y1 ==y2)
	{
		if(x2 > x1) return SNAKE_DIRECTION_RIGHT;
		if(x2 < x1) return SNAKE_DIRECTION_LEFT;
	}
	return -1;
}

void Snake_init()
{
	//初始化地图
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(i==0||i==19||j==0||j==19)
			{
				snakeGame.map[i][j] = MAP_WALL_HARD;
			}
			else
			{
				int rnd = rand();
				if(rnd%8==0) snakeGame.map[i][j] = MAP_WALL_HARD;
				else snakeGame.map[i][j] = MAP_NORMAL;
			}
		}
	}
	snakeGame.snakeHead = 0;
	for(int i=0;i<3;i++)
	{
		snakeGame.snakePositions[i][0] = 5;
		snakeGame.snakePositions[i][1] = 5 + i;
	}
	snakeGame.snakeLength = 3;
	snakeGame.viewPortCenterX = 3;
	snakeGame.viewPortCenterY = 3;
}

void Snake_drawTerrain(int centerX, int centerY)
{
	//绘制背景的地形图。需要注意的是x方向的中轴对应x=0
	//y 为常量，-0.5
	//z只能为负。
	//目前规划的绘制区域大小为7*7
	int paintRegionX1 = centerX - 3;
	int paintRegionY1 = centerY - 3;
	int paintRegionX2 = centerX + 3;
	int paintRegionY2 = centerY + 3;
	if(paintRegionX1 < 0) paintRegionX1 = 0;
	if(paintRegionX2 > 19) paintRegionX2 = 19;
	if(paintRegionY1 < 0) paintRegionY1 = 0;
	if(paintRegionY2 > 19) paintRegionY2 = 19;
	
	for(int i=paintRegionX1;i<=paintRegionX2+1;i++)
	{
		Vec3D point1;
		Vec3D point2;
		point1[1] = point2[1] = -0.5;
		point1[0] = point2[0] = (i - centerX)/2.0 - 0.25;
		point1[2] = (paintRegionY1 - centerY)/2.0 - 1.5;
		point2[2] = (paintRegionY2 + 1 - centerY)/2.0 - 1.5;
		OLEDFB3D_drawLine3D(point1, point2);
	}
	
	for(int i=paintRegionY1;i<=paintRegionY2+1;i++)
	{
		Vec3D point1;
		Vec3D point2;
		point1[1] = point2[1] = -0.5;
		point1[2] = point2[2] = (i - centerY)/2.0 - 1.5;
		point1[0] = (paintRegionX1 - centerX)/2.0 - 0.25;
		point2[0] = (paintRegionX2 + 1 - centerX)/2.0 - 0.25;
		OLEDFB3D_drawLine3D(point1, point2);
	}
	
	for(int i=paintRegionX1;i<=paintRegionX2;i++)
	{
		for(int j=paintRegionY1;j<=paintRegionY2;j++)
		{
			if(snakeGame.map[i][j]==MAP_WALL_HARD)
			{
				Quad3D quad;
				Vec3D temp;
				for(int i=0;i<4;i++) quad[i][1] = -0.25;
				quad[0][0] = (i - centerX)/2.0 - 0.25;
				quad[2][0] = (i - centerX)/2.0 + 0.25;
				quad[0][2] = (j - centerY)/2.0 - 1.5;
				quad[2][2] = (j + 1 - centerY)/2.0 - 1.5;
				quad[1][0] = quad[0][0];
				quad[1][2] = quad[2][2];
				quad[3][0] = quad[2][0];
				quad[3][2] = quad[0][2];
				OLEDFB3D_drawQuad3D(quad);
				for(int i=0;i<4;i++)
				{
					for(int j=0;j<3;j++)
					{
						temp[j] = quad[i][j];
					}
					temp[1] = -0.5; 
					OLEDFB3D_drawLine3D(quad[i],temp);
				}
			}
		}
	}
}

void Snake_drawSnake()
{
    Vec3D lastPoint[3];
    Vec3D currentPoint[3];
    
    for(int i=0;i<snakeGame.snakeLength;i++)
    {
    	int relativeX = snakeGame.snakePositions[i][0] - 3;
    	int relativeY = snakeGame.snakePositions[i][1] - 3;
		int relPos = relativePosition(snakeGame.snakePositions[i-1][0],
				snakeGame.snakePositions[i-1][1],
				snakeGame.snakePositions[i][0],
				snakeGame.snakePositions[i][1]);
    	if( i == 0 )
    	{
        	lastPoint[0][0] = relativeX;
        	lastPoint[0][1] = -0.5;
        	lastPoint[0][2] = -0.5*relativeY;
        	continue;
    	}
    	else if (i == 1)
    	{
    		
    	}
    	else if (i == snakeGame.snakeLength - 1)
    	{
    	}
    	else
    	{
    		
    	}
    }
    
    for(int j = 5;j >= 1;j--)
    {
    	if( j == 5)
    	{
    		lastPoint[0][0] = 0;
    		lastPoint[0][1] = -0.5;
    		lastPoint[0][2] = -0.5*j + 0;
    		continue;
    	}
    	else if( j == (5 - 1))
    	{
    		currentPoint[0][0] = -0.4;
    		currentPoint[0][1] = -0.5;
    		currentPoint[0][2] = -0.5*j;
    		currentPoint[1][0] = +0.4;
    		currentPoint[1][1] = -0.5;
    		currentPoint[1][2] = -0.5*j;
    		currentPoint[2][0] = 0;
    		currentPoint[2][1] = -0.25;
    		currentPoint[2][2] = -0.5*j;
    		for(int i=0;i<3;i++)
    		{
    			OLEDFB3D_drawLine3D(lastPoint[0],currentPoint[i]);
    		}
    		for(int i=0;i<3;i++)
    		{
    			for(int k=0;k<i;k++)
    			{
    				OLEDFB3D_drawLine3D(currentPoint[i],currentPoint[k]);
    			}
    		}
    	}
    	else if(j==1)
    	{
    		currentPoint[0][0] = 0;
    		currentPoint[0][1] = -0.5;
    		currentPoint[0][2] = -0.5*j - 0.1;
    		for(int i=0;i<3;i++)
    		{
    			OLEDFB3D_drawLine3D(currentPoint[0],lastPoint[i]);
    		}
    	}
    	else
    	{
    		currentPoint[0][0] = -0.2;
    		currentPoint[0][1] = -0.5;
    		currentPoint[0][2] = -0.5*j;
    		currentPoint[1][0] = +0.2;
    		currentPoint[1][1] = -0.5;
    		currentPoint[1][2] = -0.5*j;
    		currentPoint[2][0] = 0;
    		currentPoint[2][1] = -0.25;
    		currentPoint[2][2] = -0.5*j;
    		for(int i=0;i<3;i++)
    		{
    			OLEDFB3D_drawLine3D(lastPoint[i],currentPoint[i]);
    		}
    		for(int i=0;i<3;i++)
    		{
    			for(int k=0;k<i;k++)
    			{
    				OLEDFB3D_drawLine3D(currentPoint[i],currentPoint[k]);
    			}
    		}
    	}
		for(int i=0;i<3;i++)
			for(int k=0;k<3;k++)
				lastPoint[i][k] = currentPoint[i][k];
    }
}

void Snake_onDrawHandler()
{
	Snake_drawTerrain(snakeGame.viewPortCenterX,snakeGame.viewPortCenterY);
	Snake_drawSnake();
}

void Snake_onTimer()
{
	
}

void Snake_eventHandler(int event, int data)
{
	switch(event)
	{
	case EVENT_KEY_DOWN:
		if(data == KEY_DOWN && snakeGame.viewPortCenterY < 20-1)
		{
			snakeGame.viewPortCenterY++;
		}
		else if(data == KEY_UP && snakeGame.viewPortCenterY > 0)
		{
			snakeGame.viewPortCenterY--;
		}
		else if(data == KEY_RIGHT && snakeGame.viewPortCenterX < 20-1)
		{
			snakeGame.viewPortCenterX++;
		}
		else if(data == KEY_LEFT && snakeGame.viewPortCenterX > 0)
		{
			snakeGame.viewPortCenterX--;
		}
		break;
	}
}
