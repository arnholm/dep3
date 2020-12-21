#ifndef DEP3PANEL_H
#define DEP3PANEL_H

#include <wx/filename.h>

//(*Headers(dep3Panel)
#include <wx/imaglist.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/treectrl.h>
//*)

class dep3Panel: public wxPanel {
public:

   static bool check_lddtree();

   dep3Panel(wxWindow* parent,wxWindowID id=wxID_ANY);
   virtual ~dep3Panel();

   void Open(const wxFileName& fname);

   //(*Declarations(dep3Panel)
   wxImageList* m_images;
   wxTreeCtrl* m_tree;
   //*)

protected:

   //(*Identifiers(dep3Panel)
   static const long ID_TREECTRL1;
   //*)

private:

   //(*Handlers(dep3Panel)
   //*)

   DECLARE_EVENT_TABLE()
};

#endif
