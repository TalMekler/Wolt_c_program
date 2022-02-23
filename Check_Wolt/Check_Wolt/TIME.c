#include "TIME.h"

int TIME_timeToMinutes(Time t) {
	return (t.hours * 60) + t.minutes;
}
Time TIME_minutesToTime(int minutes) {
	Time t;
	t.hours = minutes / 60;
	t.minutes = minutes - (t.hours * 60);

	return t;
}
Time TIME_calcTime(Time start, Time end) {
	int calc_minutes = TIME_timeToMinutes(end) - TIME_timeToMinutes(start);
	return TIME_minutesToTime(calc_minutes);
}
Time createTime() {
	Time t;
	char c;
	t.hours = 0;
	t.minutes = 0;
	printf("(hh:mm): ");
	scanf("%d%c%d", &t.hours, &c, &t.minutes);

	return t;
}

void printTime(Time t) {
	int hours = t.hours, minutes = t.minutes;
	(hours < 10) ? printf("0%d:", hours) : printf("%d:", hours);
	(minutes < 10) ? printf("0%d", minutes) : printf("%d", minutes);
}