#include <pthread.h>
#include <stdio.h>
#include <iostream>

int sum, expected;
void *runner(void *param);


int main(int argc, char *argv[]) {

  pthread_t tid;
  pthread_attr_t attr;

  if (argc != 2) {
    fprintf(stderr, "usage: a.out <integer value>\n");
    return -1;
  }

  if(atoi(argv[1]) < 0) {
    fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
    return -1;
  }

  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, runner, argv[1]);
  pthread_join(tid, NULL);
//step 2 comment that ^^
  int upper2 = atoi(argv[1]);
  expected = (upper2 * (upper2 + 1))/2;
  // if (sum != expected) {
  //   printf("sum= %d\n", sum);
  // }
  printf("sum= %d\n", sum);
}

void *runner(void *param) {
  int i, upper = atoi((char*)param);

  sum = 0;
  pthread_t *workers;
  workers = new pthread_t[upper];
  for (int i = 0; i <= upper; i++) {
    //pthread_join(workers[i], NULL);
    sum += i;
  }

  pthread_exit(0);

}
//
// #define NUM_THREADS 10
//
// for (int i = 0; i < NUM_THREADS; i++) {
//   pthread_join(workers[i], NULL);
// }
