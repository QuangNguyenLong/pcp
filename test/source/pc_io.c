#include <pcprep/point_cloud.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
  pcp_point_cloud_t pc;
  pc.rgb   = NULL;
  pc.pos   = NULL;
  pc.size  = 0;

  int prep = pcp_point_cloud_load(&pc, argv[1]);
  printf("%lu\n", pc.size);
  printf("%f\n", pc.pos[123]);

  pcp_point_cloud_write(pc, "out_msh.ply", 1);
  pcp_point_cloud_free(&pc);
}
