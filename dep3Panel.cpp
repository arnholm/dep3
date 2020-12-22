#include "dep3Panel.h"

#include "images/green.xpm"
#include "images/orange.xpm"
#include "images/red.xpm"
#include <wx/utils.h>

#include <vector>

//(*InternalHeaders(dep3Panel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dep3Panel)
const long dep3Panel::ID_TREECTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dep3Panel,wxPanel)
	//(*EventTable(dep3Panel)
	//*)
END_EVENT_TABLE()

dep3Panel::dep3Panel(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(dep3Panel)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	m_tree = new wxTreeCtrl(this, ID_TREECTRL1, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
	BoxSizer1->Add(m_tree, 1, wxEXPAND, 5);
	SetSizer(BoxSizer1);
	m_images = new wxImageList(16, 16, 1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	// Set the images for m_tree.
	m_tree->SetImageList(m_images);
	//*)

	// add red, green and orange 16x16 images to imagelist
	m_images->Add(wxBitmap(green_xpm));  // index 0
	m_images->Add(wxBitmap(red_xpm));    // index 1
	m_images->Add(wxBitmap(orange_xpm)); // index 2
}

dep3Panel::~dep3Panel()
{
	//(*Destroy(dep3Panel)
	//*)
}

bool dep3Panel::check_lddtree()
{
   wxString command = "which lddtree";
   wxArrayString output;
   wxArrayString errors;
   wxExecute (command, output, errors);

   if(output.GetCount() > 0) {
      wxFileName fname(output[0]);
      if(fname.Exists()) {
         return true;
      }
   }

   return false;
}


void dep3Panel::Open(const wxFileName& fname)
{
   wxString command = "lddtree " + fname.GetFullPath();
   wxArrayString output;
   wxArrayString errors;
   wxExecute (command, output, errors);

   constexpr size_t max_depth = 128;
   std::vector<wxTreeItemId> ids(max_depth);

   size_t ndep = output.GetCount();
   for(size_t i=0; i<ndep; i++) {

      // determine level in tree and green/red status
      size_t indent = output[i].find_first_not_of(' ');
      size_t ilev   = indent/4;
      int index     = (output[i].find("not found")==std::string::npos)? 0 : 1;

      if(ilev==0) {
         // create the root
         ids[0] = m_tree->AddRoot(output[i],index);
      }
      else {

         // add child item using red or green item colour
         ids[ilev] = m_tree->AppendItem(ids[ilev-1],output[i].substr(indent),index);

         if(index==1) {
            for(size_t j=0; j<ilev; j++) {

               // set orange if currently green
               if(0==m_tree->GetItemImage(ids[j])) m_tree->SetItemImage(ids[j],2);
            }
         }
      }
   }

   if(ndep>0) {
      m_tree->Expand(ids[0]);
   }

   // If we got some errors, output them in a subtree
   size_t nerr = errors.GetCount();
   if(nerr > 0) {
      auto err_id = m_tree->AddRoot("ERRORS",1);
      for(size_t i=0; i<nerr; i++) {
         m_tree->AppendItem(err_id,errors[i]);
      }
      m_tree->Expand(err_id);
   }


}
