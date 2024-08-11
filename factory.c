#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MATH_IMPL
#include "math.h"

#define DS_IMPL
#include "ds.h"

#define ST_IMPL
#include "stui.h"

#define FPS 60

#define m_at(m, i, j) (m).buf[(i) + (j) * (m).w]

typedef enum {
  GROUND_BLANK = 0,
  NUM_GROUND_TYPES,
} Ground;

typedef struct {
  enum {
    MACHINE_BLANK = 0,
    MACHINE_BELT,
  } type;
} Machine;

// Write to back, render front
typedef struct {
  Arena *mem;
  Machine *machines;
  int w, h;
} Map;

void alloc_map(Map *m) {
  // map->mem= arena_init(256 * 1024 * 1024);

  // Ground *gbuf = calloc(2 * m->w * m->h, sizeof(m->front[0]));
  // m->front = buf;
  // buf += m->w * m->h;
  // m->back = buf;

}

int main() {
  srand(time(0));

  st_init();
  atexit(st_cleanup);

  Arena scratch = arena_init(256 * 1024 * 1024);

  Map map = { .w = 100, .h = 100, };
  alloc_map(&map);

  while (true) {
    arena_free_all(&scratch);

    /* ===== Input ===== */

    /* ===== Simulation ===== */

    // {
    //   Dice *temp = map.front;
    //   map.front = map.back;
    //   map.back = temp;
    // }

    /* ===== Rendering ===== */
    st_clear();

    int win_w = st_width(),
        win_h = st_height();

    for (int y = 0; y < win_h; y++) {
      for (int x = 0; x < win_w; x++) {
        printf("% 3d", y);
      }
      printf("\n");
    }

    sleep_ms(1000000 / FPS);
  }

  return 0;
}
