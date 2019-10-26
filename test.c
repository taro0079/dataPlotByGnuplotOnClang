#include <stdio.h>
#include <math.h>
#define NX 720

int main(int argc, char const* argv[])
{
	FILE *gp;
	int i;
	double dx, x[NX+1], y[NX+1];

	/* create data */
	dx = 4*M_PI / NX;
	for (i = 0; i <= NX ; i++) {
		x[i] = -2 * M_PI + i * dx;
		y[i] = sin(x[i]);
	}

	/* create graph */
	gp = popen("gnuplot -persist", "w");
	fprintf(gp, "set xrange [-6.5:6.5]\n");
	fprintf(gp, "set yrange [-1.5:1.5]\n");
	fprintf(gp, "plot '-' with lines linetype 1 title \"sin\"\n");

	for (i  = 0;  i<= NX ; i++) {
		fprintf(gp, "%f\t%f\t\n", x[i], y[i]);
	}
	pclose(gp);

	return 0;
}
