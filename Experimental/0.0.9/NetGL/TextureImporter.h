#pragma once
#include "NetGL.h"

namespace NetGL {
	namespace Toolkit {
		public ref class TextureImporter
		{
		public:
			int TextureID;
			int ImageFormat = NetGL::OpenGL::BGRAExt;
			TextureImporter(void);
			TextureImporter(System::Drawing::Bitmap^ Texture);
			void BindTexture(OpenGL^ opengl);
			void DeleteTexture(OpenGL^ opengl);

			static int BindTexture(OpenGL^ gl, int imageFormat, System::Drawing::Bitmap^ texture);
		private:
			System::Drawing::Bitmap^ Bitmap;
		};
	}
}

