#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <mutex>
using namespace std;
mutex mtx;
int sum = 0;
void *runner(void *param);


int main(int argc, char *argv[]) {

  //pthread_t tid;
  pthread_t ths[100];
  pthread_attr_t attr;

  /*if (argc != 2) {
    fprintf(stderr, "usage: a.out <integer value>\n");
    return -1;
  }

  if(atoi(argv[1]) < 0) {
    fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
    return -1;
  }*/

  pthread_attr_init(&attr);

  for(int t = 0; t != 100; t++) {
    pthread_create(&ths[t], &attr, runner, argv[1]);
  }

  for(int t = 0; t != 100; t++) {
    pthread_join(ths[t], NULL);
  }

  if (sum != 100) {
      cout << sum << endl;
      return 0;
  }

  //printf("sum= %d\n", sum);

}

void *runner(void *param) {
  mtx.lock();
  int upper = 100;

  //for (int i = 1; i <= upper; i++) {
  sum++;
  //}
  mtx.unlock();
  pthread_exit(0);

}
