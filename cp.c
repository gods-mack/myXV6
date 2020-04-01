#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h" // contain file discriptor permssion

char buf[512];


int
main(int argc, char *argv[])
{
  int fd0,fd1,n;  // fd0-->source file pointer
	 	  // fd1-->destination file pointer
	 	  
  if(argc <= 2){
    printf(1, "Need 2 arguments!\n");
    exit();
  }
  
  if((fd0 = open(argv[1],O_RDONLY)) < 0){
  	printf(1,"cp: can't open %s\n",argv[1]);
  	exit();
  }
  if((fd1 = open(argv[2],O_CREATE|O_RDWR)) < 0){
  	printf(1,"cp: can't open %s\n",argv[2]);
  	exit();
  }
  
  // read from source file n byte per time
  while((n = read(fd0, buf, sizeof(buf)) ) > 0){
  
  	write(fd1, buf, n); // write to dest. file
  }
  
  close(fd0);
  close(fd1);
  
  exit();
}
