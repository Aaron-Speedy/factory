#ifndef MATH_H
#define MATH_H

// https://cboard.cprogramming.com/c-programming/170381-cross-platform-wait-sleep.html
#ifdef _WIN32
#include <windows.h>
void sleep_ms(int ms) {
  Sleep(ms);
}
#elif __unix__
#define _POSIX_C_SOURCE 200809L
#include <time.h>
int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);
void sleep_ms(int ms) {
  struct timespec ts = { .tv_sec = ms/1000, .tv_nsec = ms%1000*1000, };
  nanosleep(&ts, NULL);
}
#else
#error "Unknown system"
#endif

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

float randf(float min, float max);
int randi(int min, int max);
int sign(int x);
void clampf(float *x, float min, float max);
void clampi(int *x, int min, int max);
int in_bounds(int x, int max);

float maxf(float x, float y);
float minf(float x, float y);

#ifdef MATH_IMPL
#undef MATH_IMPL

float randf(float min, float max) {
  float scale = rand() / (float) RAND_MAX;
  return min + scale * ( max - min );
}

int randi(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

int sign(int x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}

void clampf(float *x, float min, float max) {
  if (*x < min) *x = min;
  else if (*x > max) *x = max;
}

void clampi(int *x, int min, int max) {
  if (*x < min) *x = min;
  else if (*x > max) *x = max;
}

int in_bounds(int x, int max) {
  if (x < 0) return 0;
  if (x >= max) return 0;
  return 1;
}

float maxf(float x, float y) {
  return x > y ? x : y;
}

float minf(float x, float y) {
  return x <= y ? x : y;
}
#endif

#endif
