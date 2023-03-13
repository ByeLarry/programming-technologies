#pragma once

namespace lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SecondForm
	/// </summary>
	public ref class SecondForm : public System::Windows::Forms::Form
	{
	public:
		SecondForm(System::String^ path)
		{
			InitializeComponent();
			label2->Text = path;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SecondForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ExBut;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SecondForm::typeid));
			this->ExBut = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ExBut
			// 
			this->ExBut->BackColor = System::Drawing::Color::Red;
			this->ExBut->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ExBut->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ExBut->Location = System::Drawing::Point(462, 1);
			this->ExBut->Name = L"ExBut";
			this->ExBut->Size = System::Drawing::Size(36, 28);
			this->ExBut->TabIndex = 3;
			this->ExBut->Text = L"X";
			this->ExBut->UseVisualStyleBackColor = false;
			this->ExBut->Click += gcnew System::EventHandler(this, &SecondForm::ExBut_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(6, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(234, 19);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Достижимость узла А из узла Б";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(6, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 19);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &SecondForm::label2_Click);
			// 
			// SecondForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(498, 139);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ExBut);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SecondForm";
			this->Text = L"SecondForm";
			this->Load += gcnew System::EventHandler(this, &SecondForm::SecondForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SecondForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ExBut_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
