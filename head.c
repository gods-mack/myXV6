#include "types.h"
#include "stat.h"
#include "user.h"
#include "str_conversion.h"

char buf[1];

void
head(int fd)
{
	int n  = 5; // limit of lines
  	int limit = 0;

  	int len = 0;
  	char tmp_buf[100];
  	while((n = read(fd, buf, sizeof(buf))) > 0) {
    		if(limit == 5){
      			exit();
    		}

    		if(buf[0] == '\n'){
    			//  printf(1,"\ntmp_buf: %s \n",tmp_buf );
      			tmp_buf[len++] = buf[0];
      			limit++;

      			if (write(1, tmp_buf, len) != len) {
           			printf(1, "head: write error\n");
           			exit();
      			}
      			len = 0;
      			int b =0;
      			for(b = 0;  b < 100; b++){
        			tmp_buf[b] = 0;
      			}

    		}		

    		else{
      			tmp_buf[len++] = buf[0];
    		}	

  	}
  	if( n < 0){
    		printf(1,"head: read error\n");
  	}

}

void
head_with_limit(int fd, int no_lines)
{
	int n  = 5; // its nothing
  	int limit = 0;

  	int len = 0; // no_lines tracker
  	char tmp_buf[100];
  	while((n = read(fd, buf, sizeof(buf))) > 0) {
    		if(limit == no_lines){
      			exit();
    		}

    		if(buf[0] == '\n'){
    			//  printf(1,"\ntmp_buf: %s \n",tmp_buf );
      			tmp_buf[len++] = buf[0];
      			limit++;

      			if (write(1, tmp_buf, len) != len) {
           			printf(1, "head: write error\n");
           			exit();
      			}
      			len = 0;
      			int b =0;
      			for(b = 0;  b < 100; b++){
        			tmp_buf[b] = 0;
      			}

    		}		

    		else{
      			tmp_buf[len++] = buf[0];
    		}	

  	}
  	if( n < 0){
    		printf(1,"head: read error\n");
  	}

}



int
main(int argc, char *argv[])
{
	char buffer[100];
	printf(1,"itoa %s\n",itoa(78,buffer,16));
	int fd, i;

  	if(argc <= 1){
      		head(0);
    		exit();
  	}
  	else if(argc == 3){

  		for(i = 2; i < argc; i++){
    			if((fd = open(argv[i], 0)) < 0){
      				printf(1, "cat: cannot open %s\n", argv[i]);
      				exit();
    			}
    			int no_lines = atoi(argv[1]);
       			head_with_limit(fd,no_lines);
    			close(fd);
  		}
  	}
  	else{

		for(i = 1; i < argc; i++){
			if((fd = open(argv[i], 0)) < 0){
	      			printf(1, "cat: cannot open %s\n", argv[i]);
	      			exit();
	    		}
	    		head(fd);
	    		close(fd);
	  	}
	  	exit();
	}
}
