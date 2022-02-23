#include "WORK.h"
#include <Windows.h>

void WORK_calcPaymentPerHour(Work* w) {
	float hours = (float)TIME_timeToMinutes(w->calc_time) / 60;
	w->payment_per_hour = w->total_salary / hours;
}
void WORK_calcPaymentPerTask(Work* w) {
	w->payment_per_task = w->total_salary / (float)w->num_of_tasks;
}
void WORK_calcTasksPerHour(Work* w) {
	float hours = (float)TIME_timeToMinutes(w->calc_time) / 60;
	w->tasks_per_hour = w->num_of_tasks / hours;
}
void WORK_printWork(const Work* w) {
	printf("\n- - - Print Work - - - \n");
	printf("Category\t|\tResult\n");
	printf("--------------------------------\n");
	printf("Start at\t\t: "); printTime(w->start); printf("\n");
	printf("End at\t\t\t: "); printTime(w->end); printf("\n");
	printf("Total working time\t: "); printTime(w->calc_time); printf("\n");
	printf("Salary\t\t\t: %.2f INS \n", w->total_salary);
	printf("Num of tasks\t\t: %d \n", w->num_of_tasks);
	printf("Payment per hour\t: %.2f INS \n", w->payment_per_hour);
	printf("Payment per task\t: %.2f INS \n", w->payment_per_task);
	printf("Tasks per hour\t\t: %.2f \n", w->tasks_per_hour);
	printf("- - - End Print Work - - - \n\n");
}
Work* createWork() {
	Work* w = NULL;
	int flag;
	w = (Work*)calloc(1, sizeof(Work));
	if (!w)
	{
		exit(1);
	}
	system("cls");
	printf("Enter start "); w->start = createTime();
	printf("Enter end "); w->end = createTime();
	w->calc_time = TIME_calcTime(w->start, w->end);
	printf("Enter salary: ");
	scanf("%f", &w->total_salary);
	printf("Enter num of tasks: ");
	scanf("%d", &w->num_of_tasks);
	WORK_calcPaymentPerHour(w);
	WORK_calcPaymentPerTask(w);
	WORK_calcTasksPerHour(w);
	printf("[Create Task] - done! \n");

	printf("Do you want to print the work? \n[0] No, [1] Yes: ");
	scanf("%d", &flag);
	if (flag)
	{
		system("cls");
		WORK_printWork(w);
	}
	return w;
}

void freeWork(Work* w) {
	free(w);
}