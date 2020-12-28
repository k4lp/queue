#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int *a,*b,*c,*d,*e;



int main() {
	 int i = 0;

	 #define m (int *)malloc(sizeof(int));
	 a=m;b=m;c=m;d=m;e=m;
	 for(;i<INT_MAX;i++){
		 printf("\n%d - %d - %d - %d - %d",*a,*b,*c,*d,*e);
		 *a++,*b++,*c++,*d++,*e++;
	 }
}
