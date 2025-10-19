#include "graph_mat-1.h"

int main()
{
	graph_mat *g = gm_init(5);

	gm_add_edge(g, 0, 1);
	gm_add_edge(g, 0, 4);
	gm_add_edge(g, 1, 4);
	gm_add_edge(g, 4, 1);
	gm_add_edge(g, 2, 2);
	gm_add_edge(g, 2, 3);

	gm_rm_edge(g, 1, 4);
	gm_rm_edge(g, 1, 4);
	gm_rm_edge(g, 1, 4);
	gm_rm_edge(g, 2, 3);
	gm_rm_edge(g, 0, 2);

	gm_disp(g);
	gm_write_dot(g, "test-2.dot");
	gm_free(g);

	return 0;
}
