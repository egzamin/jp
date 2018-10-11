## Użyteczne skróty klawiszowe

If there's one key-command you remember in Atom, it should be `shift-⌘-P`.

| skrót          | funkcja                        |
|----------------|--------------------------------|
|  shift+⌘+L     |  split-selection-into-lines    |
|  ctrl-⌘-space  |  select emoji 😎               |
|  ⌘-D           |  select token                  |
|  ⌘-L           |  select line                   |
|  shift-ctrl-↓  |  add selection up/down         |
|  ctrl-M        |  find matching bracket         |
|  ctrl-K        |  cut to end of line            |
|  ⌘-]           |  indent selected text          |
|  ⌘-[           |  oudent                        |
|  ⌘-↑           |  move to top                   |
|  ⌘-↓           |  move to bottom                |

## Wyrażenia regularne, czyli regexps

Przykład z wyszukaj (⌘-F) w `[Nowak, Dominik](https://github.com/abc/sp2016)`:
```regexp
\[(.+)\].+$
```
i zamień na `Nowak, Dominik`
```regexp
$1
```

## Różne rzeczy…

Sprawdzamy jakie mamy zainstalowane pakiety:

```bash
apm list --installed --bare > my-packages.txt
```

Instalujemy pakiety z listy _my-packages.txt_ na innym komputerze:

```bash
apm install --packages-file my-packages.txt
```

## Konfiguracja edytora Atom

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

.overlay.select-list ol.list-group li {
  font-size: @ui-font-size;
}
```

If you are unfamiliar with LESS, you can read more about it here:
[LessCSS](http://www.lesscss.org).
