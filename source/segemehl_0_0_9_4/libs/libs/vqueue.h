/**
 * vqueue.h
 * implementation of a simple queue for objects of defined size
 *
 * @author Christian Otto
 * @email christian@bioinf.uni-leipzig.de
 * @company Bioinformatics, University of Leipzig
 * @date Mon Oct 13 14:13:08 CEST 2008
 */

/*
 * SVN
 * Revision of last commit: $Rev: 69 $
 * Author: $Author: steve $
 * Date: $Date: 2008-10-16 15:10:07 +0200 (Thu, 16 Oct 2008) $
 * Id: $Id$
 * Url: $URL$
 */

#ifndef VQUEUE_H
#define VQUEUE_H

#include <stdlib.h>
#include "basic-types.h"

typedef struct {
  void *queuespace;
  Lint enqueueindex;
  Lint dequeueindex;
  Lint numofelem;
  Lint allocelem;
  size_t sizeofelem;
} VQueue;

void bl_vqueueInit(VQueue *q, Lint allocelem, size_t sizeofelem);
void bl_vqueueDestruct(VQueue *q, void (*rmv)(void*));
BOOL bl_vqueueIsEmpty(VQueue *q);
void bl_vqueueResize(VQueue *q);
void bl_vqueueEnqueue(VQueue *q, void *elem);
void* bl_vqueueDequeue(VQueue *q, void (*rmv)(void*));
void* bl_vqueueFront(VQueue *q);
void* bl_vqueueFrontN(VQueue *q, Lint N);
Lint bl_vqueueSize(VQueue *q);

#endif /* VQUEUE_H */
