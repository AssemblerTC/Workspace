set matchpairs+=<:>
"background-color #090B18
set cursorline
set cursorcolumn
"insertar template
nnoremap <F5> :0r ~/template.cpp<CR>:24<CR>i<Tab>
"selecionar todo y copiar al clipboard
nnoremap <C-a> ggvG"+y
"Compilar :D :D :D :D :D :D
nnoremap <F9> <Esc>:w<CR>:make<CR><CR>
inoremap <F9> <Esc>:w<CR>:make<CR><CR>
"cambiar make
set makeprg=g++\ -std=c++11\ -Wall\ -W\ -DACMTUYO\ %
"listar autocompletado con Shift+TAB
inoremap <S-Tab> <C-n>
set shiftwidth=2
set tabstop=2
set softtabstop=2
set expandtab
set number
set backup
syntax on
set mouse=a
set ruler
set smartcase
set title 
set wildmenu
set showcmd
"set cursorline
"set cursorcolumn
mat Keyword "\<forn\>"
"Activar 256 colores de la terminal
set t_Co=256
"colocar molokai theme
color molokai 
"Quitar fondo y activar molokai2
hi Normal ctermbg=none
let g:molokai_original = 1

"let g:rehash256 = 1

"Auto identar
filetype indent on

"Identar con TAB como en emacs
set cinkeys=0{,0},0),0#,!<Tab>,;,:,o,O,e
set indentkeys=!<Tab>,o,O
map <Tab> i<Tab><Esc>^
set cinoptions=:0,(0,u0,W1s
"inoremap {<CR>  {<CR>}<Esc>O

"Auto completar llaves y saltar si ya esta cerrado
"inoremap        (  ()<Left>
"inoremap <expr> )  strpart(getline('.'), col('.')-1, 1) == ")" ? "\<Right>" : ")"

function! CerrarLlave(lista)
  let linea = getline('.')
  let pos = col('.')
  if pos < col('$')
    return "{"
  endif
  for cad in a:lista
    if (stridx(linea, cad, pos - len(cad) - 1) != -1)
      return " {\<CR>}\<C-o>==\<C-o>O"
    endif
  endfor
  return "{}\<left>"
endfunction

inoremap <expr> { CerrarLlave(["else", ")", "do", "try"])

set guioptions-=T  "Quitar el toolbar del gvim
"Auto abrir Quickfix para ver errores de compilacion
autocmd QuickFixCmdPost [^l]* nested cwindow
autocmd QuickFixCmdPost    l* nested lwindow
