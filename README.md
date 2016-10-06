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


### Konfiguracja edytora Atom

Atom, *~/.atom/keymap.cson*:

```yaml
'.platform-linux atom-text-editor':
  'cmd-shift-p': 'command-palette:toggle'
  'cmd-shift-h': 'git-plus:menu'

'.platform-darwin atom-text-editor':
  'alt-a': 'native!'
  'alt-shift-s': 'unset!'
  'ctrl-shift-i': 'auto-indent:apply'
  'cmd-shift-m': 'markdown-preview:toggle'
```

*~/.atom/snippets.cson*:

```yaml
'.source.c':
  'main with include':
    'prefix': 'maini'
    'body': '#include <stdio.h>\nint main() {\n  $0\n}\n'
```

*~/.atom/styles.less*

```less
@ui-font-size: 16px;

linter-message {
  font-size: @ui-font-size;
}

.tab-bar .tab, .tab-bar .tab.active {
  font-size: @ui-font-size;
}

.status-bar {
  font-size: @ui-font-size;
}

.tree-view {
  font-size: @ui-font-size;
}

.settings-view {
  font-size: @ui-font-size;
}

.overlay .select-list ol.list-group li,
.overlay.select-list ol.list-group li {
  font-size: @ui-font-size;
}
```

If you are unfamiliar with LESS, you can read more about it here:
[LessCSS](http://www.lesscss.org).
