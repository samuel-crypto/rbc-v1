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
bits (KPA attack)
