#include <stdio.h>
#include <stdlib.h>

struct date {
	int day;
	int month;
	int year;
};

//Function//

void
print_date(struct date today){
	
	printf("Today is: %02i/%02i/%04i\n", today.day, today.month, today.year);

}

//Main//

int
main(){
	struct date today;

	today.day=18;
	today.month=3;
	today.year=2016;
	
	print_date(today);
	
	return 0;
}
