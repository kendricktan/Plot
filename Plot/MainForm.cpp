#include "MainForm.h"

using namespace Plot;

[STAThreadAttribute]

int main(array<System::String ^> ^args){
	graphList = new GraphList[MAX_NO_GRAPHS];	// Initializes new graphing list

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MainForm());
	return 0;
}

Void MainForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e){
	UNREFERENCED_PARAMETER(sender);
	UNREFERENCED_PARAMETER(e);
	OpenGL->Render();
	OpenGL->SwapOpenGLBuffers();
	OpenGL->MouseEvents(debugLabel, OpenGL_Container);
	OpenGL->cameraViewLabel(cameraStatusStrip);
}

Void MainForm::debugButton_Click(System::Object^  sender, System::EventArgs^  e){
}

Void MainForm::defaultView_Click(System::Object^  sender, System::EventArgs^  e){
	minView.x = -10;
	minView.y = -10;
	minView.z = -10;

	maxView.x = 10;
	maxView.y = 10;
	maxView.z = 10;

	resultDif.x = 0;
	resultDif.y = 0;
	resultDif.z = 0;

	mouseDif.x = 0;
	mouseDif.y = 0;
	mouseDif.z = 0;

	translateDif.x = 0;
	translateDif.y = 0;

	translateResult.x = 0;
	translateResult.y = 0;
}

Void MainForm::equationTextbox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e){
	if (e->KeyChar == (char)13){
		if (equationTextbox->Text != ""){
			plotButton->PerformClick();
		}
	}
}

Void MainForm::plotButton_Click(System::Object^  sender, System::EventArgs^  e){
	

	// Check if graph is complex graph
	graphList[curGraphNo].isComplex = isComplexCheckBox->Checked;
	graphList[curGraphNo].isComplexCubic = cubicRadio->Checked;
	
	graphList[curGraphNo].r = randomFloat(0, 1);
	graphList[curGraphNo].g = randomFloat(0, 1);
	graphList[curGraphNo].b = randomFloat(0, 1);

	graphList[curGraphNo].plotRange = abs(minView.x) + abs(maxView.x) + 2;
	graphList[curGraphNo].plotRange *= graphDensity;	// Calculates the density of the graph
	if (!graphList[curGraphNo].isComplex){
		graphList[curGraphNo].plotRange *= graphList[curGraphNo].plotRange;	// Squares the number of coordinates required because its a 3D graph
	}

	graphList[curGraphNo].parsedCoordinates = new Coordinates[(int)graphList[curGraphNo].plotRange];	// Initializes the new array size

	// Initializes complex graphs
	if (graphList[curGraphNo].isComplex){
		graphList[curGraphNo].complexCoordinates = new Coordinates[(int)graphList[curGraphNo].plotRange];
	}

	if (graphList[curGraphNo].isComplexCubic){
		graphList[curGraphNo].complexCoordinatesCubic = new Coordinates[(int)graphList[curGraphNo].plotRange];
	}

	bIsDoneParsing = false;

	// If its not a complex graph
	if (!graphList[curGraphNo].isComplex){
		size_t strPlace = 0;

		std::string str, strSubject, strEquation;	// str = full string, strSubject = Subject variable, strEquation = equation only
		MarshalString(equationTextbox->Text, str);	// Converts string in textbox in form to std:;string

		// Splits the equation into blah with respect to blah (for easier parsing)
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);	// Converts to lowercase
		removeWhitespace(str);
		strPlace = str.find("=");

		// Checks if there is any '=', if not then prompts the user to enter for one
		if (strPlace == -1){
			MessageBox::Show("Could not find a '=' sign in the equation given. Please recheck the inputted equation.");
			return;
		}

		// If first place isn't x, y, or z then parsing WILL fail, therefore prompt user
		// and exit
		/*if (!str.at(0).Equals("x") && !str.at(0).Equals("y") && !str.at(0).Equals("z")){
			MessageBox::Show("Incorrect maths equation format. Please use a format like: 'y=sin(x)+cos(z)'");
			return;
		}*/

		strSubject = str.substr(0, strPlace);
		strEquation = str.substr(strPlace + 1);

		/* Everything happens here */
		parseEquation<float>(strSubject, strEquation);	// Parses the string 

		graphListView->Items->Add(gcnew String(str.c_str()));
		graphListView->Items[curGraphNo]->ForeColor = Color::FromArgb(1, (int)(graphList[curGraphNo].r * 255), (int)(graphList[curGraphNo].g * 255), (int)(graphList[curGraphNo].b * 255));
	}

	// Quadratic complex graph
	else if (graphList[curGraphNo].isComplex && quadraticRadio->Checked){
		std::string str, strOne, strTwo, strThree, strFour, strComplex;

		MarshalString(complexTxtbox1->Text, strOne);
		MarshalString(complexTxtbox2->Text, strTwo);
		MarshalString(complexTxtbox3->Text, strThree);
		MarshalString(complexTxtbox4->Text, strFour);

		float xPos = (float)Convert::ToInt32(complexTxtbox2->Text);
		xPos = -xPos;

		str = "(" + strOne + "x+" + strTwo + ")^" + strThree + "+" + strFour;
		strComplex = "-(" + strOne + "z+" + strTwo + ")^" + strThree + "+" + strFour;

		removeWhitespace(str);
		removeWhitespace(strComplex);

		parseEquation<float>("y", str);
		parseComplexEquation<float>(strComplex, xPos);

		str = "[C] y=" + str;

		graphListView->Items->Add(gcnew String(str.c_str()));
		graphListView->Items[curGraphNo]->ForeColor = Color::FromArgb(1, (int)(graphList[curGraphNo].r * 255), (int)(graphList[curGraphNo].g * 255), (int)(graphList[curGraphNo].b * 255));
	}

	// Cubic complex graph
	else if (graphList[curGraphNo].isComplex && cubicRadio->Checked){
		std::string str, strOne, strTwo, strThree, strFour, strComplex, strComplexCubic;

		MarshalString(complexTxtbox1->Text, strOne);
		MarshalString(complexTxtbox2->Text, strTwo);
		MarshalString(complexTxtbox3->Text, strThree);
		MarshalString(complexTxtbox4->Text, strFour);

		float xPos = (float)Convert::ToInt32(complexTxtbox2->Text);
		float xPosFix = (float)Convert::ToInt32(complexTxtbox1->Text);
		xPos = -xPos;

		str = "(" + strOne + "x+" + strTwo + ")^" + strThree + "+" + strFour;
		strComplex = "(" + strOne + "z+" + strTwo + ")^2+" + strFour;
		strComplexCubic = "-(" + strOne + "z+" + strTwo + ")^2+" + strFour;

		removeWhitespace(str);
		removeWhitespace(strComplex);
		removeWhitespace(strComplexCubic);

		parseEquation<float>("y", str);
		parseComplexEquation<float>(strComplex, xPos - (xPosFix / 2));
		parseComplexEquationCubic<float>(strComplexCubic, xPos + (xPosFix / 2));

		str = "[C] y=" + str;

		graphListView->Items->Add(gcnew String(str.c_str()));
		graphListView->Items[curGraphNo]->ForeColor = Color::FromArgb(1, (int)(graphList[curGraphNo].r * 255), (int)(graphList[curGraphNo].g * 255), (int)(graphList[curGraphNo].b * 255));
	}

	bIsDoneParsing = true;

	curGraphNo++;

	debugLabel->Text = curGraphNo.ToString();
}

