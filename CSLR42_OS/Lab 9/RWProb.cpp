#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void *reader(void *);
void *writer(void *);

int readcount=0, writecount=0, sh_var=5, bsize[5];
              