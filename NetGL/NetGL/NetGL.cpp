#include "pch.h"

// Dies ist die Haupt-DLL.
//#include "Stdafx.h"
#include "NetGL.h"


namespace NetGL {

	NetGL::OpenGL::OpenGL()
	{

	}

	void NetGL::OpenGL::Initial(System::IntPtr hwnd)
	{
		// Create HDC from Handle
		HWND nHwnd = (HWND)hwnd.ToPointer();
		HDC hWnd = GetDC(nHwnd);

		// Create Pixelformat
		PIXELFORMATDESCRIPTOR desc;
		desc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;

		int Pixelformat = ChoosePixelFormat(hWnd, &desc);
		SetPixelFormat(hWnd, Pixelformat, &desc);

		// Create Render Screen
		HGLRC hrc = wglCreateContext(hWnd);
		Console::WriteLine(GetLastError().ToString());

		if (!wglMakeCurrent(hWnd, hrc)) {
			Console::WriteLine("Error: Failure to initial OpenGl");
		}

		Console::WriteLine(GetLastError().ToString());

		// Sets the Graphic Device
		this->ContexArray = new std::vector<HGLRC>();
		this->GraphicDevice = hWnd;
		this->ContexArray->push_back(hrc);

		// Initial Extentions
		if (this->modernGL) {
			InitialExt();
		}
	}

	void NetGL::OpenGL::Clear(int ClearValue)
	{
		glClear(ClearValue);
	}

	void NetGL::OpenGL::MatrixMode(int MatrixMode)
	{
		glMatrixMode(MatrixMode);
	}

	void NetGL::OpenGL::LoadIdentity()
	{
		glLoadIdentity();
	}

	void NetGL::OpenGL::Begin(int BeginMode)
	{
		glBegin(BeginMode);
	}

	void NetGL::OpenGL::Vertex3f(float X, float Y, float Z)
	{
		glVertex3f(X, Y, Z);
	}

	void NetGL::OpenGL::Normal(float X, float Y, float Z)
	{
		glNormal3f(X, Y, Z);
	}

	void NetGL::OpenGL::TextCord(float X, float Y)
	{
		glTexCoord2f(X, Y);
	}

	void NetGL::OpenGL::End()
	{
		glEnd();
	}

	void NetGL::OpenGL::Flush()
	{
		glFlush();
	}

	void NetGL::OpenGL::Color3f(float R, float G, float B)
	{
		glColor3f(R, G, B);
	}

	void NetGL::OpenGL::Color3f(System::Drawing::Color Color)
	{
		glColor3f(Color.R, Color.G, Color.B);
	}

	void NetGL::OpenGL::Translate(float X, float Y, float Z)
	{
		glTranslatef(X, Y, Z);
	}

	void NetGL::OpenGL::Rotate(float Angle, float X, float Y, float Z)
	{
		glRotatef(Angle, X, Y, Z);
	}

	void NetGL::OpenGL::Scale(float WidthX, float WidthY, float Height)
	{
		glScalef(WidthX, WidthY, Height);
	}

	void NetGL::OpenGL::VertexPointer(int Size, int ArrayType, int Stride, array<short>^ DataArray)
	{
		GLshort* arr = new GLshort[DataArray->Length];
		for (int i = 0; i < DataArray->Length; i++)
		{
			arr[i] = DataArray[i];
		}
		glVertexPointer(Size, ArrayType, Stride, arr);
	}

	void NetGL::OpenGL::VertexPointer(int Size, int ArrayType, int Stride, array<int>^ DataArray)
	{
		GLint* arr = new GLint[DataArray->Length];
		for (int i = 0; i < DataArray->Length; i++)
		{
			arr[i] = DataArray[i];
		}
		glVertexPointer(Size, ArrayType, Stride, arr);
	}

	void NetGL::OpenGL::VertexPointer(int Size, int ArrayType, int Stride, array<float>^ DataArray)
	{
		GLfloat* arr = new GLfloat[DataArray->Length];
		for (int i = 0; i < DataArray->Length; i++)
		{
			arr[i] = DataArray[i];
		}
		glVertexPointer(Size, ArrayType, Stride, arr);
	}

