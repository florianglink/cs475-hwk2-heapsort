#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5
#define MAX_INPUT_LEN 128

int main()
{
	char input[MAX_INPUT_LEN];
	struct Employee employees[MAX_EMPLOYEES];
	int count = 0;

	while(input[0] != 'n') {
		struct Employee temp;
		printf("Name: ");
		fgets(temp.name, MAX_INPUT_LEN, stdin);
		printf("\nSalary: ");
		scanf("%d", temp.salary);
		employees[count] = temp;
		count++;
		printf("Enter another user? (y/n)? \n");
		fgets(input, MAX_INPUT_LEN, stdin);
	}
	return 0;
}
