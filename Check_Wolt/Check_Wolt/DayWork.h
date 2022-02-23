#pragma once
#include "WORK.h"

typedef struct DayWork {
	Work** works;
	int num_of_works;
	Time working_time;
	int num_of_tasks;
	float salary;
	float payment_per_hour;
	float tasks_per_hour;
	float payment_per_task;
} DayWork;

void DW_calcNumOfTasks(DayWork* dw);
void DW_calcSalary(DayWork* dw);
void DW_calcWorkingTime(DayWork* dw);
void DW_calcPaymentPerHour(DayWork* dw);
void DW_calcPaymentPerTask(DayWork* dw);
void DW_calcTasksPerHour(DayWork* dw);
void DW_printDW(const DayWork* dw);
void freeAllWorks(DayWork* dw);