	void NetGL::OpenGL::VertexPointer(int Size, int ArrayType, int Stride, array<double>^ DataArray)
	{
		GLdouble* arr = new GLdouble[DataArray->Length];
		for (int i = 0; i < DataArray->Length; i++)
		{
			arr[i] = DataArray[i];
		}
		glVertexPointer(Size, ArrayType, Stride, arr);
	}

	void NetGL::OpenGL::VertexPointer(int Size, int ArrayType, int Stride, List<float>^ ArrayValues)
	{
		GLfloat* floatarr = new float[ArrayValues->Count];
		for (int i = 0; i < ArrayValues->Count; i++)
		{
			floatarr[i] = ArrayValues[i];
		}
		glVertexPointer(Size, ArrayType, Stride, floatarr);
	}

	void NetGL::OpenGL::VertexPointer(int Size, int ArrayType, int Stride, int Offset)
	{
		glVertexPointer(Size, ArrayType, Stride, &Offset);
	}

	void NetGL::OpenGL::VertexPointer(int Size, int ArrayType, int Stride)
	{
		glVertexPointer(Size, ArrayType, Stride, NULL);
	}

	void NetGL::OpenGL::PolygonMode(int face, int mode) {
		glPolygonMode(face, mode);
	}

	void NetGL::OpenGL::EnabledClientState(int mode)
	{
		glEnableClientState(mode);
	}

	void NetGL::OpenGL::DisableClientState(int mode)
	{
		glDisableClientState(mode);
	}

	void NetGL::OpenGL::DrawElements(int Mode, int Size, int ElementType, array<byte>^ IndexArray)
	{
		glDrawElements(Mode, Size, ElementType, &IndexArray);
	}

	void NetGL::OpenGL::DrawElements(int Mode, int Size, int ElementType, array<short>^ IndexArray)
	{
		glDrawElements(Mode, Size, ElementType, &IndexArray);
	}

	void NetGL::OpenGL::DrawElements(int Mode, int Size, int ElementType, array<int>^ IndexArray)
	{
		glDrawElements(Mode, Size, ElementType, &IndexArray);
	}

	void NetGL::OpenGL::DrawElements(int Mode, int Size, int ElementType, array<UINT32>^ IndexArray)
	{
		glDrawElements(Mode, Size, ElementType, &IndexArray);
	}

	void NetGL::OpenGL::DrawElements(int Mode, int Size, int ElementType, List<int>^ ArrayValues)
	{
		GLuint* indexarr = new GLuint[ArrayValues->Count];
		for (int i = 0; i < ArrayValues->Count; i++)
		{
			indexarr[i] = ArrayValues[i];
		}
		glDrawElements(Mode, Size, ElementType, indexarr);
	}

	void NetGL::OpenGL::DrawElements(int Mode, int Size, int ElementType)
	{
		glDrawElements(Mode, Size, ElementType, NULL);
	}

	void NetGL::OpenGL::Enable(int Flag)
	{
		glEnable(Flag);
	}

	void NetGL::OpenGL::Disable(int Flag)
	{
		glDisable(Flag);
	}

	int NetGL::OpenGL::GenTextures(int n)
	{
		GLuint texture;
		glGenTextures(n, &texture);
		return texture;
	}

	void NetGL::OpenGL::BindTexture(int target, int texture)
	{
		glBindTexture(target, texture);
	}

	void NetGL::OpenGL::DeleteTextures(int n, int textures)
	{
		GLuint texture = textures;
		glDeleteTextures(n, &texture);
	}

	void NetGL::OpenGL::TexParameteri(int target, int pname, int param)
	{
		glTexParameteri(target, pname, param);
	}

	void NetGL::OpenGL::Build2DMipmaps(int target, int level, int format, int type, Drawing::Bitmap^ Texture)
	{
		Drawing::Rectangle rect(0, 0, Texture->Width, Texture->Height);
		Drawing::Imaging::BitmapData^ data = Texture->LockBits(rect, Drawing::Imaging::ImageLockMode::ReadOnly, Drawing::Imaging::PixelFormat::Format32bppArgb);
		gluBuild2DMipmaps(target, level, Texture->Width, Texture->Height, format, type, (void*)data->Scan0);
		Texture->UnlockBits(data);
	}

	int NetGL::OpenGL::GetError()
	{
		return glGetError();
	}

