## Języki programowania, 2015/16

Git:

* Scott Chacon, Ben Straub. [Pro Git](https://git-scm.com/book/en/v2)
  - [6.1 GitHub – Account Setup and Configuration](https://git-scm.com/book/en/v2/GitHub-Account-Setup-and-Configuration)
  - [6.2 GitHub – Contributing to a Project](https://git-scm.com/book/en/v2/GitHub-Contributing-to-a-Project)

Atom:

* Instalujemy pakiety:
  [linter](https://github.com/atom-community/linter),
  [linter-gcc](https://atom.io/packages/linter-gcc),
  [git-plus](https://atom.io/packages/git-plush).

Command Line, Git, Text Editor:

* [Learn Enough to Be Dangerous](http://www.learnenough.com)


### Konfiguracja…

Atom, *keymap.cson*:

```yaml
'.platform-linux':
  'cmd-shift-p': 'command-palette:toggle'
  'cmd-shift-h': 'git-plus:menu'
```

*snippets.cson*:

```yaml
'.source.c':
  'main with include':
    'prefix': 'maini'
    'body': '#include <stdio.h>\nint main() {\n  $0\n}\n'
```
