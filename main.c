#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
THE ALGORITHM------
https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
1.Find the largest index k such that a[k] < a[k+1].
  If no such index exists, the permutation is the last permutation.
2.Find the largest index l greater than k such that a[k] < a[l].
3.Swap the value of a[k] with that of a[l].
4.Reverse the sequence from a[k+1] up to and including the final element a[n].
 */

void print_arr(int const n, int const * const arr);
bool next_perm(int const n, int * arr);
void swap(int * const a, int * const b);

int main(
  int const argc,
  char const * const * const argv
) {

  if (argc < 2) {
    fprintf(stderr, "Too few arguments. Try with an integer (>0)\n");
  } else if (argc > 2) {
    fprintf(stderr, "Too many arguments. Try with ONE integer (>0)\n");
  }
  if (argc != 2) {
    fprintf(stderr, "Example Usage: %s 4\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int const n = atoi(argv[1]);
  if (n <= 0) {
    fprintf(stderr, "Try with an integer >0\n");
    exit(EXIT_FAILURE);
  }
  printf("%d\n", n);

  int arr[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = i;
  }
  do {
  print_arr(n, arr);
  } while (next_perm(n, arr));

  return EXIT_SUCCESS;
}


void print_arr(int const n, int const * const arr) {
  for (int i = 0; i < n; ++i) {
    printf("%d,", arr[i]);
  }
  printf("\n");
}


bool next_perm(int const n, int * a) {
  int k = n-2;
  while (a[k] >= a[k+1]) {
    k -= 1;
  }
  if (k < 0) {
    return false;
  }

  int l = n-1;
  while (a[k] >= a[l]) {
    l -= 1;
  }

  swap(a+k, a+l);
  for (int i=k+1,j=n-1; i<j; ++i,--j) {
    swap(a+i, a+j);
  }
  return true;
}

void swap(int * const x, int * const y) {
  int t = *x;
  *x = *y;
  *y = t;
}