	void NetGL::OpenGL::TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, array<int>^ data)
	{
		glTexImage2D(target, level, internalformat, width, height, border, format, type, &data);
	}

	void NetGL::OpenGL::TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, array<byte>^ data)
	{
		glTexImage2D(target, level, internalformat, width, height, border, format, type, &data);
	}

	void NetGL::OpenGL::TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, array<short>^ data)
	{
		glTexImage2D(target, level, internalformat, width, height, border, format, type, &data);
	}

	void NetGL::OpenGL::TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, array<float>^ data)
	{
		glTexImage2D(target, level, internalformat, width, height, border, format, type, &data);
	}

	void NetGL::OpenGL::TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type, Drawing::Bitmap^ image)
	{
		Drawing::Rectangle Rect(0, 0, width, height);
		Drawing::Imaging::BitmapData^ data = image->LockBits(Rect, Drawing::Imaging::ImageLockMode::ReadOnly, Drawing::Imaging::PixelFormat::Format32bppPArgb);
		glTexImage2D(target, level, internalformat, width, height, border, format, type, (void*)data->Scan0);
		image->UnlockBits(data);
	}

	void NetGL::OpenGL::Vertex4d(double X, double Y, double Z, double W)
	{
		glVertex4d(X, Y, Z, W);
	}

	void NetGL::OpenGL::Vertex4f(float X, float Y, float Z, float W)
	{
		glVertex4f(X, Y, Z, W);
	}

	void NetGL::OpenGL::Vertex4i(int X, int Y, int Z, int W)
	{
		glVertex4i(X, Y, Z, W);
	}

	void NetGL::OpenGL::Vertex4s(short X, short Y, short Z, short W)
	{
		glVertex4s(X, Y, Z, W);
	}

	void NetGL::OpenGL::Vertex3d(double X, double Y, double Z)
	{
		glVertex3d(X, Y, Z);
	}

	void NetGL::OpenGL::Vertex3i(int X, int Y, int Z)
	{
		glVertex3i(X, Y, Z);
	}

	void NetGL::OpenGL::Vertex3s(short X, short Y, short Z)
	{
		glVertex3s(X, Y, Z);
	}

	void NetGL::OpenGL::Vertex2d(double X, double Y)
	{
		glVertex2d(X, Y);
	}

	void NetGL::OpenGL::Vertex2f(float X, float Y)
	{
		glVertex2f(X, Y);
	}

	void NetGL::OpenGL::Vertex2i(int X, int Y)
	{
		glVertex2i(X, Y);
	}

	void NetGL::OpenGL::Vertex2s(short X, short Y)
	{
		glVertex2s(X, Y);
	}


	void NetGL::OpenGL::Vertex4dv(double V)
	{
		const GLdouble v = V;
		glVertex4dv(&v);
	}

	void NetGL::OpenGL::Vertex4fv(float V)
	{
		const GLfloat v = V;
		glVertex4fv(&v);
	}

	void NetGL::OpenGL::Vertex4iv(int V)
	{
		const GLint v = V;
		glVertex4iv(&v);
	}

	void NetGL::OpenGL::Vertex4sv(short V)
	{
		const GLshort v = V;
		glVertex4sv(&v);
	}

	void NetGL::OpenGL::Vertex3dv(double V)
	{
		const GLdouble v = V;
		glVertex3dv(&v);
	}

	void NetGL::OpenGL::Vertex3fv(float V)
	{
		const GLfloat v = V;
		glVertex3fv(&v);
	}

	void NetGL::OpenGL::Vertex3iv(int V)
	{
		const GLint v = V;
		glVertex3iv(&v);
	}

	void NetGL::OpenGL::Vertex3sv(short V)
	{
		const GLshort v = V;
		glVertex3sv(&v);
	}

	void NetGL::OpenGL::Vertex2dv(double V)
	{
		const GLdouble v = V;
		glVertex2dv(&v);
	}

	void NetGL::OpenGL::Vertex2fv(float V)
	{
		const GLfloat v = V;
		glVertex2fv(&v);
	}

	void NetGL::OpenGL::Vertex2iv(int V)
	{
		const GLint v = V;
		glVertex2iv(&v);
	}

	void NetGL::OpenGL::Vertex2sv(short V)
	{
		const GLshort v = V;
		glVertex2sv(&v);
	}

	void NetGL::OpenGL::Normal3b(byte X, byte Y, byte Z)
	{
		glNormal3b(X, Y, Z);
	}

	void NetGL::OpenGL::Normal3d(double X, double Y, double Z)
	{
		glNormal3d(X, Y, Z);
	}

	void NetGL::OpenGL::Normal3f(float X, float Y, float Z)
	{
		glNormal3f(X, Y, Z);
	}

	void NetGL::OpenGL::Normal3i(int X, int Y, int Z)
	{
		glNormal3i(X, Y, Z);
	}

	void NetGL::OpenGL::Normal3s(short X, short Y, short Z)
	{
		glNormal3s(X, Y, Z);
	}

	void NetGL::OpenGL::Normal3bv(const byte V)
	{
		const GLbyte v = V;
		glNormal3bv(&v);
	}

	void NetGL::OpenGL::Normal3dv(double V)
	{
		const GLdouble v = V;
		glNormal3dv(&v);
	}

	void NetGL::OpenGL::Normal3fv(float V)
	{
		const GLfloat v = V;
		glNormal3fv(&v);
	}

	void NetGL::OpenGL::Normal3iv(int V)
	{
		const GLint v = V;
		glNormal3iv(&v);
	}

	void NetGL::OpenGL::Normal3sv(short V)
	{
		const GLshort v = V;
		glNormal3sv(&v);
	}

	void NetGL::OpenGL::NormalPointer(int Type, int Stride, array<int>^ data)
	{
		GLint* arr = new GLint[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glNormalPointer(Type, Stride, arr);
	}

	void NetGL::OpenGL::NormalPointer(int Type, int Stride, array<short>^ data)
	{
		GLshort* arr = new GLshort[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glNormalPointer(Type, Stride, arr);
	}

	void NetGL::OpenGL::NormalPointer(int Type, int Stride, array<double>^ data)
	{
		GLdouble* arr = new GLdouble[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glNormalPointer(Type, Stride, arr);
	}

	void NetGL::OpenGL::TexCoord1d(double S)
	{
		glTexCoord1d(S);
	}

	void NetGL::OpenGL::TexCoord1f(float S)
	{
		glTexCoord1f(S);
	}

	void NetGL::OpenGL::TexCoord1i(int S)
	{
		glTexCoord1i(S);
	}

	void NetGL::OpenGL::TexCoord1s(short S)
	{
		glTexCoord1s(S);
	}

	void NetGL::OpenGL::TexCoord1dv(double V)
	{
		const GLdouble v = V;
		glTexCoord1dv(&v);
	}

	void NetGL::OpenGL::TexCoord1fv(float V)
	{
		const GLfloat v = V;
		glTexCoord1fv(&v);
	}

	void NetGL::OpenGL::TexCoord1iv(int V)
	{
		const GLint v = V;
		glTexCoord1iv(&v);
	}

	void NetGL::OpenGL::TexCoord1sv(short V)
	{
		const GLshort v = V;
		glTexCoord1sv(&v);
	}

	void NetGL::OpenGL::TexCoord2d(double W, double T)
	{
		glTexCoord2d(W, T);
	}

	void NetGL::OpenGL::TexCoord2f(float W, float T)
	{
		glTexCoord2f(W, T);
	}

	void NetGL::OpenGL::TexCoord2i(int W, int T)
	{
		glTexCoord2i(W, T);
	}

	void NetGL::OpenGL::TexCoord2s(short W, short T)
	{
		glTexCoord2s(W, T);
	}

	void NetGL::OpenGL::TexCoord2dv(double V)
	{
		const GLdouble v = V;
		glTexCoord2dv(&v);
	}

	void NetGL::OpenGL::TexCoord2fv(float V)
	{
		const GLfloat v = V;
		glTexCoord2fv(&v);
	}

	void NetGL::OpenGL::TexCoord2iv(int  V)
	{
		const GLint v = V;
		glTexCoord2iv(&v);
	}

	void NetGL::OpenGL::TexCoord2sv(short V)
	{
		const GLshort v = V;
		glTexCoord2sv(&v);
	}

	void NetGL::OpenGL::TexCoordPointer(int Size, int Type, int Stride, array<int>^ data)
	{
		GLint* arr = new GLint[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glTexCoordPointer(Size, Type, Stride, arr);
	}

	void NetGL::OpenGL::TexCoordPointer(int Size, int Type, int Stride, array<short>^ data)
	{
		GLshort* arr = new GLshort[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glTexCoordPointer(Size, Type, Stride, arr);
	}

	void NetGL::OpenGL::TexCoordPointer(int Size, int Type, int Stride, array<double>^ data)
	{
		GLdouble* arr = new GLdouble[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glTexCoordPointer(Size, Type, Stride, arr);
	}

	bool NetGL::OpenGL::SwapLayerBuffers(int mode)
	{
		return wglSwapLayerBuffers(this->GraphicDevice, mode);
	}

	int NetGL::OpenGL::GenNetGLContex()
	{
		HGLRC contex = wglCreateContext(this->GraphicDevice);
		this->ContexArray->push_back(contex);
		return this->ContexArray->size();
	}

	bool NetGL::OpenGL::MakeCurrent(int index)
	{
		HGLRC contex = this->ContexArray->at(index);
		BOOL isCurrent = wglMakeCurrent(this->GraphicDevice, contex);
		InitialExt();
		return isCurrent;
	}

	bool NetGL::OpenGL::ShareLists(int t, int s)
	{
		HGLRC target = ContexArray->at(t);
		HGLRC source = ContexArray->at(s);
		return wglShareLists(target, source);
	}

	void NetGL::OpenGL::Lightf(int Light, int LightType, float param)
	{
		glLightf(Light, LightType, param);
	}

	void NetGL::OpenGL::Lightfv(int Light, int LightType, const float param)
	{
		glLightfv(Light, LightType, &param);
	}

	void NetGL::OpenGL::ClearColor(float R, float G, float B, float A)
	{
		glClearColor(R, G, B, A);
	}

	void NetGL::OpenGL::ClearColor()
	{
		glClearColor(0, 0, 0, 0);
	}

	void NetGL::OpenGL::AlphaFunc(int function, float ColorValue)
	{
		glAlphaFunc(function, ColorValue);
	}

	void NetGL::OpenGL::TexCoordPointer(int Size, int Type, int stride, array<float>^ data)
	{
		GLfloat* arr = new GLfloat[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glTexCoordPointer(Size, Type, stride, arr);
	}

	void NetGL::OpenGL::DrawArrays(int mode, int first, int count)
	{
		glDrawArrays(mode, first, count);
	}

	void NetGL::OpenGL::NormalPointer(int Type, int Stride, array<float>^ data)
	{
		GLfloat* arr = new GLfloat[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glNormalPointer(Type, Stride, arr);
	}

	int NetGL::OpenGL::GenBuffer(int n)
	{
		GLuint ID;
		glGenBuffers(n, &ID);
		return (int)ID;
	}

	void NetGL::OpenGL::BindBuffer(int Target, int BBuffer)
	{
		glBindBuffer(Target, BBuffer);
	}

	void NetGL::OpenGL::DeleteBuffers(int n, int BufferID)
	{
		const GLuint Buffer = BufferID;
		glDeleteBuffers(n, &Buffer);
	}

	void NetGL::OpenGL::BufferData(int target, int size, array<float>^ data, int usage)
	{
		GLfloat* arr = new GLfloat[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glBufferData(target, size, arr, usage);
	}

	void NetGL::OpenGL::BufferData(int target, int size, array<short>^ data, int usage)
	{
		GLshort* arr = new GLshort[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glBufferData(target, size, arr, usage);
	}

	void NetGL::OpenGL::BufferData(int target, int size, array<int>^ data, int usage)
	{
		GLint* arr = new GLint[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glBufferData(target, size, arr, usage);
	}

	void NetGL::OpenGL::BufferData(int target, int size, array<double>^ data, int usage)
	{
		GLdouble* arr = new GLdouble[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glBufferData(target, size, arr, usage);
	}

	void NetGL::OpenGL::InitialExt()
	{
		// Modern GL
		glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
		if (glBindBuffer != NULL)
		{
			Console::WriteLine("glBindBuffer" + true);
		}
		else
		{
			Console::WriteLine("glBindBuffer" + false);
		}

		glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
		if (glGenBuffers != NULL)
		{
			Console::WriteLine("glGenBuffers" + true);
		}
		else
		{
			Console::WriteLine("glGenBuffers" + false);
		}

		glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
		if (glBufferData != NULL)
		{
			Console::WriteLine(true);
		}
		else
		{
			Console::WriteLine(false);
		}

		glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
		if (glDeleteBuffers != NULL)
		{
			Console::WriteLine(true);
		}
		else
		{
			Console::WriteLine(false);
		}

		glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
		if (glGenVertexArrays != NULL)
		{
			Console::WriteLine(true);
		}
		else
		{
			Console::WriteLine(false);
		}

		glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
		if (glBindVertexArray != NULL)
		{
			Console::WriteLine(true);
		}
		else
		{
			Console::WriteLine(false);
		}

		glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
		if (glEnableVertexAttribArray != NULL)
		{
			Console::WriteLine(true);
		}
		else
		{
			Console::WriteLine(false);
		}

		glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
		if (glVertexAttribPointer != NULL)
		{
			Console::WriteLine(true);
		}
		else
		{
			Console::WriteLine(false);
		}

		glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glDisableVertexAttribArray");
		if (glDisableVertexAttribArray != NULL)
		{
			Console::WriteLine(true);
		}
		else
		{
			Console::WriteLine(false);
		}

		glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
		if (glDeleteVertexArrays != NULL)
		{
			Console::WriteLine(true);
		}
		else
		{
			Console::WriteLine(false);
		}

	}


	int NetGL::OpenGL::GenVertexArrays(int n)
	{
		GLuint ID;
		glGenVertexArrays(n, &ID);
		return (int)ID;
	}

	void NetGL::OpenGL::BindVertexArray(int BufferID)
	{
		glBindVertexArray(BufferID);
	}

	void NetGL::OpenGL::EnableVertexAttribArray(int BufferID)
	{
		glEnableVertexAttribArray(BufferID);
	}

	void NetGL::OpenGL::VertexAttribPointer(int Index, int Size, int Type, int Normalized, int Stride, array<float>^ data)
	{
		GLfloat* arr = new GLfloat[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}

		glVertexAttribPointer(Index, Size, Type, Normalized, Stride, arr);
	}

	void NetGL::OpenGL::VertexAttribPointer(int Index, int Size, int Type, int Normalized, int Stride, array<short>^ data)
	{
		GLshort* arr = new GLshort[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glVertexAttribPointer(Index, Size, Type, Normalized, Stride, arr);
	}

	void NetGL::OpenGL::VertexAttribPointer(int Index, int Size, int Type, int Normalized, int Stride, array<int>^ data)
	{
		GLint* arr = new GLint[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glVertexAttribPointer(Index, Size, Type, Normalized, Stride, arr);
	}

	void NetGL::OpenGL::VertexAttribPointer(int Index, int Size, int Type, int Normalized, int Stride, array<double>^ data)
	{
		GLdouble* arr = new GLdouble[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}
		glVertexAttribPointer(Index, Size, Type, Normalized, Stride, arr);
	}

	void NetGL::OpenGL::DeleteVertexArrays(int n, int BufferID)
	{
		const GLuint i = BufferID;
		glDeleteVertexArrays(n, &i);
	}

	void NetGL::OpenGL::LookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) 
	{
		gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
	}

	void NetGL::OpenGL::Frustum(float left, float right, float bottom, float top, float znear, float zfar) 
	{
		glFrustum(left, right, bottom, top, znear, zfar);
	}

	void NetGL::OpenGL::Ortho(float left, float right, float bottom, float top, float znear, float zfar)
	{
		glOrtho(left, right, bottom, top, znear, zfar);
	}

	void NetGL::OpenGL::Viewport(float x, float y, float width, float height) 
	{
		glViewport(x, y, width, height);
	}

	void NetGL::OpenGL::PushMatrix() {
		glPushMatrix();
	}

	void NetGL::OpenGL::PopMatrix() {
		glPopMatrix();
	}

	void NetGL::OpenGL::BlendFunc(int sfactor, int dfactor) {
		glBlendFunc(sfactor, dfactor);

	}

	void NetGL::OpenGL::LineWidth(float width) {
		glLineWidth(width);
	}

}