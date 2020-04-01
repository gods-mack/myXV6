#include "types.h"
#include "stat.h"
#include "user.h"

char buf[1];

void
cat(int fd)
{
  int n ;
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

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    cat(0);
    exit();
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "cat: cannot open %s\n", argv[i]);
      exit();
    }
    cat(fd);
    close(fd);
  }
  exit();
}
