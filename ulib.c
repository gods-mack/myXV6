#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"

char*
strcpy(char *s, const char *t)
{
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
    ;
  return os;
}

int
strcmp(const char *p, const char *q)
{
  while(*p && *p == *q)
    p++, q++;
  return (uchar)*p - (uchar)*q;
}

uint
strlen(const char *s)
{
  int n;

  for(n = 0; s[n]; n++)
    ;
  return n;
}

void*
memset(void *dst, int c, uint n)
{
  stosb(dst, c, n);
  return dst;
}

char*
strchr(const char *s, char c)
{
  for(; *s; s++)
    if(*s == c)
      return (char*)s;
  return 0;
}

char*
gets(char *buf, int max)
{
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    cc = read(0, &c, 1);
    if(cc < 1)
      break;
    buf[i++] = c;
    if(c == '\n' || c == '\r')
      break;
  }
  buf[i] = '\0';
  return buf;
}

int
stat(const char *n, struct stat *st)
{
  int fd;
  int r;

  fd = open(n, O_RDONLY);
  if(fd < 0)
    return -1;
  r = fstat(fd, st);
  close(fd);
  return r;
}

int
atoi(const char *s)
{
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
    n = n*10 + *s++ - '0';
  return n;
}

/********************** MODIFIED BY MANISH *************************/

int 
manish(const char *s){
	int res = 0; // Initialize result 
  
   	 // Iterate through all characters of input string and 
   	 // update result 
	int i;
   	for ( i = 0; s[i] != '\0'; ++i) 
        	res = res * 10 + s[i] - '0'; 
  
   	 // return result. 
   	return res; 
}

void strrev(char  *str) {

	int l, i; 
        char *begin_ptr, *end_ptr, ch; 
  
    	
	l = strlen(str); 
  
	// Set the begin_ptr and end_ptr 
    	// initially to start of string 
    	begin_ptr = str; 
    	end_ptr = str; 
  	
    	// Move the end_ptr to the last character 
   	for (i = 0; i < l - 1; i++) 
        	end_ptr++; 
  
    	// Swap the char from start and end 
    	// index using begin_ptr and end_ptr 
    	for (i = 0; i < l / 2; i++) { 
  
        	// swap character 
        	ch = *end_ptr; 
        	*end_ptr = *begin_ptr; 
        	*begin_ptr = ch; 
  
        	// update pointers positions 
        	begin_ptr++; 
        	end_ptr--; 
    	} 
    
}



char *itoa(int num,char buffer[], int base){
	//char buffer[256];
	
	int i = 0;
	int neg = 0; // negative flag
	
	if (num == 0){ 
        	buffer[i++] = '0'; 
        	buffer[i] = '\0'; 
        	char *s = &buffer[0];
        	return s;
    	} 
  

    	if (num < 0 && base == 10){
		neg = 1;
		num = -num; 
   	}
    
  
	
	if(base == 10){
		while(num > 0){
			int rem = num%10;
			buffer[i++] = (char)48+rem;
			num = num/10;
		}
	}
	if(base == 2){ // binary
		while(num > 0){
			int rem = num%2;
			buffer[i] = (char)48+rem;
			num = num/2;
			i++;
		}
	}
	if(base == 8){ // octal
		while(num > 0){
			buffer[i++] = (char)48 + num%8;
			num = num/8;
		}
	}
	if(base == 16){ // hexa
		while(num > 0){
			if(num%16 > 9){
				int rem = num % 16;
				buffer[i++] = (char)'a' + (rem - 10);
			}
			else{
				buffer[i++] = (char)48 + num%16;
			}
			num = num/16;
		}
	}
	

	if(neg == 1){ // put '-' sign on front
		buffer[i++] = '-';
	}
	buffer[i] = '\0';
	
	char *buf = &buffer[0];
	
	strrev(buf);
	return buf;
}




/************** END oF MODIFICATION FIELD  *****************/

void*
memmove(void *vdst, const void *vsrc, int n)
{
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  while(n-- > 0)
    *dst++ = *src++;
  return vdst;
}
