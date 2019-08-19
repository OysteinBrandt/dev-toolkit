"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Plugins
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
call plug#begin('~/.vim/plugged') " Directory for plugins

" Utilities
Plug 'itchyny/lightline.vim'	" statusline 
Plug 'kien/ctrlp.vim'			" fuzzy find files
Plug 'tpope/vim-fugitive'		" the ultimate git helper

"Plug 'scrooloose/nerdtree'		" file drawer, open with :NERDTreeToggle
"Plug 'benmills/vimux'
"Plug 'tpope/vim-commentary'	" comment/uncomment lines with gcc or gc in visual mode

" Colorschemes
"Plug 'arcticicestudio/nord-vim'
"Plug 'chriskempson/base16-vim'

call plug#end() " Initialize plugin system

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => General
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let mapleader = ','
set autoread 

" Tab control
set noexpandtab		" tabs ftw
set smarttab		" tab respects 'tabstop', 'shiftwidth', and 'softtabstop'
set tabstop=4		" the visible width of tabs
set softtabstop=4	" edit as if the tabs are 4 characters wide
set shiftwidth=4	" number of spaces to use for indent and unindent
set shiftround		" round indent to a multiple of 'shiftwidth'

set clipboard=unnamed

" faster redrawing
set ttyfast

" code folding settings
set foldmethod=syntax	" fold based on indent
set foldnestmax=10		" deepest fold is 10 levels
set nofoldenable		" don't fold by default
set foldlevel=1

" netrw / Explore settings
let g:netrw_liststyle = 3	" start explorer in a tree view
let g:netrw_banner = 0		" remove the explorer banner

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => User Interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set hlsearch	" highlight text when search matches
set number		" display line number(s)
set noshowmode	" disable text that displays the active mode (eg. -- INSERT --)

set encoding=utf8
let base16colorspace=256  " Access colors present in 256 colorspace"
if !has('gui_running')
  set t_Co=256
endif
"set background=dark
"colorscheme delek
colorscheme ron "pablo
"colorscheme wombat
"colorscheme base16-default-dark


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Mappings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
map <leader>ev :e! ~/.vimrc<cr> " edit ~/.vimrc
nmap <leader>k :Lex				" open explorer

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Plugin settings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" map fuzzyfinder (CtrlP) plugin
" nmap <silent> <leader>t :CtrlP<cr>
nmap <silent> <leader>r :CtrlPBuffer<cr>
let g:ctrlp_map='<leader>t'
let g:ctrlp_dotfiles=1
let g:ctrlp_working_path_mode = 'ra'

let g:ctrlp_custom_ignore = {
            \ 'dir': '\.git$\|node_modules$\|\.hg$\|\.svn$',
            \ 'file': '\.exe$\|\.so$'
            \ }

" search the nearest ancestor that contains .git, .hg, .svn
let g:ctrlp_working_path_mode = 2

let g:lightline = {
      \ 'active': {
      \   'left': [ [ 'mode', 'paste' ],
      \             [ 'gitbranch', 'readonly', 'filename', 'modified' ] ]
      \ },
      \ 'component_function': {
      \   'gitbranch': 'fugitive#head'
      \ },
      \ }


" TODO(obr): Test NERDTree, should this plugin be used instead of built in `Explore`?
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"let g:NERDTreeQuitOnOpen=0		" close NERDTree after a file is opened
"let NERDTreeShowHidden=1		" show hidden files in NERDTree
"" Toggle NERDTree
"nmap <silent> <leader>k :NERDTreeToggle<cr>
"" expand to the path of the file in the current buffer
"nmap <silent> <leader>y :NERDTreeFind<cr>

