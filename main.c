#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2, pid3, pid4;

    printf("P0: PID = %d, PPID = %d\n",
           getpid(), getppid());

    /* P0 creates P1 */
    pid1 = fork();

    if (pid1 < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid1 == 0)
    {

        printf("P1: PID = %d, PPID = %d\n",
               getpid(), getppid());

        /* P1 creates P3 */
        pid3 = fork();

        if (pid3 == 0)
        {
            printf("P3: PID = %d, PPID = %d\n",
                   getpid(), getppid());
            return 0;
        }

        /* P1 creates P4 */
        pid4 = fork();

        if (pid4 == 0)
        {
            printf("P4: PID = %d, PPID = %d\n",
                   getpid(), getppid());
            return 0;
        }

        wait(NULL);
        wait(NULL);

        return 0;
    }

    /* P0 creates P2 */
    pid2 = fork();

    if (pid2 == 0)
    {
        printf("P2: PID = %d, PPID = %d\n",
               getpid(), getppid());
        return 0;
    }

    wait(NULL);
    wait(NULL);

    return 0;
}