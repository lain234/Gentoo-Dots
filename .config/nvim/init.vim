"    _____________________________________ 
"   |                                     |
"   | | \ | | ___  _____   _(_)_ __ ___   |
"   | |  \| |/ _ \/ _ \ \ / / | '_ ` _ \  |
"   | | |\  |  __/ (_) \ V /| | | | | | | |
"   | |_| \_|\___|\___/ \_/ |_|_| |_| |_| |
"   |_____________________________________|


" config by: https://github.com/lain234

" Plugins

call plug#begin('~/.config/nvim/plugged')

Plug 'preservim/nerdtree' " File Search

Plug 'shaunsingh/nord.nvim' " Theme

Plug 'vim-airline/vim-airline' " Bottom Bar
Plug 'vim-airline/vim-airline-themes' " Bottom Bar Themes
Plug 'ryanoasis/vim-devicons' " Icons

call plug#end()

" General Settings

set encoding=UTF-8 nobackup nowritebackup nocursorline splitbelow splitright wildmode=longest,list,full

set nu rnu

" Key Bindings

let mapleader=","

nnoremap <leader>s :source ~/.config/nvim/init.vim<CR>
nnoremap Q <nop>
nnoremap <leader>e :Explore<CR>
nnoremap <leader>n :NERDTree<CR>
nnoremap <leader>p :PlugInstall<CR>
nnoremap <leader>c :PlugClean<CR>
nnoremap <leader>i :intro<CR>

" Color Settings

colorscheme nord

set background=dark
set termguicolors

hi! Normal ctermbg=NONE guibg=NONE

" Airline Settings 

" let g:airline#extensions#tabline#enabled = 1

let g:airline_theme='nord_minimal'

let g:airline#extensions#whitespace#enabled = 0

set noshowmode
