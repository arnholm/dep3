#ifndef DEP3DROPTARGET_H
#define DEP3DROPTARGET_H

#include <wx/dnd.h>

class dep3DropTarget : public wxFileDropTarget {
public:
   dep3DropTarget();
   virtual ~dep3DropTarget();
   bool OnDropFiles(wxCoord x, wxCoord y,  const wxArrayString& filenames);
};

#endif // DEP3DROPTARGET_H
