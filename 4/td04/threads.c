#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

void *thread (void *arg)
{
	int n = (*((int*) arg));
	if (n < 0)	pthread_exit((void*) 1);

	for (int i = 0; i < 5; i++)
	{
		printf("\tPID : %d,\tTID : %lu\n", getpid(), pthread_self());
		printf("\t\tLinux Thread ID: %ld\n", syscall(SYS_gettid));
		sleep(n);
	}
	pthread_exit((void*) 0);
}

int main (int argc, char *argv[])
{
	int n1, n2;
	int retour1, retour2;

	printf("PID du processus : %d\n", getpid());


	if (argc < 3) {
        fprintf(stderr, "Usage: %s <value>\n", argv[0]);
        return 1;
    }

    n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);


	pthread_t th1, th2;

	pthread_create(&th1, NULL, thread, (void*) &n1);
	pthread_create(&th2, NULL, thread, (void*) &n2);
	pthread_join(th1, (void*) &retour1);
	pthread_join(th2, (void*) &retour2);

	printf("Valeurs de retour : retour1 = %d, retour2 = %d\n", retour1, retour2);

}