#pragma once
#include "DotNetUtilities.h"
#include "GUA_OM.h"

Tri_Mesh *mesh;
bool isPoint = false;
bool isFace = false;
namespace testmesh {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	private: GLPanel::GLPanelControl^  glPanelControl1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;






	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			GLPanel::HKCCameraProp^  hkcCameraProp1 = (gcnew GLPanel::HKCCameraProp());
			GLPanel::HKCDisplayProp^  hkcDisplayProp1 = (gcnew GLPanel::HKCDisplayProp());
			GLPanel::HKCPixelFormat^  hkcPixelFormat1 = (gcnew GLPanel::HKCPixelFormat());
			GLPanel::HKCTrackballProp^  hkcTrackballProp1 = (gcnew GLPanel::HKCTrackballProp());
			GLPanel::HKCTrackballTrig^  hkcTrackballTrig1 = (gcnew GLPanel::HKCTrackballTrig());
			GLPanel::HKCTrackballTrig^  hkcTrackballTrig2 = (gcnew GLPanel::HKCTrackballTrig());
			GLPanel::HKCTrackballTrig^  hkcTrackballTrig3 = (gcnew GLPanel::HKCTrackballTrig());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->glPanelControl1 = (gcnew GLPanel::GLPanelControl());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(657, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(171, 138);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// glPanelControl1
			// 
			hkcCameraProp1->Enabled = true;
			hkcCameraProp1->Far = 1000;
			hkcCameraProp1->Fov = 45;
			hkcCameraProp1->Near = 0.001;
			hkcCameraProp1->Type = GLPanel::HKCCameraProp::CAMERATYPE::PERSPECTIVE;
			hkcCameraProp1->Zoom = 1;
			this->glPanelControl1->Camera_Property = hkcCameraProp1;
			hkcDisplayProp1->Back_Color = System::Drawing::Color::White;
			hkcDisplayProp1->Grid_Axis = System::Drawing::Color::Black;
			hkcDisplayProp1->Grid_Draw = true;
			hkcDisplayProp1->Grid_Line = System::Drawing::Color::DimGray;
			this->glPanelControl1->Display_Property = hkcDisplayProp1;
			this->glPanelControl1->Empty_Panel = false;
			this->glPanelControl1->Location = System::Drawing::Point(26, 22);
			this->glPanelControl1->Name = L"glPanelControl1";
			hkcPixelFormat1->Accumu_Buffer_Bits = GLPanel::HKCPixelFormat::PIXELBITS::BITS_0;
			hkcPixelFormat1->Alpha_Buffer_Bits = GLPanel::HKCPixelFormat::PIXELBITS::BITS_0;
			hkcPixelFormat1->Stencil_Buffer_Bits = GLPanel::HKCPixelFormat::PIXELBITS::BITS_0;
			this->glPanelControl1->Pixel_Format = hkcPixelFormat1;
			this->glPanelControl1->Size = System::Drawing::Size(595, 292);
			this->glPanelControl1->TabIndex = 2;
			hkcTrackballProp1->Const_Res = false;
			hkcTrackballProp1->Delta_Res = 500;
			hkcTrackballProp1->Enabled = true;
			hkcTrackballProp1->Move_Res = 1000;
			hkcTrackballTrig1->Key_Down = false;
			hkcTrackballTrig1->Keyboard = System::Windows::Forms::Keys::None;
			hkcTrackballTrig1->Mouse = System::Windows::Forms::MouseButtons::Right;
			hkcTrackballTrig1->Mouse_Down = false;
			hkcTrackballProp1->Move_Trigger = hkcTrackballTrig1;
			hkcTrackballTrig2->Key_Down = false;
			hkcTrackballTrig2->Keyboard = System::Windows::Forms::Keys::None;
			hkcTrackballTrig2->Mouse = System::Windows::Forms::MouseButtons::Left;
			hkcTrackballTrig2->Mouse_Down = false;
			hkcTrackballProp1->Rotate_Trigger = hkcTrackballTrig2;
			hkcTrackballProp1->Zoom_Res = 1000;
			hkcTrackballTrig3->Key_Down = false;
			hkcTrackballTrig3->Keyboard = System::Windows::Forms::Keys::None;
			hkcTrackballTrig3->Mouse = System::Windows::Forms::MouseButtons::Middle;
			hkcTrackballTrig3->Mouse_Down = false;
			hkcTrackballProp1->Zoom_Trigger = hkcTrackballTrig3;
			this->glPanelControl1->Trackball_Property = hkcTrackballProp1;
			this->glPanelControl1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::glPanelControl1_Paint);
			this->glPanelControl1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::glPanelControl1_KeyDown);
			this->glPanelControl1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::glPanelControl1_KeyUp);
			this->glPanelControl1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::glPanelControl1_MouseDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(678, 211);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(678, 242);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 376);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->glPanelControl1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 openFileDialog1->ShowDialog();
			 }
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
				 std::string filename;
				 MarshalString( openFileDialog1->FileName, filename );

				 if( mesh != NULL )
					 delete mesh ;

				 mesh = new Tri_Mesh;


				 if(ReadFile(  filename, mesh  ) )
				 {
					 std::cout<<filename<<std::endl;
					 mesh->select_fh = mesh->face_handle(0) ;
					 mesh->select_vh = mesh->vertex_handle(0);
				 }
				 //mesh->select_fh = NULL;

				 glPanelControl1->Invalidate();

			 }

