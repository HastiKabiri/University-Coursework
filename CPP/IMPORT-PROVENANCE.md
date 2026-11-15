# Import provenance and backup recovery

The two C++ projects now live in this repository. Historical repository names and commit IDs are recorded below as plain text so documentation does not depend on deleted GitHub destinations.

| Current location | Historical repository | Imported source commit |
| --- | --- | --- |
| [Practice](Practice/) | `HastiKabiri/CPP-practice` | `df492a113748cdb2797abbe1a4dff1d6dbad5bf7` |
| [Student record assignment](Assignments/Singly-Linked-List-Student-System/) | `HastiKabiri/singly-linked-list-student-system-CPP` | `eac678fee3d2cd9ce5c2d8b8149c45742f6168e0` |

## What was preserved

- All eight loose C++ source files, all five CSV files, the dataset guide, study notes, original README content, and the source ZIP.
- Two student IDs were removed only from attribution comments; program logic is unchanged.
- Six compiled executables and three machine-specific VS Code configuration files are intentionally absent from this public working tree. They remain recoverable from the local backups.
- Original README files use `README.original.md`. The practice README's obsolete clone example is corrected to the consolidated repository.
- Original commits were not merged into this repository. Each original history contains two commits, preserved in its complete Git bundle.

## Private local backups

The backup directory is `Desktop/codes/University-Coursework-Backups`, alongside the local `University-Coursework` checkout. It contains:

- `CPP-practice-before-consolidation.bundle`
- `singly-linked-list-student-system-CPP-before-consolidation.bundle`

Both bundles were verified, restored into independent temporary repositories, and passed `git fsck --full`. Restored commit sets, source tips, and tracked file contents matched the originals before deletion. These are full histories, not just ZIP snapshots.

Keep the bundles local: they preserve historical identifiers and machine-specific files that were intentionally omitted from the public import. Do not delete or upload them as part of repository cleanup.

## Restore an original history

From the local `University-Coursework` directory, restore into new sibling folders:

```bash
git clone ../University-Coursework-Backups/CPP-practice-before-consolidation.bundle ../CPP-practice-restored
git clone ../University-Coursework-Backups/singly-linked-list-student-system-CPP-before-consolidation.bundle ../student-system-restored
```

These commands create new local repositories and do not overwrite this coursework repository or the backup bundles. The restored `origin` initially points to its local bundle, not a GitHub repository. Git bundles preserve Git history and tracked files; they are not backups of GitHub issues, stars, pull requests, or repository settings.

[Back to C++ Programming](README.md) · [University Coursework](../README.md)
