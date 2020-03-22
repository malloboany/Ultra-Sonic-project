#pragma once
#include "physics .h"
#include <cstdlib>
namespace voicewaves {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			aTrackBar->Maximum = sizeTrackBar->Value / 2 - 1;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  sizeLabel;
	private: System::Windows::Forms::Label^  gravLabel;
	private: System::Windows::Forms::TrackBar^  sizeTrackBar;
	private: System::Windows::Forms::TrackBar^  gravityTrackBar;
	private: System::Windows::Forms::Label^  adress;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


	public: static float GRAV;
			static float SIZE = 10.0f;
			static float TEMP = 1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	public:
	private: System::Windows::Forms::Label^  Frequency;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  fLabel;
	private: System::Windows::Forms::Label^  waveVelocityLabel;
	private: System::Windows::Forms::TrackBar^  fTrackBar;
	private: System::Windows::Forms::TrackBar^  waveVelocityTrackBar;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  aLabel;
	private: System::Windows::Forms::TrackBar^  aTrackBar;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  about;

	private:

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  densityLabel;
	private: System::Windows::Forms::Label^  PLabel;
	private: System::Windows::Forms::Label^  IPLabel;
	private: System::Windows::Forms::Label^  tempLabel;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TrackBar^  tempTrackBar;
	private: System::Windows::Forms::Label^  ratioLabel;
	private: System::Windows::Forms::Label^  label11;



	private: System::Windows::Forms::Button^  refreshButton;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  VoicePLabel;
	private: System::Windows::Forms::Label^  WaveIntensityLabel;
	private: System::Windows::Forms::Label^  PPLabel;
	private: System::Windows::Forms::Label^  waveEnergyLabel;
	private: System::Windows::Forms::Label^  ReluLabel;
	public:

	public:
	private:


