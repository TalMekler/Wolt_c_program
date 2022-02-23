#include "DayWork.h"

int main() {
	DayWork* dw = NULL;
	Work** tmp = NULL;
	int add_work_flag = 1;
	dw = (DayWork*)calloc(1, sizeof(DayWork));
	if (!dw)
	{
		exit(1);
	}

	do {
		switch (add_work_flag)
		{
		case 1:
			tmp = (Work**)realloc(dw->works, sizeof(Work*)*(dw->num_of_works + 1));
			if (!tmp)
			{
				exit(1);
			}
			dw->works = tmp;
			dw->works[dw->num_of_works] = createWork();
			dw->num_of_works += 1;
			printf("Do you want to add more work?\n[0] No, [1] Yes: "); scanf("%d", &add_work_flag);
			break;
		case 0:
			printf("Stop adding works. \n");
			break;
		}

	} while (add_work_flag == 1);

	printf("Stop adding works. \n");
	DW_calcNumOfTasks(dw);
	DW_calcSalary(dw);
	DW_calcWorkingTime(dw);
	DW_calcPaymentPerHour(dw);
	DW_calcPaymentPerTask(dw);
	DW_calcTasksPerHour(dw);
	DW_printDW(dw);
	freeAllWorks(dw);
	free(dw);
	dw = NULL;
	return 0;
}