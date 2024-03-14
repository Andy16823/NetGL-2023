// NetGL.h

#pragma once
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <vector>
#include <string>
#include "glcorearb.h"
#include <msclr\marshal_cppstd.h>
#include "wglext.h"


using namespace System;
using namespace System::Collections::Generic;

namespace NetGL {
	public ref class OpenGL
	{
	public:

		// Clear Values //
		static int DepthBufferBit = GL_DEPTH_BUFFER_BIT;
		static int ColorBufferBit = GL_COLOR_BUFFER_BIT;
		static int AccumBufferBit = GL_ACCUM_BUFFER_BIT;
		static int StencilBufferBit = GL_STENCIL_BUFFER_BIT;

		// Matrix Mode //
		static int Projection = GL_PROJECTION;
		static int ModelView = GL_MODELVIEW;
		static int Texture = GL_TEXTURE;
		static int Color = GL_COLOR;
		static int ProjectionMatrix = GL_PROJECTION_MATRIX;
		static int ModelviewMatrix = GL_MODELVIEW_MATRIX;

		// VBegin Mode //
		static int Points = GL_POINT;
		static int Lines = GL_LINES;
		static int LineStrip = GL_LINE_STRIP;
		static int Triangles = GL_TRIANGLES;
		static int TriangleStrip = GL_TRIANGLE_STRIP;
		static int TriangleFan = GL_TRIANGLE_FAN;
		static int Quads = GL_QUADS;
		static int QuadStrip = GL_QUAD_STRIP;
		static int Polygon = GL_POLYGON;
		static int ShortArray = GL_SHORT;
		static int IntArray = GL_INT;
		static int FloatArray = GL_FLOAT;
		static int DoubleArray = GL_DOUBLE;
		static int ColorArray = GL_COLOR_ARRAY;
		static int EdgeFlagArray = GL_EDGE_FLAG_ARRAY;
		static int IndexArray = GL_INDEX_ARRAY;
		static int NormalArray = GL_NORMAL_ARRAY;
		static int TexCordArray = GL_TEXTURE_COORD_ARRAY;
		static int VertexArray = GL_VERTEX_ARRAY;
		static int UnsignedByte = GL_UNSIGNED_BYTE;
		static int UnsignedShort = GL_UNSIGNED_SHORT;
		static int UnsignedInt = GL_UNSIGNED_INT;
		static int Texture2D = GL_TEXTURE_2D;
		static int Texture2DMultisample = GL_TEXTURE_2D_MULTISAMPLE;
		static int ProxyTexture2D = GL_PROXY_TEXTURE_2D;
		static int Alpha = GL_ALPHA;
		static int Alpha4 = GL_ALPHA4;
		static int Alpha8 = GL_ALPHA8;
		static int Alpha12 = GL_ALPHA12;
		static int Alpha16 = GL_ALPHA16;
		static int DepthComponent = GL_DEPTH_COMPONENT;
		static int Luminance = GL_LUMINANCE;
		static int Luminance4 = GL_LUMINANCE4;
		static int Luminance8 = GL_LUMINANCE8;
		static int Luminance12 = GL_LUMINANCE12;
		static int Luminance16 = GL_LUMINANCE16;
		static int LuminanceAlpha = GL_LUMINANCE_ALPHA;
		static int Luminance4Alpha4 = GL_LUMINANCE4_ALPHA4;
		static int Luminance6Alpha2 = GL_LUMINANCE6_ALPHA2;
		static int Luminance8Alpha8 = GL_LUMINANCE8_ALPHA8;
		static int Luminance12Alpha4 = GL_LUMINANCE12_ALPHA4;
		static int Luminance12Alpha12 = GL_LUMINANCE12_ALPHA12;
		static int Luminance16Alpha16 = GL_LUMINANCE16_ALPHA16;
		static int Intensity = GL_INTENSITY;
		static int Intensity4 = GL_INTENSITY4;
		static int Intensity8 = GL_INTENSITY8;
		static int Intensity12 = GL_INTENSITY12;
		static int Intensity16 = GL_INTENSITY16;
		static int R3G3B2 = GL_R3_G3_B2;
		static int RGB = GL_RGB;
		static int RGB4 = GL_RGB4;
		static int RGB5 = GL_RGB5;
		static int RGB8 = GL_RGB8;
		static int RGB10 = GL_RGB10;
		static int RGB12 = GL_RGB12;
		static int RGB16 = GL_RGB16;
		static int RGBA = GL_RGBA;
		static int RGBA2 = GL_RGBA2;
		static int RGBA4 = GL_RGB4;
		static int RGB5A1 = GL_RGB5_A1;
		static int RGBA8 = GL_RGBA8;
		static int RGB10A2 = GL_RGB10_A2;
		static int RGBA12 = GL_RGBA12;
		static int RGBA16 = GL_RGBA16;
		static int ColorIndex = GL_COLOR_INDEX; // <-
		static int Red = GL_RED;
		static int Green = GL_GREEN;
		static int Blue = GL_BLUE;
		static int Byte = GL_BYTE;
		static int Bitmap = GL_BITMAP;
		static int Short = GL_SHORT;
		static int Int = GL_INT;
		static int Float = GL_FLOAT;
		static int AlphaTest = GL_ALPHA_TEST; // <-
		static int AutoNormal = GL_AUTO_NORMAL;
		static int Blend = GL_BLEND;
		static int ColorLogicOp = GL_COLOR_LOGIC_OP;
		static int ColorMaterial = GL_COLOR_MATERIAL;
		static int CullFace = GL_CULL_FACE;
		static int DepthTest = GL_DEPTH_TEST;
		static int Dither = GL_DITHER;
		static int Fog = GL_FOG;
		static int IndexLogicOp = GL_INDEX_LOGIC_OP;
		static int Lighting = GL_LIGHTING;
		static int LineSmooth = GL_LINE_SMOOTH;
		static int LineStipple = GL_LINE_STIPPLE;
		static int Map1Color4 = GL_MAP1_COLOR_4;
		static int Map1Index = GL_MAP1_INDEX;
		static int Map1Normal = GL_MAP1_NORMAL;
		static int Map1TextureCoord1 = GL_MAP1_TEXTURE_COORD_1;
		static int Map1TextureCoord2 = GL_MAP1_TEXTURE_COORD_2;
		static int Map1TextureCoord3 = GL_MAP1_TEXTURE_COORD_3;
		static int Map1TextureCoord4 = GL_MAP1_TEXTURE_COORD_4;
		static int Map1Vertex3 = GL_MAP1_VERTEX_3;
		static int Map1Vertex4 = GL_MAP1_VERTEX_4;
		static int Map2Color4 = GL_MAP2_COLOR_4;
		static int Map2Index = GL_MAP2_INDEX;
		static int Map2Normal = GL_MAP2_NORMAL;
		static int Map2TextureCoord1 = GL_MAP2_TEXTURE_COORD_1;
		static int Map2TextureCoord2 = GL_MAP2_TEXTURE_COORD_2;
		static int Map2TextureCoord3 = GL_MAP2_TEXTURE_COORD_3;
		static int Map2TextureCoord4 = GL_MAP2_TEXTURE_COORD_4;
		static int Map2Vertex3 = GL_MAP2_VERTEX_3;
		static int Map2Vertex4 = GL_MAP2_VERTEX_4;
		static int Normalize = GL_NORMALIZE;
		static int PointSmooth = GL_POINT_SMOOTH;
		static int PolygonOffsetFill = GL_POLYGON_OFFSET_FILL;
		static int PolygonOffsetLine = GL_POLYGON_OFFSET_LINE;
		static int PolygonOffsetPoint = GL_POLYGON_OFFSET_POINT;
		static int PolygonSmooth = GL_POLYGON_SMOOTH;
		static int PolygonStipple = GL_POLYGON_STIPPLE;
		static int ScrissorTest = GL_SCISSOR_TEST;
		static int StencilTest = GL_STENCIL_TEST;
		static int Texture1D = GL_TEXTURE_1D;
		static int TextureGenQ = GL_TEXTURE_GEN_Q;
		static int TextureGenR = GL_TEXTURE_GEN_R;
		static int TextureGenS = GL_TEXTURE_GEN_S;
		static int TextureGenT = GL_TEXTURE_GEN_T;
		static int TextureMinFilter = GL_TEXTURE_MIN_FILTER;
		static int TextureMagFilter = GL_TEXTURE_MAG_FILTER;
		static int TextureWrapS = GL_TEXTURE_WRAP_S;
		static int TextureWrapT = GL_TEXTURE_WRAP_T;
		static int TexturePriority = GL_TEXTURE_PRIORITY;
		static int Linear = GL_LINEAR;
		static int Nearest = GL_NEAREST;
		static int NearestMipMapNearest = GL_NEAREST_MIPMAP_NEAREST;
		static int LinearMipMapNearest = GL_LINEAR_MIPMAP_NEAREST;
		static int NearestMipMapLinear = GL_NEAREST_MIPMAP_LINEAR;
		static int LinearMipMapLinear = GL_LINEAR_MIPMAP_LINEAR;
		static int Repeate = GL_REPEAT;
		static int Clamp = GL_CLAMP;
		static int BGRAExt = GL_BGRA_EXT;
		static int BGRA = GL_BGRA;
		static int SwapMainPlane = WGL_SWAP_MAIN_PLANE;
		static int SwapOverlay1 = WGL_SWAP_OVERLAY1;
		static int SwapOverlay2 = WGL_SWAP_OVERLAY2;
		static int SwapOverlay3 = WGL_SWAP_OVERLAY3;
		static int SwapOverlay4 = WGL_SWAP_OVERLAY4;
		static int SwapOverlay5 = WGL_SWAP_OVERLAY5;
		static int SwapOverlay6 = WGL_SWAP_OVERLAY6;
		static int SwapOverlay7 = WGL_SWAP_OVERLAY7;
		static int SwapOverlay8 = WGL_SWAP_OVERLAY8;
		static int SwapOverlay9 = WGL_SWAP_OVERLAY9;
		static int SwapOverlay10 = WGL_SWAP_OVERLAY10;
		static int SwapOverlay11 = WGL_SWAP_OVERLAY11;
		static int SwapOverlay12 = WGL_SWAP_OVERLAY12;
		static int SwapOverlay13 = WGL_SWAP_OVERLAY13;
		static int SwapOverlay14 = WGL_SWAP_OVERLAY14;
		static int SwapOverlay15 = WGL_SWAP_OVERLAY15;
		static int SwapUnderlay1 = WGL_SWAP_UNDERLAY1;
		static int SwapUnderlay2 = WGL_SWAP_UNDERLAY2;
		static int SwapUnderlay3 = WGL_SWAP_UNDERLAY3;
		static int SwapUnderlay4 = WGL_SWAP_UNDERLAY4;
		static int SwapUnderlay5 = WGL_SWAP_UNDERLAY5;
		static int SwapUnderlay6 = WGL_SWAP_UNDERLAY6;
		static int SwapUnderlay7 = WGL_SWAP_UNDERLAY7;
		static int SwapUnderlay8 = WGL_SWAP_UNDERLAY8;
		static int SwapUnderlay9 = WGL_SWAP_UNDERLAY9;
		static int SwapUnderlay10 = WGL_SWAP_UNDERLAY10;
		static int SwapUnderlay11 = WGL_SWAP_UNDERLAY11;
		static int SwapUnderlay12 = WGL_SWAP_UNDERLAY12;
		static int SwapUnderlay13 = WGL_SWAP_UNDERLAY13;
		static int SwapUnderlay14 = WGL_SWAP_UNDERLAY14;
		static int SwapUnderlay15 = WGL_SWAP_UNDERLAY15;
		static int Light0 = GL_LIGHT0;
		static int Light1 = GL_LIGHT1;
		static int Light2 = GL_LIGHT2;
		static int Light3 = GL_LIGHT3;
		static int Light4 = GL_LIGHT4;
		static int Light5 = GL_LIGHT5;
		static int Light6 = GL_LIGHT6;
		static int Light7 = GL_LIGHT7;
		static int MaxLights = GL_MAX_LIGHTS;
		static int Ambient = GL_AMBIENT;
		static int Difuse = GL_DIFFUSE;
		static int Specular = GL_SPECULAR;
		static int Position = GL_POSITION;
		static int SpotDirection = GL_SPOT_DIRECTION;
		static int SpotExponent = GL_SPOT_EXPONENT;
		static int SpotCutOff = GL_SPOT_CUTOFF;
		static int ConstantAttenuation = GL_CONSTANT_ATTENUATION;
		static int LinearAttenuation = GL_LINEAR_ATTENUATION;
		static int QuadraticAttenuation = GL_QUADRATIC_ATTENUATION;
		static int BGR = GL_BGR_EXT;
		static int Nver = GL_NEVER;
		static int Less = GL_LESS;
		static int Equal = GL_EQUAL;
		static int Lequal = GL_LEQUAL;
		static int Greater = GL_GREATER;
		static int NotEqual = GL_NOTEQUAL;
		static int Gequal = GL_GEQUAL;
		static int Always = GL_ALWAYS;
		static int False = GL_FALSE;
		static int True = GL_TRUE;
		static int FrontAndBack = GL_FRONT_AND_BACK;
		static int Line = GL_LINE;
		static int Fill = GL_FILL;
		static int Multisample = GL_MULTISAMPLE;

		static int ArrayBuffer = GL_ARRAY_BUFFER;
		static int ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER;
		static int StreamDraw = GL_STREAM_DRAW;
		static int StreamRead = GL_STREAM_READ;
		static int StreamCopy = GL_STREAM_COPY;
		static int StaticDraw = GL_STATIC_DRAW;
		static int StaticRead = GL_STATIC_READ;
		static int StaticCopy = GL_STATIC_COPY;
		static int DynamicDraw = GL_DYNAMIC_DRAW;
		static int DynamicRead = GL_DYNAMIC_READ;
		static int DynamicCopy = GL_DYNAMIC_COPY;
		static int SrcAlpha = GL_SRC_ALPHA;
		static int OneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA;

		static int VertexShader = GL_VERTEX_SHADER;
		static int FragmentShader = GL_FRAGMENT_SHADER;

		static int Texture0 = GL_TEXTURE0;
		static int Texture1 = GL_TEXTURE1;
		static int Texture2 = GL_TEXTURE2;
		static int Texture3 = GL_TEXTURE3;
		static int Texture4 = GL_TEXTURE4;
		static int Texture5 = GL_TEXTURE5;
		static int Texture6 = GL_TEXTURE6;
		static int Texture7 = GL_TEXTURE7;
		static int Texture8 = GL_TEXTURE8;
		static int Texture9 = GL_TEXTURE9;
		static int Texture10 = GL_TEXTURE10;
		static int Texture11 = GL_TEXTURE11;
		static int Texture12 = GL_TEXTURE12;
		static int Texture13 = GL_TEXTURE13;
		static int Texture14 = GL_TEXTURE14;
		static int Texture15 = GL_TEXTURE15;
		static int Texture16 = GL_TEXTURE16;
		static int Texture17 = GL_TEXTURE17;
		static int Texture18 = GL_TEXTURE18;
		static int Texture19 = GL_TEXTURE19;
		static int Texture20 = GL_TEXTURE20;
		static int Texture21 = GL_TEXTURE21;
		static int Texture22 = GL_TEXTURE22;
		static int Texture23 = GL_TEXTURE23;
		static int Texture24 = GL_TEXTURE24;
		static int Texture25 = GL_TEXTURE25;
		static int Texture26 = GL_TEXTURE26;
		static int Texture27 = GL_TEXTURE27;
		static int Texture28 = GL_TEXTURE28;
		static int Texture29 = GL_TEXTURE29;
		static int Texture30 = GL_TEXTURE30;
		static int Texture31 = GL_TEXTURE31;

		static int DrawFrameBuffer = GL_DRAW_FRAMEBUFFER;
		static int ReadFrameBuffer = GL_READ_FRAMEBUFFER;
		static int FrameBuffer = GL_FRAMEBUFFER;
		static int FrameBufferComplete = GL_FRAMEBUFFER_COMPLETE;
		static int FrameBufferUndefined = GL_FRAMEBUFFER_UNDEFINED;
		static int FrameBufferIncompleteAttachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT;
		static int FrameBufferIncompleteMissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT;
		static int FrameBufferIncompleteDrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER;
		static int FrameBufferIncompleteReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER;
		static int FrameBufferUnsupported = GL_FRAMEBUFFER_UNSUPPORTED;
		static int FrameBufferIncompleteMultisample = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE;
		static int FrameBufferIncompleteLayerTargets = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS;
		static int DepthAttachment = GL_DEPTH_ATTACHMENT;
		static int StencilAttachment = GL_STENCIL_ATTACHMENT;
		static int StencilIndex = GL_STENCIL_INDEX;
		static int DepthStencilAttachment = GL_DEPTH_STENCIL_ATTACHMENT;
		static int RenderBuffer = GL_RENDERBUFFER;
		static int Depth24Stencil8 = GL_DEPTH24_STENCIL8;
		static int DepthComponent24 = GL_DEPTH_COMPONENT24;
		
		static int ColorAttachment0 = GL_COLOR_ATTACHMENT0;
		static int ColorAttachment1 = GL_COLOR_ATTACHMENT1;
		static int ColorAttachment2 = GL_COLOR_ATTACHMENT2;
		static int ColorAttachment3 = GL_COLOR_ATTACHMENT3;
		static int ColorAttachment4 = GL_COLOR_ATTACHMENT4;
		static int ColorAttachment5 = GL_COLOR_ATTACHMENT5;
		static int ColorAttachment6 = GL_COLOR_ATTACHMENT6;
		static int ColorAttachment7 = GL_COLOR_ATTACHMENT7;
		static int ColorAttachment8 = GL_COLOR_ATTACHMENT8;
		static int ColorAttachment9 = GL_COLOR_ATTACHMENT9;
		static int ColorAttachment10 = GL_COLOR_ATTACHMENT10;
		static int ColorAttachment11 = GL_COLOR_ATTACHMENT11;
		static int ColorAttachment12 = GL_COLOR_ATTACHMENT12;
		static int ColorAttachment13 = GL_COLOR_ATTACHMENT13;
		static int ColorAttachment14 = GL_COLOR_ATTACHMENT14;
		static int ColorAttachment15 = GL_COLOR_ATTACHMENT15;
		static int ColorAttachment16 = GL_COLOR_ATTACHMENT16;
		static int ColorAttachment17 = GL_COLOR_ATTACHMENT17;
		static int ColorAttachment18 = GL_COLOR_ATTACHMENT18;
		static int ColorAttachment19 = GL_COLOR_ATTACHMENT19;
		static int ColorAttachment20 = GL_COLOR_ATTACHMENT20;
		static int ColorAttachment21 = GL_COLOR_ATTACHMENT21;
		static int ColorAttachment22 = GL_COLOR_ATTACHMENT22;
		static int ColorAttachment23 = GL_COLOR_ATTACHMENT23;
		static int ColorAttachment24 = GL_COLOR_ATTACHMENT24;
		static int ColorAttachment25 = GL_COLOR_ATTACHMENT25;
		static int ColorAttachment26 = GL_COLOR_ATTACHMENT26;
		static int ColorAttachment27 = GL_COLOR_ATTACHMENT27;
		static int ColorAttachment28 = GL_COLOR_ATTACHMENT28;
		static int ColorAttachment29 = GL_COLOR_ATTACHMENT29;
		static int ColorAttachment30 = GL_COLOR_ATTACHMENT30;
		static int ColorAttachment31 = GL_COLOR_ATTACHMENT31;
		static int None = GL_NONE;
		static int One = GL_ONE;

		// GL Wrapper
		PFNGLBINDBUFFERPROC glBindBuffer;
		PFNGLGENBUFFERSPROC glGenBuffers;
		PFNGLBUFFERDATAPROC glBufferData;
		PFNGLDELETEBUFFERSPROC glDeleteBuffers;
		PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
		PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
		PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
		PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
		PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
		PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
		PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
		PFNGLCREATESHADERPROC glCreateShader;
		PFNGLSHADERSOURCEPROC glShaderSource;
		PFNGLCOMPILESHADERPROC glCompileShader;
		PFNGLCREATEPROGRAMPROC glCreateProgram;
		PFNGLATTACHSHADERPROC glAttachShader;
		PFNGLLINKPROGRAMPROC glLinkProgram;
		PFNGLUSEPROGRAMPROC glUseProgram;
		PFNGLDELETESHADERPROC glDeleteShader;
		PFNGLDELETEPROGRAMPROC glDeleteProgram;
		PFNGLUNIFORM1IPROC glUniform1i;
		PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
		PFNGLACTIVETEXTUREPROC glActiveTexture;
		PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
		PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
		PFNGLBUFFERSUBDATAPROC glBufferSubData;
		PFNGLUNIFORM1FPROC glUniform1f;
		PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
		PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
		PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
		PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
		PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
		PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
		PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
		PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
		PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
		PFNGLUNIFORM3FPROC glUniform3f;
		PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;

		// Konstruktor
		NetGL::OpenGL::OpenGL(void);

		// Variabeln
		bool modernGL = false;

		// Basics
		void Initial(System::IntPtr hwndl);
		void Clear(int Value);
		void MatrixMode(int MatrixMode);
		void LoadIdentity();
		void Begin(int BeginMode);
		void End();
		void Flush();
		void Color3f(float R, float G, float B);
		void Color3f(System::Drawing::Color Color);
		void Translate(float X, float Y, float Z);
		void Rotate(float Angle, float X, float Y, float Z);
		void Scale(float WidthX, float WidthY, float Height);
		int GetError();
		bool SwapLayerBuffers(int mode);
		int GenNetGLContex();
		bool MakeCurrent(int index);
		bool ShareLists(int t, int s);

		// Normal Data
		void Normal3b(byte X, byte Y, byte Z);
		void Normal3d(double X, double Y, double Z);
		void Normal3f(float X, float Y, float Z);
		void Normal3i(int X, int Y, int Z);
		void Normal3s(short X, short Y, short Z);
		void Normal(float X, float Y, float Z);
		void Normal3bv(const byte v);
		void Normal3dv(double v);
		void Normal3fv(float v);
		void Normal3iv(int v);
		void Normal3sv(short v);
		void NormalPointer(int Type, int stride, array<float>^ data);
		void NormalPointer(int Type, int Stride, array<int>^ data);
		void NormalPointer(int Type, int Stride, array<short>^ data);
		void NormalPointer(int Type, int Stride, array<double>^ data);

		// Texture Data
		void TextCord(float X, float Y);
		void TexCoord1d(double S);
		void TexCoord1f(float S);
		void TexCoord1i(int S);
		void TexCoord1s(short S);
		void TexCoord1dv(double V);
		void TexCoord1fv(float V);
		void TexCoord1iv(int V);
		void TexCoord1sv(short V);
		void TexCoord2d(double S, double T);
		void TexCoord2f(float S, float T);
		void TexCoord2i(int S, int T);
		void TexCoord2s(short S, short T);
		void TexCoord2dv(double V);
		void TexCoord2fv(float V);
		void TexCoord2iv(int V);
		void TexCoord2sv(short V);
		void TexCoordPointer(int Size, int Type, int stride, array<float>^ data);
		void TexCoordPointer(int Size, int Type, int stride, array<int>^ data);
		void TexCoordPointer(int Size, int Type, int stride, array<short>^ data);
		void TexCoordPointer(int Size, int Type, int stride, array<double>^ data);

		// Vertex Data
		void Vertex4d(double X, double Y, double Z, double W);
		void Vertex4f(float X, float Y, float Z, float W);
		void Vertex4i(int X, int Y, int Z, int W);
		void Vertex4s(short X, short Y, short Z, short W);
		void Vertex3d(double X, double Y, double Z);
		void Vertex3i(int X, int Y, int Z);
		void Vertex3f(float X, float Y, float Z);
		void Vertex3s(short X, short Y, short Z);
		void Vertex2d(double X, double Y);
		void Vertex2f(float X, float Y);
		void Vertex2i(int X, int Y);
		void Vertex2s(short X, short Y);
		void Vertex4dv(double V);
		void Vertex4fv(float V);
		void Vertex4iv(int V);
		void Vertex4sv(short V);
		void Vertex3dv(double V);
		void Vertex3fv(float V);
		void Vertex3iv(int V);
		void Vertex3sv(short V);
		void Vertex2dv(double V);
		void Vertex2fv(float V);
		void Vertex2iv(int V);
		void Vertex2sv(short V);
		void VertexPointer(int Size, int ArrayType, int stride, array<short>^ Array);
		void VertexPointer(int Size, int ArrayType, int stride, array<int>^ Array);
		void VertexPointer(int Size, int ArrayType, int stride, array<float>^ Array);
		void VertexPointer(int Size, int ArrayType, int stride, array<double>^ Array);
		void VertexPointer(int Size, int ArrayType, int stride, List<float>^ List);
		void VertexPointer(int Size, int ArrayType, int stride, int Offset);
		void VertexPointer(int Size, int ArrayType, int Stride);
		void PolygonMode(int face, int mode);

		// Drawing
		void DrawElements(int Mode, int Count, int ElementType, array<byte>^ Array);
		void DrawElements(int Mode, int Count, int ElementType, array<short>^ Array);
		void DrawElements(int Mode, int Count, int ElementType, array<int>^ Array);
		void DrawElements(int Mode, int Count, int ElementType, array<UINT32>^ Array);
		void DrawElements(int Mode, int Count, int ElementType, List<int>^ List);
		void DrawElements(int Mode, int Count, int ElementType);
		void DrawArrays(int mode, int first, int count);

		// Enable & Disable
		void EnabledClientState(int mode);
		void DisableClientState(int mode);
		void Enable(int Flag);
		void Disable(int Flag);

		// Texture
		int GenTextures(int n);
		void AlphaFunc(int function, float ColorValue);
		void BindTexture(int target, int texture);
		void DeleteTextures(int n, int texture);
		void TexParameteri(int target, int pname, int param);
		void TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type);
		void TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, array<int>^ data);
		void TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, array<byte>^ data);
		void TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, array<short>^ data);
		void TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, array<float>^ data);
		void TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, Drawing::Bitmap^ image);
		void Build2DMipmaps(int target, int Level, int Format, int Type, Drawing::Bitmap^ Texture);
		void BlendFunc(int sfactor, int dfactor);
		void BlendFuncSeparate(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);
		

		// Lights
		void Lightf(int Light, int LightTyp, float param);
		void Lightfv(int Light, int LightTyp, const float param);
		void ClearColor(float R, float G, float B, float A);
		void ClearColor();

		// Buffers
		void BindBuffer(int Target, int Buffer);
		int GenBuffer(int n);
		void DeleteBuffers(int n, int BufferID);
		void BufferData(int target, int size, array<float>^ data, int usage);
		void BufferData(int target, int size, array<short>^ data, int usage);
		void BufferData(int target, int size, array<int>^ data, int usage);
		void BufferData(int target, int size, array<double>^ data, int usage);
		generic<typename T>
		void BufferData(int target, int size, array<T>^ data, int usage);
		void BufferData(int target, int size, void* data, int usage);
		void BufferSubData(int target, int offset, int size, array<float>^ data);

		// Matrix & View
		void LookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
		void Perspective(float fov, float apsect, float znear, float zfar);
		void Frustum(float left, float right, float bottom, float top, float znear, float zfar);
		void Ortho(float left, float right, float bottom, float top, float znear, float zfar);
		void Viewport(float x, float y, float width, float height);
		void PushMatrix();
		void PopMatrix();

		// VAO
		int GenVertexArrays(int n);
		void BindVertexArray(int BufferID);
		void EnableVertexAttribArray(int BufferID);
		void VertexAttribPointer(int index, int size, int type, bool normalized, int stride, int pointer);
		void VertexAttribPointer(int index, int size, int type, bool normalized, int stride, IntPtr pointer);
		void VertexAttribPointer(int Index, int Size, int Type, int Normalized, int Stride, array<float>^ data);
		void VertexAttribPointer(int Index, int Size, int Type, int Normalized, int Stride, array<short>^ data);
		void VertexAttribPointer(int Index, int Size, int Type, int Normalized, int Stride, array<int>^ data);
		void VertexAttribPointer(int Index, int Size, int Type, int Normalized, int Stride, array<double>^ data);
		void VertexAtrribIPointer(int index, int size, int type, int stride, int pointer);
		void VertexAtrribIPointer(int index, int size, int type, int stride, IntPtr pointer);
		void DeleteVertexArrays(int n, int BufferID);

		//Shaders
		int CreateShader(int type);
		void SetShaderSource(int shader, int count, String^ source);
		void CompileShader(int shader);
		int CreateProgram();
		void AttachShader(int shaderProgram, int shader);
		void LinkProgram(int shaderProgram);
		void UseProgram(int shaderProgram);
		void DeleteShader(int shader);
		void DeleteProgram(int program);
		void Uniform1I(int location, int v0);
		void Uniform1f(int location, float value);
		void Uniform3f(int location, float x, float y, float z);
		int GetUniformLocation(int program, String^ name);
		void ActiveTexture(int texture);
		array<float>^ GetFloatArray(int name, int size);
		void UniformMatrix4fv(int location, int count, bool transpose, array<float>^ matrixData);
		void SetModelviewMatrix(int location, int count, bool transpose);
		void SetProjectionMatrix(int location, int count, bool transpose);
		void SwapIntervalEXT(int interval);
		void GlCullFace(int mode);
		void DepthFunc(int mode);
		void GenerateMipMap(int target);

		int GenFramebuffers(int n);
		void BindFramebuffer(int target, int id);
		int CheckFramebufferStatus(int target);
		void FrameBufferTexture2D(int target, int attachment, int textarage, int texture, int level);
		void DrawPixels(int width, int height, int format, int type);
		int GenRenderbuffers(int n);
		void BindRenderbuffer(int target, int id);
		void RenderbufferStorage(int target, int internalFormat, int width, int height);
		void FramebufferRenderbuffer(int target, int attachment, int renderBufferTarget, int renderBuffer);
		void DrawBuffer(int buf);
		void ReadBuffer(int mode);
		void ColorMask(bool red, bool green, bool blue, bool alpha);

		// Basics
		void LineWidth(float value);
	private:

		HDC GraphicDevice;
		std::vector<HGLRC>* ContexArray;
		void InitialExt();
	};
}