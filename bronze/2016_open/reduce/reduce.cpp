/*
ID: qoob
LANG: C++
TASK: reduce
*/

#include <stdlib.h>
#include <stdio.h>

#define COORD_MAX 40000

typedef struct {
	int x;
	int y;
} coord_t;

int calculate_min_area(coord_t* coords, int size, int ignore_idx) {
	coord_t bl = {COORD_MAX, COORD_MAX};
	coord_t tr = {0, 0};

	for (int i = 0; i < size; i++) {
		printf("Iteration: %d\n", i);
		if (!(i == ignore_idx)) {
			if (bl.x > coords[i].x)
				bl.x = coords[i].x;

			if (bl.y > coords[i].y)
				bl.y = coords[i].y;

			if (tr.x < coords[i].x)
				tr.x = coords[i].x;

			if (tr.y < coords[i].y)
				tr.y = coords[i].y;

		}
	}

	return (tr.x - bl.x) * (tr.y - bl.y);
}

int main() {
	FILE* in = fopen("reduce.in", "r");
	FILE* out = fopen("reduce.out", "w");

	int n;
	fscanf(in, "%d\n", &n);

	coord_t coords[n];

	for (int i = 0; i < n; i++) {
		fscanf(in, "%d %d\n", &coords[i].x, &coords[i].y);
	}

	int areas[n];
	int prev = COORD_MAX;

	for (int i = 0; i < n; i++) {
		areas[i] = calculate_min_area(coords, n, i);
		if (prev > areas[i]) {
			prev = areas[i];
		}
	}
	
	fprintf(out, "%d", prev);
}