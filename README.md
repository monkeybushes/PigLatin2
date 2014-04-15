PigLatin2
=========

English to PigLatin, pointer practice


This is the first in a long series of practice programs for C.

Currently, the program gets a segmentation fault when the user types in certain characters. It is apparent I still need
to practice my pointer skills. For now, this is Version 1.0.

--

This program is designed to take a user's input in English and translate it into pig latin by following these rules:

[1] For words that begin with consonant sounds, the initial consonant or consonant cluster is moved to the end of the word, and "ay" is added, as in the following examples:
"happy" → "appyhay"
"duck" → "uckday"
"glove" → "oveglay"
For words that begin with vowel sounds or silent letter, you just add ay to the end. Examples are:
"egg" → "eggay"
"inbox" → "inboxay"
"eight" → "eightay"

It is able to follow this rule to the letter.

I built this on Windows using Cygwin/GCC, so you will need the Cygwin DLL's to be able to run the exe's already built.
