#include <pthread.h>
#include <stdio.h>
#include <time.h>

int rupees = 0;

void *add_rupees(void *arg) {
  for (int i = 0; i < 100000; i++) {
    rupees++;
  }
  return NULL;
}

int main() {
  pthread_t link, dark_link;

  pthread_create(&link, NULL, add_rupees, NULL);
  pthread_create(&dark_link, NULL, add_rupees, NULL);

  pthread_join(link, NULL);
  pthread_join(dark_link, NULL);

  printf("Expected Rupees: 2000000 \n");
  printf("Acutal Rupees: %d\n", rupees);
  printf("if it's less that 2M somehting is wrong\n");
  return 0;
}
