/*
 * AppReactionTime.h
 *
 *  Created on: Jun 14, 2015
 *      Author: tansinan
 */

#ifndef APPREACTIONTIME_H_
#define APPREACTIONTIME_H_

#include "AppFramework.h"

App AppReactionTime_theApp;

void AppReactionTime_init();

void AppReactionTime_onDrawHandler();

void AppReactionTime_eventHandler(int event, int data);

#endif /* APPREACTIONTIME_H_ */
