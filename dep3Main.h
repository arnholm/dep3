/***************************************************************
 * Name:      dep3Main.h
 * Purpose:   Defines Application Frame
 * Author:    cpde template ()
 * Created:   2012-07-19
 * Copyright: cpde template ()
 * License:
 **************************************************************/

#ifndef DEP3MAIN_H
#define DEP3MAIN_H

//(*Headers(dep3Frame)
#include <wx/aui/aui.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)
#include <wx/filename.h>
#include <wx/config.h>


class dep3Frame: public wxFrame {
public:
   friend class dep3DropTarget;

   dep3Frame(wxWindow* parent,wxWindowID id = -1);
   virtual ~dep3Frame();

private:

   void DoFileOpen(const wxFileName& fname);

   //(*Handlers(dep3Frame)
   void OnQuit(wxCommandEvent& event);
   void OnAbout(wxCommandEvent& event);
   void OnFileOpenSelected(wxCommandEvent& event);
   //*)

   //(*Identifiers(dep3Frame)
   static const long ID_STATICTEXT1;
   static const long ID_PANEL1;
   static const long ID_AUINOTEBOOK1;
   static const long ID_MENUITEM1;
   static const long idMenuQuit;
   static const long idMenuAbout;
   static const long ID_STATUSBAR1;
   //*)

   //(*Declarations(dep3Frame)
   wxAuiManager* AuiManager1;
   wxAuiNotebook* AuiNotebook1;
   wxMenuItem* MenuItem3;
   wxPanel* InfoPage;
   wxStaticText* StaticText1;
   wxStatusBar* StatusBar1;
   //*)

   DECLARE_EVENT_TABLE()

private:
   wxString  m_default_dir;
   wxConfig* m_config;
};

#endif // DEP3MAIN_H
