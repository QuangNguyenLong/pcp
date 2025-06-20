#ifndef MESH_H
#define MESH_H

#ifdef __cplusplus
extern "C"
{

#endif

#include "pcprep/pcprep_export.h"
#include <stdint.h>
#include <stdlib.h>

  typedef struct pcp_mesh_t
  {
    float    *pos;
    uint32_t  num_verts;
    uint32_t *indices;
    uint32_t  num_indices;
  } pcp_mesh_t;

  PCPREP_EXPORT
  int pcp_mesh_alloc(pcp_mesh_t *mesh,
                     uint32_t    num_verts,
                     uint32_t    num_indices);
  PCPREP_EXPORT
  int pcp_mesh_free(pcp_mesh_t *mesh);
  PCPREP_EXPORT
  int pcp_mesh_load(pcp_mesh_t *mesh, const char *filename);
  PCPREP_EXPORT
  int pcp_mesh_write(pcp_mesh_t  mesh,
                     const char *filename,
                     int         binary);
  PCPREP_EXPORT
  int pcp_mesh_get_screen_ratio(pcp_mesh_t mesh,
                                float     *mvp,
                                float     *screen_ratio);

#ifdef __cplusplus
}
#endif
#endif