			 static float A = 1;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->VoicePLabel = (gcnew System::Windows::Forms::Label());
			this->WaveIntensityLabel = (gcnew System::Windows::Forms::Label());
			this->PPLabel = (gcnew System::Windows::Forms::Label());
			this->waveEnergyLabel = (gcnew System::Windows::Forms::Label());
			this->ReluLabel = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->refreshButton = (gcnew System::Windows::Forms::Button());
			this->ratioLabel = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->PLabel = (gcnew System::Windows::Forms::Label());
			this->IPLabel = (gcnew System::Windows::Forms::Label());
			this->densityLabel = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->about = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tempLabel = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tempTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->Frequency = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->fLabel = (gcnew System::Windows::Forms::Label());
			this->waveVelocityLabel = (gcnew System::Windows::Forms::Label());
			this->fTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->waveVelocityTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->aLabel = (gcnew System::Windows::Forms::Label());
			this->aTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->sizeLabel = (gcnew System::Windows::Forms::Label());
			this->gravLabel = (gcnew System::Windows::Forms::Label());
			this->sizeTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->gravityTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->adress = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tempTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->waveVelocityTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aTrackBar))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gravityTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->groupBox4);
			this->panel1->Controls->Add(this->about);
			this->panel1->Controls->Add(this->exitButton);
			this->panel1->Controls->Add(this->groupBox3);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->adress);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(266, 732);
			this->panel1->TabIndex = 0;
			this->panel1->Click += gcnew System::EventHandler(this, &MyForm::panel1_Click);
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->VoicePLabel);
			this->groupBox4->Controls->Add(this->WaveIntensityLabel);
			this->groupBox4->Controls->Add(this->PPLabel);
			this->groupBox4->Controls->Add(this->waveEnergyLabel);
			this->groupBox4->Controls->Add(this->ReluLabel);
			this->groupBox4->Controls->Add(this->label16);
			this->groupBox4->Controls->Add(this->label15);
			this->groupBox4->Controls->Add(this->label14);
			this->groupBox4->Controls->Add(this->label13);
			this->groupBox4->Controls->Add(this->label12);
			this->groupBox4->Controls->Add(this->refreshButton);
			this->groupBox4->Controls->Add(this->ratioLabel);
			this->groupBox4->Controls->Add(this->label11);
			this->groupBox4->Controls->Add(this->PLabel);
			this->groupBox4->Controls->Add(this->IPLabel);
			this->groupBox4->Controls->Add(this->densityLabel);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->label4);
			this->groupBox4->Location = System::Drawing::Point(13, 443);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(227, 257);
			this->groupBox4->TabIndex = 7;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Result";
			this->groupBox4->Enter += gcnew System::EventHandler(this, &MyForm::groupBox4_Enter);
			// 
			// VoicePLabel
			// 
			this->VoicePLabel->AutoSize = true;
			this->VoicePLabel->ForeColor = System::Drawing::Color::Red;
			this->VoicePLabel->Location = System::Drawing::Point(109, 230);
			this->VoicePLabel->Name = L"VoicePLabel";
			this->VoicePLabel->Size = System::Drawing::Size(48, 13);
			this->VoicePLabel->TabIndex = 18;
			this->VoicePLabel->Text = L"0 Pascal";
			// 
			// WaveIntensityLabel
			// 
			this->WaveIntensityLabel->AutoSize = true;
			this->WaveIntensityLabel->ForeColor = System::Drawing::Color::Red;
			this->WaveIntensityLabel->Location = System::Drawing::Point(109, 202);
			this->WaveIntensityLabel->Name = L"WaveIntensityLabel";
			this->WaveIntensityLabel->Size = System::Drawing::Size(45, 13);
			this->WaveIntensityLabel->TabIndex = 17;
			this->WaveIntensityLabel->Text = L"0 J/sm2";
			// 
			// PPLabel
			// 
			this->PPLabel->AutoSize = true;
			this->PPLabel->ForeColor = System::Drawing::Color::Red;
			this->PPLabel->Location = System::Drawing::Point(109, 180);
			this->PPLabel->Name = L"PPLabel";
			this->PPLabel->Size = System::Drawing::Size(33, 13);
			this->PPLabel->TabIndex = 16;
			this->PPLabel->Text = L"0 J/S";
			// 
			// waveEnergyLabel
			// 
			this->waveEnergyLabel->AutoSize = true;
			this->waveEnergyLabel->ForeColor = System::Drawing::Color::Red;
			this->waveEnergyLabel->Location = System::Drawing::Point(109, 153);
			this->waveEnergyLabel->Name = L"waveEnergyLabel";
			this->waveEnergyLabel->Size = System::Drawing::Size(29, 13);
			this->waveEnergyLabel->TabIndex = 15;
			this->waveEnergyLabel->Text = L"0 Jol";
			// 
			// ReluLabel
			// 
			this->ReluLabel->AutoSize = true;
			this->ReluLabel->ForeColor = System::Drawing::Color::Red;
			this->ReluLabel->Location = System::Drawing::Point(109, 129);
			this->ReluLabel->Name = L"ReluLabel";
			this->ReluLabel->Size = System::Drawing::Size(24, 13);
			this->ReluLabel->TabIndex = 14;
			this->ReluLabel->Text = L"0 N";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(6, 230);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(84, 13);
			this->label16->TabIndex = 13;
			this->label16->Text = L"Voice Pressure :";
			this->label16->Click += gcnew System::EventHandler(this, &MyForm::label16_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(6, 202);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(84, 13);
			this->label15->TabIndex = 12;
			this->label15->Text = L"Wave Intensity :";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(6, 180);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(17, 13);
			this->label14->TabIndex = 11;
			this->label14->Text = L"P:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 153);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(75, 13);
			this->label13->TabIndex = 10;
			this->label13->Text = L"Wave Energy:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 129);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(65, 13);
			this->label12->TabIndex = 9;
			this->label12->Text = L"Reluctance:";
			// 
			// refreshButton
			// 
			this->refreshButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->refreshButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->refreshButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"refreshButton.Image")));
			this->refreshButton->Location = System::Drawing::Point(174, 8);
			this->refreshButton->Name = L"refreshButton";
			this->refreshButton->Size = System::Drawing::Size(47, 37);
			this->refreshButton->TabIndex = 8;
			this->refreshButton->UseVisualStyleBackColor = false;
			this->refreshButton->Click += gcnew System::EventHandler(this, &MyForm::refreshButton_Click);
			// 
			// ratioLabel
			// 
			this->ratioLabel->AutoSize = true;
			this->ratioLabel->ForeColor = System::Drawing::Color::Red;
			this->ratioLabel->Location = System::Drawing::Point(109, 90);
			this->ratioLabel->Name = L"ratioLabel";
			this->ratioLabel->Size = System::Drawing::Size(13, 13);
			this->ratioLabel->TabIndex = 7;
			this->ratioLabel->Text = L"0";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 93);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(91, 26);
			this->label11->TabIndex = 6;
			this->label11->Text = L"Ratio (gas density\r\nto air density) :";
			// 
			// PLabel
			// 
			this->PLabel->AutoSize = true;
			this->PLabel->ForeColor = System::Drawing::Color::Red;
			this->PLabel->Location = System::Drawing::Point(109, 70);
			this->PLabel->Name = L"PLabel";
			this->PLabel->Size = System::Drawing::Size(47, 13);
			this->PLabel->TabIndex = 5;
			this->PLabel->Text = L"0 pascal";
			// 
			// IPLabel
			// 
			this->IPLabel->AutoSize = true;
			this->IPLabel->ForeColor = System::Drawing::Color::Red;
			this->IPLabel->Location = System::Drawing::Point(109, 44);
			this->IPLabel->Name = L"IPLabel";
			this->IPLabel->Size = System::Drawing::Size(47, 13);
			this->IPLabel->TabIndex = 4;
			this->IPLabel->Text = L"0 pascal";
			// 
			// densityLabel
			// 
			this->densityLabel->AutoSize = true;
			this->densityLabel->ForeColor = System::Drawing::Color::Red;
			this->densityLabel->Location = System::Drawing::Point(109, 19);
			this->densityLabel->Name = L"densityLabel";
			this->densityLabel->Size = System::Drawing::Size(47, 13);
			this->densityLabel->TabIndex = 3;
			this->densityLabel->Text = L"0 g/cm3";
			this->densityLabel->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 70);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(51, 13);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Pressure:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 44);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Ideal Pressure:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Density:";
			// 
			// about
			// 
			this->about->Location = System::Drawing::Point(13, 706);
			this->about->Name = L"about";
			this->about->Size = System::Drawing::Size(75, 23);
			this->about->TabIndex = 6;
			this->about->Text = L"About";
			this->about->UseVisualStyleBackColor = true;
			this->about->Click += gcnew System::EventHandler(this, &MyForm::about_Click);
			// 
			// exitButton
			// 
			this->exitButton->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->exitButton->Location = System::Drawing::Point(165, 706);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(75, 23);
			this->exitButton->TabIndex = 5;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MyForm::exitButton_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Location = System::Drawing::Point(13, 369);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(227, 68);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Keys";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label5->Location = System::Drawing::Point(10, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(135, 39);
			this->label5->TabIndex = 0;
			this->label5->Text = L"-w : Generate a wave.\r\n-Space : Add a mol of gas. \r\n-Esc : Exit.";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tempLabel);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->tempTrackBar);
			this->groupBox2->Controls->Add(this->Frequency);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->fLabel);
			this->groupBox2->Controls->Add(this->waveVelocityLabel);
			this->groupBox2->Controls->Add(this->fTrackBar);
			this->groupBox2->Controls->Add(this->waveVelocityTrackBar);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->aLabel);
			this->groupBox2->Controls->Add(this->aTrackBar);
			this->groupBox2->Location = System::Drawing::Point(13, 157);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(227, 206);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Physics";
			// 
			// tempLabel
			// 
			this->tempLabel->AutoSize = true;
			this->tempLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tempLabel->Location = System::Drawing::Point(181, 168);
			this->tempLabel->Name = L"tempLabel";
			this->tempLabel->Size = System::Drawing::Size(49, 13);
			this->tempLabel->TabIndex = 16;
			this->tempLabel->Text = L"1 Kelven";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label10->Location = System::Drawing::Point(181, 181);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 13);
			this->label10->TabIndex = 15;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label9->Location = System::Drawing::Point(6, 161);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(67, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Temperature";
			// 
			// tempTrackBar
			// 
			this->tempTrackBar->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tempTrackBar->Location = System::Drawing::Point(71, 151);
			this->tempTrackBar->Maximum = 100;
			this->tempTrackBar->Name = L"tempTrackBar";
			this->tempTrackBar->Size = System::Drawing::Size(104, 45);
			this->tempTrackBar->TabIndex = 13;
			this->tempTrackBar->Value = 1;
			this->tempTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::tempTrackBar_Scroll);
			// 
			// Frequency
			// 
			this->Frequency->AutoSize = true;
			this->Frequency->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7));
			this->Frequency->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Frequency->Location = System::Drawing::Point(6, 109);
			this->Frequency->Name = L"Frequency";
			this->Frequency->Size = System::Drawing::Size(86, 13);
			this->Frequency->TabIndex = 12;
			this->Frequency->Text = L"Wave Frequency";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label6->Location = System::Drawing::Point(7, 67);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Wave Velocity";
			// 
			// fLabel
			// 
			this->fLabel->AutoSize = true;
			this->fLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->fLabel->Location = System::Drawing::Point(181, 109);
			this->fLabel->Name = L"fLabel";
			this->fLabel->Size = System::Drawing::Size(29, 13);
			this->fLabel->TabIndex = 10;
			this->fLabel->Text = L"1 Hz";
			// 
			// waveVelocityLabel
			// 
			this->waveVelocityLabel->AutoSize = true;
			this->waveVelocityLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->waveVelocityLabel->Location = System::Drawing::Point(181, 67);
			this->waveVelocityLabel->Name = L"waveVelocityLabel";
			this->waveVelocityLabel->Size = System::Drawing::Size(34, 13);
			this->waveVelocityLabel->TabIndex = 9;
			this->waveVelocityLabel->Text = L"1 m/s";
			// 
			// fTrackBar
			// 
			this->fTrackBar->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->fTrackBar->Location = System::Drawing::Point(71, 100);
			this->fTrackBar->Maximum = 100;
			this->fTrackBar->Name = L"fTrackBar";
			this->fTrackBar->Size = System::Drawing::Size(104, 45);
			this->fTrackBar->TabIndex = 8;
			this->fTrackBar->Value = 1;
			this->fTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::fTrackBar_Scroll);
			// 
			// waveVelocityTrackBar
			// 
			this->waveVelocityTrackBar->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->waveVelocityTrackBar->Location = System::Drawing::Point(71, 61);
			this->waveVelocityTrackBar->Maximum = 40;
			this->waveVelocityTrackBar->Name = L"waveVelocityTrackBar";
			this->waveVelocityTrackBar->Size = System::Drawing::Size(104, 45);
			this->waveVelocityTrackBar->TabIndex = 7;
			this->waveVelocityTrackBar->Value = 1;
			this->waveVelocityTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::waveVelocityTrackBar_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label2->Location = System::Drawing::Point(7, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"A";
			// 
			// aLabel
			// 
			this->aLabel->AutoSize = true;
			this->aLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->aLabel->Location = System::Drawing::Point(181, 28);
			this->aLabel->Name = L"aLabel";
			this->aLabel->Size = System::Drawing::Size(24, 13);
			this->aLabel->TabIndex = 2;
			this->aLabel->Text = L"1 m";
			// 
			// aTrackBar
			// 
			this->aTrackBar->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->aTrackBar->Location = System::Drawing::Point(71, 19);
			this->aTrackBar->Maximum = 19;
			this->aTrackBar->Name = L"aTrackBar";
			this->aTrackBar->Size = System::Drawing::Size(104, 45);
			this->aTrackBar->TabIndex = 1;
			this->aTrackBar->Value = 1;
			this->aTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::aTrackBar_Scroll);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->sizeLabel);
			this->groupBox1->Controls->Add(this->gravLabel);
			this->groupBox1->Controls->Add(this->sizeTrackBar);
			this->groupBox1->Controls->Add(this->gravityTrackBar);
			this->groupBox1->Location = System::Drawing::Point(13, 57);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(227, 94);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Environment";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label3->Location = System::Drawing::Point(2, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Cube Size";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(7, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Gravity";
			// 
			// sizeLabel
			// 
			this->sizeLabel->AutoSize = true;
			this->sizeLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->sizeLabel->Location = System::Drawing::Point(200, 62);
			this->sizeLabel->Name = L"sizeLabel";
			this->sizeLabel->Size = System::Drawing::Size(19, 13);
			this->sizeLabel->TabIndex = 6;
			this->sizeLabel->Text = L"10";
			// 
			// gravLabel
			// 
			this->gravLabel->AutoSize = true;
			this->gravLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->gravLabel->Location = System::Drawing::Point(200, 16);
			this->gravLabel->Name = L"gravLabel";
			this->gravLabel->Size = System::Drawing::Size(13, 13);
			this->gravLabel->TabIndex = 5;
			this->gravLabel->Text = L"0";
			// 
			// sizeTrackBar
			// 
			this->sizeTrackBar->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->sizeTrackBar->Location = System::Drawing::Point(83, 43);
			this->sizeTrackBar->Maximum = 20;
			this->sizeTrackBar->Minimum = 5;
			this->sizeTrackBar->Name = L"sizeTrackBar";
			this->sizeTrackBar->Size = System::Drawing::Size(104, 45);
			this->sizeTrackBar->TabIndex = 4;
			this->sizeTrackBar->Value = 10;
			this->sizeTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::sizeTrackBar_Scroll);
			// 
			// gravityTrackBar
			// 
			this->gravityTrackBar->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->gravityTrackBar->Location = System::Drawing::Point(83, 9);
			this->gravityTrackBar->Maximum = 30;
			this->gravityTrackBar->Name = L"gravityTrackBar";
			this->gravityTrackBar->Size = System::Drawing::Size(104, 45);
			this->gravityTrackBar->TabIndex = 1;
			this->gravityTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::gravityTrackBar_Scroll);
			// 
			// adress
			// 
			this->adress->AutoSize = true;
			this->adress->Font = (gcnew System::Drawing::Font(L"Tahoma", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->adress->ForeColor = System::Drawing::Color::Red;
			this->adress->Location = System::Drawing::Point(13, 13);
			this->adress->Name = L"adress";
			this->adress->Size = System::Drawing::Size(211, 27);
			this->adress->TabIndex = 0;
			this->adress->Text = L"Ultrasonic Project";
			this->adress->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(266, 733);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Location = System::Drawing::Point(0, 20);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Opacity = 0.5;
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Control Panel";
			this->TopMost = true;
			this->TransparencyKey = System::Drawing::Color::White;
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->MouseEnter += gcnew System::EventHandler(this, &MyForm::MyForm_MouseEnter);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tempTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->waveVelocityTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aTrackBar))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gravityTrackBar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: void _UPDATE(){
					 densityLabel->Text = System::Convert::ToString(physics::getDensity(physics::count, SIZE) + "\t g/cm3");
					 IPLabel->Text = System::Convert::ToString(physics::getIdealPressure(physics::count / 20, TEMP, SIZE) + "\t pascal");
					 PLabel->Text = System::Convert::ToString(physics::getPressure(physics::count / 20, physics::count, physics::molecVelocity, SIZE) + "\t pascal");
					 ratioLabel->Text = System::Convert::ToString(physics::getRatio(SIZE));
					 ReluLabel->Text = System::Convert::ToString(physics::getReluctance(physics::count, SIZE) + "N");
					 waveEnergyLabel->Text = System::Convert::ToString(physics::getWaveEnergy(physics::count, SIZE, physics::TIMER) + " Jol");
					 PPLabel->Text = System::Convert::ToString(physics::getP(physics::count, SIZE) + " J/S");
					 WaveIntensityLabel->Text = System::Convert::ToString(physics::getI(physics::count, SIZE) + " J/s.m2");
					 VoicePLabel->Text = System::Convert::ToString(physics::getVoicePressure(physics::count, SIZE) + " Pascal");
		}
	private: System::Void gravityTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 gravLabel->Text = System::Convert::ToString(gravityTrackBar->Value);
				 GRAV = gravityTrackBar->Value;
				 _UPDATE();
	}
