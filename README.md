## Języki programowania, 2015/16

Git:

* Scott Chacon, Ben Straub. [Pro Git](https://git-scm.com/book/en/v2)
  - [6.1 GitHub – Account Setup and Configuration](https://git-scm.com/book/en/v2/GitHub-Account-Setup-and-Configuration)
  - [6.2 GitHub – Contributing to a Project](https://git-scm.com/book/en/v2/GitHub-Contributing-to-a-Project)
* [Git Tips](https://github.com/git-tips/tips) – most commonly used git tips and tricks

Atom:

* Instalujemy pakiety:
  [linter](https://github.com/atom-community/linter),
  [linter-gcc](https://atom.io/packages/linter-gcc),
  [git-plus](https://atom.io/packages/git-plush).

Command Line, Git, Text Editor:

* [Learn Enough to Be Dangerous](http://www.learnenough.com)
* [The Art of Command Line](https://github.com/jlevy/the-art-of-command-line)

Algorytmy w C:

* [Numerical Recipes in C](http://www2.units.it/ipl/students_area/imm2/files/Numerical_Recipes.pdf) –
  the Art of Scientific Computing
* JL Bentley, MD McIlroy.
  [Engineering a Sort Function](http://cs.fit.edu/~pkc/classes/writing/samples/bentley93engineering.pdf)


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
