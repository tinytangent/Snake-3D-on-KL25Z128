/*
 * SnakeLogic.h
 *
 *  Created on: Jun 4, 2015
 *      Author: tansinan
 */

#ifndef SNAKELOGIC_H_
#define SNAKELOGIC_H_

void Snake_init();
void Snake_onDrawHandler();
void Snake_drawTerrain();
void Snake_drawSnake();
void Snake_eventHandler(int event, int data);
void Snake_onTimer();


#endif /* SNAKELOGIC_H_ */
