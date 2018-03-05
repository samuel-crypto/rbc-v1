# RBC -- version 1.0
## What is this?
This is a purposefully broken encryption system, designed for basic 
training in basic (rotational) cryptoanalysis.

## How to compile / run
Make sure you have a standard library and a linux environment.
Next, run the following:

`make all`

followed by

`./rbc`

to run the code (by default this encrypts and decrypts a plaintext of 0 
with a key of 0 (64-bits)).

## Cipher specs

**Round design:** Feistel-esque

**Plaintext block size:** `128-bit` (2 `64-bit` pieces)

**Key block size:** `128-bit` (also 2 `64-bit` pieces)

**Estimated security:** There are likely multiple ways to break this, 
but the one I have in mind would reduce this by **at least** a couple of 
dozen bits (KPA attack)

**Key expansion:** I'm not even sure how to call this abomination... 
(purpose of analysis is not to break it, because it was mopped up really 
quickly and doesn't demonstrate the main point which is related to the 
weakened round design)
