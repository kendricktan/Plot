#include "OpenGL.h"

using namespace OpenGLForm;

/* Things to do
1. Include a plane [/]
2. Graph 3D graph [/]
3. Graph 3D graph w/ fixed equation [/]
4. Graph 3D graph w/ plotted equation [/]
5. Graph 3D graph w/ any variable in respect to any variable (e.g y=12*x+2; x = 5; z= 5, etc...) [/]
6. Graph multiple 3D graphs  [/]
7. Graph Complex graph	[/]
8. Graph Complex Cubic graph 
8. Aargand Diagram
*/

void renderText(char *txt, float x, float y, float z)
{
	char text[32];
	sprintf_s(text, txt);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos3f(x, y, z);
	for (int i = 0; text[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}


// Constructor
COpenGL::COpenGL(System::Windows::Forms::GroupBox ^ parentForm, GLsizei iWidth, GLsizei iHeight)
{
	CreateParams^ cp = gcnew CreateParams;

	// Set the position on the form
	cp->X = 0;
	cp->Y = 0;
	cp->Height = iHeight;
	cp->Width = iWidth;

	// Specify the form as the parent.
	cp->Parent = parentForm->Handle;

	// Create as a child of the specified parent and make OpenGL compliant (no clipping)
	cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	// Create the actual window
	this->CreateHandle(cp);

	m_hDC = GetDC((HWND)this->Handle.ToPointer());

	if (m_hDC)
	{
		MySetPixelFormat(m_hDC);
		ReSizeGLScene(iWidth, iHeight);
		InitGL();
		InitUserSettings();
	}
}

// Destroyer
COpenGL::~COpenGL()
{
	this->DestroyHandle();
}

// Buffer swapper
void COpenGL::SwapOpenGLBuffers()
{
	SwapBuffers(m_hDC);
}

// Initialize other settings
bool COpenGL::InitGL(){								// All setup for opengl goes here
	glShadeModel(GL_SMOOTH);							// Enable smooth shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black background
	glClearDepth(1.0f);									// Depth buffer setup
	glEnable(GL_DEPTH_TEST);							// Enables depth testing
	glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations

	return true;										// Initialisation went ok
}

// Resize and initialise the gl window
GLvoid COpenGL::ReSizeGLScene(GLsizei width, GLsizei height)		
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

// Set pixel format
GLint COpenGL::MySetPixelFormat(HDC hdc)
{
	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		16,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	GLint  iPixelFormat;

	// get the device context's best, available pixel format match 
	if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
	{
		MessageBox::Show("ChoosePixelFormat Failed");
		return 0;
	}

	// make that match the device context's current pixel format 
	if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
	{
		MessageBox::Show("SetPixelFormat Failed");
		return 0;
	}

	if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
	{
		MessageBox::Show("wglCreateContext Failed");
		return 0;
	}

	if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
	{
		MessageBox::Show("wglMakeCurrent Failed");
		return 0;
	}


	return 1;
}

bool COpenGL::InitUserSettings(){
	minView.x = -10;
	minView.y = -10;
	minView.z = -10;

	maxView.x = 10;
	maxView.y = 10;
	maxView.z = 10;

	return true;
}

// Mouse even handler
void COpenGL::MouseEvents(System::Windows::Forms::Label^ label, System::Windows::Forms::GroupBox^ Container){
	POINT mouse;	// Stores the X and Y coords for the current mouse
	GetCursorPos(&mouse);	// Gets the current cursor coordinates (mouse coordinates)

	ScreenToClient((HWND)this->Handle.ToPointer(), &mouse);	// Gets coordinates of the specified point (OpenGL window)

	// If within the OpenGL window
	if (mouse.x > 0 && mouse.y > 0 && mouse.x < Container->Width && mouse.y < Container->Height){
		
		// If Mouse down without holding control key
		if (GetAsyncKeyState(VK_LBUTTON) && !GetAsyncKeyState(VK_CONTROL)){

			if (mouseCoord.x == 0 && mouseCoord.y == 0){
				mouseCoord.x = (float)mouse.x;
				mouseCoord.y = (float)mouse.y;
			}

			mouseDif.x = resultDif.x + mouse.x - mouseCoord.x;
			mouseDif.y = resultDif.y + mouse.y - mouseCoord.y;
		}

		else if (GetAsyncKeyState(VK_RBUTTON)){
			if (mouseCoord.x == 0 && mouseCoord.y == 0){
				mouseCoord.x = (float)mouse.x;
				mouseCoord.y = (float)mouse.y;
			}

			translateDif.x = translateResult.x + mouse.x - mouseCoord.x;
			translateDif.y = translateResult.y + mouse.y- mouseCoord.y;
		}

		else if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_CONTROL)){
			// We're going to use mouse y to change the z axis of the plotter
			if (mouseCoord.z == 0){
				mouseCoord.z = (float)mouse.y;
			}

			mouseDif.z = resultDif.z + mouse.y - mouseCoord.z;
		}

		// Resets everything
		else{
			mouseCoord.x = 0;
			mouseCoord.y = 0;
			mouseCoord.z = 0;

			resultDif.x = mouseDif.x;
			resultDif.y = mouseDif.y;
			resultDif.z = mouseDif.z;

			translateResult.x = translateDif.x;
			translateResult.y = translateDif.y;
			//translateResult.z = translateDif.z;
		}
	}

}

