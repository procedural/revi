#pragma once

void   reviCreateProgram     (void ** outProgramID, unsigned codeVertexBytesCount, const void * codeVertex, unsigned codeFragmentBytesCount, const void * codeFragment, const void * pipelineState);
void   reviCreateBuffer      (void ** outBufferID,  unsigned constantFloat4sCount);
void   reviCreateMesh        (void ** outMeshID,    unsigned vertexFloat4sCount, unsigned uvFloat2sCount);
void   reviCreateTexture     (void ** outTextureID, unsigned pixelUnsignedChar4sWidthxHeight);
void   reviCreateRender      (void ** outRenderID,  unsigned pixelUnsignedChar4sWidthxHeight);
void   reviCreateSignal      (void ** outSignalID);

void   reviSetBuffer         (const void * bufferID,  const void * allConstantFloat4s,                          const void * optionalSignalID);
void   reviSetMesh           (const void * meshID,    const void * allVertexFloat4s, const void * allUvFloat2s, const void * optionalSignalID);
void   reviSetTexture        (const void * textureID, const void * allPixelUnsignedChar4s,                      const void * optionalSignalID);
void   reviSetRender         (const void * renderID,  const void * allPixelUnsignedChar4s,                      const void * optionalSignalID);
void   reviGetRender         (const void * renderID,  void * outAllPixelUnsignedChar4s,                         const void * optionalSignalID);

int    reviGetSignalValue    (const void * signalID);
void   reviSetSignalValueTo0 (const void * signalID);

void   reviRenderBegin       (const void * renderID);
void   reviRenderDraw        (const void * renderID, const void * programID, const void * bufferID, const void * meshID, const void * textureID);
void   reviRenderEnd         (const void * renderID, const void * optionalSignalID);

void * reviRenderPresent     (const void * renderID, unsigned renderStartPixelX, unsigned renderStartPixelY, unsigned windowWidth, unsigned windowHeight);

void   reviDestroyProgram    (const void * programID);
void   reviDestroyBuffer     (const void * bufferID);
void   reviDestroyMesh       (const void * meshID);
void   reviDestroyTexture    (const void * textureID);
void   reviDestroyRender     (const void * renderID);
void   reviDestroySignal     (const void * signalID);

void   reviDestroyEverything (void);
