## Troubleshooting

# If the statusline is not coloured then modify TERM in your shell configuration (.zshrc for example)

`export TERM=xterm-256color`

# If the statusline is not drawn with the correct shape (ie. rectangles instead of arrows)

Try the following:
* install powerline fonts (github.com/powerline/fonts)
* configure terminal to use it
* add `let g:airline_powerline_fonts = 1` in the `.vimrc` file
