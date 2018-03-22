# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is the longest English word in existence, with 45 letters.

## According to its man page, what does `getrusage` do?

It returns the resource usage statistics for who, which can be one of the following:
RUSAGE_SELF: the calling process which consists of all threads in the process
RUSAGE_CHILDREN: all children and descendants of the calling process that have been terminated or waited for
RUSAGE_THREAD: the calling thread

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

'before' and 'after' are of the struct data type. Passing by value would copy the whole struct into the stack, which could use up too much space on the stack. It would be faster and space-saving to pass by reference.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

for gets a character. if the character is an alphabet or an apostrophe that isn't at the start of the word, that character will be added to the word and the next character will be checked. else, if the character is a number, the following
alphabetical and numerical characters will be skipped over, then a new word is started. else, if the character is neither alphabetical, numerical or an apostrophe, and a word has been formed (where the 0th position has a character), a null
character will be added to the word to complete it. the word is then checked for spelling and printed if misspelled; following that, a new word is started.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

It will be difficult to identify and ignore words with numbers in them, as whole words will be scanned without checking for numbers within them. This will result in the unnecessary printing of alphanumerical words that don't pass the
spellchecker.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

The words in the file are pre-existing, not variables created in main, and hence they are constant. The same applies to words in the dictionary.



