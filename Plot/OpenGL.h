#pragma once

#include <string>
#include <windows.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <glm.hpp>
#include "Graphing.h"

using namespace System;
using namespace System::Windows::Forms;

namespace OpenGLForm
{
	public ref class COpenGL : public System::Windows::Forms::NativeWindow
	{
	public:
		COpenGL(System::Windows::Forms::GroupBox ^ parentForm, GLsizei iWidth, GLsizei iHeight);	// Constructor

		Void SwapOpenGLBuffers();

		Void Render();
		Void MouseEvents(System::Windows::Forms::Label^ label, System::Windows::Forms::GroupBox^ Container);

		Void cameraViewLabel(System::Windows::Forms::ToolStripStatusLabel^ label);

		HDC getHDC(){
			return m_hDC;
		}


	private:
		HDC m_hDC;
		HGLRC m_hglrc;
		

	protected:
		~COpenGL();	// Destroyer

		bool InitGL();	// Initialize OpenGL settings
		bool InitUserSettings(); // Inititalize user settings

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height); // Resize and initialise the gl window
		GLint MySetPixelFormat(HDC hdc);	// Pixel format

	};
}