#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Time {
	int hours;
	int minutes;
}Time;

int TIME_timeToMinutes(Time t);
Time TIME_minutesToTime(int minutes);
Time TIME_calcTime(Time start, Time end);
Time createTime();
void printTime(Time t);