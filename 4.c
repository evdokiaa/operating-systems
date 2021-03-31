#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>



int main (int argc, char *argv[]){
        
	int status;
	int fd[2];
	pipe(fd);
	int a=1;
	pid_t  childpid[3];
	
        for (int i=0; i<3; i++){
                if (fork()==0){
                        childpid[i]=getpid();
			if (getpid()==childpid[0]){
				
				//close(fd[1]);
				read (fd[0] , &a , sizeof(a));		
				//close(fd[0]);
				
				//printf("a is now  %d \n", a);
				//a++;
				
				for (int i=0; i<5; i++){
					printf ("child 0 %d excecutes a critical section \n", getpid());
				}
				
				//close(fd[0]);
				write(fd[1], &a , sizeof(a));
				//close(fd[1]);

				for (int j=0; j<2; j++){
					for (int i=0; i<7; i++){
                                		printf ("child 0 %d excecutes a non critical section \n", getpid());
					}
				}
                                
				//close(fd[1]);
                                read(fd[0], &a , sizeof(a));
                                //close(fd[0]);
				
				//printf("a is now  %d \n", a);
                                //a++;
				
				for (int i=0; i<5; i++){
                                	printf ("child 0 %d excecutes a critical section \n", getpid());
				}
                                
				//close(fd[0]);
                                write(fd[1], &a , sizeof(a));
                                //close(fd[1]);
                                
				for (int i=0; i<7; i++){
                                                printf ("child 0 %d excecutes a non critical section \n", getpid());
                                }
				
			        //close(fd[1]);
                                read(fd[0] , &a , sizeof(a));
                                //close(fd[0]);
				
				//printf("a is now  %d \n", a);
                                //a++;
                                
				for (int i=0; i<5; i++){
                                        printf ("child 0 %d excecutes a critical section \n", getpid());
                                }
				
				//close(fd[0]);
                                write(fd[1], &a , sizeof(a));
                                //close(fd[1]);

				exit(0);
			}
			else if (getpid()==childpid[1]){
				
				for (int j=0; j<3; j++){
					for (int i=0; i<7; i++){
                                	        printf ("child 1 %d excecutes a non critical section \n", getpid());
                                	}
				        
					
					//close(fd[1]);
                                	read(fd[0], &a , sizeof(a));
                                	//close(fd[0]);

					//printf("a is now  %d \n", a);
                                	//a++;

					for (int i=0; i<5; i++){
						printf ("child 1 %d excecutes a critical section \n", getpid());
					}
					
					//close(fd[0]);
                                	write(fd[1], &a , sizeof(a));
                                	//close(fd[1]);
					}
				exit(0);
			}
			else if (getpid()==childpid[2]){
				
				for (int j=0; j<3; j++){
					
					//close(fd[1]);
                                        read(fd[0], &a , sizeof(a));
                                        //close(fd[0]);
					
					//printf("a is now  %d \n", a);
                                	//a++;

					for (int i=0; i<5; i++){
						printf ("child 2 %d excecutes a critical section \n", getpid());
					}
					
					//close(fd[0]);
                                        write(fd[1], &a , sizeof(a));
                                        //close(fd[1]);
					
					for (int i=0; i<7; i++){

                                	        printf ("child 2 %d excecutes a non critical section \n", getpid());
					}
				}
				exit(0);
			}
		}
	}

	//close(fd[0]);
        write(fd[1],&a,sizeof(a));
        //close(fd[1]);

	for (int i=0; i<3; i++){
        	wait(&status);
	}
}
