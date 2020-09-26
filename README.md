The Diff Match and Patch libraries offer robust algorithms to perform the
operations required for synchronizing plain text.

1. Diff:
   * Compare two blocks of plain text and efficiently return a list of differences.
   * [Diff Demo](https://neil.fraser.name/software/diff_match_patch/demos/diff.html)
2. Match:
   * Given a search string, find its best fuzzy match in a block of plain text. Weighted for both accuracy and location.
   * [Match Demo](https://neil.fraser.name/software/diff_match_patch/demos/match.html)
3. Patch:
   * Apply a list of patches onto plain text. Use best-effort to apply patch even when the underlying text doesn't match.
   * [Patch Demo](https://neil.fraser.name/software/diff_match_patch/demos/patch.html)

Originally built in 2006 to power Google Docs.

This particular fork takes the https://github.com/fvla/diff-match-patch fork (removal of Qt dependencies) and
focuses on just the C++ version.

### Reference

* [API](https://github.com/google/diff-match-patch/wiki/API) - Common API across all languages.
* [Line or Word Diffs](https://github.com/google/diff-match-patch/wiki/Line-or-Word-Diffs) - Less detailed diffs.
* [Plain Text vs. Structured Content](https://github.com/google/diff-match-patch/wiki/Plain-Text-vs.-Structured-Content) - How to deal with data like XML.
* [Unidiff](https://github.com/google/diff-match-patch/wiki/Unidiff) - The patch serialization format.
* [C++ API notes](https://github.com/google/diff-match-patch/wiki/Language:-Cpp)

### Algorithms
This library implements [Myer's diff algorithm](https://neil.fraser.name/writing/diff/myers.pdf) which is generally considered to be the best general-purpose diff. A layer of [pre-diff speedups and post-diff cleanups](https://neil.fraser.name/writing/diff/) surround the diff algorithm, improving both performance and output quality.

This library also implements a [Bitap matching algorithm](https://neil.fraser.name/writing/patch/bitap.ps) at the heart of a [flexible matching and patching strategy](https://neil.fraser.name/writing/patch/).
