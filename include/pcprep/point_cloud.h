#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "pcprep/pcprep_export.h"
#include "pcprep/vec3f.h"
#include <stdint.h>
#include <stdlib.h>

  typedef struct pcp_point_cloud_t
  {
    float   *pos;
    uint8_t *rgb;
    size_t   size; // number of points, *pos have size*3 elements
  } pcp_point_cloud_t;
  // this need reference
  PCPREP_EXPORT
  int pcp_point_cloud_init(pcp_point_cloud_t *pc, size_t size);
  // this need reference
  PCPREP_EXPORT
  int pcp_point_cloud_free(pcp_point_cloud_t *pc);
  // this need reference
  PCPREP_EXPORT
  int pcp_point_cloud_load(pcp_point_cloud_t *pc,
                           const char        *filename);
  // this doesn't need reference
  PCPREP_EXPORT
  int pcp_point_cloud_write(pcp_point_cloud_t pc,
                            const char       *filename,
                            int               binary);
  // this doesn't need reference
  PCPREP_EXPORT
  int pcp_point_cloud_get_min(pcp_point_cloud_t pc, pcp_vec3f_t *min);
  // this doesn't need reference
  PCPREP_EXPORT
  int pcp_point_cloud_get_max(pcp_point_cloud_t pc, pcp_vec3f_t *max);

  // TODO: put this in utils.h
  PCPREP_EXPORT
  int get_tile_id(pcp_vec3f_t n,
                  pcp_vec3f_t min,
                  pcp_vec3f_t max,
                  pcp_vec3f_t v);
  // this doesn't need reference
  // `tiles` should be passed as a reference of a pcp_point_cloud_t*
  PCPREP_EXPORT
  int pcp_point_cloud_tile(pcp_point_cloud_t   pc,
                           int                 n_x,
                           int                 n_y,
                           int                 n_z,
                           pcp_point_cloud_t **tiles);
  // `pcs` should be passed as an array of pcp_point_cloud_t
  // `output` should be passed as a reference to a pcp_point_cloud_t
  // TODO: put this in utils.h
  PCPREP_EXPORT
  int point_cloud_merge(pcp_point_cloud_t *pcs,
                        size_t             pc_count,
                        pcp_point_cloud_t *out);
  // `output` should be passed as a reference to a pcp_point_cloud_t
  PCPREP_EXPORT
  int pcp_point_cloud_sample(pcp_point_cloud_t  pc,
                             float              ratio,
                             unsigned char      strategy,
                             pcp_point_cloud_t *out);

  // `output` should be passed as a reference to a pcp_point_cloud_t
  PCPREP_EXPORT
  int pcp_point_cloud_remove_dupplicates(pcp_point_cloud_t  pc,
                                         pcp_point_cloud_t *out);
  // `output` should be passed as a reference to a pcp_point_cloud_t
  PCPREP_EXPORT
  int pcp_point_cloud_voxelize(pcp_point_cloud_t  pc,
                               float              voxel_size,
                               pcp_point_cloud_t *out);
  PCPREP_EXPORT
  int pcp_point_cloud_get_pixel_per_tile(pcp_point_cloud_t pc,
                                         int               nx,
                                         int               ny,
                                         int               nz,
                                         int               width,
                                         int               height,
                                         float            *mvp,
                                         int *pixel_count);
#ifdef __cplusplus
}
#endif
#endif
