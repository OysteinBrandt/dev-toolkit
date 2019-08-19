## Troubleshooting

### If the `nord` colorscheme is used, additional installations may be required in order to get the correct color pallete
* see https://www.nordtheme.com/docs/ports/vim/installation

### If the statusline is not coloured then modify TERM in your shell configuration (.zshrc for example)

`export TERM=xterm-256color`

### If the statusline is not drawn with the correct shape (ie. rectangles instead of arrows)

#### Try the following:
* install powerline fonts (github.com/powerline/fonts), for common systems install with `sudo apt-get install fonts-powerline`

#### If it still does not work, try additional steps below
* configure terminal to use the installed font 
* add `let g:airline_powerline_fonts = 1` in the `.vimrc` file
