/*
 * AppFramework.c
 *
 *  Created on: Jun 11, 2015
 *      Author: tansinan
 */

#include "AppFramework.h"


#include "AppFramework.h"

App* currentApp = NULL;

void App_create(App* app, void (*paintHandler)(), void (*eventHandler)(int event, int data))
{
	app->paintHandler = paintHandler;
	app->eventHandler = eventHandler;
}

void App_switchTo(App* app)
{
	currentApp = app;
}

App* App_getCurrentApp()
{
	return currentApp;
}

void App_sendMessage(int event, int data)
{
	currentApp->eventHandler(event, data);
}

void App_repaint()
{
	currentApp->paintHandler();
}
