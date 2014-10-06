# How to install vim and emacs, how to install and use plugins and custoomizations on them


Installing vim.
```bash
sudo pacman -S vim
sudo apt-get install vim
sudo yum install vim
```

Installing emacs.
```bash
sudo pacman -S emacs
sudo apt-get install emacs
sudo yum install emacs
```

Emacs has a great tutorial.Vim has a great wiki.

What makes an IDE a useful one, a good one?
* Edit, Mark, Cut, Paste
* File browser.
* Tab browser.
* Autocomplete.
* Compiler integration.
* Search fuctions in files - find in files.
* Search in code - go to definitions, find use in files.
* Coloring shemes.
* Function and class browser.
* Session and project handling.
* Code identation helpers.

http://vim.wikia.com/wiki/Use_Vim_like_an_IDE

Plugins for vim and emacs:

**Edit, Mark, Cut, Paste**

 vim:

 emacs:
 
**File browsers**

 vim: built in(:e .), NERDTree, vimExplorer, vinegar,..,unite.vim, command-t

  emacs: built in (C-x C-f .)

**Tab browser(and buffers)**

vim: built in(:tabe ), minibuf explorer, others....

http://vim.wikia.com/wiki/Using_tab_pages

http://vim.wikia.com/wiki/Easier_buffer_switching#Scripts

emacs: built in (C-x b), 

**Autocomplete**

vim : buit in(Ctrl+N), 

 https://github.com/Valloric/YouCompleteMe

http://www.vim.org/scripts/script.php?script_id=3302 

https://github.com/Shougo/neocomplete.vim

emacs: http://www.emacswiki.org/emacs/AutoComplete

**Compiler integration**

vim : built-in(:make)

 https://github.com/vim-scripts/SingleCompile 

 http://www.vim.org/scripts/script.php?script_id=213


emacs : buit-in(M-x compile)

**Search functions in files, find in files**

vim : buit-in(:grep), http://vim.wikia.com/wiki/Find_in_files_within_Vim

emacs : buit-in (M-x grep searc_term ./*)

**Search in code - go to definitions, find use in files**

vim : built-in(go over function or variable and press 'gd'), taglist, http://vim.wikia.com/wiki/Use_Vim_like_an_IDE

emacs: http://www.emacswiki.org/emacs/EmacsTags
 
**Coloring schemes**

vim : add "syntax on" to .vimrc

emacs: built in

**Function and class browser**

vim: taglist

emacs: http://www.gnu.org/software/emacs/manual/html_mono/ebrowse.html

**Session and project handling**

vim: built in sessions in vim, additonal script, other

add this to your .vimrc
```vimscript
function! MakeSession()
  let b:sessiondir = $HOME . "/.vim/sessions" . getcwd()
  if (filewritable(b:sessiondir) != 2)
    exe 'silent !mkdir -p ' b:sessiondir
    redraw!
  endif
  let b:filename = b:sessiondir . '/session.vim'
  exe "mksession! " . b:filename
endfunction

function! LoadSession()
  let b:sessiondir = $HOME . "/.vim/sessions" . getcwd()
  let b:sessionfile = b:sessiondir . "/session.vim"
  if (filereadable(b:sessionfile))
    exe 'source ' b:sessionfile
  else
    echo "No session loaded."
  endif
endfunction
au VimEnter * nested :call LoadSession()
au VimLeave * :call MakeSession()
```


emacs: https://www.gnu.org/software/emacs/manual/html_node/emacs/Saving-Emacs-Sessions.html

**Code identation helpers**

vim: plugins and macros

emacs : built in 


# Using stuff remotely with ssh

```bash
ssh -X
```

https://github.com/Russell91/sshrc/blob/master/sshrc