private: System::Void glPanelControl1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 if ( mesh != NULL )
			 {
				 mesh->Render_SolidWireframe();

				 glEnable(GL_COLOR_MATERIAL);
				 glDisable(GL_LIGHTING);
				 glColor3f( 1.0, 0.0, 0.0 );
				 glBegin(GL_TRIANGLES);


				 if(isPoint)
				 {
					 for( OMT::VFIter vf_it = mesh->vf_iter(mesh->select_vh) ; vf_it ; ++vf_it )
					 {
						 for(OMT::FVIter fv_it= mesh->fv_iter(vf_it.handle()) ; fv_it ; ++fv_it){
							 glVertex3dv( mesh->point(fv_it).data() );
						 }
					 }
				 }
				 else if(isFace)
				 {
					 for(OMT::FVIter fv_it= mesh->fv_iter(mesh->select_fh) ; fv_it ; ++fv_it){
						 glVertex3dv( mesh->point(fv_it).data() );
					 }
				 }
				 glEnd();
				 glEnable(GL_LIGHTING);
			 }
		 }
private: System::Void glPanelControl1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if ( e->KeyCode == System::Windows::Forms::Keys::ControlKey )
			 {
				 isPoint = true;
				 isFace = false;
				 glPanelControl1->Trackball_Property->Enabled = false ;
			 }
			 else if ( e->KeyCode == System::Windows::Forms::Keys::ShiftKey )
			 {
				 isFace = true;
				 isPoint = false;
				 glPanelControl1->Trackball_Property->Enabled = false ;
			 }
		 }
private: System::Void glPanelControl1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if ( e->KeyCode == System::Windows::Forms::Keys::ControlKey )
			 {
				 glPanelControl1->Trackball_Property->Enabled = true ;
			 }
			 else if ( e->KeyCode == System::Windows::Forms::Keys::ShiftKey )
			 {
				 isFace = false;
				 isPoint = false;
				 glPanelControl1->Trackball_Property->Enabled = false ;
			 }
		 }
private: System::Void glPanelControl1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 int Op_X,Op_Y;
			 Op_X = e->X ;
			 Op_Y = glPanelControl1->Height - e->Y ;
			 if ( e->Button == System::Windows::Forms::MouseButtons::Right )
			 {   
				 if( !glPanelControl1->Trackball_Property->Enabled)  
				 {
					 if(isPoint)
					 {
						 if(mesh!=NULL)mesh->Select_Point( Op_X, Op_Y );
						 label1->Text = "Point";
					 }
					 else if(isFace)
					 {
						 if(mesh!=NULL)mesh->Select_Face( Op_X, Op_Y );
						 label1->Text = "Face";
					 }
				 }
					
			 }
			 glPanelControl1->Invalidate();
		 }
};
}

