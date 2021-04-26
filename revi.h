#pragma once

int    reviCreateProgram     (void ** outProgramID, unsigned codeVertexBytesCount, const void * codeVertex, unsigned codeFragmentBytesCount, const void * codeFragment, const void * pipelineState);
int    reviCreateBuffer      (void ** outBufferID,  unsigned constantFloat4sCount);
int    reviCreateMesh        (void ** outMeshID,    unsigned vertexFloat4sCount, unsigned colorFloat4sCount, unsigned uvFloat2sCount);
int    reviCreateTexture     (void ** outTextureID, unsigned pixelUnsignedChar4sWidthxHeight, unsigned levelsCount);
int    reviCreateRender      (void ** outRenderID,  unsigned pixelUnsignedChar4sWidth, unsigned pixelUnsignedChar4sHeight);
int    reviCreateCommands    (void ** outCommandsID);
int    reviCreateSignal      (void ** outSignalID);

void   reviSetBuffer         (const void * bufferID,  const void * allConstantFloat4s,                                                        const void * optionalSignalID);
void   reviSetMesh           (const void * meshID,    const void * allVertexFloat4s, const void * allColorFloat4s, const void * allUvFloat2s, const void * optionalSignalID);
void   reviSetTexture        (const void * textureID, unsigned level, const void * allPixelUnsignedChar4s,                                    const void * optionalSignalID);
void   reviSetRender         (const void * renderID,  const void * allPixelUnsignedChar4s,                                                    const void * optionalSignalID);
void   reviGetRender         (const void * renderID,  void * outAllPixelUnsignedChar4s,                                                       const void * optionalSignalID);

void   reviCommandsBegin     (const void * commandsID, const void * renderID, const void * sharedBufferID, const void * localBufferID);
void   reviCommandsDraw      (const void * commandsID, const void * programID, unsigned localBufferConstantFloat4sFirst, unsigned localBufferConstantFloat4sCount, const void * textureID, unsigned textureFilterNearest, const void * meshID);
void   reviCommandsEnd       (const void * commandsID);
int    reviCommandsExecute   (const void * commandsID, const void * optionalSignalID);

int    reviGetSignalValue    (const void * signalID);
void   reviSetSignalValueTo0 (const void * signalID);

void * reviWindowPresent     (const char * windowName, unsigned windowWidth, unsigned windowHeight, const void * renderID, int * outStatus);

void   reviDebugMode         (unsigned enable);

void   reviDestroyProgram    (const void * programID);
void   reviDestroyBuffer     (const void * bufferID);
void   reviDestroyMesh       (const void * meshID);
void   reviDestroyTexture    (const void * textureID);
void   reviDestroyRender     (const void * renderID);
void   reviDestroyCommands   (const void * commandsID);
void   reviDestroySignal     (const void * signalID);

void   reviDestroyEverything (void);
