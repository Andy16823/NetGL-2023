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

		// Initial Extentions
		if (this->modernGL) {
			InitialExt();
		}

		std::string strVersion = (const char*)glGetString(GL_VERSION);
		strVersion = strVersion.substr(0, strVersion.find(" "));
		float number = std::atof(strVersion.c_str());
		Console::WriteLine("Using GL " + number);

		// Sets the Graphic Device
		this->ContexArray = new std::vector<HGLRC>();
		this->GraphicDevice = hWnd;
		this->ContexArray->push_back(hrc);

		auto error = glGetError();
		if (error != 0) {
			Console::WriteLine("Error after init " + error);
		}
		else {
			Console::WriteLine("NetGL " + NET_GL_VERSION + " Initalized!");
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

	void OpenGL::DrawElementsInstanced(int Mode, int Count, int ElementType, IntPtr Indices, int InstanceCount)
	{
		glDrawElementsInstanced(Mode, Count, ElementType, (void*)Indices, InstanceCount);
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

	void OpenGL::TexParameterfv(int target, int pname, array<float>^ data)
	{
		pin_ptr<float> pinnedData = &data[0];
		glTexParameterfv(target, pname, pinnedData);
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

	void NetGL::OpenGL::TexImage2D(int target, int level, int internalformat, int width, int height, int border, int format, int type)
	{
		glTexImage2D(target, level, internalformat, width, height, border, format, type, NULL);
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

	void OpenGL::DrawArraysInstanced(int mode, int first, int count, int instancecount)
	{
		glDrawArraysInstanced(mode, first, count, instancecount);
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
		/*GLfloat* arr = new GLfloat[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}*/
		pin_ptr<float> pinnedArray = &data[0];
		glBufferData(target, size, pinnedArray, usage);
	}

	void NetGL::OpenGL::BufferData(int target, int size, array<short>^ data, int usage)
	{
		/*GLshort* arr = new GLshort[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}*/
		pin_ptr<short> pdata = &data[0];
		glBufferData(target, size, pdata, usage);
	}

	void NetGL::OpenGL::BufferData(int target, int size, array<int>^ data, int usage)
	{
		/*GLint* arr = new GLint[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}*/
		pin_ptr<int> pdata = &data[0];
		glBufferData(target, size, pdata, usage);
	}

	void NetGL::OpenGL::BufferData(int target, int size, array<double>^ data, int usage)
	{
		/*GLdouble* arr = new GLdouble[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}*/
		pin_ptr<double> pdata = &data[0];
		glBufferData(target, size, pdata, usage);
	}

	generic<typename T>
	void NetGL::OpenGL::BufferData(int target, int size, array<T>^ data, int usage)
	{
		/*GLfloat* arr = new GLfloat[data->Length];
		for (int i = 0; i < data->Length; i++)
		{
			arr[i] = data[i];
		}*/
		pin_ptr<T> pinnedArray = &data[0];
		glBufferData(target, size, pinnedArray, usage);
	}

	void NetGL::OpenGL::BufferData(int target, int size, void* data, int usage)
	{
		glBufferData(target, size, data, usage);
	}

	void NetGL::OpenGL::BufferSubData(int target, int offset, int size, array<float>^ data) 
	{
		pin_ptr<float> pdata = &data[0];
		glBufferSubData(target, offset, size, pdata);
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

		glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)wglGetProcAddress("glVertexAttribIPointer");
		if (glVertexAttribIPointer != NULL)
		{
			Console::WriteLine("glVertexAttribIPointer init");
		}
		else {
			Console::WriteLine("Could not load glVertexAttribIPointer");
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

		glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
		if (glCreateShader != NULL)
		{
			Console::WriteLine("glCreateShader loaded");
		}
		else 
		{
			Console::WriteLine("Error while loading glCreateShader");
		}

		glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
		if (glShaderSource != NULL) 
		{
			Console::WriteLine("glShaderSource loaded");
		}
		else {
			Console::WriteLine("Error while loading glShaderSource");
		}

		glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
		if (glCompileShader != NULL)
		{
			Console::WriteLine("glCompileShader loaded");
		}
		else {
			Console::WriteLine("Error while loading glCompileShader");
		}

		glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
		if (glCreateProgram != NULL)
		{
			Console::WriteLine("glCreateProgram loaded");
		}
		else {
			Console::WriteLine("Error while loading glCreateProgram");
		}

		glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
		if (glAttachShader != NULL)
		{
			Console::WriteLine("glAttachShader loaded");
		}
		else {
			Console::WriteLine("Error while loading glAttachShader");
		}

		glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
		if (glLinkProgram != NULL)
		{
			Console::WriteLine("glLinkProgram loaded");
		}
		else {
			Console::WriteLine("Error while loading glLinkProgram");
		}

		glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
		if (glUseProgram != NULL)
		{
			Console::WriteLine("glUseProgram loaded");
		}
		else {
			Console::WriteLine("Error while loading glUseProgram");
		}

		glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
		if (glDeleteShader != NULL)
		{
			Console::WriteLine("glDeleteShader loaded");
		}
		else {
			Console::WriteLine("Error while loading glDeleteShader");
		}

		glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
		if (glDeleteProgram != NULL)
		{
			Console::WriteLine("glDeleteProgram loaded");
		}
		else {
			Console::WriteLine("Error while loading glDeleteProgram");
		}

		glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
		if (glUniform1i != NULL)
		{
			Console::WriteLine("glUniform1i loaded");
		}
		else {
			Console::WriteLine("Error while loading glUniform1i");
		}

		glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
		if (glGetUniformLocation != NULL)
		{
			Console::WriteLine("glGetUniformLocation loaded");
		}
		else {
			Console::WriteLine("Error while loading glGetUniformLocation");
		}

		glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
		if (glActiveTexture != NULL)
		{
			Console::WriteLine("glActiveTexture loaded");
		}
		else {
			Console::WriteLine("Error while loading glActiveTexture");
		}

		glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
		if (glUniformMatrix4fv != NULL)
		{
			Console::WriteLine("glUniformMatrix4fv loaded");
		}
		else {
			Console::WriteLine("Error while loading glUniformMatrix4fv");
		}

		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
		if (wglSwapIntervalEXT != NULL)
		{
			Console::WriteLine("wglSwapIntervalEXT loaded");
		}
		else {
			Console::WriteLine("Error while loading wglSwapIntervalEXT");
		}

		glBufferSubData = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
		if (glBufferSubData != NULL)
		{
			Console::WriteLine("glBufferSubData loaded");
		}
		else {
			Console::WriteLine("Error while loading glBufferSubData");
		}

		glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
		if (glUniform1f != NULL)
		{
			Console::WriteLine("glUniform1f loaded");
		}
		else {
			Console::WriteLine("Error while loading glUniform1f");
		}

		glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
		if (glGenerateMipmap != NULL)
		{
			Console::WriteLine("glGenerateMipmap loaded");
		}
		else {
			Console::WriteLine("Error while loading glGenerateMipmap");
		}

		glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
		if (glGenFramebuffers != NULL)
		{
			Console::WriteLine("glGenFramebuffers loaded");
		}
		else {
			Console::WriteLine("Error while loading glGenFramebuffers");
		}

		glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
		if (glBindFramebuffer != NULL)
		{
			Console::WriteLine("glBindFramebuffer loaded");
		}
		else {
			Console::WriteLine("Error while loading glBindFramebuffer");
		}

		glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
		if (glCheckFramebufferStatus != NULL)
		{
			Console::WriteLine("glCheckFramebufferStatus loaded");
		}
		else {
			Console::WriteLine("Error while loading glCheckFramebufferStatus");
		}

		glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");
		if (glFramebufferTexture2D != NULL)
		{
			Console::WriteLine("glFramebufferTexture2D loaded");
		}
		else {
			Console::WriteLine("Error while loading glFramebufferTexture2D");
		}

		glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
		if (glGenRenderbuffers != NULL)
		{
			Console::WriteLine("glGenRenderbuffers loaded");
		}
		else {
			Console::WriteLine("Error while loading glGenRenderbuffers");
		}

		glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
		if (glBindRenderbuffer != NULL)
		{
			Console::WriteLine("glBindRenderbuffer loaded");
		}
		else {
			Console::WriteLine("Error while loading glBindRenderbuffer");
		}

		glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
		if (glRenderbufferStorage != NULL)
		{
			Console::WriteLine("glRenderbufferStorage loaded");
		}
		else {
			Console::WriteLine("Error while loading glRenderbufferStorage");
		}

		glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
		if (glFramebufferRenderbuffer != NULL)
		{
			Console::WriteLine("glFramebufferRenderbuffer loaded");
		}
		else {
			Console::WriteLine("Error while loading glFramebufferRenderbuffer");
		}

		glUniform3f = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
		if (glUniform3f != NULL)
		{
			Console::WriteLine("glUniform3f loaded");
		}
		else {
			Console::WriteLine("Error while loading glUniform3f");
		}

		glUniform4f = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
		if (glUniform4f != NULL) {
			Console::WriteLine("glUniform4f loaded");
		}
		else {
			Console::WriteLine("Error while loading glUniform4f");
		}

		glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)wglGetProcAddress("glBlendFuncSeparate");
		if (glBlendFuncSeparate != NULL) {
			Console::WriteLine("glBlendFuncSeparate loaded");
		}
		else {
			Console::WriteLine("Error while loading glBlendFuncSeparate");
		}

		glBlendEquation = (PFNGLBLENDEQUATIONPROC)wglGetProcAddress("glBlendEquation");
		if (glBlendEquation != NULL) {
			Console::WriteLine("glBlendEquation loaded");
		}
		else {
			Console::WriteLine("Error while loading glBlendEquation");
		}

		glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)wglGetProcAddress("glVertexAttribDivisor");
		if (glVertexAttribDivisor != NULL) {
			Console::WriteLine("glVertexAttribDivisor loaded");
		}
		else {
			Console::WriteLine("Error while loading glVertexAttribDivisor");
		}

		glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)wglGetProcAddress("glDrawArraysInstanced");
		if (glDrawArraysInstanced != NULL) {
			Console::WriteLine("glDrawArraysInstanced loaded");
		}
		else {
			Console::WriteLine("Error while loading glDrawArraysInstanced");
		}

		glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
		if (glDeleteFramebuffers != NULL) {
			Console::WriteLine("glDeleteFramebuffers loaded");
		}
		else {
			Console::WriteLine("Error while loading glDeleteFramebuffers");
		}

		glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");
		if (glDeleteRenderbuffers != NULL) {
			Console::WriteLine("glDeleteRenderbuffers loaded");
		}
		else {
			Console::WriteLine("Error while loading glDeleteRenderbuffers");
		}

		glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)wglGetProcAddress("glDrawArraysInstanced");
		if (glDrawArraysInstanced != NULL) {
			Console::WriteLine("glDrawArraysInstanced loaded");
		}
		else {
			Console::WriteLine("Error while loading glDrawArraysInstanced");
		}

		Console::WriteLine("ModernGL Loaded!");
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

	void NetGL::OpenGL::DisableVertexAttribArray(int index)
	{
		glDisableVertexAttribArray(index);
	}

	void NetGL::OpenGL::VertexAttribPointer(int index, int size, int type, bool normalized, int stride, int pointer)
	{
		glVertexAttribPointer(index, size, type, normalized, stride, (void*)pointer);
	}

	void NetGL::OpenGL::VertexAttribPointer(int index, int size, int type, bool normalized, int stride, IntPtr pointer)
	{
		glVertexAttribPointer(index, size, type, normalized, stride, (void*)pointer);
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

	void NetGL::OpenGL::VertexAtrribIPointer(int index, int size, int type, int stride, int pointer)
	{
		glVertexAttribIPointer(index, size, type, stride, (void*) pointer);
	}

	void NetGL::OpenGL::VertexAtrribIPointer(int index, int size, int type, int stride, IntPtr pointer)
	{
		glVertexAttribIPointer(index, size, type, stride, (void*)pointer);
	}

	void NetGL::OpenGL::DeleteVertexArrays(int n, int BufferID)
	{
		const GLuint i = BufferID;
		glDeleteVertexArrays(n, &i);
	}

	void OpenGL::VertexAttribDivisor(int index, int divisor)
	{
		glVertexAttribDivisor(index, divisor);
	}

	void NetGL::OpenGL::LookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) 
	{
		gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
	}

	void NetGL::OpenGL::Frustum(float left, float right, float bottom, float top, float znear, float zfar) 
	{
		glFrustum(left, right, bottom, top, znear, zfar);
	}

	void NetGL::OpenGL::Perspective(float fov, float aspect, float znear, float zfar) 
	{
		gluPerspective(fov, aspect, znear, zfar);
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

	void NetGL::OpenGL::BlendFuncSeparate(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha)
	{
		glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
	}

	void NetGL::OpenGL::LineWidth(float width) {
		glLineWidth(width);
	}

	int NetGL::OpenGL::CreateShader(int type) {
		GLuint id;
		id = glCreateShader(type);
		return (int) id;
	}

	void NetGL::OpenGL::SetShaderSource(int shader, int count, String^ source) 
	{
		const char* sourceCode = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(source)).ToPointer();
		glShaderSource(shader, count, &sourceCode, nullptr);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)sourceCode));
	}

	void NetGL::OpenGL::CompileShader(int shader)
	{
		glCompileShader(shader);
	}

	int NetGL::OpenGL::CreateProgram() 
	{
		GLuint id;
		id = glCreateProgram();
		return (int)id;
	}

	void NetGL::OpenGL::AttachShader(int shaderProgram, int shader)
	{
		glAttachShader(shaderProgram, shader);
	}

	void NetGL::OpenGL::LinkProgram(int shaderProgram)
	{
		glLinkProgram(shaderProgram);
	}

	void NetGL::OpenGL::UseProgram(int shaderProgram)
	{
		glUseProgram(shaderProgram);
	}

	void NetGL::OpenGL::DeleteShader(int shader)
	{
		glDeleteShader(shader);
	}

	void NetGL::OpenGL::DeleteProgram(int program)
	{
		glDeleteProgram(program);
	}

	void NetGL::OpenGL::Uniform1I(int location, int v0)
	{
		glUniform1i(location, v0);
	}

	void NetGL::OpenGL::Uniform1f(int location, float value) {
		glUniform1f(location, value);
	}

	int NetGL::OpenGL::GetUniformLocation(int program, String^ name)
	{
		const char* cname = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(name)).ToPointer();
		GLuint location;
		location = glGetUniformLocation(program, cname);
		System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)cname));
		return location;
	}

	void NetGL::OpenGL::ActiveTexture(int texture)
	{
		glActiveTexture(texture);
	}

	array<float>^ NetGL::OpenGL::GetFloatArray(int name, int size)
	{
		float* result = new float[size];
		glGetFloatv(name, result);

		array<float>^ managedArray = gcnew array<float>(size);
		System::Runtime::InteropServices::Marshal::Copy(IntPtr(result), managedArray, 0, size);
		delete[] result;

		return managedArray;
	}

	void NetGL::OpenGL::UniformMatrix4fv(int location, int count, bool transpose, array<float>^ matrixData) 
	{
		pin_ptr<float> pinnedArray = &matrixData[0];
		glUniformMatrix4fv(location, count, transpose, pinnedArray);
	}

	void NetGL::OpenGL::SetModelviewMatrix(int location, int count, bool transpose)
	{
		float* result = new float[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, result);
		glUniformMatrix4fv(location, count, transpose, result);
		delete[] result;
	}

	void NetGL::OpenGL::SetProjectionMatrix(int location, int count, bool transpose)
	{
		float* result = new float[16];
		glGetFloatv(GL_PROJECTION_MATRIX, result);
		glUniformMatrix4fv(location, count, transpose, result);
		delete[] result;
	}

	void NetGL::OpenGL::SwapIntervalEXT(int interval) 
	{
		wglSwapIntervalEXT(interval);
	}

	void NetGL::OpenGL::GlCullFace(int mode) 
	{
		glCullFace(mode);
	}

	void NetGL::OpenGL::DepthFunc(int mode) 
	{
		glDepthFunc(mode);
	}

	void NetGL::OpenGL::GenerateMipMap(int target) 
	{
		glGenerateMipmap(target);
	}

	int NetGL::OpenGL::GenFramebuffers(int n) 
	{
		GLuint ID;
		glGenFramebuffers(n, &ID);
		return (int)ID;
	}

	void NetGL::OpenGL::BindFramebuffer(int target, int id)
	{
		glBindFramebuffer(target, id);
	}

	int NetGL::OpenGL::CheckFramebufferStatus(int target) {
		return glCheckFramebufferStatus(target);
	}

	void NetGL::OpenGL::FrameBufferTexture2D(int target, int attachment, int textarage, int texture, int level)
	{
		glFramebufferTexture2D(target, attachment, textarage, texture, level);
	}

	void NetGL::OpenGL::DrawPixels(int width, int height, int format, int type)
	{
		glDrawPixels(width, height, format, type, nullptr);
	}

	int NetGL::OpenGL::GenRenderbuffers(int n)
	{
		GLuint ID;
		glGenRenderbuffers(n, &ID);
		return (int)ID;
	}
	void NetGL::OpenGL::BindRenderbuffer(int target, int id)
	{
		glBindRenderbuffer(target, id);
	}

	void NetGL::OpenGL::RenderbufferStorage(int target, int internalFormat, int width, int height)
	{
		glRenderbufferStorage(target, internalFormat, width, height);
	}
	
	void NetGL::OpenGL::FramebufferRenderbuffer(int target, int attachment, int renderBufferTarget, int renderBuffer)
	{
		glFramebufferRenderbuffer(target, attachment, renderBufferTarget, renderBuffer);
	}

	void NetGL::OpenGL::Uniform3f(int location, float x, float y, float z) 
	{
		glUniform3f(location, x, y, z);
	}

	void OpenGL::Uniform4f(int location, float x, float y, float z, float w)
	{
		glUniform4f(location, x, y, z, w);
	}

	void NetGL::OpenGL::DrawBuffer(int buf) 
	{
		glDrawBuffer(buf);
	}

	void NetGL::OpenGL::ReadBuffer(int mode)
	{
		glReadBuffer(mode);
	}

	void OpenGL::DeleteFramebuffers(int n, int buffer)
	{
		const GLuint gl_buffer = buffer;
		glDeleteBuffers(n, &gl_buffer);
	}

	void OpenGL::DeleteRenderbuffers(int n, int buffer)
	{
		const GLuint gl_buffer = buffer;
		glDeleteFramebuffers(n, &gl_buffer);
	}

	void NetGL::OpenGL::ColorMask(bool red, bool green, bool blue, bool alpha) {
		glColorMask(red, green, blue, alpha);
	}

	void OpenGL::BlendEquation(int mode)
	{
		glBlendEquation(mode);
	}

}