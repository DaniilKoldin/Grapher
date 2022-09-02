#include <math.h>
#include <stdio.h>
#include "calc.h"

#define WIDTH 80
#define HEIGHT 25
#define X WIDTH / 2
#define Y HEIGHT / 2
#define XMAX WIDTH - X - 1
#define XMIN -(WIDTH - X)
#define YMAX HEIGHT - Y
#define YMIN -(HEIGHT - Y) + 1


int plot(char gr[][WIDTH], int x, int y);

void init_grid(char gr[][WIDTH]);

void show_grid(char gr[][WIDTH]);

int main() {
    char *inp_str;
    size_t len;
    getline(&inp_str, &len, stdin);
    node *list = parser(inp_str);
    node *res = to_pol(list);
    char grid[HEIGHT][WIDTH];
    init_grid(grid);
    for (double x = -4 * 3.14159; x <= 4 * 3.14159; x += 0.08) {
        double y;
        y = calc(res, x);
        plot(grid, rintf(x * 10), rintf(y * 8));
    }
    show_grid(grid);
    destroy(list);
    destroy(res);
    return (0);
}

/* Set "pixel" at specific coordinates */
int plot(char gr[][WIDTH], int x, int y) {
    int flag = 0;
    if ((x > XMAX || x < XMIN) && (y > YMAX || y < YMIN))
        flag = ERROR;
    if (flag != ERROR)
        gr[Y - y][X + x] = '*';
    return flag != ERROR ? 1 : ERROR;
}

/* Initialize grid */
void init_grid(char gr[][WIDTH]) {
    int x, y;

    for (y = 0; y < HEIGHT; y++)
        for (x = 0; x < WIDTH; x++) gr[y][x] = '.';
    /* draw the axis */
}

/* display grid */
void show_grid(char gr[][WIDTH]) {
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) putchar(gr[y][x]);
        putchar('\n');
    }
}
