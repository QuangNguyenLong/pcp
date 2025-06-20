#include <pcprep/aabb.h>
#include <pcprep/vec3u.h>

int pcp_aabb_to_mesh(pcp_aabb_t aabb, pcp_mesh_t *mesh)
{
  // Check if the AABB is valid
  if (aabb.min.x > aabb.max.x || aabb.min.y > aabb.max.y ||
      aabb.min.z > aabb.max.z)
  {
    return -1;
  }
  pcp_mesh_alloc(mesh, 8, 12 * 3);

  pcp_vec3f_t *vertices = (pcp_vec3f_t *)mesh->pos;

  vertices[0]           = aabb.min;
  vertices[1] = pcp_vec3f_set(aabb.min.x, aabb.min.y, aabb.max.z);
  vertices[2] = pcp_vec3f_set(aabb.min.x, aabb.max.y, aabb.min.z);
  vertices[3] = pcp_vec3f_set(aabb.min.x, aabb.max.y, aabb.max.z);
  vertices[4] = pcp_vec3f_set(aabb.max.x, aabb.min.y, aabb.min.z);
  vertices[5] = pcp_vec3f_set(aabb.max.x, aabb.min.y, aabb.max.z);
  vertices[6] = pcp_vec3f_set(aabb.max.x, aabb.max.y, aabb.min.z);
  vertices[7] = aabb.max;

  pcp_vec3u_t *faces = (pcp_vec3u_t *)mesh->indices;
  faces[0]           = pcp_vec3u_set(0, 1, 3);
  faces[1]           = pcp_vec3u_set(0, 3, 2);
  faces[2]           = pcp_vec3u_set(4, 7, 5);
  faces[3]           = pcp_vec3u_set(4, 6, 7);
  faces[4]           = pcp_vec3u_set(0, 6, 4);
  faces[5]           = pcp_vec3u_set(0, 2, 6);
  faces[6]           = pcp_vec3u_set(1, 5, 7);
  faces[7]           = pcp_vec3u_set(1, 7, 3);
  faces[8]           = pcp_vec3u_set(0, 5, 1);
  faces[9]           = pcp_vec3u_set(0, 4, 5);
  faces[10]          = pcp_vec3u_set(2, 3, 7);
  faces[11]          = pcp_vec3u_set(2, 7, 6);
  return 0;
}
