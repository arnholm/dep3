/***************************************************************
 * Name:      dep3Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    cpde template ()
 * Created:   2012-07-19
 * Copyright: cpde template ()
 * License:
 **************************************************************/

#include "dep3Main.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>

#include "dep3Panel.h"
#include "dep3DropTarget.h"

//(*InternalHeaders(dep3Frame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "images/dep3_32x32.xpm"
#include "images/dep3_48x48.xpm"
#include "images/dep3_64x64.xpm"


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(dep3Frame)
const long dep3Frame::ID_STATICTEXT1 = wxNewId();
const long dep3Frame::ID_PANEL1 = wxNewId();
const long dep3Frame::ID_AUINOTEBOOK1 = wxNewId();
const long dep3Frame::ID_MENUITEM1 = wxNewId();
const long dep3Frame::idMenuQuit = wxNewId();
const long dep3Frame::idMenuAbout = wxNewId();
const long dep3Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dep3Frame,wxFrame)
    //(*EventTable(dep3Frame)
    //*)
END_EVENT_TABLE()

dep3Frame::dep3Frame(wxWindow* parent,wxWindowID id)
{
   //(*Initialize(dep3Frame)
   wxBoxSizer* BoxSizer1;
   wxMenu* Menu1;
   wxMenu* Menu2;
   wxMenuBar* MenuBar1;
   wxMenuItem* MenuItem1;
   wxMenuItem* MenuItem2;

   Create(parent, wxID_ANY, _("dep3 - Simple Linux dependency tree viewer"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
   SetClientSize(wxSize(700,700));
   AuiManager1 = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
   AuiNotebook1 = new wxAuiNotebook(this, ID_AUINOTEBOOK1, wxPoint(121,317), wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
   InfoPage = new wxPanel(AuiNotebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
   BoxSizer1 = new wxBoxSizer(wxVERTICAL);
   BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   StaticText1 = new wxStaticText(InfoPage, ID_STATICTEXT1, _("Analyze a new binary file via \"File -> Open\" (Ctrl+O)\nor simply by dragging into the application.  \n"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
   wxFont StaticText1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
   StaticText1->SetFont(StaticText1Font);
   BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   BoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
   InfoPage->SetSizer(BoxSizer1);
   BoxSizer1->Fit(InfoPage);
   BoxSizer1->SetSizeHints(InfoPage);
   AuiNotebook1->AddPage(InfoPage, _("InfoPage"));
   AuiManager1->AddPane(AuiNotebook1, wxAuiPaneInfo().Name(_T("PaneName0")).CenterPane().Caption(_("Pane caption")));
   AuiManager1->Update();
   MenuBar1 = new wxMenuBar();
   Menu1 = new wxMenu();
   MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Open...\tCtrl+O"), wxEmptyString, wxITEM_NORMAL);
   Menu1->Append(MenuItem3);
   MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
   Menu1->Append(MenuItem1);
   MenuBar1->Append(Menu1, _("&File"));
   Menu2 = new wxMenu();
   MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
   Menu2->Append(MenuItem2);
   MenuBar1->Append(Menu2, _("Help"));
   SetMenuBar(MenuBar1);
   StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
   int __wxStatusBarWidths_1[1] = { -1 };
   int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
   StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
   StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
   SetStatusBar(StatusBar1);

   Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dep3Frame::OnFileOpenSelected);
   Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dep3Frame::OnQuit);
   Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dep3Frame::OnAbout);
   //*)

   m_config = new wxConfig(wxT("dep3"),wxT("Arnholm"));
   m_config->Read("DefaultDir",&m_default_dir);

   wxIconBundle icons;
   icons.AddIcon(wxIcon(dep3_32x32_xpm));
   icons.AddIcon(wxIcon(dep3_48x48_xpm));
   icons.AddIcon(wxIcon(dep3_64x64_xpm));
   SetIcons(icons);


    // Drag & drop support
   SetDropTarget(new dep3DropTarget());

   if(!dep3Panel::check_lddtree()) {
      wxString msg = "Please install pax-utils:\n $ sudo apt-get install pax-utils";
      wxMessageBox(msg, "lddtree not found!");
   }

}

dep3Frame::~dep3Frame()
{
   m_config->Write("DefaultDir",m_default_dir);
   delete m_config;

    //(*Destroy(dep3Frame)
    //*)

   // shut down AUI
   AuiManager1->UnInit();
}

void dep3Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void dep3Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to dep3"));
}

void dep3Frame::OnFileOpenSelected(wxCommandEvent& event)
{
   wxFileDialog dlg(this,wxT("Open executable/shared object files"),m_default_dir,wxT(""),wxT("Executable & shared object files (*;*.so)|*;*.so|All files (*.*)|*.*"),wxFD_OPEN|wxFD_FILE_MUST_EXIST);
   if(dlg.ShowModal() == wxID_OK) {
      wxArrayString paths;
      dlg.GetPaths(paths);

      wxFileName fname(paths[0]);
      DoFileOpen(fname);
   }
}


void dep3Frame::DoFileOpen(const wxFileName& fname)
{
   int ipage = AuiNotebook1->GetPageIndex(InfoPage);
   AuiNotebook1->DeletePage(ipage);

   m_default_dir = fname.GetPath();

   dep3Panel* page = new dep3Panel(AuiNotebook1);
   AuiNotebook1->AddPage(page,fname.GetFullName(),true);
   page->Open(fname);
}
