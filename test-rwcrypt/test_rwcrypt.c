#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */
#include <string.h>
#include <fcntl.h>


#define SYS_rcrypt 334
#define SYS_wcrypt 335

int main()
{  
         
    long int ret_status;
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    char msg[100]="Gabriela teste ";
    int count=strlen(msg);
    printf("%s=%i\n",msg,count);

    fd=open("teste.txt", O_WRONLY | O_TRUNC | O_CREAT, mode );
    ret_status = syscall(SYS_wcrypt,fd,msg,count);
    close(fd);

    strcpy(msg,"");

    fd=open("teste.txt",O_RDONLY);
    ret_status = syscall(SYS_rcrypt,fd,msg,count);
    printf("Saida=%s\n",msg);
    printf("%s=%i\n",msg,count);
    close(fd);

    return 0;
}
