#include "types.h"
#include "stat.h"
#include "user.h"




int gcd(int a, int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}

int
main(int argc, char *argv[])
{
  int i;
  
  if(argc > 1){
  	printf(1,"gcd of number %d\n",gcd(37,71));
  	exit();
  }

  if(argc <= 1){
   printf(1, "Usage: %s words",argv[0]);
    exit();
  }

  for(i = 1; i < argc; i++){
    
    printf(1, "%s ", argv[i]);
     
  }
  printf(1,"\n");
   
  exit();
}
