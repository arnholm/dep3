# dep3
Simple Linux dependency tree viewer

dep3 is a GUI front end on top of lddtree from the package pax-utils. To use dep3, please first install pax-utils

    $ sudo apt-get install pax utils
	 
You can then use File->Open or drag/drop linux executables or shared objects into dep3 and a dependency graph will be shown. Missing dependencies are marked in red, resolved dependencies are marked in green. Anything depending on a missing module is marked in orange.


The info screen
![info](/images/info.png)

Dependency graph of an application with a missing shared object
![angelcad](/images/angelcad.png)


