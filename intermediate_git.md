## Intermediate Git

* Mark Dominus
  - [Why can't Git resolve all conflicted merges?](http://blog.plover.com/prog/git-merge.html)
  - [My Git Habits](http://blog.plover.com/prog/git-habits.html)
* Bert Belder, [Checkout github pull requests locally](https://gist.github.com/piscisaureus/3342247)
* Chris Wanstrath, [Hub makes git better with GitHub](http://defunkt.io/hub/)
* Seth Robertson, [On undoing, fixing, or removing commits in git](http://sethrobertson.github.io/GitFixUm/fixup.html)
* [Going back in time to split older commits](http://blog.thoughtram.io/git/2014/08/18/going-back-in-time-to-split-older-commits.html) –
  na blogu „ThoughtRAM - extend your memory”


### Zmniejszamy liczbę commitów, zmieniamy ich kolejność itp.

> Another common practice is to rebase
> the last few commits in your current branch
>
> [Interactive rebase](https://help.github.com/articles/about-git-rebase/) on GitHub


```sh
git checkout issue16                       # o ile commity są na tej gałęzi
git log --pretty=oneline HEAD~8..HEAD      # sprawdzamy ostatnich 8 commitów
git rebase -i HEAD~4                       # zmieniamy ostatnie 4 committy

.. edycja ..
....  edit -- jeśli chcemy poprawić ten commit lub coś do niego dodać
........  git reset HEAD^  # rollback the last commit
........  git status
........  git add --patch  # lub dodajemy/edytujemy pliki
........
........  git rebase --continue
....  reword -- poprawiamy tekst wpisu do log
```

*Uwaga:* Na stronie manuala *gitrevisions* jest opisane znaczenie:
`HEAD^`, `^HEAD`, `HEAD~n`.

Teraz sprawdzamy wpisy log i scalamy wprowadzone zmiany:

```sh
git log --pretty=oneline
git rebase master                          # o ile jesteśmy na gałęzi issue16
git checkout master
git merge issue16
git branch -d issue16                      # możemy usunąć scaloną gałąź
```

### Undo różnych rzeczy

```sh
git reset --merge                 # merge
git reset --hard ORIG_HEAD        # rebase
git show some-branch:some-file.js # extract a file from another branch
git revert -n                     # to undo a previous commit or two, 
                                  # look at the changes, and see which 
                                  # ones might have caused a problem
```

### Stashing

czyli, odkładanie pracy na później...

```sh
git stash
git stash list
git stash apply stash@{0}  # przykłady
git stash drop  stash@{0}
```
