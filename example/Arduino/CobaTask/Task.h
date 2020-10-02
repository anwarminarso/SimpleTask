// Task.h

#ifndef _TASK_h
#define _TASK_h

#include "Arduino.h"

typedef void(*taskFunction)(uint32_t now);
typedef void(*instanceTaskFunction)();
typedef void(*endTaskFunction)();
struct taskItem {
	taskFunction fPtr;
	uint32_t next;
	uint32_t recur;
	char itemName[8];
};

// func => function
// id => id function max 7 char
// initial run => delay run (ms)
// recursive run => run every (ms) after delay run
void addTask(taskFunction func, const char * id, uint32_t initialRun, uint32_t recur);
void setInstanceTask(void (*userFunc)(void));
void setEndTask(void (*userFunc)(void));
int _queueGetTop(taskItem &item);
int _addToQueue(taskItem item);


#endif

