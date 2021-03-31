#include <stdio.h>
#include <stdio.lib>
#include 

int main{
       int status1, status2, status3, status4, status5;
       pid_t child1, child2, child3, child4, child5;
       child1=fork();
       if (child1==0){
	       child3=fork();
	       if (child3==0){
		       pid_t pid3, ppid3;
		       pid3 = getpid();
		       ppid3=getppid();		       
		       for (int i==0; i<10; i++){
			       printf ("My id: %d", pid3);
			       printf ("p %d/n", ppid3);
		       }
		      exit(0);
	       }
	       else if (child3>0){
		      child4=fork();
	              if (child4==0){
		       pid_t pid4, ppid4;
		       pid3 = getpid();
		       ppid3=getppid();		       
		       for (int i==0; i<10; i++){
			       printf ("My id: %d", pid4);
			       printf ("p %d/n", ppid4);
		       }
		      exit(0);
	       }
		      

	       if (child3==0){
		      
		       pid_t pid3, ppid3
		       pid3 = getpid();
		      
		        


		      


		       
