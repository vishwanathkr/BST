# $Id: broadcast.sh,v 1.1 2010/09/26 01:02:40 root Exp $
#
# This file will be interpreted by /public/Modules/bin/cat-broadcast
# with file name generation disabled.  Be sure to escape characters
# (like \`) to avoid unwanted interpolation.  Also, be sure to 
# restrict write access to this file and any it execs!
#
  "$(date +"%a %b %d, %Y %l:%M%P") - Prepping `basename $(realpath ${1%%/broadcast*}/..)`"
#  There are $(expr 246 - `date +%j`) days remaining this quarter.
# Substitute julian day of quarter end in line above... just a silly example.
#
# For more complex, possibly user specific actions, edit the
# custom.sh script.
#`[ -x $(dirname $1)/custom.sh ] && $(dirname $1)/custom.sh`
