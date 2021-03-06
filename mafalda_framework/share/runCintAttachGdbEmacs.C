/*
 * 	Copyright 2012 John Idarraga
 *
 * 	This file is part of MAFalda.

    MAFalda is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    MAFalda is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MAFalda.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 *
 * Run CINT, load libs, start emacs and tell him to attach to the pid :)

   $ root -l runCintAttachGdbEmacs.C

   then you are ready to place breakpoints

   (gdb) b 'BlobsFinder::BlobsFinder()'
   (gdb) c

   At this point the control of the process has come back to the CINT session.
   You can run whatever you need

   root [1] .x runExample.C

   when you hit the break point the control comes back to gdb in the nice
   split emacs window.  Enjoy :)

   If you just want to see you code crashing and then backtrace it.  Skip the
   setting a breat point step.

 */

void runCintAttachGdbEmacs() {

	// Load libs // Include your own lib here
	gSystem->Load("libCore");
	gSystem->Load("libHist");
	gSystem->Load("libHistPainter");
	gSystem->Load("libMediPixAnalysisCore.so");

	// Get pid
	int pid = gSystem->GetPid();
	cout << "Pid : " << gSystem->GetPid() << endl;

	// Prepare a command to run emacs with gdb
	TString com=".! emacs --eval ' (gdb \"gdb --annotate=3 --pid ";
	com += pid;
	com += "\") ' &";

	// Issue the command.  The CINT prompt frizes.  At this point you
	//  can prepare your breakpoints and give the order "continue".
	cout << "Trying to run emacs in gdb mode --> " << com << endl;
	gROOT->ProcessLine(com);

}