void COpenGL::Render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
	glLoadIdentity();									// Reset the current modelview matrix
	glTranslatef(0.f, 0.0f, -50.0f);						// Zoom out by 50 units

	// Zooms in/out + Pans
	glTranslatef(translateDif.x*0.05, -translateDif.y*0.05, -mouseDif.z*0.5f);

	// Rotates object
	glRotatef(mouseDif.y, 1.0f, 0, 0);
	glRotatef(mouseDif.x, 0, 1.0f, 0);

	// Renders axis label
	renderText("-x", minView.x - fontDistance, 0, 0);
	renderText("x", maxView.x + fontDistance, 0, 0);

	renderText("-y", 0, minView.y - fontDistance, 0);
	renderText("y", 0, maxView.y + fontDistance, 0);

	renderText("-z", 0, 0, minView.z - fontDistance);
	renderText("z", 0, 0, maxView.z + fontDistance);


	// Draws plane
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
		// X plane
		for (float x = minView.x; x <= maxView.x; x++){
			glVertex3f(x, minView.y, 0.0f);
			glVertex3f(x, maxView.y, 0.0f);

			glVertex3f(x, 0, minView.z);
			glVertex3f(x, 0, maxView.z);
		}
		// Y planes
		for (float y = minView.y; y <= maxView.y; y++){
			glVertex3f(minView.x, y, 0.0f);
			glVertex3f(maxView.x, y, 0.0f);

			glVertex3f(0, y, minView.z);
			glVertex3f(0, y, maxView.z);
		}
		// Z plane
		for (float z = minView.z; z <= maxView.z; z++){
			glVertex3f(0, minView.y, z);
			glVertex3f(0, maxView.y, z);

			glVertex3f(minView.x, 0, z);
			glVertex3f(maxView.x, 0, z);
		}
		
	glEnd();

	if (bIsDoneParsing){
			glPointSize(3.5f);

		glBegin(GL_POINTS);
		
		// Normal graphs
		for (int k = 0; k < curGraphNo; k++){
			glColor3f(graphList[k].r, graphList[k].g, graphList[k].b);
			for (int i = 0; i <= graphList[k].plotRange; i++){
				if (graphList[k].parsedCoordinates[i].x >= minView.x && graphList[k].parsedCoordinates[i].x <= maxView.x)
					if (graphList[k].parsedCoordinates[i].y >= minView.y && graphList[k].parsedCoordinates[i].y <= maxView.y)
						if (graphList[k].parsedCoordinates[i].z >= minView.z && graphList[k].parsedCoordinates[i].z <= maxView.z)
							glVertex3f(graphList[k].parsedCoordinates[i].x, graphList[k].parsedCoordinates[i].y, graphList[k].parsedCoordinates[i].z);
			}
		}

		// Complex graphs
		for (int k = 0; k < curGraphNo; k++){
			glColor3f(graphList[k].r, graphList[k].g, graphList[k].b);
			if (graphList[k].isComplex){
				for (int i = 0; i <= graphList[k].plotRange; i++){
					if (graphList[k].complexCoordinates[i].x >= minView.x && graphList[k].complexCoordinates[i].x <= maxView.x)
						if (graphList[k].complexCoordinates[i].y >= minView.y && graphList[k].complexCoordinates[i].y <= maxView.y)
							if (graphList[k].complexCoordinates[i].z >= minView.z && graphList[k].complexCoordinates[i].z <= maxView.z)
								glVertex3f(graphList[k].complexCoordinates[i].x, graphList[k].complexCoordinates[i].y, graphList[k].complexCoordinates[i].z);
				}
			}
		}
		
		// Complex cubic graphs
		for (int k = 0; k < curGraphNo; k++){
			glColor3f(graphList[k].r, graphList[k].g, graphList[k].b);
			if (graphList[k].isComplexCubic){
				for (int i = 0; i <= graphList[k].plotRange; i++){
					if (graphList[k].complexCoordinatesCubic[i].x >= minView.x && graphList[k].complexCoordinatesCubic[i].x <= maxView.x)
						if (graphList[k].complexCoordinatesCubic[i].y >= minView.y && graphList[k].complexCoordinatesCubic[i].y <= maxView.y)
							if (graphList[k].complexCoordinatesCubic[i].z >= minView.z && graphList[k].complexCoordinatesCubic[i].z <= maxView.z)
								glVertex3f(graphList[k].complexCoordinatesCubic[i].x, graphList[k].complexCoordinatesCubic[i].y, graphList[k].complexCoordinatesCubic[i].z);
				}
			}
		}


		glEnd();
	}

}

Void COpenGL::cameraViewLabel(System::Windows::Forms::ToolStripStatusLabel^ label){
	label->Text = "Camera - x:" + mouseDif.x.ToString() + " y: " + mouseDif.y.ToString() + " z: " + mouseDif.z.ToString();
}