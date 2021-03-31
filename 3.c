#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h> 
#include <string.h>


int main(int argc, char *argv[]) {
	int status;

	pid_t  childpid[atoi(argv[1])]; 
	int one[atoi(argv[1])][2]; 
	for (int i=0; i<atoi(argv[1]); i++)  pipe(one[i]); 
	int counter=0;
	int souri;
	for (int i=0; i<atoi(argv[1]); i++){
		if (fork()==0){
			childpid[i]=getpid();  
			int curr=0;

			do{            
			
				for (int j=0; j<atoi(argv[1]); j++){
					if (getpid()==childpid[j]){
						//sleep(j);
						//close(one[j][1]);                                                      //counter*atoi(argv[1])][1]);
                                		read(one[j][0], &souri , sizeof(souri)) ;                          //counter*atoi(argv[1])][0], &souri , sizeof(souri)+1 ) ;
                                		//close(one[j][0]);   						//counter*atoi(argv[1])][0]);
						printf("read:%d   child:%d  " , souri, j);

						int next=souri*(j+1+counter*atoi(argv[1]));
						printf("next:%d  " , next); 	
											
						//close(one[j+1][0]);                                                      //+counter*atoi(argv[1])][0]);
                                		if (j!=atoi(argv[1])-1) {write(one[j+1][1], &next, sizeof(next)); }//close(one[j+1][1]);}            //+counter*atoi(argv[1])][1], &next , sizeof(next)+1);
						else { write(one[0][1], &next, sizeof(next));   //close(one[0][1]);}


						
						counter++;
						//sleep((atoi(argv[1])-j-1));
						curr=j;
					
					}
					
				}
			}
			}while((curr+counter*atoi(argv[1])-1)<atoi(argv[2]));
			if (curr==atoi(argv[2])%atoi(argv[1])) {printf("factorial is %d", souri); }
			exit(0);
		}
	}
		int uno=1;
		//close(one[0][0]);
		write(one[0][1], &uno , sizeof(&uno)+1);
		//close(one[0][1]);
		
		for (int i=0; i<atoi(argv[1]); i++) wait(&status);
	

	return 0;
}
