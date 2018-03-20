#include <stdio.h>

int m, n, g, k; //number of spells, number of halls (and their names), number of galleries, number of monsters
int spell_damage[1000], spell_mana[1000], dungeon[1000][1000], monster[1000]; //dungeon = halls + galleries (an matrix graph)

int knapsack(int i, int capacity) { //(position of item in the vector, capacity of knapsack)
  int a, b, result;
  if (capacity <= 0) { // we have killed the monster!
    return 0;
    printf("killed\n" );
  } else {
    a = spell_mana[i] + knapsack(i + 1, capacity - spell_damage[i]);
    b = 
  }
}

int main ( ) {
  int i, j, vertex1, vertex2;
  int monster_life;
  scanf("%d %d %d %d", &m, &n, &g, &k);

  while (m != 0 && n != 0 && g != 0 && k != 0 ) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        dungeon[i][j] = 0;
      }
    }

    for (i = 0; i < m; i++) {
      scanf("%d %d", &spell_mana[i], &spell_damage[i]);
    }
    for (i = 0; i < g; i++) {
      scanf("%d %d", &vertex1, &vertex2);
      dungeon[vertex1-1][vertex2-1] = 1;
      dungeon[vertex2-1][vertex1-1] = 1;
    }
    /*
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf("%d ", dungeon[i][j]);
      }
      printf("\n");
    }
    */
    for (i = 0; i < k; i++) { //hall where the monster lives an his life
      scanf("%d %d", &j, &monster_life);
      printf("%d %d\n", j, monster_life);
      dungeon[j][j] = dungeon[j][j] + knapsack(0, monster_life); //already calculates the weight of that hall and saves where we have space [j][j]
    }

    for (i = 0; i < n; i++) {
      printf("%d: ", i);
      for (j = 0; j < n; j++) {
        printf("%d ", dungeon[i][j]);
      }
      printf("\n");
    }
    printf("\n");

    scanf("%d %d %d %d", &m, &n, &g, &k);
  }
  return 0;
}
