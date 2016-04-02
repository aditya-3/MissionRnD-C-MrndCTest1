/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int checkForDate(int **a)
{
	int day1, day2, mon1, mon2, year1, year2;
	day1 = a[0][0]; mon1 = a[0][1]; year1 = a[0][2];
	day2 = a[1][0]; mon2 = a[1][1]; year2 = a[1][2];

	if (year1 == year2 && mon1 == mon2 && day1 == day2)
		return 0;
	else if (year1 <= year2)
	{
		if (mon1 <= mon2)
		{
			if (day1 <= day2)
				return 1;
			else
				return 2;
		}
		else
			return 2;
	}
	else
		return 2;

}
int calculate(int **a, int k)
{
	int day1, day2, mon1, mon2, year1, year2,result=0;
	if (k == 1)
	{
		
		day1 = a[0][0]; mon1 = a[0][1]; year1 = a[0][2];
		day2 = a[1][0]; mon2 = a[1][1]; year2 = a[1][2];
	}
	else
	{
		day2 = a[0][0]; mon2 = a[0][1]; year2 = a[0][2];
		day1 = a[1][0]; mon1 = a[1][1]; year1 = a[1][2];
	}
	if (day2 > day1)
		result += day2 - day1;
	else if (day2!=day1)
	{
		result += day2 - day1 + 30;
		mon2 -= 1;
	}
	if (mon2 > mon1)
		result = result+(mon2 - mon1)*30;
	else if (mon2!=mon1)
	{
		result = result+(mon2 - mon1+12)*30;
		year2 -= 1;
	}
	result =result+ (year2 - year1)*365;
	return result;

}
int between_days(struct node *date1head, struct node *date2head){
	if (date1head==NULL || date2head==NULL)
		return -1;
	else
	{
		int *a[5],i;
		for (i = 0; i < 2; i++)
			a[i] = (int *)calloc(3 , sizeof(int));
		for (i = 0; i < 2; i++)
		{
			a[0][0] *= 10;
			a[1][0] *= 10;
			a[0][0]+= date1head->data;
			a[1][0]+= date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
		}
		for (i = 0; i < 2; i++)
		{
			a[0][1] *= 10;
			a[1][1] *= 10;
			a[0][1] += date1head->data;
			a[1][1] += date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
		}
		for (i = 0; i < 4; i++)
		{
			a[0][2] *= 10;
			a[1][2] *= 10;
			a[0][2] += date1head->data;
			a[1][2] += date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
		}
		int k = checkForDate(a);
		if (k == 0)
			return -1;
		else 
			return calculate(a,k);
	}
}