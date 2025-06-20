#ifndef CANVAS_H
#define CANVAS_H

#include "pcprep/pcprep_export.h"
#include "pcprep/utils.h"
#include "pcprep/vec3uc.h"

typedef struct pcp_canvas_t pcp_canvas_t;

/**
 * @brief holds the data of a virtual screen to be drawn.
 *
 *
 */
struct pcp_canvas_t
{
  size_t         width;
  size_t         height;
  pcp_vec3uc_t   bg_col;
  unsigned char *pixels;
  float        **min_z_value;

#ifdef HAVE_GPU
  char        *vert_shader;
  char        *frag_shader;
  unsigned int program_id;
  unsigned int frame_buffer;
  unsigned int rendered_texture;
  unsigned int depth_buffer;
  unsigned int vertex_array_id;
  unsigned int matrix_id;
#endif

  void (*draw_points)(
      pcp_canvas_t *, float *, float *, unsigned char *, size_t);
  void (*clear)(pcp_canvas_t *);
};

PCPREP_EXPORT
int pcp_canvas_init(pcp_canvas_t *cv,
                    size_t        width,
                    size_t        height,
#ifdef HAVE_GPU
                    char *vert_shader,
                    char *frag_shader,
#endif
                    pcp_vec3uc_t bg_col);

PCPREP_EXPORT
int canvas_free(pcp_canvas_t *cv);

#ifdef HAVE_GPU
void pcp_canvas_draw_points_gpu(pcp_canvas_t  *cv,
                                float         *mvp,
                                float         *pos,
                                unsigned char *rgb,
                                size_t         count);
#endif
void pcp_canvas_draw_points_cpu(pcp_canvas_t  *cv,
                                float         *mvp,
                                float         *pos,
                                unsigned char *rgb,
                                size_t         count);

void pcp_canvas_clear(pcp_canvas_t *cv);

#endif
