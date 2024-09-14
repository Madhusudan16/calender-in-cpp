#include <iostream.h>
#include <conio.h>
#include <time.h>

#define SIZE 12
#define LEAP 4
#define W_DAY 7
#define STD_YEAR 1980

class Calender {
	public:
		int month,day,year; // this variable save current month / days and year
		int month_days[SIZE];
		char week_days[W_DAY];
		int set_year_start_day;
		Calender() {

			week_days[0] = 'M';
			week_days[1] = 'T';
			week_days[2] = 'W';
			week_days[3] = 'T';
			week_days[4] = 'F';
			week_days[5] = 'S';
			week_days[6] = 'S';
		}
		void set_day_of_year();
		void set_calender();
		void display_calender();
};
void Calender::set_calender() { // this function set current year calender
	time_t timeref;
	struct tm *tm_ref;
	time(&timeref);
	tm_ref = gmtime(&timeref);
	month  = tm_ref->tm_mon; // set current month
	year = tm_ref->tm_year;// set current year
	day  = tm_ref->tm_mday; // set current day
	year = 1900 + year;
	// section
		for(int i=1; i<=SIZE; i++) {
			if(i == 2) {
				  continue;
			}
			if(i%2 == 0 && i < 8){
				month_days[i] = 30;
			} else if(i%2 != 0 && i < 8) {
				month_days[i] = 31;
			} else if(i%2 == 0 && i>7) {
				month_days[i] = 31;
			} else if(i%2 != 0 && i>7) {
				month_days[i] = 30;
			}
		}
	//end section
	if(year % LEAP == 0) {
		month_days[2] =	29;
	} else {
		month_days[2] = 28;
	}
}
void Calender:: display_calender() { // this function display calender
	int month_count = 1;
	int days_count = 1;
	int wdays = 0;

	cout << "=========Calender -"<< year << "========\n" ;

	for(month_count = 1; month_count<=SIZE ; month_count++) {
	  cout << week_days[0];
		for(wdays=0;wdays<W_DAY; wdays++) {
			cout <<week_days[wdays];
		}
		cout << "\n";
		for(int j = 1; j<= set_year_start_day; j++) {
			 cout << " ";
		}

	  for(days_count =01; days_count <= month_days[month_count];days_count++) {
			if(days_count%W_DAY == 0) {
				  cout << "\n";
			}
			set_year_start_day = days_count % W_DAY;
			cout << " "<<   days_count;

		}
		cout << "\n";
	}

}
void Calender :: set_day_of_year() {
	int year_diff = 0;
	int num_of_leap = 0;
	int number_of_days = 0;
	year_diff = year - STD_YEAR;
	if(year_diff > 0) {

	}
	num_of_leap =(year_diff % LEAP) + 1;
	number_of_days = (365 * year_diff) + num_of_leap;
		 //	number_of_week = number_of_days / W_DAY;
	set_year_start_day = number_of_days % W_DAY;
	display_calender();
}
int main() {

	Calender mycal;
	clrscr();
	mycal.set_calender();
	mycal.set_day_of_year();
	return 0;
}
