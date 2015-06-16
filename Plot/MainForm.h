#pragma once

#include <string>
#include <iostream>
#include "OpenGL.h"
#include "Functions.h"
#include "Graphing.h"
#include "GraphProperties.h"

namespace Plot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			OpenGL = gcnew COpenGL(this->OpenGL_Container, this->OpenGL_Container->Width, this->OpenGL_Container->Height);
			graphProperties = gcnew GraphProperties();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::GroupBox^  OpenGL_Container;

	private: System::Windows::Forms::TextBox^  equationTextbox;
	private: System::Windows::Forms::Button^  plotButton;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  removeSelectedButton;
	private: System::Windows::Forms::Button^  clearAllButton;
	private: System::Windows::Forms::ListView^  graphListView;

	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  cameraStatusStrip;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  debugButton;

	private: System::Windows::Forms::Label^  debugLabel;
	private: System::Windows::Forms::Button^  toggleColorButton;

	private: System::Windows::Forms::Button^  defaultView;
	private: System::Windows::Forms::TrackBar^  graphDensityBar;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  increaseView;

	private: System::Windows::Forms::Button^  decreaseView;
	private: System::Windows::Forms::CheckBox^  isComplexCheckBox;
	private: System::Windows::Forms::TextBox^  complexTxtbox2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  complexTxtbox3;

	private: System::Windows::Forms::TextBox^  complexTxtbox1;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  complexTxtbox4;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tutorialToolStripMenuItem;

	private: OpenGLForm::COpenGL ^ OpenGL;
	private: System::Windows::Forms::ToolStripMenuItem^  graphPropertiesToolStripMenuItem;
	private: System::Windows::Forms::RadioButton^  cubicRadio;
	private: System::Windows::Forms::RadioButton^  quadraticRadio;

	private: GraphProperties^ graphProperties;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->OpenGL_Container = (gcnew System::Windows::Forms::GroupBox());
			this->equationTextbox = (gcnew System::Windows::Forms::TextBox());
			this->plotButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->toggleColorButton = (gcnew System::Windows::Forms::Button());
			this->removeSelectedButton = (gcnew System::Windows::Forms::Button());
			this->clearAllButton = (gcnew System::Windows::Forms::Button());
			this->graphListView = (gcnew System::Windows::Forms::ListView());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->cameraStatusStrip = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->cubicRadio = (gcnew System::Windows::Forms::RadioButton());
			this->quadraticRadio = (gcnew System::Windows::Forms::RadioButton());
			this->isComplexCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->graphDensityBar = (gcnew System::Windows::Forms::TrackBar());
			this->debugLabel = (gcnew System::Windows::Forms::Label());
			this->debugButton = (gcnew System::Windows::Forms::Button());
			this->defaultView = (gcnew System::Windows::Forms::Button());
			this->increaseView = (gcnew System::Windows::Forms::Button());
			this->decreaseView = (gcnew System::Windows::Forms::Button());
			this->complexTxtbox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->complexTxtbox3 = (gcnew System::Windows::Forms::TextBox());
			this->complexTxtbox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->complexTxtbox4 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->graphPropertiesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tutorialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graphDensityBar))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// OpenGL_Container
			// 
			this->OpenGL_Container->Location = System::Drawing::Point(13, 61);
			this->OpenGL_Container->Name = L"OpenGL_Container";
			this->OpenGL_Container->Size = System::Drawing::Size(700, 555);
			this->OpenGL_Container->TabIndex = 0;
			this->OpenGL_Container->TabStop = false;
			this->OpenGL_Container->Text = L"OpenGL Container";
			// 
			// equationTextbox
			// 
			this->equationTextbox->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->equationTextbox->Location = System::Drawing::Point(77, 32);
			this->equationTextbox->Name = L"equationTextbox";
			this->equationTextbox->Size = System::Drawing::Size(283, 22);
			this->equationTextbox->TabIndex = 2;
			this->equationTextbox->Text = L"y=cos(x)+sin(z)";
			this->equationTextbox->TextChanged += gcnew System::EventHandler(this, &MainForm::equationTextbox_TextChanged);
			this->equationTextbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::equationTextbox_KeyPress);
			// 
			// plotButton
			// 
			this->plotButton->Location = System::Drawing::Point(365, 32);
			this->plotButton->Name = L"plotButton";
			this->plotButton->Size = System::Drawing::Size(82, 23);
			this->plotButton->TabIndex = 3;
			this->plotButton->Text = L"Plot";
			this->plotButton->UseVisualStyleBackColor = true;
			this->plotButton->Click += gcnew System::EventHandler(this, &MainForm::plotButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 14);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Equation:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->toggleColorButton);
			this->groupBox1->Controls->Add(this->removeSelectedButton);
			this->groupBox1->Controls->Add(this->clearAllButton);
			this->groupBox1->Controls->Add(this->graphListView);
			this->groupBox1->Location = System::Drawing::Point(720, 37);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(196, 436);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Displayed Graphs";
			// 
			// toggleColorButton
			// 
			this->toggleColorButton->Location = System::Drawing::Point(5, 349);
			this->toggleColorButton->Name = L"toggleColorButton";
			this->toggleColorButton->Size = System::Drawing::Size(185, 23);
			this->toggleColorButton->TabIndex = 3;
			this->toggleColorButton->Text = L"Toggle Selected Color";
			this->toggleColorButton->UseVisualStyleBackColor = true;
			this->toggleColorButton->Click += gcnew System::EventHandler(this, &MainForm::toggleColorButton_Click);
			// 
			// removeSelectedButton
			// 
			this->removeSelectedButton->Location = System::Drawing::Point(6, 378);
			this->removeSelectedButton->Name = L"removeSelectedButton";
			this->removeSelectedButton->Size = System::Drawing::Size(184, 23);
			this->removeSelectedButton->TabIndex = 2;
			this->removeSelectedButton->Text = L"Remove Selected";
			this->removeSelectedButton->UseVisualStyleBackColor = true;
			this->removeSelectedButton->Click += gcnew System::EventHandler(this, &MainForm::removeSelectedButton_Click);
			// 
			// clearAllButton
			// 
			this->clearAllButton->Location = System::Drawing::Point(6, 407);
			this->clearAllButton->Name = L"clearAllButton";
			this->clearAllButton->Size = System::Drawing::Size(184, 23);
			this->clearAllButton->TabIndex = 1;
			this->clearAllButton->Text = L"Clear All";
			this->clearAllButton->UseVisualStyleBackColor = true;
			this->clearAllButton->Click += gcnew System::EventHandler(this, &MainForm::clearAllButton_Click);
			// 
			// graphListView
			// 
			this->graphListView->AutoArrange = false;
			this->graphListView->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graphListView->LabelWrap = false;
			this->graphListView->Location = System::Drawing::Point(6, 21);
			this->graphListView->Name = L"graphListView";
			this->graphListView->Size = System::Drawing::Size(184, 322);
			this->graphListView->TabIndex = 0;
			this->graphListView->UseCompatibleStateImageBehavior = false;
			this->graphListView->View = System::Windows::Forms::View::List;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->cameraStatusStrip });
			this->statusStrip1->Location = System::Drawing::Point(0, 627);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(927, 22);
			this->statusStrip1->TabIndex = 7;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// cameraStatusStrip
			// 
			this->cameraStatusStrip->Name = L"cameraStatusStrip";
			this->cameraStatusStrip->Size = System::Drawing::Size(117, 17);
			this->cameraStatusStrip->Text = L"Camera - x: 0 y: 0 z: 0";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->cubicRadio);
			this->groupBox2->Controls->Add(this->quadraticRadio);
			this->groupBox2->Controls->Add(this->isComplexCheckBox);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->graphDensityBar);
			this->groupBox2->Location = System::Drawing::Point(720, 479);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(196, 137);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Graph Properties";
			// 
			// cubicRadio
			// 
			this->cubicRadio->AutoSize = true;
			this->cubicRadio->Location = System::Drawing::Point(29, 110);
			this->cubicRadio->Name = L"cubicRadio";
			this->cubicRadio->Size = System::Drawing::Size(54, 18);
			this->cubicRadio->TabIndex = 15;
			this->cubicRadio->Text = L"Cubic";
			this->cubicRadio->UseVisualStyleBackColor = true;
			this->cubicRadio->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cubicRadio_CheckedChanged);
			// 
			// quadraticRadio
			// 
			this->quadraticRadio->AutoSize = true;
			this->quadraticRadio->Checked = true;
			this->quadraticRadio->Location = System::Drawing::Point(29, 86);
			this->quadraticRadio->Name = L"quadraticRadio";
			this->quadraticRadio->Size = System::Drawing::Size(77, 18);
			this->quadraticRadio->TabIndex = 14;
			this->quadraticRadio->TabStop = true;
			this->quadraticRadio->Text = L"Quadratic";
			this->quadraticRadio->UseVisualStyleBackColor = true;
			this->quadraticRadio->CheckedChanged += gcnew System::EventHandler(this, &MainForm::quadraticRadio_CheckedChanged);
			// 
			// isComplexCheckBox
			// 
			this->isComplexCheckBox->AutoSize = true;
			this->isComplexCheckBox->Location = System::Drawing::Point(9, 62);
			this->isComplexCheckBox->Name = L"isComplexCheckBox";
			this->isComplexCheckBox->Size = System::Drawing::Size(106, 18);
			this->isComplexCheckBox->TabIndex = 12;
			this->isComplexCheckBox->Text = L"Complex graph";
			this->isComplexCheckBox->UseVisualStyleBackColor = true;
			this->isComplexCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::isComplexCheckBox_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 14);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Graph Density";
			// 
			// graphDensityBar
			// 
			this->graphDensityBar->Location = System::Drawing::Point(5, 35);
			this->graphDensityBar->Maximum = 75;
			this->graphDensityBar->Minimum = 5;
			this->graphDensityBar->Name = L"graphDensityBar";
			this->graphDensityBar->Size = System::Drawing::Size(185, 45);
			this->graphDensityBar->TabIndex = 0;
			this->graphDensityBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->graphDensityBar->Value = 20;
			this->graphDensityBar->Scroll += gcnew System::EventHandler(this, &MainForm::graphDensityBar_Scroll);
			// 
			// debugLabel
			// 
			this->debugLabel->AutoSize = true;
			this->debugLabel->Location = System::Drawing::Point(1005, 162);
			this->debugLabel->Name = L"debugLabel";
			this->debugLabel->Size = System::Drawing::Size(56, 14);
			this->debugLabel->TabIndex = 11;
			this->debugLabel->Text = L"Text here";
			// 
			// debugButton
			// 
			this->debugButton->Location = System::Drawing::Point(991, 125);
			this->debugButton->Name = L"debugButton";
			this->debugButton->Size = System::Drawing::Size(142, 23);
			this->debugButton->TabIndex = 12;
			this->debugButton->Text = L"Debug Button";
			this->debugButton->UseVisualStyleBackColor = true;
			this->debugButton->Click += gcnew System::EventHandler(this, &MainForm::debugButton_Click);
			// 
			// defaultView
			// 
			this->defaultView->Location = System::Drawing::Point(453, 32);
			this->defaultView->Name = L"defaultView";
			this->defaultView->Size = System::Drawing::Size(100, 23);
			this->defaultView->TabIndex = 9;
			this->defaultView->Text = L"Default View";
			this->defaultView->UseVisualStyleBackColor = true;
			this->defaultView->Click += gcnew System::EventHandler(this, &MainForm::defaultView_Click);
			// 
			// increaseView
			// 
			this->increaseView->Location = System::Drawing::Point(640, 32);
			this->increaseView->Name = L"increaseView";
			this->increaseView->Size = System::Drawing::Size(74, 23);
			this->increaseView->TabIndex = 10;
			this->increaseView->Text = L"View ++";
			this->increaseView->UseVisualStyleBackColor = true;
			this->increaseView->Click += gcnew System::EventHandler(this, &MainForm::increaseView_Click);
			// 
			// decreaseView
			// 
			this->decreaseView->Location = System::Drawing::Point(559, 32);
			this->decreaseView->Name = L"decreaseView";
			this->decreaseView->Size = System::Drawing::Size(75, 23);
			this->decreaseView->TabIndex = 11;
			this->decreaseView->Text = L"-- View";
			this->decreaseView->UseVisualStyleBackColor = true;
			this->decreaseView->Click += gcnew System::EventHandler(this, &MainForm::decreaseView_Click);
			// 
			// complexTxtbox2
			// 
			this->complexTxtbox2->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->complexTxtbox2->Location = System::Drawing::Point(179, 32);
			this->complexTxtbox2->Name = L"complexTxtbox2";
			this->complexTxtbox2->Size = System::Drawing::Size(45, 22);
			this->complexTxtbox2->TabIndex = 3;
			this->complexTxtbox2->Text = L"2";
			this->complexTxtbox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(76, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 14);
			this->label3->TabIndex = 12;
			this->label3->Text = L"y = (";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(226, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 14);
			this->label4->TabIndex = 13;
			this->label4->Text = L")^";
			// 
			// complexTxtbox3
			// 
			this->complexTxtbox3->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->complexTxtbox3->Location = System::Drawing::Point(246, 32);
			this->complexTxtbox3->Name = L"complexTxtbox3";
			this->complexTxtbox3->ReadOnly = true;
			this->complexTxtbox3->Size = System::Drawing::Size(45, 22);
			this->complexTxtbox3->TabIndex = 14;
			this->complexTxtbox3->Text = L"2";
			this->complexTxtbox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// complexTxtbox1
			// 
			this->complexTxtbox1->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->complexTxtbox1->Location = System::Drawing::Point(104, 32);
			this->complexTxtbox1->Name = L"complexTxtbox1";
			this->complexTxtbox1->ReadOnly = true;
			this->complexTxtbox1->Size = System::Drawing::Size(45, 22);
			this->complexTxtbox1->TabIndex = 14;
			this->complexTxtbox1->Text = L"1";
			this->complexTxtbox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(152, 35);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(24, 14);
			this->label5->TabIndex = 15;
			this->label5->Text = L"x + ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(293, 35);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(16, 14);
			this->label6->TabIndex = 3;
			this->label6->Text = L"+ ";
			// 
			// complexTxtbox4
			// 
			this->complexTxtbox4->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->complexTxtbox4->Location = System::Drawing::Point(312, 32);
			this->complexTxtbox4->Name = L"complexTxtbox4";
			this->complexTxtbox4->Size = System::Drawing::Size(45, 22);
			this->complexTxtbox4->TabIndex = 3;
			this->complexTxtbox4->Text = L"3";
			this->complexTxtbox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(927, 24);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->graphPropertiesToolStripMenuItem });
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// graphPropertiesToolStripMenuItem
			// 
			this->graphPropertiesToolStripMenuItem->Name = L"graphPropertiesToolStripMenuItem";
			this->graphPropertiesToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->graphPropertiesToolStripMenuItem->Text = L"Graph Properties";
			this->graphPropertiesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::graphPropertiesToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutToolStripMenuItem,
					this->tutorialToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// tutorialToolStripMenuItem
			// 
			this->tutorialToolStripMenuItem->Name = L"tutorialToolStripMenuItem";
			this->tutorialToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->tutorialToolStripMenuItem->Text = L"How to use";
			this->tutorialToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::tutorialToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(927, 649);
			this->Controls->Add(this->equationTextbox);
			this->Controls->Add(this->complexTxtbox4);
			this->Controls->Add(this->debugLabel);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->debugButton);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->complexTxtbox3);
			this->Controls->Add(this->complexTxtbox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->complexTxtbox1);
			this->Controls->Add(this->decreaseView);
			this->Controls->Add(this->increaseView);
			this->Controls->Add(this->defaultView);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->plotButton);
			this->Controls->Add(this->OpenGL_Container);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Plot v1.0";
			this->groupBox1->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graphDensityBar))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public:
			Void plotButton_Click(System::Object^  sender, System::EventArgs^  e);
			Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
			Void debugButton_Click(System::Object^  sender, System::EventArgs^  e);
			Void defaultView_Click(System::Object^  sender, System::EventArgs^  e);
			Void graphDensityBar_Scroll(System::Object^  sender, System::EventArgs^  e);
			Void decreaseView_Click(System::Object^  sender, System::EventArgs^  e);
			Void increaseView_Click(System::Object^  sender, System::EventArgs^  e);
			Void clearAllButton_Click(System::Object^  sender, System::EventArgs^  e);
			Void toggleColorButton_Click(System::Object^  sender, System::EventArgs^  e);
			Void removeSelectedButton_Click(System::Object^  sender, System::EventArgs^  e);
			Void isComplexCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			Void copyToClipboardToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			Void equationTextbox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
private: System::Void equationTextbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void graphPropertiesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	graphProperties->Visible = !graphProperties->Visible;
}
private: System::Void quadraticRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	complexTxtbox3->Text = "2";
}
private: System::Void cubicRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	complexTxtbox3->Text = "3";
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Plot v1.0 - Made by Kendrick Tan for IB Computer Science IA 2015");
}
private: System::Void tutorialToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("To plot: Type in any equation you'd like to plot with the variables x, y, or z into the textbox and press plot!\nControls: right click and drag to rotate, hold ctrl and right click and drag to zoom, left click and drag to pan!\n");
}
};
}
