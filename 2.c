#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int pause(void);

void handler(int mysignal) {}

int main (int argc, char *argv[]){
 	int status;
	pid_t  c[5];
	signal(SIGCONT,handler);
	int cnt=0;
	c[0]=fork();
	if (c[0]==0){
		c[0]=getpid();
		pause();
		while(1){
			printf("Child1 %d is executed (%d)\n",c[0],cnt);
			cnt++;
			sleep(1);
			}
		exit(0);
	        }
	
	else if(c[0]>0){
	        c[1]=fork();
		if(c[1]==0) {
			c[1]=getpid();
			pause();
			while(1){
				printf("Child2 %d is executed (%d)\n",c[1],cnt);
				cnt++;
				sleep(1);
 		        }
			exit(0);
		}
		else if(c[1]>0){
 			c[2]=fork();
				if (c[2]==0){ 
	       	 			c[2]=getpid();
					pause();
		 			while(1){		
						printf("Child3 %d is executed (%d)\n",c[2],cnt);
						cnt++;
						sleep(1);
					}
					exit(0);
	 			}			
				else if(c[2]>0){
					c[3]=fork();
					    if (c[3]==0){    
						c[3]=getpid();
						pause();
						while(1){
							printf("Child4 %d is executed (%d)\n",c[3],cnt);
							cnt++;
							sleep(1);
					}
					exit(0);
					}
					else if (c[3]>0){
						c[4]=fork();
		       				if (c[4]==0){
							c[4]=getpid();
							pause();
							while(1){
								printf("Child5 %d is executed (%d)\n",c[4],cnt);
								cnt++;
								sleep(1);
 							}
							exit(0);
							}
					}
				}
		}
	}
	sleep(1);
	for(int j=0; j<4; j++){
        	for(int i=0; i<5; i++){
       			kill(c[atoi(argv[i+1])-1],SIGCONT);
			sleep(3);
			kill(c[atoi(argv[i+1])-1],SIGSTOP);
			if (j==3) kill(c[atoi(argv[i+1])-1],SIGTERM);
		}

	}
	wait(&status);
	exit(0);
			
			
	
	return 0;
}
