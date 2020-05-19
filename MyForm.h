#pragma once

#using <system.Net.dll>

#include "Transaction.h"

namespace Window {

	using namespace System;
	using namespace System::Net;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Double func(String^ s1, String^ s2)
	{
		String^ apiKey = "e419ea527f3f46aaaa988fd25ce90188";
		WebClient^ client = gcnew WebClient();
		String^ answer = client->DownloadString("https://openexchangerates.org/api/latest.json?app_id=" + apiKey);

		String^ answer1 = answer->Substring(answer->LastIndexOf("\"" + s1 + "\": ") + 7);
		String^ answer2 = answer->Substring(answer->LastIndexOf("\"" + s2 + "\": ") + 7);

		int temp1 = answer1->IndexOf(",");
		int temp2 = answer2->IndexOf(",");

		array<wchar_t>^ ans1 = gcnew array<wchar_t>(temp1);
		array<wchar_t>^ ans2 = gcnew array<wchar_t>(temp2);

		answer1->CopyTo(0, ans1, 0, temp1);
		answer2->CopyTo(0, ans2, 0, temp2);

		String^ str1 = gcnew String(ans1);
		String^ str2 = gcnew String(ans2);

		Double d1 = Convert::ToDouble(str1->Replace(".", ","));
		Double d2 = Convert::ToDouble(str2->Replace(".", ","));

		return d2 / d1;
	}

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			list = gcnew Collections::Generic::List<Transaction^>();

		}

		Collections::Generic::List<Transaction^>^ list;

		void stackAdapter()
		{
			this->textBox2->Text = "";
			this->list->Reverse();
			for each (Transaction ^ var in this->list)
			{
				this->textBox2->Text += var->ToString() + Environment::NewLine + Environment::NewLine;
			}
			this->list->Reverse();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button5;





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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->comboBox2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(236, 205);
			this->panel1->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label1->Location = System::Drawing::Point(37, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 26);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Курс валют";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox1->Location = System::Drawing::Point(12, 99);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 29);
			this->textBox1->TabIndex = 3;
			// 
			// comboBox2
			// 
			this->comboBox2->DisplayMember = L"RUB";
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"USD", L"EUR", L"RUB" });
			this->comboBox2->Location = System::Drawing::Point(112, 51);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(100, 32);
			this->comboBox2->TabIndex = 2;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button1->Location = System::Drawing::Point(12, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Веб-синхронизация";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DisplayMember = L"USD";
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"USD", L"EUR", L"RUB" });
			this->comboBox1->Location = System::Drawing::Point(12, 51);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(94, 32);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// textBox2
			// 
			this->textBox2->AcceptsReturn = true;
			this->textBox2->AcceptsTab = true;
			this->textBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox2->ForeColor = System::Drawing::Color::Black;
			this->textBox2->HideSelection = false;
			this->textBox2->Location = System::Drawing::Point(12, 224);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(593, 429);
			this->textBox2->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(545, 224);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Журнал";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Location = System::Drawing::Point(255, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(350, 205);
			this->panel2->TabIndex = 8;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button5->Location = System::Drawing::Point(179, 83);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(168, 35);
			this->button5->TabIndex = 9;
			this->button5->Text = L"USD в RUB";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label3->Location = System::Drawing::Point(8, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(318, 26);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Выполнить перевод на сумму";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox3->Location = System::Drawing::Point(3, 48);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(344, 29);
			this->textBox3->TabIndex = 3;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button4->Location = System::Drawing::Point(3, 83);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(170, 35);
			this->button4->TabIndex = 2;
			this->button4->Text = L"RUB в USD";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button3->Location = System::Drawing::Point(3, 164);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(344, 35);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Сбросить результат";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button2->Location = System::Drawing::Point(3, 124);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(344, 34);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Отменить последнюю операцию";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(617, 659);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::SystemColors::WindowText;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Калькулятор валют";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->textBox1->Text = Convert::ToString(
				Math::Round(
					func(
						this->comboBox1->SelectedItem->ToString(),
						this->comboBox2->SelectedItem->ToString()
					), 2
				)
			);
		}

		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
		{
			this->comboBox1->SelectedIndex = 0;
			this->comboBox2->SelectedIndex = 2;
		}

		private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e)
		{

		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (this->list->Count)
			{
				this->list->RemoveAt(this->list->Count - 1);
				stackAdapter();
			}
		}

		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e)
		{

		}

		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->list->Add(
				gcnew Transaction(
					this->comboBox2->SelectedItem->ToString(),
					this->comboBox1->SelectedItem->ToString(),
					Math::Round(Double::Parse(this->textBox3->Text), 5),
					Math::Round(Double::Parse(this->textBox1->Text), 5)
				)
			);
			stackAdapter();
		}

		private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->list->Add(
				gcnew Transaction(
					this->comboBox1->SelectedItem->ToString(),
					this->comboBox2->SelectedItem->ToString(),
					Math::Round(Double::Parse(this->textBox3->Text), 5),
					Math::Round(1/Double::Parse(this->textBox1->Text), 5)
				)
			);
			stackAdapter();
		}

		private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (this->comboBox1->SelectedItem != nullptr && this->comboBox2->SelectedItem != nullptr)
			{
				this->button4->Text = this->comboBox2->SelectedItem->ToString() + " в " + this->comboBox1->SelectedItem->ToString();
				this->button5->Text = this->comboBox1->SelectedItem->ToString() + " в " + this->comboBox2->SelectedItem->ToString();
			}
			else
			{
				this->button4->Text = "RUB в USD";
				this->button5->Text = "USD в RUB";
			}
		}

		private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (this->comboBox1->SelectedItem != nullptr && this->comboBox2->SelectedItem != nullptr)
			{
				this->button4->Text = this->comboBox2->SelectedItem->ToString() + " в " + this->comboBox1->SelectedItem->ToString();
				this->button5->Text = this->comboBox1->SelectedItem->ToString() + " в " + this->comboBox2->SelectedItem->ToString();
			}
			else
			{
				this->button4->Text = "RUB в USD";
				this->button5->Text = "USD в RUB";
			}
		}

		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->list->RemoveRange(0, this->list->Count);
			stackAdapter();
		}
};
}