private: System::Void sizeTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 sizeLabel->Text = System::Convert::ToString(sizeTrackBar->Value);
			 SIZE = sizeTrackBar->Value;

			 aTrackBar->Maximum = sizeTrackBar->Value / 2 - 1;
			 if (aTrackBar->Value >= sizeTrackBar->Value / 2 - 1){
				 aTrackBar->Value = 1;
				 A = aTrackBar->Value;
				 aLabel->Text = System::Convert::ToString(aTrackBar->Value);
				 physics::A = A;
			 }
			 _UPDATE();
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(0);
}
private: System::Void aTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 A = aTrackBar->Value;
			 aLabel->Text = System::Convert::ToString(aTrackBar->Value);
			 physics::A = A;
			 _UPDATE();
}
private: System::Void waveVelocityTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 waveVelocityLabel->Text = System::Convert::ToString(waveVelocityTrackBar->Value);
			 physics::setWaveVelocity(waveVelocityTrackBar->Value);
			 _UPDATE();
}
private: System::Void fTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 fLabel->Text = System::Convert::ToString(fTrackBar->Value);
			 physics::setf(fTrackBar->Value);
			 _UPDATE();
}
private: System::Void about_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("Ultrasonic Project\n\nMohammed Alloboany \n malloboany.blogspot.com \n facebook.com\\m.alloboany \n\nAll rights are reserved 2016");
			 _UPDATE();
}
private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 densityLabel->Text = System::Convert::ToString(physics::getDensity(physics::count, SIZE)+"\t g/cm3");
			 IPLabel->Text = System::Convert::ToString(physics::getIdealPressure(physics::count / 20, TEMP, SIZE) + "\t pascal");
			 PLabel->Text = System::Convert::ToString(physics::getPressure(physics::count / 20,physics::count,1,SIZE)+"\t pascal");
			 ratioLabel->Text = System::Convert::ToString(physics::getRatio(SIZE));
			 
}
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tempTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 TEMP = tempTrackBar->Value;
			 tempLabel->Text = System::Convert::ToString(tempTrackBar->Value);
			 _UPDATE();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer1_Tick_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 densityLabel->Text = System::Convert::ToString(physics::f);
}
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
}
private: System::Void refreshButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 _UPDATE();
}
private: System::Void label16_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel1_Click(System::Object^  sender, System::EventArgs^  e) {
			 _UPDATE();
}
private: System::Void MyForm_Click(System::Object^  sender, System::EventArgs^  e) {
			 _UPDATE();
}
private: System::Void MyForm_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 _UPDATE();
}
private: System::Void groupBox4_Enter(System::Object^  sender, System::EventArgs^  e) {
			 _UPDATE();
}
};
}
