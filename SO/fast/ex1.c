#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int score = 0;
pthread_mutex_t lock;

void *player(void *arg) {
  int id = *(int *)arg;

  for (int i = 0; i < 10; i++) {
    pthread_mutex_lock(&lock);
    score++;
    printf("Jogador %d marcou! Score: %d\n", id, score);
    pthread_mutex_unlock(&lock);
    usleep(100000); // simula tempo de jogo
  }

  return NULL;
}

int main() {
  pthread_t players[3];
  int ids[3] = {1, 2, 3};

  pthread_mutex_init(&lock, NULL);

  for (int i = 0; i < 3; i++)
    pthread_create(&players[i], NULL, player, &ids[i]);

  for (int i = 0; i < 3; i++)
    pthread_join(players[i], NULL);

  pthread_mutex_destroy(&lock);

  printf("\n🏁 Pontuação final: %d\n", score);
}
