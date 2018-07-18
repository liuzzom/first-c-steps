#include <stdio.h>
#include <stdlib.h>

struct date {
	int day;
	int month;
	int year;
};

struct time{
	int hour;
	int minutes;
	int seconds;
};

struct date_and_time{
	struct date sdate;
	struct time stime;
};

//Function//

void
print_date(struct date d){
	
	printf("Today is: %02i/%02i/%04i\n", d.day, d.month, d.year);

}

void 
print_time(struct time t){

	printf("Now is: %02i:%02i:%02i\n", t.hour, t.minutes, t.seconds);
	
}

void
print_date_and_time(struct date_and_time dt){
	print_date(dt.sdate);
	print_time(dt.stime);
}

//Main//

int
main(){
	struct date_and_time now;

	now.sdate.day=18;
	now.sdate.month=3;
	now.sdate.year=2016;
	
	now.stime.hour=12;
	now.stime.minutes=52;
	now.stime.seconds=12;
	
	print_date_and_time(now);
	
	return 0;
}
