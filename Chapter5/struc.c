#include<stdio.h>


struct student{
	int rollno;
	int marks;
};

int main(){
	struct student st1;
	st1.rollno = 1;
	st1.marks = 90;
	printf("%d..%d", st1.rollno, st1.marks);
	return 0;
}
