#pragma once

void   reviCreateProgram     (void ** outProgramID, unsigned codeVertexBytesCount, const void * codeVertex, unsigned codeFragmentBytesCount, const void * codeFragment, const void * pipelineState);
void   reviCreateBuffer      (void ** outBufferID,  unsigned constantFloat4sCount);
void   reviCreateMesh        (void ** outMeshID,    unsigned vertexFloat4sCount, unsigned colorFloat4sCount, unsigned uvFloat2sCount);
void   reviCreateTexture     (void ** outTextureID, unsigned pixelUnsignedChar4sWidthxHeight, unsigned levelsCount);
void   reviCreateRender      (void ** outRenderID,  unsigned pixelUnsignedChar4sWidthxHeight);
void   reviCreateCommands    (void ** outCommandsID);
void   reviCreateSignal      (void ** outSignalID);

void   reviSetBuffer         (const void * bufferID,  const void * allConstantFloat4s,                                                        const void * optionalSignalID);
void   reviSetMesh           (const void * meshID,    const void * allVertexFloat4s, const void * allColorFloat4s, const void * allUvFloat2s, const void * optionalSignalID);
void   reviSetTexture        (const void * textureID, unsigned level, const void * allPixelUnsignedChar4s,                                    const void * optionalSignalID);
void   reviSetRender         (const void * renderID,  const void * allPixelUnsignedChar4s,                                                    const void * optionalSignalID);
void   reviGetRender         (const void * renderID,  void * outAllPixelUnsignedChar4s,                                                       const void * optionalSignalID);

void   reviCommandsBegin     (const void * commandsID, const void * renderID, const void * bufferID);
void   reviCommandsDraw      (const void * commandsID, const void * programID, const void * textureID, const void * meshID);
void   reviCommandsEnd       (const void * commandsID);
void   reviCommandsExecute   (const void * commandsID, const void * optionalSignalID);

int    reviGetSignalValue    (const void * signalID);
void   reviSetSignalValueTo0 (const void * signalID);

void * reviRenderPresent     (const void * renderID, unsigned renderStartPixelX, unsigned renderStartPixelY, unsigned windowWidth, unsigned windowHeight, const char * windowName);

void   reviDebugMode         (unsigned enable);

void   reviDestroyProgram    (const void * programID);
void   reviDestroyBuffer     (const void * bufferID);
void   reviDestroyMesh       (const void * meshID);
void   reviDestroyTexture    (const void * textureID);
void   reviDestroyRender     (const void * renderID);
void   reviDestroyCommands   (const void * commandsID);
void   reviDestroySignal     (const void * signalID);

void   reviDestroyEverything (void);
