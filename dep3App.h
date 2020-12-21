/***************************************************************
 * Name:      dep3App.h
 * Purpose:   Defines Application Class
 * Author:    cpde template ()
 * Created:   2012-07-19
 * Copyright: cpde template ()
 * License:
 **************************************************************/

#ifndef DEP3APP_H
#define DEP3APP_H

#include <wx/app.h>
class dep3Frame;

class dep3App : public wxApp {
public:
   virtual bool OnInit();
   dep3Frame* GetFrame();
};

// the magic that will make wxGetApp work
DECLARE_APP(dep3App);

#endif // DEP3APP_H
