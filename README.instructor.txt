Customization that previously has been accomplished with modifications to
"dotfiles" and a "prepfile" are now made using a course "modulefile", that
is named for the course and found in the $UMBRELLA/public/modulefiles/
directory.  Using modules to establish an environment eliminates restrictions
on which shells may be used, and facilitates dynamic customization.  Modules
are dynamically loaded and unloaded to alter arbitrary environment variables,
create aliases, modify PATHs, etc.

You've been supplied with a default modulefile that will, amoung other things:
  - set the envVAR "PREPLABEL" when it is loaded
  - changes CWD to $UMBRELLA/$USER when that directory exists
  - prepend $UMBRELLA/public/bin to PATH (if directory exists)
  - prepend $UMBRELLA/public/man to MANPATH (if directory exists)
  - Display a brief message affirming that the module has been loaded,
    and display the contents of the $UMBRELLA/public/broadcast file.
  - Load modules (like prolog, mmsim, cadence, hspice, etc.) as would
    have been done previously in a "prepfile".
  - Restrict "prepping" of certain packages to appropriate hosts.
  - Modifies variables used to maintain terminal titlebar.
  - (optionally) set user's umask
  - (optionally) execute a customization script.

The default ACMS "dotfiles" will "prep" a course specific user's environment
at login.  OCE students should be able to just type the name of the course
(or package) that they want to "prep", or use the "prep" and "unprep"
commands as needed.  These aliases are built over the "module" command;
Advanced users may wish to use modules directly, but this should not be
required.  "modulefiles" are coded in Tcl using modules and TclX extentions.
Mosts configuration is done with "setenv" and "prepend-path" commands,
examples of which you will find in the supplied modulefile.

You may add other modulefiles to your "modulefiles/" directory, but we
anticipath that minor changes to the default file will be all that is
required.  ACMS will maintain modulefiles for all supported software packages.

If you need to install additional software that you will build from source,
we suggest creating a directory within $PUBLIC for archives and extracted
packages, and (for those using GNU configure) configuring with the
"--prefix=$PUBLIC" option.

Python modules should be installed as:
	python setup.py install --prefix=$PUBLIC
and placing the following in the course modulefile:
	prepend-path PYTHONPATH $PUBLIC

Something similar should be done for Java jar files and CLASSPATH.

Manpages:
	module(1), modulefile(4), prep(1), unprep(1).

References:
	http://modules.sourceforge.net
	http://modules.sourceforge.net/docs/MC2_whitney_paper.pdf