Void MainForm::clearAllButton_Click(System::Object^  sender, System::EventArgs^  e){
	curGraphNo = 0;
	graphListView->Items->Clear();
}

Void MainForm::removeSelectedButton_Click(System::Object^  sender, System::EventArgs^  e){
	int index = -1;

	for (int i = 0; i < graphListView->Items->Count; i++){
		if (graphListView->Items[i]->Selected){
			index = i;
			break;
		}
	}

	if (index != -1){
		graphListView->Items[index]->Remove();

		// We're reorganizing our graphList
		for (int i = index; i < curGraphNo; i++){
			graphList[i] = graphList[i + 1];
		}

		curGraphNo--;	// Remove current no of graphs
	}
}

Void MainForm::toggleColorButton_Click(System::Object^  sender, System::EventArgs^  e){
	int index = -1;

	for (int i = 0; i < graphListView->Items->Count; i++){
		if (graphListView->Items[i]->Selected){
			index = i;
			break;
		}
	}

	if (index != -1){
		graphList[index].r = randomFloat(0, 1);
		graphList[index].g = randomFloat(0, 1);
		graphList[index].b = randomFloat(0, 1);

		graphListView->Items[index]->ForeColor = Color::FromArgb(1, (int)(graphList[index].r * 255), (int)(graphList[index].g * 255), (int)(graphList[index].b * 255));
	}
}

// 3D graph density
Void MainForm::graphDensityBar_Scroll(System::Object^  sender, System::EventArgs^  e){
	graphDensity = graphDensityBar->Value;
}

// Decrease view
Void MainForm::decreaseView_Click(System::Object^  sender, System::EventArgs^  e){
	if (minView.x + 5 < maxView.x - 5){
		minView.x += 5;
		maxView.x -= 5;
	}
	if (minView.y + 5 < maxView.y - 5){
		minView.y += 5;
		maxView.y -= 5;
	}

	if (minView.z + 5 < maxView.z - 5){
		maxView.z -= 5;
		minView.z += 5;
	}

	if(mouseDif.z - 10 > 20)
		mouseDif.z -= 15;
}

// Increase view
Void MainForm::increaseView_Click(System::Object^  sender, System::EventArgs^  e){
	minView.x -= 5;
	minView.y -= 5;
	minView.z -= 5;

	maxView.x += 5;
	maxView.y += 5;
	maxView.z += 5;

	mouseDif.z += 15;
}

Void MainForm::isComplexCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	equationTextbox->Visible = !isComplexCheckBox->Checked;
}

// Takes screenshot
Void MainForm::copyToClipboardToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	int width = OpenGL_Container->Width;
	int height = OpenGL_Container->Height;

	//create
	HDC hdcParent = OpenGL->getHDC();
	HDC hdc = CreateCompatibleDC(hdcParent);
	HBITMAP hBmp = CreateCompatibleBitmap(hdcParent, width, height);
	SelectObject(hdc, hBmp);


	//copy to clipboard
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_BITMAP, hBmp);
	CloseClipboard();
}