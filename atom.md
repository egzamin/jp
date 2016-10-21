## Przystosowujemy Atom do pracy z programami w C

If there's one key-command you remember in Atom, it should be `shift-⌘-p`.

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


## Różne rzeczy…

Sprawdzamy jakie mamy zainstalowane pakiety:

```bash
apm list --installed --bare > my-packages.txt
```

Instalujemy pakiety z listy _my-packages.txt_ na innym komputerze:

```bash
apm install --packages-file my-packages.txt
```
