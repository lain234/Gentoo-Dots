# /etc/skel/.bashrc
#
# This file is sourced by all *interactive* bash shells on startup,
# including some apparently interactive shells such as scp and rcp
# that can't tolerate any output.  So make sure this doesn't display
# anything or bad things will happen !


# Test for an interactive shell.  There is no need to set anything
# past this point for scp and rcp, and it's important to refrain from
# outputting anything in those cases.
if [[ $- != *i* ]] ; then
	# Shell is non-interactive.  Be done now!
	return
fi


# Put your fun stuff here.

export VISUAL=nvim
export EDITOR="$VISUAL"

export PATH="/home/lain/scripts:$PATH"

export PATH="/home/lain/.local/bin:$PATH"

alias dotfiles='/usr/bin/git --git-dir=$HOME/git/dotfiles/ --work-tree=$HOME' 

alias n='nvim'

[ -z "$(pidof X)" ] && startx

# neofetch --off --separator '\t'

fetch

export PS1=" \[\e[00;34m\]✿ \W \[\e[0m\]"
export PATH=$PATH:/home/lain/.spicetify
