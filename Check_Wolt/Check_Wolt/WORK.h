#pragma once
#include "TIME.h"

typedef struct Work {
	Time start;
	Time end;
	Time calc_time; // calc in function (TIME.h)
	int num_of_tasks;
	float total_salary;
	float payment_per_hour; // calc in function
	float tasks_per_hour; // calc in function
	float payment_per_task; // calc in function
}Work;

void WORK_calcPaymentPerHour(Work* w);
void WORK_calcPaymentPerTask(Work* w);
void WORK_calcTasksPerHour(Work* w);
void WORK_printWork(Work* w);
Work* createWork();
void freeWork(Work* w);