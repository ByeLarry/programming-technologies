#pragma once
#include<string.h>
#include "SecondForm.h"

namespace lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
		
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ ExBut;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ExBut = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Desktop;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 493);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(336, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Посчитать\r\n";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 19);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Выберите размер матрицы:";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// ExBut
			// 
			this->ExBut->BackColor = System::Drawing::Color::Red;
			this->ExBut->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ExBut->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ExBut->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ExBut->Location = System::Drawing::Point(323, 1);
			this->ExBut->Name = L"ExBut";
			this->ExBut->Size = System::Drawing::Size(36, 28);
			this->ExBut->TabIndex = 2;
			this->ExBut->Text = L"X";
			this->ExBut->UseVisualStyleBackColor = false;
			this->ExBut->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::SystemColors::MenuText;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9",
					L"10"
			});
			this->listBox1->Location = System::Drawing::Point(228, 31);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 24);
			this->listBox1->TabIndex = 3;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox1_SelectedIndexChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->richTextBox1->Location = System::Drawing::Point(16, 87);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(332, 236);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"00\n00";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::richTextBox1_TextChanged);
			this->richTextBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::richTextBox1_KeyDown);
			this->richTextBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::richTextBox1_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(73, 338);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(227, 19);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Матрица задана некорректно!";
			this->label2->Visible = false;
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::InfoText;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox1->Location = System::Drawing::Point(34, 392);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(43, 27);
			this->comboBox1->TabIndex = 6;
			// 
			// comboBox2
			// 
			this->comboBox2->BackColor = System::Drawing::SystemColors::InfoText;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox2->Location = System::Drawing::Point(34, 434);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(43, 27);
			this->comboBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 392);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 23);
			this->label3->TabIndex = 8;
			this->label3->Text = L"A";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(8, 434);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 23);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Б";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(58, 464);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(258, 19);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Некорректно выбраны выршины!";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(360, 553);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->ExBut);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ввод матрицы";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		listBox1->SelectedIndex = 0;
		comboBox1->SelectedIndex = 0;
		comboBox2->SelectedIndex = 1;
		comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
		comboBox2->DropDownStyle = ComboBoxStyle::DropDownList;
		label5->Visible = false;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label2->Visible = false;
		label5->Visible = false;
		bool check = true;

		if (System::Convert::ToInt32(comboBox1->Text) > System::Convert::ToInt32(listBox1->SelectedItem->ToString())) {
			label5->Visible = true;
			check = false;
		}

		if(System::Convert::ToInt32(comboBox2->Text) > System::Convert::ToInt32(listBox1->SelectedItem->ToString())){
			label5->Visible = true;
			check = false;
		}

		if (comboBox1->Text == comboBox2->Text ) {
			label5->Visible = true;
			check = false;
		}
		int sel = System::Convert::ToInt32(listBox1->SelectedItem->ToString());
		int c = 0;
		
		String^ text = richTextBox1->Text->Replace('\n', ' ');
		for each (String ^ line in richTextBox1->Lines) {
			for each (Char ch in line) {
				if (ch == '0') {
					c++;
				}
				else if (ch == '1') {
					c++;
				}
			}
		}
		
		//richTextBox1->AppendText(System::Convert::ToString(c));
		if (c != sel*sel) {
			check = false;
			label2->Visible = true;
		}
		if (check) {
			String^ text = richTextBox1->Text->Replace('\n', ' ');
			array<String^>^ lines = text->Split(' ');
			array<array<int^>^>^ matrix = gcnew array<array<int^>^>(sel);
			for (int i = 0; i < sel; i++) { matrix[i] = gcnew array<int^>(sel); }
			for (int i = 0; i < sel; i++) {
				for (int j = 0; j < sel; j++) {
					if ((lines[i][j]) == '1') {
						matrix[i][j] = 1;
					}
					if ((lines[i][j]) == '0') {
						matrix[i][j] = 0;
					}
				}
			}
			
			int start = System::Convert::ToInt32(comboBox1->Text) - 1;
			int end = System::Convert::ToInt32(comboBox2->Text) - 1;
			array<array<int>^>^ graph = gcnew array<array<int>^>(sel);
			for (int i = 0; i < sel; i++) {
				graph[i] = gcnew array<int>(sel);
				for (int j = 0; j < sel; j++) {
					graph[i][j] = *matrix[i][j];
				}
			}
			array<int>^ dist = gcnew array<int>(sel);
			array<bool>^ visited = gcnew array<bool>(sel);
			for (int i = 0; i < sel; i++) {
				dist[i] = 999999;
				visited[i] = false;
			}
			dist[start] = 0;

			for (int i = 0; i < sel - 1; i++) {
				int u = -1;
				for (int j = 0; j < sel; j++) {
					if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
						u = j;
					}
				}
				visited[u] = true;
				for (int v = 0; v < sel; v++) {
					if (graph[u][v] > 0) {
						int alt = dist[u] + graph[u][v];
						if (alt < dist[v]) {
							dist[v] = alt;
						}
					}
				}
			}
			String^ path;
			if (dist[end] == 999999) {
				path = "Нет пути между выбранными вершинами!";
			}
			else {
				path =  (end+1) + "\nКоличество шагов: " + " = " + dist[end] + "\n";
				int curend = end;
				while (curend != start) {
					for (int i = 0; i < sel; i++) {
						if (graph[i][curend] > 0 && dist[i] + graph[i][curend] == dist[curend]) {
							path = (i + 1) + " -> " + path;
							curend = i;
							break;
						}
					}
				}
				path =   path;
				
			}
			SecondForm^ form2 = gcnew SecondForm(path);
			form2->ShowDialog();

		}


		
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	;

	if (listBox1->SelectedIndex.ToString() == "0") {
		richTextBox1->Clear();
		richTextBox1->AppendText("00\n00\n");
	}
	if (listBox1->SelectedIndex.ToString() == "1") {
		richTextBox1->Clear();
		richTextBox1->AppendText("000\n000\n000\n");
	}
	if (listBox1->SelectedIndex.ToString() == "2") {
		richTextBox1->Clear();
		richTextBox1->AppendText("0000\n0000\n0000\n0000\n");
	}
	if (listBox1->SelectedIndex.ToString() == "3") {
		richTextBox1->Clear();
		richTextBox1->AppendText("00000\n00000\n00000\n00000\n00000\n");
	}
	if (listBox1->SelectedIndex.ToString() == "4") {
		richTextBox1->Clear();
		for (int i; i < 6; i++) {
			richTextBox1->AppendText("000000\n");
		}
	}
	if (listBox1->SelectedIndex.ToString() == "5") {
		richTextBox1->Clear();
		for (int i; i < 7; i++) {
			richTextBox1->AppendText("0000000\n");
		}
	}
	if (listBox1->SelectedIndex.ToString() == "6") {
		richTextBox1->Clear();
		for (int i; i < 8; i++) {
			richTextBox1->AppendText("00000000\n");
		}
	}
	if (listBox1->SelectedIndex.ToString() == "7") {
		richTextBox1->Clear();
		for (int i; i < 9; i++) {
			richTextBox1->AppendText("000000000\n");
		}
	}
	if (listBox1->SelectedIndex.ToString() == "8") {
		richTextBox1->Clear();
		for (int i; i < 10; i++) {
			richTextBox1->AppendText("0000000000\n");
		}
	}

}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	int cpos = richTextBox1->SelectionStart;
	if (e->KeyChar != '1' && e->KeyChar != '0') {
		e->Handled = true;
		richTextBox1->Text = richTextBox1->Text->Replace(e->KeyChar.ToString(), "");
		richTextBox1->SelectionStart = cpos ;
		richTextBox1->SelectionLength = 0;
	}
	int curpos = richTextBox1->SelectionStart;
	int currentline = richTextBox1->GetLineFromCharIndex(cpos);
	int sel = System::Convert::ToInt32(listBox1->SelectedItem->ToString());
	
	if (currentline == sel ) {
		e->Handled = true;
	}
}
private: System::Void richTextBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter || (e->KeyCode == Keys::Enter && e->Modifiers == Keys::Control)) {
		e->Handled = true;
	}
	if (e->KeyCode == Keys::Space) {
		e->Handled = true;
	}
	if (e->KeyCode == Keys::Back) {
		int cpos = richTextBox1->SelectionStart;
		int currentline = richTextBox1->GetLineFromCharIndex(cpos);
		int lineStartPosition = richTextBox1->GetFirstCharIndexFromLine(currentline);
		if (cpos == lineStartPosition) {
			e->Handled = true;
		}
	}
}
};
}
