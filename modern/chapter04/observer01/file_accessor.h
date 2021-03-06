#ifndef _FILE_ACCESSOR_H_
#define _FILE_ACCESSOR_H_

#include <stdbool.h>
#include <stdio.h>

#include "buffer.h"

#ifdef __cplusplus
extern "C"{
#endif 

struct FileAcessorContext {};

typedef struct FileErrorObserver{
  void (*const onError)(struct FileErrorObserver *pThis, struct FileAccessorContext *pFileCtx);
} FileErrorObserver;

extern FileErrorObserver default_file_error_observer;

typedef struct FileAccessorContext{
  FILE *fp;
  const char *pFname;
  const char *pMode;
  bool (*const processor)(struct FileAccessorContext *pThis);
  FileErrorObserver *pFileErrorObserver;
} FileAccessorContext;

bool access_file(FileAccessorContext *pThis);
FILE *get_file_pointer(FileAccessorContext *pThis);
long file_size(FileAccessorContext *pThis);
long file_current_pos(FileAccessorContext *pThis);
int set_file_pos(FileAccessorContext *pThis, long offset, int whence);
bool read_file(FileAccessorContext *pThis, BufferContext *pBufCtx);
bool write_file(FileAccessorContext *pThis, BufferContext *pBufCtx);

#ifdef __cplusplus
}
#endif

#endif