#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("=== EXEC PROGRAM ===\n");
    printf("Program name : %s\n", argv[0]);
    printf("PID          : %d\n", getpid());
    printf("Parent PID   : %d\n", getppid());

    return 0;
}