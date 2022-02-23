#include "DayWork.h"
#include <Windows.h>

void DW_calcNumOfTasks(DayWork* dw) {
	int i, s=0;
	for (i = 0; i < dw->num_of_works; i++) {
		s = s + dw->works[i]->num_of_tasks;
	}
	dw->num_of_tasks = s;
}

void DW_calcSalary(DayWork* dw) {
	int i;
	for (i = 0; i < dw->num_of_works; i++) {
		dw->salary += dw->works[i]->total_salary;
	}
}

void DW_calcWorkingTime(DayWork* dw) {
	int i, total_minutes_of_work = 0;
	for (i = 0; i < dw->num_of_works; i++) {
		total_minutes_of_work += TIME_timeToMinutes(dw->works[i]->calc_time);
	}
	dw->working_time = TIME_minutesToTime(total_minutes_of_work);
}

void DW_calcPaymentPerHour(DayWork* dw) {
	float hours = (float)TIME_timeToMinutes(dw->working_time) / 60;
	dw->payment_per_hour = dw->salary / hours;
}

void DW_calcPaymentPerTask(DayWork* dw) {
	dw->payment_per_task = (float)dw->salary / dw->num_of_tasks;
}

void DW_calcTasksPerHour(DayWork* dw) {
	float hours = (float)TIME_timeToMinutes(dw->working_time) / 60;
	dw->tasks_per_hour = dw->num_of_tasks / hours;
}

void DW_printDW(const DayWork* dw) {
	system("cls");
	printf("\n- - - Print DayWork - - - \n");
	printf("Category\t|\tResult\n");
	printf("--------------------------------\n");
	printf("Num of works\t\t: %d \n", dw->num_of_works);
	printf("Total working time\t: "); printTime(dw->working_time); printf("\n");
	printf("Salary\t\t\t: %.2f INS \n", dw->salary);
	printf("Num of tasks\t\t: %d \n", dw->num_of_tasks);
	printf("Payment per hour\t: %.2f INS \n", dw->payment_per_hour);
	printf("Payment per task\t: %.2f INS \n", dw->payment_per_task);
	printf("Tasks per hour\t\t: %.2f \n", dw->tasks_per_hour);
	printf("- - - End Print DayWork - - - \n\n");
}

void freeAllWorks(DayWork* dw) {
	int i;
	for (i = 0; i < dw->num_of_works; i++) {
		freeWork(dw->works[i]);
	}
	free(dw->works);
}