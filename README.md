# xs_comparison
Codes used for exploratory comparison of neutrino-nucleus cross sections made with event generators and calculated with first principles theory.

Directory contains four root macros written in C++ to plot differential cross sections for neutrinos and anti-neutrions with RFG and SF. 
	
	* diffxs_nu_rfg.cpp -- compares NEUT and GENIE RFG for neutrinos
	* diffxs_nu_sf.cpp -- compares NEUT and GENUE SF for neutrinos
	* diffxs_Anu_rfg.cpp -- compares NEUT and GENIE RFG for anti-neutrinos
	* diffxs_Anu_sf.cpp -- compares NEUT and GENUE SF for anti-neutrinos

The root files were prepared with NUISANCE and the histogram of the cross section is made by drawing a histogram in the appropriate variable in the ROOT tree and scaling. The scaling factors:

	* fScaleFactor_alttest -- used to convert to event rates into cross sections in units cm^2
	* 10e41 -- to get cross section in units 10e-15 fm^2
	* Divide by 2*pi*d(cos(theta)) and d(omega)=20 MeV
	* Scale by a truth cut in energy so it is independent of bin width ( = 15)

These scalings give a differential cross section in 10e-15 fm^2/Mev/sr

To run:
	`root name_of_macro.cpp`

