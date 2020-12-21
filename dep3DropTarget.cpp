#include "dep3DropTarget.h"
#include "dep3App.h"
#include "dep3Main.h"
#include <wx/filename.h>


dep3DropTarget::dep3DropTarget()
{}

dep3DropTarget::~dep3DropTarget()
{}

bool dep3DropTarget::OnDropFiles(wxCoord x, wxCoord y,  const wxArrayString& filenames)
{
   dep3Frame* frame = wxGetApp().GetFrame();

   size_t nfiles = filenames.GetCount();
   for(size_t ifile=0; ifile<nfiles; ifile++) {

      wxFileName fname(filenames[ifile]);
      frame->DoFileOpen(fname);
   }
   return false;
}
